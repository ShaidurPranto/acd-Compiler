parser grammar C8086Parser;

options {
    tokenVocab = C8086Lexer;
}

@parser::header {
    #include <iostream>
    #include <fstream>
	#include <sstream>
	#include <vector>
    #include <string>
    #include <cstdlib>
	#include <regex>
	#include <utility>
    #include "C8086Lexer.h"
	#include "./headers/2105177_SymbolTable.h"
	#include "./headers/util.cpp"
	#include "./headers/2105177_SymbolInfo.h"

	extern std::ofstream codeFile;
	extern std::ofstream optCodeFile;
	extern std::ofstream tempFile;
	extern std::string tempFileName;
	extern std::string codeFileName;
	extern std::string optCodeFileName;

	extern SymbolTable symbolTable;
}

@parser::members {
	bool isDebug = true;
	int stackMemberCount;
	int labelCount = 0;
	int lineCount = 1;
	std::string loopExpressionLabel = "EMPTY";
	std::string loopStatementLabel = "EMPTY";
	std::string currentFuncName = "EMPTY";
	bool isReturned = false;
	int pushCount = 0;
	int popCount = 0;
	int numberOfArguments = 0;

	// static boilerplate , utility functions to generate code
	void writeIntoCodeFile(const std::string& code) {
		if (!codeFile) {
			std::cout << "Error opening codeFile.txt" << std::endl;
			return;
		}
		codeFile << code;
		codeFile.flush();
	}
	void writeIntoOptCodeFile(const std::string& code) {
		if (!optCodeFile) {
			std::cout << "Error opening optCodeFile.txt" << std::endl;
			return;
		}
		optCodeFile << code;
		optCodeFile.flush();
	}
	int countNewLineOuccrences(std::string code) {
		int count = 0;
		for (char c : code) {
			if (c == '\n') {
				count++;
			}
		}
		return count;
	}
	void writeIntoTempFile(std::string code) {
		if (!tempFile) {
			std::cout << "Error opening tempFile.txt" << std::endl;
			return;
		}
		tempFile << code;
		tempFile.flush();
		if (code.find('\n') != std::string::npos) {
			lineCount += countNewLineOuccrences(code);
		}
	}
	std::string getComment(std::string line) {
		std::string code = "    ; Line " + line;
		return code;
	}
	void initializeCodeFile() {
		std::string templateCode = ".MODEL SMALL\n.STACK 1000H\n.DATA\n    number DB \"00000$\"\n";
		writeIntoCodeFile(templateCode);
	}
	void initializeTempFile() {
		std::string templateCode = ".CODE\n";
		writeIntoTempFile(templateCode);
	}
	void finalizeTempFile() {
		std::string part1 = "new_line proc\n    push ax\n    push dx\n    mov ah,2\n    mov dl,0Dh\n    int 21h\n";
		writeIntoTempFile(part1);

		std::string part2 = "    mov ah,2\n    mov dl,0Ah\n    int 21h\n    pop dx\n    pop ax\n    ret\nnew_line endp\n";
		writeIntoTempFile(part2);

		std::string part3 = "print_output proc  ;print what is in ax\n    push ax\n    push bx\n    push cx\n    push dx\n    push si\n    lea si,number\n    mov bx,10\n    add si,4\n    cmp ax,0\n    jnge negate\nprint:\n    xor dx,dx\n    div bx\n    mov [si],dl\n    add [si],'0'\n    dec si\n    cmp ax,0\n    jne print\n    inc si\n    lea dx,si\n    mov ah,9\n    int 21h\n";
		writeIntoTempFile(part3);

		std::string part4 = "    pop si\n    pop dx\n    pop cx\n    pop bx\n    pop ax\n    ret\nnegate:\n    push ax\n    mov ah,2\n    mov dl,'-'\n    int 21h\n    pop ax\n    neg ax\n    jmp print\nprint_output endp\n\nEND\n";
		writeIntoTempFile(part4);
	}
	void mergeTempFileToCodeFile() {
		std::ifstream tempFile(tempFileName, std::ios::in | std::ios::binary);
		if (!tempFile) {
			std::cout << "Error opening tempFile.txt" << std::endl;
			return;
		}

		tempFile.seekg(0, std::ios::end);
		size_t size = tempFile.tellg();
		tempFile.seekg(0, std::ios::beg);

		std::string code(size, '\0');
		tempFile.read(&code[0], size);

		tempFile.close();
		writeIntoCodeFile(code);
	}
	void initializeDataSegment() {
		std::string dataSegment = "    ;initialize data segment\n    MOV AX, @DATA\n    MOV DS, AX\n";
		writeIntoTempFile(dataSegment);
	}
	void initializeMainFunction(const std::string &functionName) {
		if (functionName == "main") {
			initializeDataSegment();
		}
	}
	void exitMainFunction() {
		std::string code = "    ;exit program\n    MOV AX,4CH\n    INT 21H\n";
		writeIntoTempFile(code);
	}

	// general utility functions
	std::string toUpper(const std::string& str) {
		std::string upperStr = str;
		for (char& c : upperStr) {
			c = toupper(c);
		}
		return upperStr;
	}	
	int increaseStackMemberCount() {
		int count = symbolTable.getStackMemberCount();
		count = count + 1;
		symbolTable.setStackMemberCount(count);
		return count;
	}	
	void preserveBasePointer() {
		std::string code;
		code = "	;preserve base pointer\n"; writeIntoTempFile(code);
		code = "    PUSH BP\n    MOV BP, SP\n"; writeIntoTempFile(code);
		// increaseStackMemberCount();
	}
	void restoreBasePointer() {
		std::string code;
		code = "	;restore base pointer\n"; writeIntoTempFile(code);
		code = "    POP BP\n"; writeIntoTempFile(code);
	}	
	int getStackMemberCount() {
		return symbolTable.getStackMemberCount();
	}
	void resetStackMemberCount() {
		symbolTable.setStackMemberCount(0);
	}	
	void enterScope(std::string name, std::string type) {
		SymbolInfo* symbol = symbolTable.insert(name,type);
		symbolTable.enterScope();
		preserveBasePointer();
		currentFuncName = name;
		isReturned = false;
		pushCount = 0;
		popCount = 0;	
	}
	void exitScope() {
		std::string code;
		code = "	;restore stack pointer\n"; writeIntoTempFile(code);
		int count = getStackMemberCount();
		// for(int i = 0; i < count; i++) {
		// 	code = "    ADD SP, 2\n"; writeIntoTempFile(code);
		// }
		code = "    ADD SP, " + std::to_string(2*count); writeIntoTempFile(code);		
		restoreBasePointer();		
	}
	SymbolInfo* lookupSymbol(std::string name) {
		SymbolInfo* symbol = symbolTable.lookUpInCurrentScope(name);
		if (symbol == NULL) {
			symbol = symbolTable.lookUp(name);
		}
		if(symbol == NULL) {
			std::cout << "Error: Symbol '" << name << "' not found in the symbol table." << std::endl;
			exit(1);
		}
		return symbol;
	}
	bool isGlobalScope() {
		return symbolTable.isRootScope();
	}
	void debug(std::string message) {
		if (isDebug) {
			std::string code = "	;DEBUG: " + message;
			writeIntoTempFile(code);
		}
	}
	void printIdentifier(Identifier id) {
		debug("Name: " + id.idName + "\n");
		debug("Type: " + id.idType + "\n");
		debug("Is Global: " + std::string(id.isGlobal ? "true" : "false") + "\n");
		debug("Is Array: " + std::string(id.isArray ? "true" : "false") + "\n");
		debug("Array Size: " + std::to_string(id.arraySize) + "\n");
		debug("Array Index: " + id.arrayIndex + "\n");
		debug("Constant Value: " + id.constValue + "\n");
		debug("Stack Offset: " + std::to_string(id.stackOffset) + "\n");
		debug("Is In Stack: " + std::string(id.isInStack ? "true" : "false") + "\n");
		debug("Start Label: " + id.startLabel + "\n");
		debug("True Label: " + id.trueLabel + "\n");
		debug("False Label: " + id.falseLabel + "\n");
		debug("Next Label: " + id.nextLabel + "\n");
	}
	void printIdentifierLabel(Identifier id) {
		debug("Start Label: " + id.startLabel + "\n");
		debug("True Label: " + id.trueLabel + "\n");
		debug("False Label: " + id.falseLabel + "\n");
		debug("Next Label: " + id.nextLabel + "\n");
	}	
	std::string generateLabel() {
		return "L" + std::to_string(labelCount++);
	}

	void preserveTemporaryRegisters() {
		std::string code = "    PUSH BX\n    PUSH CX\n    PUSH DX\n";
		writeIntoTempFile(code);
	}
	void restoreTemporaryRegisters() {
		std::string code = "    POP DX\n    POP CX\n    POP BX\n";
		writeIntoTempFile(code);
	}
	vector<std::string> changeLabel(vector<std::string> lines, std::string label, std::string newLabel, bool all = false){
		bool labelReplaced = false;

		for (int i = static_cast<int>(lines.size()) - 1; i >= 0; --i) {
			std::string originalLine = lines[i];

			size_t leadingWsLen = originalLine.find_first_not_of(" \t");
			if (leadingWsLen == std::string::npos) continue;
			std::string leadingWhitespace = (leadingWsLen != std::string::npos) ? originalLine.substr(0, leadingWsLen) : "";

			std::istringstream iss(originalLine.substr(leadingWsLen));
			std::string firstWord, secondWord;
			if (!(iss >> firstWord >> secondWord)) continue;

			std::string extra;
			if (iss >> extra) continue;

			if (firstWord[0] == 'J' && secondWord == label) {
				lines[i] = leadingWhitespace + firstWord + " " + newLabel;
				labelReplaced = true;
				if(!all) break;
			}
		}
		if (!labelReplaced) {
			std::cerr << "Label '" << label << "' not found\n";
			return lines;
		}
		return lines; 		
	}
	void changeLabelFromTemp(std::string label, std::string newLabel, bool all = false) {
		debug("Changing label: " + label + " to: " + newLabel + "\n");

		if (label == newLabel) return;
		std::ifstream inputFile(tempFileName);
		std::vector<std::string> lines;
		std::string line;
		while (std::getline(inputFile, line)) {
			lines.push_back(line);
		}
		inputFile.close();

		lines = changeLabel(lines,label,newLabel,all);

		std::ofstream outputFile(tempFileName, std::ios::out | std::ios::trunc);
		for (const auto& l : lines) {
			outputFile << l << "\n";
		}
		outputFile.close();
		writeIntoTempFile("\n"); 
	}
	
	std::vector<std::string> removeComments(const std::vector<std::string>& lines) {
		std::vector<std::string> result;

		for (const std::string& line : lines) {
			if (line.find_first_not_of(" \t") == std::string::npos) continue;
			size_t leadingWsLen = line.find_first_not_of(" \t");
			std::string leadingWhitespace = line.substr(0, leadingWsLen);
			size_t commentPos = line.find(';');
			std::string coreContent;
			if (commentPos != std::string::npos) {
				if (leadingWsLen != std::string::npos)
					coreContent = line.substr(leadingWsLen, commentPos - leadingWsLen);
			} else {
				if (leadingWsLen != std::string::npos)
					coreContent = line.substr(leadingWsLen);
			}
			size_t endPos = coreContent.find_last_not_of(" \t");
			if (endPos != std::string::npos)
				coreContent = coreContent.substr(0, endPos + 1);
			else
				coreContent.clear();
			if (!coreContent.empty()) {
				result.push_back(leadingWhitespace + coreContent);
			}
		}

		return result;
	}
	bool isWhitespaceOrEmpty(const std::string& s) {
		return s.find_first_not_of(" \t") == std::string::npos;
	}
	std::string toUpperTrimmed(const std::string& str) {
		std::string result;
		for (char ch : str) {
			if (!std::isspace(static_cast<unsigned char>(ch)))
				result += std::toupper(ch);
		}
		return result;
	}
	std::vector<std::string> optimizeAssembly(const std::vector<std::string>& lines) {
		std::vector<std::string> result;

		for (size_t i = 0; i < lines.size(); ++i) {
			std::string line = lines[i];

			std::istringstream issCurr(line);
			std::string instrCurr, op1Curr, op2Curr;
			issCurr >> instrCurr >> op1Curr;
			if (issCurr.peek() == ',') issCurr.get();
			issCurr >> op2Curr;

			std::string upperInstrCurr = toUpperTrimmed(instrCurr);
			std::string upperOp1Curr = toUpperTrimmed(op1Curr);
			std::string upperOp2Curr = toUpperTrimmed(op2Curr);

			if (i + 1 < lines.size() && !isWhitespaceOrEmpty(lines[i + 1])) {
				std::istringstream issNext(lines[i + 1]);
				std::string instrNext, op1Next, op2Next;
				issNext >> instrNext >> op1Next;
				if (issNext.peek() == ',') issNext.get();
				issNext >> op2Next;

				std::string upperInstrNext = toUpperTrimmed(instrNext);
				std::string upperOp1Next = toUpperTrimmed(op1Next);
				std::string upperOp2Next = toUpperTrimmed(op2Next);

				bool redundantPushPop =
					((upperInstrCurr == "PUSH" && upperInstrNext == "POP") ||
					(upperInstrCurr == "POP" && upperInstrNext == "PUSH")) &&
					(upperOp1Curr == upperOp1Next);

				if (redundantPushPop) {
					++i;
					continue;
				}

				bool isRedundantMovPair =
					upperInstrCurr == "MOV" && upperInstrNext == "MOV" &&
					upperOp1Curr == upperOp2Next && upperOp2Curr == upperOp1Next;

				if (isRedundantMovPair) {
					++i;
					continue;
				}

				if (upperInstrCurr == "MOV" && upperOp1Curr == "BX" && upperOp2Curr == "1") {
					if (i + 2 < lines.size()) {
						std::istringstream issNext2(lines[i + 2]);
						std::string instrNext2, opNext2;
						issNext2 >> instrNext2 >> opNext2;
						std::string upperInstrNext2 = toUpperTrimmed(instrNext2);
						if (upperInstrNext2 == "IMUL") {
							i += 2;
							continue;
						}
					}
				}
			}

			if ((upperInstrCurr == "ADD" || upperInstrCurr == "SUB") && upperOp2Curr == "0") {
				continue;
			}

			result.push_back(line);
		}

		return result;
	}
	std::vector<std::string> mergeConsecutiveLabels(std::vector<std::string> lines) {
		std::vector<std::string> cleanedLines;
		std::vector<std::string> labelGroup;
		std::vector<std::pair<std::string, std::string>> change;

		for (size_t i = 0; i < lines.size(); ++i) {
			const std::string& line = lines[i];
			std::string trimmed = line;
			trimmed.erase(0, trimmed.find_first_not_of(" \t"));

			if (!trimmed.empty() && trimmed.back() == ':' && trimmed.find(' ') == std::string::npos) {
				labelGroup.push_back(trimmed.substr(0, trimmed.size() - 1));
			} else {
				if (labelGroup.size() > 1) {
					cleanedLines.push_back(labelGroup[0] + ":");
					for (size_t j = 1; j < labelGroup.size(); ++j) {
						change.push_back(std::make_pair(labelGroup[j], labelGroup[0]));
					}
				} else if (labelGroup.size() == 1) {
					cleanedLines.push_back(labelGroup[0] + ":");
				}
				labelGroup.clear();
				cleanedLines.push_back(line);
			}
		}

		if (!labelGroup.empty()) {
			cleanedLines.push_back(labelGroup[0] + ":");
			for (size_t j = 1; j < labelGroup.size(); ++j) {
				change.push_back(std::make_pair(labelGroup[j], labelGroup[0]));
			}
		}

		for (size_t i = 0; i < change.size(); ++i) {
			cleanedLines = changeLabel(cleanedLines, change[i].first, change[i].second, true);
		}

		return cleanedLines;
	}
	void optimizeCode() {
		// read lines from code file
		std::ifstream inputFile(codeFileName);
		std::vector<std::string> lines;
		std::string line;
		while (std::getline(inputFile, line)) {
			lines.push_back(line);
		}
		inputFile.close();

		lines = removeComments(lines);
		lines = optimizeAssembly(lines);
		lines = mergeConsecutiveLabels(lines);

		// write to optcode file
		std::ofstream outputFile(optCodeFileName, std::ios::out | std::ios::trunc);
		for (const auto& l : lines) {
			outputFile << l << "\n";
		}
		outputFile.close();
		writeIntoTempFile("\n"); 		
	}
	void cleanFileFromNonText(const std::string& fileName) {
		std::ifstream inputFile(fileName, std::ios::in | std::ios::binary);
		if (!inputFile) {
			std::cerr << "Error opening file: " << fileName << " for reading" << std::endl;
			return;
		}

		std::ostringstream buffer;
		buffer << inputFile.rdbuf();
		std::string content = buffer.str();
		inputFile.close();

		std::string cleaned;
		for (char ch : content) {
			if ((ch >= 32 && ch <= 126) || ch == '\n' || ch == '\t' || ch == '\r') {
				cleaned += ch;
			}
		}

		std::ofstream outputFile(fileName, std::ios::out | std::ios::trunc | std::ios::binary);
		if (!outputFile) {
			std::cerr << "Error opening file: " << fileName << " for writing" << std::endl;
			return;
		}

		outputFile << cleaned;
		outputFile.close();
	}	
	std::string extractBlock(const std::vector<std::string>& lines, const std::string& procName, size_t& startIndex, size_t& endIndex) {
		std::string startTag = procName + " PROC";
		std::string endTag = procName + " ENDP";
		bool inBlock = false;
		std::ostringstream block;

		for (size_t i = 0; i < lines.size(); ++i) {
			if (!inBlock && lines[i].find(startTag) != std::string::npos) {
				startIndex = i;
				inBlock = true;
			}
			if (inBlock) {
				block << lines[i] << '\n';
				if (lines[i].find(endTag) != std::string::npos) {
					endIndex = i;
					break;
				}
			}
		}
		return block.str();
	}
	void moveMainProcAfterCode(const std::string& filename) {
		std::ifstream fileIn(filename);
		if (!fileIn.is_open()) {
			std::cerr << "Error: Cannot open file " << filename << std::endl;
			return;
		}

		std::vector<std::string> lines;
		std::string line;
		while (std::getline(fileIn, line)) {
			lines.push_back(line);
		}
		fileIn.close();

		size_t mainStart = 0, mainEnd = 0;
		std::string mainBlock = extractBlock(lines, "main", mainStart, mainEnd);
		if (mainBlock.empty()) {
			std::cerr << "Error: 'main PROC' block not found.\n";
			return;
		}

		// Find the index of the line with ".CODE"
		size_t codeLineIndex = 0;
		for (size_t i = 0; i < lines.size(); ++i) {
			if (lines[i].find(".CODE") != std::string::npos) {
				codeLineIndex = i;
				break;
			}
		}

		// Reconstruct the file content
		std::ostringstream output;
		for (size_t i = 0; i <= codeLineIndex; ++i) {
			output << lines[i] << '\n';
		}

		output << '\n' << mainBlock << '\n';  // Insert main PROC after .CODE

		for (size_t i = 0; i < lines.size(); ++i) {
			if (i < mainStart || i > mainEnd) {
				// Avoid duplicating the main PROC block
				if (i != codeLineIndex)  // Already added .CODE
					output << lines[i] << '\n';
			}
		}

		std::ofstream fileOut(filename);
		if (!fileOut.is_open()) {
			std::cerr << "Error: Cannot write to file " << filename << std::endl;
			return;
		}

		fileOut << output.str();
		fileOut.close();

		std::cout << "'main PROC' block moved after '.CODE' successfully.\n";
	}



	// handling different grammar rules
	void globalVariableDeclaration(Identifier id, std::string line) {
		SymbolInfo* symbol = symbolTable.insert(id.idName, "ID");
		if (symbol != NULL) {
			symbol->id = id;
			symbol->id.isGlobal = true;
		}

		int size = 1;
		if (id.isArray) {
			size = id.arraySize;
		}
		std::string code = "    " + id.idName + " DW " + std::to_string(size) + " DUP (0000H)" + getComment(line) + "\n";
		writeIntoCodeFile(code);
	}
	void localVariableDeclaration(Identifier id, std::string line) {
		SymbolInfo* symbol = symbolTable.insert(id.idName, "ID");
		if (symbol != NULL) {
			symbol->id = id;
			symbol->id.isGlobal = false;
			if(id.isArray) {
				for(int i = 0; i < id.arraySize; i++) {
					increaseStackMemberCount();
					symbol->id.stackOffset = 2 * getStackMemberCount();
					std::string code = "    SUB SP, 2"+ getComment(line) +"\n";
					writeIntoTempFile(code);
				}
			} else {
				increaseStackMemberCount();
				symbol->id.stackOffset = 2 * getStackMemberCount();
				std::string code = "    SUB SP, 2" + getComment(line) + "\n";
				writeIntoTempFile(code);
			}
		}
	}
	void variableDeclaration(std::string type, identifier_list ids, std::string line) {
		for (auto id : ids.get_identifiers()) {
			id.idType = type;
			if (isGlobalScope()) {
				globalVariableDeclaration(id, line);
			} else {
				localVariableDeclaration(id, line);
			}
		}
	}

	std::string identifierAddress(Identifier id) {
		std::string address = "";
		if(id.constValue != "EMPTY") {
			address = id.constValue;
			return address;
		}

		if (id.isGlobal) {
			if (id.isArray) {
				address = id.idName + "[" + id.arrayIndex + "]";
			} else {
				address = id.idName;
			}
		} else {
			if (id.isArray) {
				// need to update this later
				int total_offset = std::stoi(id.arrayIndex) * 2 + id.stackOffset;
				address = "[BP - "  + std::to_string(total_offset) + "]";
			} else {
				if(id.stackOffset >= 0) {
					address = "[BP - "  + std::to_string(id.stackOffset) + "]";
				}else {
					address = "[BP + "  + std::to_string(0 - id.stackOffset) + "]";
				}
			}
		}
		return address;
	}
	void printVariable(Identifier id, std::string line) {
		std::string code;
		// code = "    PUSH AX" + getComment(line) + "\n"; 
		// writeIntoTempFile(code);
		code = "    MOV AX, " + identifierAddress(id) + getComment(line) + "\n";
		writeIntoTempFile(code);
		code = "    CALL print_output" + getComment(line) + "\n";
		writeIntoTempFile(code);
		code = "    CALL new_line" + getComment(line) + "\n";
		writeIntoTempFile(code);
		// code = "	POP AX" + getComment(line) + "\n";
		// writeIntoTempFile(code);
	}
	Identifier evaluateIncDec(Identifier id, std::string line) {
		if(id.isEvaluated) {
			return id;
		}
		std::string code;
		std::string label = generateLabel();
		code = "    JMP " + id.startLabel + "\n"; writeIntoTempFile(code);
		code = "    " + label + ":\n"; writeIntoTempFile(code);
	
		changeLabelFromTemp(id.nextLabel, label);
		id.nextLabel = label;

		id.nextLabel = label;
		id.isEvaluated = true;
		return id;
	}
	void simpleIncDecEvaluation(Identifier id,std::string line) {
		std::string code;
		if(id.isInStack) {
			code = "    POP AX\n"; writeIntoTempFile(code);
		} else {
			code = "    MOV AX, " + identifierAddress(id) + "\n"; writeIntoTempFile(code);
		}
		code = "    " + id.incDecOp + " AX, 1" + "\n"; writeIntoTempFile(code);
		code = "    MOV " + identifierAddress(id) + ", AX" + "\n"; writeIntoTempFile(code);		
	}
	void assignVariable(Identifier var, Identifier value, std::string line) {
		std::string code;
		std::string label;
		if(value.isInStack) {
			code = "    POP AX" + getComment(line) + "\n"; writeIntoTempFile(code);
			code = "    MOV " + identifierAddress(var) + ", AX" + getComment(line) + "\n"; writeIntoTempFile(code);
		} else {
			code = "    MOV AX, " + identifierAddress(value) + getComment(line) + "\n"; writeIntoTempFile(code);
			code = "    MOV " + identifierAddress(var) + ", AX" + getComment(line) + "\n"; writeIntoTempFile(code);
		}
		if(value.isIncDec) {
			evaluateIncDec(value, line);
		}
	}
	void concatenatingAddMul(Identifier left, Identifier right, std::string line, std::string operation) {
		std::string code;
		if(right.isInStack) {
			code = "    POP BX" + getComment(line) + "\n"; writeIntoTempFile(code);
		}else {
			code = "    MOV BX, " + identifierAddress(right) + getComment(line) + "\n"; writeIntoTempFile(code);
		}

		if(left.isInStack) {
			code = "    POP AX" + getComment(line) + "\n"; writeIntoTempFile(code);
		}else {
			code = "    MOV AX, " + identifierAddress(left) + getComment(line) + "\n"; writeIntoTempFile(code);
		}		

		if(operation == "+") {
			code = "    ADD AX, BX" + getComment(line) + "\n"; writeIntoTempFile(code);
		} else if(operation == "-") {
			code = "    SUB AX, BX" + getComment(line) + "\n"; writeIntoTempFile(code);
		} else if(operation == "*") {
			code = "    IMUL BL" + getComment(line) + "\n"; writeIntoTempFile(code);
		} else if(operation == "%") {
			code = "    DIV BL" + getComment(line) + "\n"; writeIntoTempFile(code);
			code = "    XOR CX, CX" + getComment(line) + "\n"; writeIntoTempFile(code);
			code = "    MOV CL, AH" + getComment(line) + "\n"; writeIntoTempFile(code);
			code = "    MOV AX, CX" + getComment(line) + "\n"; writeIntoTempFile(code);
		}
		code = "    PUSH AX" + getComment(line) + "\n"; writeIntoTempFile(code);
	}

	void generateRelationalCode(Identifier expr,Identifier left, Identifier right, std::string line, std::string operation) {
		std::string code;

		code = "	" + expr.startLabel + ":\n"; writeIntoTempFile(code);
		if(right.isInStack) {
			code = "    POP BX" + getComment(line) + "\n"; writeIntoTempFile(code);
		} else {
			code = "    MOV BX, " + identifierAddress(right) + getComment(line) + "\n"; writeIntoTempFile(code);
		}
		if(left.isInStack) {
			code = "    POP AX" + getComment(line) + "\n"; writeIntoTempFile(code);
		} else {
			code = "    MOV AX, " + identifierAddress(left) + getComment(line) + "\n"; writeIntoTempFile(code);
		}

		if(operation == "<") {
			code = "    CMP AX, BX" + getComment(line) + "\n"; writeIntoTempFile(code);
			code = "	JL " + expr.trueLabel + "\n"; writeIntoTempFile(code);
			code = "    JMP " + expr.falseLabel + "\n"; writeIntoTempFile(code);
		} else if(operation == "<=") {
			code = "	CMP AX, BX" + getComment(line) + "\n"; writeIntoTempFile(code);
			code = "	JLE " + expr.trueLabel + "\n"; writeIntoTempFile(code);
			code = "    JMP " + expr.falseLabel + "\n"; writeIntoTempFile(code);
		} else if(operation == ">") {
			code = "    CMP AX, BX" + getComment(line) + "\n"; writeIntoTempFile(code);
			code = "	JG " + expr.trueLabel + "\n"; writeIntoTempFile(code);
			code = "    JMP " + expr.falseLabel + "\n"; writeIntoTempFile(code);
		} else if(operation == ">=") {
			code = "    CMP AX, BX" + getComment(line) + "\n"; writeIntoTempFile(code);
			code = "	JGE " + expr.trueLabel + "\n"; writeIntoTempFile(code);
			code = "    JMP " + expr.falseLabel + "\n"; writeIntoTempFile(code);
		} else if(operation == "==") {
			code = "    CMP AX, BX" + getComment(line) + "\n"; writeIntoTempFile(code);
			code = "	JE " + expr.trueLabel + "\n"; writeIntoTempFile(code);
			code = "    JMP " + expr.falseLabel + "\n"; writeIntoTempFile(code);
		} else if(operation == "!=") {
			code = "    CMP AX, BX" + getComment(line) + "\n"; writeIntoTempFile(code);
			code = "	JNE " + expr.trueLabel + "\n"; writeIntoTempFile(code);
			code = "    JMP " + expr.falseLabel + "\n"; writeIntoTempFile(code);
		}else {
			debug("Relational operator not handled in the function generate relational code");
		}		
	}
	void assignLogicalVariable(Identifier var, Identifier logicValue, std::string line) {
		std::string code;
		code = "    " + logicValue.trueLabel + ":\n"; writeIntoTempFile(code);
		code = "    MOV AX, 1" + getComment(line) + "\n"; writeIntoTempFile(code);
		code = "    MOV " + identifierAddress(var) + ", AX" + getComment(line) + "\n"; writeIntoTempFile(code);
		code = "    JMP " + logicValue.nextLabel + "\n"; writeIntoTempFile(code);
		code = "    " + logicValue.falseLabel + ":\n"; writeIntoTempFile(code);
		code = "    MOV AX, 0" + getComment(line) + "\n"; writeIntoTempFile(code);
		code = "    MOV " + identifierAddress(var) + ", AX" + getComment(line) + "\n"; writeIntoTempFile(code);
		code = "    " + logicValue.nextLabel + ":\n"; writeIntoTempFile(code);
	}
	Identifier generateRelationalCodeForSimpleExpression(Identifier id) {
		if(id.trueLabel != "EMPTY") {
			return id;
		}

		std::string code;
		Identifier newId = id;
		newId.startLabel = generateLabel();
		newId.trueLabel = newId.trueLabel = generateLabel();
		newId.falseLabel = newId.falseLabel = generateLabel();
		newId.nextLabel = newId.nextLabel = generateLabel();

		code = "	" + newId.startLabel + ":\n"; writeIntoTempFile(code);
		if(id.isInStack) {
			code = "    POP AX\n"; writeIntoTempFile(code);
		} else {
			code = "    MOV AX, " + identifierAddress(id) + "\n"; writeIntoTempFile(code);
		}
		code = "	CMP AX, 0\n"; writeIntoTempFile(code);
		code = "	JNE " + newId.trueLabel + "\n"; writeIntoTempFile(code);
		code = "    JMP " + newId.falseLabel + "\n"; writeIntoTempFile(code);

		return newId;		
	}
	Identifier generateLogicalCode(Identifier left, Identifier right, std::string line, std::string operation) {
		Identifier id;
		if (operation == "&&") {
			changeLabelFromTemp(left.nextLabel, right.startLabel, true); left.nextLabel = right.startLabel;
			changeLabelFromTemp(left.trueLabel, right.startLabel, true); left.trueLabel = right.startLabel; 
			changeLabelFromTemp(left.falseLabel, right.falseLabel, true); left.falseLabel = right.falseLabel; 
		} else if (operation == "||") {
			changeLabelFromTemp(left.nextLabel, right.startLabel, true); left.nextLabel = right.startLabel;
			changeLabelFromTemp(left.trueLabel, right.trueLabel, true); left.trueLabel = right.trueLabel; 
			changeLabelFromTemp(left.falseLabel, right.startLabel, true); left.falseLabel = right.startLabel; 
		} else {
			debug("Logical operator not handled in the function generate logical code");
		}
		id.startLabel = left.startLabel;
		id.trueLabel = right.trueLabel;
		id.falseLabel = right.falseLabel;
		id.nextLabel = right.nextLabel;		
		return id;
	}
	Identifier generateLoopExpression(Identifier id, std::string line) {
		if(id.trueLabel != "EMPTY") {
			return id;
		}
		Identifier newId = generateRelationalCodeForSimpleExpression(id);
		if(id.isIncDec) {
			newId.startLabel = id.startLabel;
			newId.isIncDec = true;
		}
		return newId;
	}

	Identifier generateCodeForIncDecOp(Identifier id,std::string op, std::string line) {
		std::string code;
		Identifier newId = id;
		newId.isIncDec = true;
		newId.startLabel = generateLabel();
		newId.nextLabel = newId.nextLabel = generateLabel();
		newId.incDecOp = op;

		code = "	JMP " + newId.nextLabel + "\n"; writeIntoTempFile(code);
		code = "	" + newId.startLabel + ":\n"; writeIntoTempFile(code);
		if(id.isInStack) {
			code = "    POP AX" + getComment(line) + "\n"; writeIntoTempFile(code);
		} else {
			code = "    MOV AX, " + identifierAddress(id) + getComment(line) + "\n"; writeIntoTempFile(code);
		}
		code = "    " + op + " AX, 1" + getComment(line) + "\n"; writeIntoTempFile(code);
		code = "    MOV " + identifierAddress(id) + ", AX" + getComment(line) + "\n"; writeIntoTempFile(code);
		code = "    JMP " + newId.nextLabel + "\n"; writeIntoTempFile(code);
		code = "    " + newId.nextLabel + ":\n"; writeIntoTempFile(code);
		return newId;
	}

	void generateCodeForAddOp(Identifier id, std::string line) {
		std::string code;
		if(id.isInStack) {
			code = "    POP AX" + getComment(line) + "\n"; writeIntoTempFile(code);
		} else {
			code = "    MOV AX, " + identifierAddress(id) + getComment(line) + "\n"; writeIntoTempFile(code);
		}
		code = "    NEG AX" + getComment(line) + "\n"; writeIntoTempFile(code);
		code = "    PUSH AX" + getComment(line) + "\n"; writeIntoTempFile(code);
	}

	// if else
	void generateCodeAfterIfExpression(Identifier id) {
		std::string code;
		code = "    " + id.trueLabel + ":\n"; writeIntoTempFile(code);
	}
	void generateCodeAfterIfStatement(Identifier id) {
		std::string code;
		code = "    JMP " + id.nextLabel + "\n"; writeIntoTempFile(code);
		code = "    " + id.falseLabel + ":\n"; writeIntoTempFile(code);
	}
	void generateCodeAfterElseStatement(Identifier id) {
		std::string code;
		code = "    " + id.nextLabel + ":\n"; writeIntoTempFile(code);
	}

	// for loop
	void setLoopLabels(){
		loopExpressionLabel = generateLabel();
		loopStatementLabel = generateLabel();
	}
	void clearLoopLabels() {
		loopExpressionLabel = "EMPTY";
		loopStatementLabel = "EMPTY";
	}
	void handleBeforeLoopExpression(Identifier conditionalExpression) {
		std::string code;
		// conditional expression
		code = "    " + conditionalExpression.trueLabel + ":\n"; writeIntoTempFile(code);

		code = "	JMP " + loopStatementLabel + "\n"; writeIntoTempFile(code);
		code = "	" + loopExpressionLabel + ":\n"; writeIntoTempFile(code);
	}
	void handleAfterLoopExpression(Identifier conditionalExpression) {
		std::string code;
		code = "    JMP " + conditionalExpression.startLabel + "\n"; writeIntoTempFile(code);
	}
	void handleBeforeLoopStatement(Identifier conditionalExpression) {
		std::string code;
		code = "	" + loopStatementLabel + ":\n"; writeIntoTempFile(code);
	}
	void handleAfterLoopStatement(Identifier conditionalExpression) {
		std::string code;
		code = "	JMP " + loopExpressionLabel + "\n"; writeIntoTempFile(code);

		// conditional expression
		// code = "	JMP " + conditionalExpression.nextLabel + "\n"; writeIntoTempFile(code);
		code = "	" + conditionalExpression.falseLabel + ":\n"; writeIntoTempFile(code);
		// code = "	" + conditionalExpression.nextLabel + ":\n"; writeIntoTempFile(code);
	}

	// while loop
	void handleBeforeWhileLoopExpression(Identifier conditionalExpression) {
		std::string code;
		code = "    " + conditionalExpression.trueLabel + ":\n"; writeIntoTempFile(code);
	}
	void handleAfterWhileLoopExpression(Identifier conditionalExpression) {
		std::string code;
		code = "    JMP " + conditionalExpression.startLabel + "\n"; writeIntoTempFile(code);
		code = "    " + conditionalExpression.falseLabel + ":\n"; writeIntoTempFile(code);
	}

	// function definition
	void parameterDeclaration(identifier_list ids, std::string line) {
		increaseStackMemberCount();	
		for (int i = ids.get_identifiers().size() - 1; i >= 0; i--) {
			Identifier id = ids.get_identifiers()[i];
			SymbolInfo* symbol = symbolTable.insert(id.idName, "ID");
			if (symbol != NULL) {
				increaseStackMemberCount();	
				symbol->id = id;
				symbol->id.isGlobal = false;
				symbol->id.stackOffset = 0 - 2 * getStackMemberCount();			
			}
		}
		resetStackMemberCount();
		numberOfArguments = ids.get_identifiers().size();
	}
	void handleReturnExpresssion(Identifier expression,std::string line){
		if (currentFuncName == "main") {
			exitScope();
			exitMainFunction();
		} else {
			std::string code;
			if(expression.isInStack) {
				code = "    POP AX" + getComment(line) + "\n"; writeIntoTempFile(code);
			} else {
				code = "    MOV AX, " + identifierAddress(expression) + getComment(line) + "\n"; writeIntoTempFile(code);
			}

			exitScope();

			if(numberOfArguments > 0) {
				code = "    RET " + std::to_string(numberOfArguments*2) + "\n"; writeIntoTempFile(code);
			}else {
				code = "    RET 2\n"; writeIntoTempFile(code);
			}
		}
		isReturned = true;
	}	

}

