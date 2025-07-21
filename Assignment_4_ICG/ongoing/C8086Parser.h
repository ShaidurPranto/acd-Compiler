
    #include <iostream>
    #include <fstream>
	#include <sstream>
	#include <vector>
    #include <string>
    #include <cstdlib>
	#include <regex>
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


// Generated from C8086Parser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  C8086Parser : public antlr4::Parser {
public:
  enum {
    LINE_COMMENT = 1, BLOCK_COMMENT = 2, STRING = 3, WS = 4, IF = 5, ELSE = 6, 
    FOR = 7, WHILE = 8, PRINTLN = 9, RETURN = 10, INT = 11, FLOAT = 12, 
    VOID = 13, LPAREN = 14, RPAREN = 15, LCURL = 16, RCURL = 17, LTHIRD = 18, 
    RTHIRD = 19, SEMICOLON = 20, COMMA = 21, ADDOP = 22, SUBOP = 23, MULOP = 24, 
    INCOP = 25, DECOP = 26, NOT = 27, RELOP = 28, LOGICOP = 29, ASSIGNOP = 30, 
    ID = 31, CONST_INT = 32, CONST_FLOAT = 33
  };

  enum {
    RuleStart = 0, RuleProgram = 1, RuleUnit = 2, RuleType_specifier = 3, 
    RuleDeclaration_list = 4, RuleVar_declaration = 5, RuleParameter_list = 6, 
    RuleFunc_declaration = 7, RuleFunc_definition = 8, RuleCompound_statement = 9, 
    RuleStatements = 10, RuleStatement = 11, RuleExpression_statement = 12, 
    RuleExpression = 13, RuleLogic_expression = 14, RuleRel_expression = 15, 
    RuleSimple_expression = 16, RuleTerm = 17, RuleUnary_expression = 18, 
    RuleFactor = 19, RuleVariable = 20, RuleArgument_list = 21, RuleArguments = 22
  };

  explicit C8086Parser(antlr4::TokenStream *input);

  C8086Parser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~C8086Parser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  	bool isDebug = true;
  	int stackMemberCount;
  	int labelCount = 0;
  	int lineCount = 1;
  	std::string loopExpressionLabel = "EMPTY";
  	std::string loopStatementLabel = "EMPTY";
  	bool isScopeAllowed = true;
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
  		for(int i = 0; i < count; i++) {
  			code = "    ADD SP, 2\n"; writeIntoTempFile(code);
  		}
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
  	void changeLabelFromTemp(std::string label, std::string newLabel) {
  		writeIntoTempFile(label + "->" + newLabel + "\n");
  		debug("changing label: "+label+" ,to: "+newLabel+"\n");
  		if (label == newLabel) return;

  		std::ifstream inputFile(tempFileName, std::ios::in);
  		if (!inputFile) {
  			std::cout << "Error opening tempFile.txt for reading" << std::endl;
  			return;
  		}

  		std::ostringstream buffer;
  		buffer << inputFile.rdbuf(); 
  		std::string content = buffer.str();
  		inputFile.close();

  		size_t pos = 0;
  		while ((pos = content.find(label, pos)) != std::string::npos) {
  			content.replace(pos, label.length(), newLabel);
  			pos += newLabel.length(); 
  			// break;
  		}

  		std::ofstream outputFile(tempFileName, std::ios::out | std::ios::trunc);
  		if (!outputFile) {
  			std::cout << "Error opening tempFile.txt for writing" << std::endl;
  			return;
  		}
  		outputFile << content;
  		outputFile.close();
  		writeIntoTempFile("\n");
  	}
  	void changeLabelFromTempFromBottom(std::string label, std::string newLabel, bool all = false) {
  		debug("Changing label: " + label + " to: " + newLabel + "\n");

  		if (label == newLabel) return;
  		std::ifstream inputFile(tempFileName);
  		std::vector<std::string> lines;
  		std::string line;
  		while (std::getline(inputFile, line)) {
  			lines.push_back(line);
  		}
  		inputFile.close();
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
  			return;
  		}
  		std::ofstream outputFile(tempFileName, std::ios::out | std::ios::trunc);
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
  			// Keep printable ASCII (32–126), newline (10), tab (9), carriage return (13)
  			if ((ch >= 32 && ch <= 126) || ch == '\n' || ch == '\t' || ch == '\r') {
  				cleaned += ch;
  			}
  			// Skip all other characters (e.g., '\0', control chars)
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
  	
  		changeLabelFromTempFromBottom(id.nextLabel, label);
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
  			changeLabelFromTempFromBottom(left.nextLabel, right.startLabel, true); left.nextLabel = right.startLabel;
  			changeLabelFromTempFromBottom(left.trueLabel, right.startLabel, true); left.trueLabel = right.startLabel; 
  			changeLabelFromTempFromBottom(left.falseLabel, right.falseLabel, true); left.falseLabel = right.falseLabel; 
  		} else if (operation == "||") {
  			changeLabelFromTempFromBottom(left.nextLabel, right.startLabel, true); left.nextLabel = right.startLabel;
  			changeLabelFromTempFromBottom(left.trueLabel, right.trueLabel, true); left.trueLabel = right.trueLabel; 
  			changeLabelFromTempFromBottom(left.falseLabel, right.startLabel, true); left.falseLabel = right.startLabel; 
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



  class StartContext;
  class ProgramContext;
  class UnitContext;
  class Type_specifierContext;
  class Declaration_listContext;
  class Var_declarationContext;
  class Parameter_listContext;
  class Func_declarationContext;
  class Func_definitionContext;
  class Compound_statementContext;
  class StatementsContext;
  class StatementContext;
  class Expression_statementContext;
  class ExpressionContext;
  class Logic_expressionContext;
  class Rel_expressionContext;
  class Simple_expressionContext;
  class TermContext;
  class Unary_expressionContext;
  class FactorContext;
  class VariableContext;
  class Argument_listContext;
  class ArgumentsContext; 

  class  StartContext : public antlr4::ParserRuleContext {
  public:
    C8086Parser::ProgramContext *p = nullptr;
    StartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ProgramContext *program();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StartContext* start();

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    UnitContext *unit();
    ProgramContext *program();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ProgramContext* program();
  ProgramContext* program(int precedence);
  class  UnitContext : public antlr4::ParserRuleContext {
  public:
    UnitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Var_declarationContext *var_declaration();
    Func_declarationContext *func_declaration();
    Func_definitionContext *func_definition();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  UnitContext* unit();

  class  Type_specifierContext : public antlr4::ParserRuleContext {
  public:
    std::string type;
    Type_specifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *FLOAT();
    antlr4::tree::TerminalNode *VOID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Type_specifierContext* type_specifier();

  class  Declaration_listContext : public antlr4::ParserRuleContext {
  public:
    identifier_list ids;
    C8086Parser::Declaration_listContext *dl = nullptr;
    antlr4::Token *idToken = nullptr;
    antlr4::Token *const_intToken = nullptr;
    Declaration_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LTHIRD();
    antlr4::tree::TerminalNode *CONST_INT();
    antlr4::tree::TerminalNode *RTHIRD();
    antlr4::tree::TerminalNode *COMMA();
    Declaration_listContext *declaration_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Declaration_listContext* declaration_list();
  Declaration_listContext* declaration_list(int precedence);
  class  Var_declarationContext : public antlr4::ParserRuleContext {
  public:
    C8086Parser::Type_specifierContext *t = nullptr;
    C8086Parser::Declaration_listContext *dl = nullptr;
    antlr4::Token *sm = nullptr;
    Var_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_specifierContext *type_specifier();
    Declaration_listContext *declaration_list();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Var_declarationContext* var_declaration();

  class  Parameter_listContext : public antlr4::ParserRuleContext {
  public:
    identifier_list ids;
    C8086Parser::Parameter_listContext *pl = nullptr;
    C8086Parser::Type_specifierContext *t = nullptr;
    antlr4::Token *idToken = nullptr;
    C8086Parser::Type_specifierContext *ts = nullptr;
    Parameter_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    Type_specifierContext *type_specifier();
    antlr4::tree::TerminalNode *COMMA();
    Parameter_listContext *parameter_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Parameter_listContext* parameter_list();
  Parameter_listContext* parameter_list(int precedence);
  class  Func_declarationContext : public antlr4::ParserRuleContext {
  public:
    Func_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_specifierContext *type_specifier();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LPAREN();
    Parameter_listContext *parameter_list();
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Func_declarationContext* func_declaration();

  class  Func_definitionContext : public antlr4::ParserRuleContext {
  public:
    C8086Parser::Type_specifierContext *t = nullptr;
    antlr4::Token *idToken = nullptr;
    C8086Parser::Parameter_listContext *pl = nullptr;
    Func_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    Compound_statementContext *compound_statement();
    Type_specifierContext *type_specifier();
    Parameter_listContext *parameter_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Func_definitionContext* func_definition();

  class  Compound_statementContext : public antlr4::ParserRuleContext {
  public:
    Compound_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LCURL();
    StatementsContext *statements();
    antlr4::tree::TerminalNode *RCURL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Compound_statementContext* compound_statement();

  class  StatementsContext : public antlr4::ParserRuleContext {
  public:
    StatementsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StatementContext *statement();
    StatementsContext *statements();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StatementsContext* statements();
  StatementsContext* statements(int precedence);
  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *forToken = nullptr;
    C8086Parser::Expression_statementContext *es = nullptr;
    C8086Parser::ExpressionContext *e = nullptr;
    C8086Parser::StatementContext *s = nullptr;
    antlr4::Token *whileToken = nullptr;
    antlr4::Token *printlnToken = nullptr;
    antlr4::Token *idToken = nullptr;
    antlr4::Token *returnToken = nullptr;
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Var_declarationContext *var_declaration();
    std::vector<Expression_statementContext *> expression_statement();
    Expression_statementContext* expression_statement(size_t i);
    Compound_statementContext *compound_statement();
    antlr4::tree::TerminalNode *FOR();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *ELSE();
    antlr4::tree::TerminalNode *WHILE();
    antlr4::tree::TerminalNode *PRINTLN();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *RETURN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StatementContext* statement();

  class  Expression_statementContext : public antlr4::ParserRuleContext {
  public:
    Identifier id;
    C8086Parser::ExpressionContext *e = nullptr;
    antlr4::Token *semicolonToken = nullptr;
    Expression_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMICOLON();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Expression_statementContext* expression_statement();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    Identifier id;
    C8086Parser::Logic_expressionContext *le = nullptr;
    C8086Parser::VariableContext *v = nullptr;
    antlr4::Token *assignopToken = nullptr;
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Logic_expressionContext *logic_expression();
    antlr4::tree::TerminalNode *ASSIGNOP();
    VariableContext *variable();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ExpressionContext* expression();

  class  Logic_expressionContext : public antlr4::ParserRuleContext {
  public:
    Identifier id;
    C8086Parser::Rel_expressionContext *re = nullptr;
    C8086Parser::Rel_expressionContext *re1 = nullptr;
    antlr4::Token *logicopToken = nullptr;
    C8086Parser::Rel_expressionContext *re2 = nullptr;
    Logic_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Rel_expressionContext *> rel_expression();
    Rel_expressionContext* rel_expression(size_t i);
    antlr4::tree::TerminalNode *LOGICOP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Logic_expressionContext* logic_expression();

  class  Rel_expressionContext : public antlr4::ParserRuleContext {
  public:
    Identifier id;
    C8086Parser::Simple_expressionContext *se = nullptr;
    C8086Parser::Simple_expressionContext *se1 = nullptr;
    antlr4::Token *relopToken = nullptr;
    C8086Parser::Simple_expressionContext *se2 = nullptr;
    Rel_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Simple_expressionContext *> simple_expression();
    Simple_expressionContext* simple_expression(size_t i);
    antlr4::tree::TerminalNode *RELOP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Rel_expressionContext* rel_expression();

  class  Simple_expressionContext : public antlr4::ParserRuleContext {
  public:
    Identifier id;
    C8086Parser::Simple_expressionContext *se = nullptr;
    C8086Parser::TermContext *t = nullptr;
    antlr4::Token *addopToken = nullptr;
    Simple_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TermContext *term();
    antlr4::tree::TerminalNode *ADDOP();
    Simple_expressionContext *simple_expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Simple_expressionContext* simple_expression();
  Simple_expressionContext* simple_expression(int precedence);
  class  TermContext : public antlr4::ParserRuleContext {
  public:
    Identifier id;
    C8086Parser::TermContext *t = nullptr;
    C8086Parser::Unary_expressionContext *ue = nullptr;
    antlr4::Token *mulopToken = nullptr;
    TermContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Unary_expressionContext *unary_expression();
    antlr4::tree::TerminalNode *MULOP();
    TermContext *term();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TermContext* term();
  TermContext* term(int precedence);
  class  Unary_expressionContext : public antlr4::ParserRuleContext {
  public:
    Identifier id;
    antlr4::Token *addopToken = nullptr;
    C8086Parser::Unary_expressionContext *ue = nullptr;
    C8086Parser::FactorContext *f = nullptr;
    Unary_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ADDOP();
    Unary_expressionContext *unary_expression();
    antlr4::tree::TerminalNode *NOT();
    FactorContext *factor();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Unary_expressionContext* unary_expression();

  class  FactorContext : public antlr4::ParserRuleContext {
  public:
    Identifier id;
    C8086Parser::VariableContext *v = nullptr;
    antlr4::Token *idToken = nullptr;
    C8086Parser::Argument_listContext *al = nullptr;
    C8086Parser::ExpressionContext *e = nullptr;
    antlr4::Token *const_intToken = nullptr;
    antlr4::Token *incopToken = nullptr;
    antlr4::Token *decopToken = nullptr;
    FactorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VariableContext *variable();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    Argument_listContext *argument_list();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *CONST_INT();
    antlr4::tree::TerminalNode *CONST_FLOAT();
    antlr4::tree::TerminalNode *INCOP();
    antlr4::tree::TerminalNode *DECOP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FactorContext* factor();

  class  VariableContext : public antlr4::ParserRuleContext {
  public:
    Identifier id;
    antlr4::Token *idToken = nullptr;
    C8086Parser::ExpressionContext *e = nullptr;
    VariableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LTHIRD();
    antlr4::tree::TerminalNode *RTHIRD();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  VariableContext* variable();

  class  Argument_listContext : public antlr4::ParserRuleContext {
  public:
    identifier_list ids;
    C8086Parser::ArgumentsContext *a = nullptr;
    Argument_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ArgumentsContext *arguments();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Argument_listContext* argument_list();

  class  ArgumentsContext : public antlr4::ParserRuleContext {
  public:
    identifier_list ids;
    C8086Parser::ArgumentsContext *a = nullptr;
    C8086Parser::Logic_expressionContext *le = nullptr;
    antlr4::Token *commaToken = nullptr;
    ArgumentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Logic_expressionContext *logic_expression();
    antlr4::tree::TerminalNode *COMMA();
    ArgumentsContext *arguments();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ArgumentsContext* arguments();
  ArgumentsContext* arguments(int precedence);

  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool programSempred(ProgramContext *_localctx, size_t predicateIndex);
  bool declaration_listSempred(Declaration_listContext *_localctx, size_t predicateIndex);
  bool parameter_listSempred(Parameter_listContext *_localctx, size_t predicateIndex);
  bool statementsSempred(StatementsContext *_localctx, size_t predicateIndex);
  bool simple_expressionSempred(Simple_expressionContext *_localctx, size_t predicateIndex);
  bool termSempred(TermContext *_localctx, size_t predicateIndex);
  bool argumentsSempred(ArgumentsContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