start :
    { initializeCodeFile(); initializeTempFile(); }p = program {
        finalizeTempFile();
		moveMainProcAfterCode(tempFileName);
        mergeTempFileToCodeFile();
		optimizeCode();
		cleanFileFromNonText(codeFileName);
		cleanFileFromNonText(optCodeFileName);
		cleanFileFromNonText(tempFileName);
    }
;

program :
    program unit
    | unit
;

unit :
    var_declaration
    | func_declaration
    | func_definition
;

type_specifier returns [std::string type] :
    INT { $type = "INT"; }
    | FLOAT { $type = "FLOAT"; }
    | VOID  { $type = "VOID"; }
;

declaration_list returns [identifier_list ids] :
    dl = declaration_list COMMA ID {
        $ids = $dl.ids;
		Identifier id;
		id.idName = $ID->getText();
        $ids.add(id);
    }
    | dl = declaration_list COMMA ID LTHIRD CONST_INT RTHIRD {
		$ids = $dl.ids;
		Identifier id;
		id.idName = $ID->getText();
		id.isArray = true;
		id.arraySize = std::stoi($CONST_INT->getText());
		$ids.add(id);
	}
    | ID {
		Identifier id;
		id.idName = $ID->getText();
		$ids.add(id);
	}
    | ID LTHIRD CONST_INT RTHIRD {
		Identifier id;
		id.idName = $ID->getText();
		id.isArray = true;
		id.arraySize = std::stoi($CONST_INT->getText());
		$ids.add(id);
	}
;

var_declaration :
    t = type_specifier dl = declaration_list sm = SEMICOLON {
		variableDeclaration($t.type, $dl.ids, to_string($sm->getLine()));
	}
;

parameter_list returns [identifier_list ids] :
    pl = parameter_list COMMA ts = type_specifier ID {
        $ids = $pl.ids;
		Identifier id;
		id.idName = $ID->getText();
		id.idType = $ts.type;
        $ids.add(id);		
	}	
    | pl = parameter_list COMMA ts = type_specifier
    | t = type_specifier ID {
		Identifier id;
		id.idName = $ID->getText();
		id.idType = $t.type;
		$ids.add(id);
	}
    | t = type_specifier
;

func_declaration :
    type_specifier ID LPAREN parameter_list RPAREN SEMICOLON
    | type_specifier ID LPAREN RPAREN SEMICOLON
;

func_definition :
    t = type_specifier ID{writeIntoTempFile($ID->getText() + " PROC\n");enterScope($ID->getText(),$t.type);} LPAREN pl = parameter_list{parameterDeclaration($pl.ids,std::to_string($ID->getLine()));} RPAREN compound_statement {
		if(!isReturned){ 
			exitScope();
			std::string code;
			if (numberOfArguments == 0) {
				code = "    RET \n";
			} else {
				code = "    RET " + std::to_string(2 * numberOfArguments) + "\n";
			}
			writeIntoTempFile(code);
		}
		writeIntoTempFile($ID->getText() + " ENDP\n\n");
		numberOfArguments = 0;
		symbolTable.exitScope();
	}
    | t = type_specifier ID{writeIntoTempFile($ID->getText() + " PROC\n");} LPAREN RPAREN {initializeMainFunction($ID->getText());enterScope($ID->getText(),$t.type);} compound_statement {
		if(!isReturned) {
			exitScope();
			if ($ID->getText() == "main") {
				exitMainFunction();
			} else {
				std::string code;
				if (numberOfArguments == 0) {
					code = "    RET \n";
				} else {
					code = "    RET " + std::to_string(2 * numberOfArguments) + "\n";
				}
				writeIntoTempFile(code);
			}
		}
		writeIntoTempFile($ID->getText() + " ENDP\n\n");
		numberOfArguments = 0;
		symbolTable.exitScope();
	}
;

compound_statement :
    LCURL statements RCURL
    | LCURL RCURL
;

statements :
    statement
    | statements statement
;

statement :
    var_declaration
    | expression_statement
    | compound_statement
    |
	FOR{setLoopLabels();} LPAREN expression_statement es = expression_statement{
		$es.id = generateLoopExpression($es.id, to_string($FOR->getLine()));
	} {handleBeforeLoopExpression($es.id);}e = expression{
		if($e.id.isIncDec){evaluateIncDec($e.id, to_string($FOR->getLine()));};handleAfterLoopExpression($es.id);
	} RPAREN {handleBeforeLoopStatement($es.id);}statement {
		handleAfterLoopStatement($es.id);
		clearLoopLabels();
	}
    | 
	IF LPAREN e = expression{
		$e.id = generateRelationalCodeForSimpleExpression($e.id);
		generateCodeAfterIfExpression($e.id);
	} RPAREN s = statement {
		generateCodeAfterIfStatement($e.id);
		generateCodeAfterElseStatement($e.id);
	}
    | 
	IF LPAREN e = expression{
		$e.id = generateRelationalCodeForSimpleExpression($e.id);
		generateCodeAfterIfExpression($e.id);
	} RPAREN statement{
		generateCodeAfterIfStatement($e.id);
	} ELSE statement {
		generateCodeAfterElseStatement($e.id);
	}
    |
	WHILE LPAREN e = expression{$e.id = generateLoopExpression($e.id, to_string($WHILE->getLine()));} RPAREN {handleBeforeWhileLoopExpression($e.id);}statement {
		handleAfterWhileLoopExpression($e.id);
		if($e.id.isIncDec) {
			simpleIncDecEvaluation($e.id, to_string($WHILE->getLine()));
		}
	}
    | PRINTLN LPAREN ID RPAREN SEMICOLON {
		Identifier id;
		SymbolInfo* symbol = symbolTable.lookUp($ID->getText());
		id = symbol->id;
		printVariable(id, to_string($PRINTLN->getLine()));		
	}
    | RETURN e = expression SEMICOLON {
		handleReturnExpresssion($e.id,std::to_string($RETURN->getLine()));
		if($e.id.isIncDec) {
			evaluateIncDec($e.id, to_string($RETURN->getLine()));
		}
	}
;

expression_statement returns [Identifier id] :
    SEMICOLON {
	}
    | e = expression SEMICOLON {
		$id = $e.id;
		if($id.isIncDec) {
			$id = evaluateIncDec($id, to_string($SEMICOLON->getLine()));
		}
	}
;

expression returns [Identifier id] :
    le = logic_expression {
		$id = $le.id;
	}
    | v = variable ASSIGNOP le = logic_expression {
		if($le.id.trueLabel == "EMPTY" && $le.id.falseLabel == "EMPTY") {
			assignVariable($v.id, $le.id, to_string($ASSIGNOP->getLine()));
		} else {
			assignLogicalVariable($v.id, $le.id, to_string($ASSIGNOP->getLine()));
		}
	}
;

logic_expression returns [Identifier id] :
    re = rel_expression {
        $id = $re.id;
    }
    | 
	re1 = rel_expression{
		$re1.id = generateRelationalCodeForSimpleExpression($re1.id);
	} LOGICOP re2 = rel_expression {
		$re2.id = generateRelationalCodeForSimpleExpression($re2.id);
		$id = generateLogicalCode($re1.id, $re2.id, to_string($LOGICOP->getLine()), $LOGICOP->getText());
    }
;

rel_expression returns [Identifier id] :
    se = simple_expression {
		$id = $se.id;
	}
    | se1 = simple_expression RELOP se2 = simple_expression {
		Identifier id;
		id.startLabel = generateLabel();
		id.trueLabel = generateLabel();
		id.falseLabel = generateLabel();
		id.nextLabel = generateLabel();
		$id = id;
		generateRelationalCode(id,$se1.id, $se2.id, to_string($RELOP->getLine()), $RELOP->getText());		
	}
;

simple_expression returns [Identifier id] :
    t = term {
        $id = $t.id;
    }
    | se = simple_expression ADDOP t = term {
		concatenatingAddMul($se.id, $t.id, to_string($ADDOP->getLine()), $ADDOP->getText());
		$id.isInStack = true;
	}
;

term returns [Identifier id] :
    ue = unary_expression {
		$id = $ue.id;
	}
    | t = term MULOP ue = unary_expression {
		concatenatingAddMul($t.id, $ue.id, to_string($MULOP->getLine()), $MULOP->getText());
		$id.isInStack = true;
	}
;

unary_expression returns [Identifier id] :
    ADDOP ue = unary_expression {
		generateCodeForAddOp($ue.id, to_string($ADDOP->getLine()));
		$id.isInStack = true;
	}
    | NOT unary_expression
    | f = factor {
		$id = $f.id;
	}
;

factor returns [Identifier id] :
    v = variable {
		$id = $v.id;
	}
    | ID LPAREN al = argument_list RPAREN {
		std::string code;
		std::string line = std::to_string($ID->getLine());
		// preserveTemporaryRegisters();
		code = "    CALL " + $ID->getText() + getComment(line) + "\n"; writeIntoTempFile(code);
		SymbolInfo* symbol = lookupSymbol($ID->getText());
		if(toUpper(symbol->getType()) != "VOID") {
			code = "    PUSH AX\n"; writeIntoTempFile(code);
			$id.isInStack = true;
		}
		// restoreTemporaryRegisters();
	}
    | LPAREN e = expression RPAREN {
		$id = $e.id;
	}
    | CONST_INT {
		Identifier id;
		id.constValue = $CONST_INT->getText();
		$id = id;
	}
    | CONST_FLOAT
    | v = variable INCOP {
		$id = generateCodeForIncDecOp($v.id, "ADD", to_string($INCOP->getLine()));
	}
    | v = variable DECOP {
		$id = generateCodeForIncDecOp($v.id, "SUB", to_string($DECOP->getLine()));
	}
;

variable returns [Identifier id] :
    ID {
		SymbolInfo* symbol = lookupSymbol($ID->getText());
		$id = symbol->id;
	}
    | ID LTHIRD e = expression RTHIRD {
		SymbolInfo* symbol = lookupSymbol($ID->getText());
		$id = symbol->id;
		$id.isArray = true;
		$id.arrayIndex = $e.id.constValue; 		
	}
;

argument_list returns [identifier_list ids] :
    a = arguments {
		$ids = $a.ids;
	}
    |
;

arguments returns [identifier_list ids] :
    a = arguments COMMA le = logic_expression {
		std::string code;
		std::string line = std::to_string($COMMA->getLine());
		if($le.id.isInStack) {
			code = "    POP AX" + getComment(line) + "\n"; writeIntoTempFile(code);
		} else {
			code = "    MOV AX, " + identifierAddress($le.id) + getComment(line) + "\n"; writeIntoTempFile(code);
		}
		code = "    PUSH AX" + getComment(line) + "\n"; writeIntoTempFile(code);
	}
    | le = logic_expression {
		std::string code;
		if($le.id.isInStack) {
			code = "    POP AX\n"; writeIntoTempFile(code);
		} else {
			code = "    MOV AX, " + identifierAddress($le.id) + "\n"; writeIntoTempFile(code);
		}
		code = "    PUSH AX\n"; writeIntoTempFile(code);
	}
;