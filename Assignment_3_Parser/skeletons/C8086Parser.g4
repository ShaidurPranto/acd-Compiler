parser grammar C8086Parser;

options {
	tokenVocab = C8086Lexer;
}

@parser::header {
    #include <iostream>
    #include <fstream>
    #include <string>
    #include <cstdlib>
    #include "C8086Lexer.h"
	#include "./headers/2105177_SymbolTable.h"
	#include "./headers/util.cpp"
	#include "./headers/2105177_SymbolInfo.h"

    extern std::ofstream parserLogFile;
    extern std::ofstream errorFile;

    extern int syntaxErrorCount;

	extern SymbolTable symbolTable;
}

@parser::members {
	// data types 
	// INT
	// FLOAT

	bool isDebug = true;

	bool insertParam = false;
	param_list params;

	void debug(std::string message) {
		// if(isDebug) writeIntoparserLogFile("DEBUG: " + message + "\n");
	}

	void debug2(std::string message) {
		if(isDebug) writeIntoparserLogFile("DEBUG: " + message + "\n");
	}	

    void writeIntoparserLogFile(const std::string message) {
        if (!parserLogFile) {
            std::cout << "Error opening parserLogFile.txt" << std::endl;
            return;
        }

        parserLogFile << message << std::endl;
        parserLogFile.flush();
    }

    void writeIntoErrorFile(const std::string message) {
        if (!errorFile) {
            std::cout << "Error opening errorFile.txt" << std::endl;
            return;
        }
        errorFile << message << std::endl;
        errorFile.flush();
    }

	std::string getRuleLogFormat(std::string line, std::string ruleName) {
		return "Line " + line + ": " + ruleName ;
	}

	void writeRuleLog(std::string line, std::string ruleName) {
		writeIntoparserLogFile(getRuleLogFormat(line, ruleName) + "\n");
	}

	bool isInt(const std::string str) {
		for (char const &c : str) {
			if (std::isdigit(c) == 0) return false;
		}
		return true;
	}

	SymbolInfo* checkAndInsertIDVar(const std::string ID, const std::string line, bool isArray = false, int arraySize = 0) {
		SymbolInfo* symbol = symbolTable.lookUpInCurrentScope(ID);
		if(symbol != NULL) {
			writeIntoparserLogFile("Error at line " + line + ": Multiple declaration of " + ID + "\n");
			writeIntoErrorFile("Error at line " + line + ": Multiple declaration of " + ID + "\n");
			syntaxErrorCount++;

			return NULL;
		}else {
			SymbolInfo* newSymbol = symbolTable.insert(ID, "ID");
			if(isArray){
				if(newSymbol != NULL) {
					newSymbol->isArray = true;
					newSymbol->arraySize = arraySize;
				}
			}
			if(newSymbol != NULL) {
				// writeIntoparserLogFile("Inserted new symbol: " + ID + "\n");
			}
			return newSymbol;
		}
	}

	std::string toUpper(const std::string& str) {
		std::string upperStr = str;
		for (char& c : upperStr) {
			c = toupper(c);
		}
		return upperStr;
	}

	void specifySymbolType(symbol_list list,std::string type) {
		for (SymbolInfo* symbol : list.get_variables()) {
			if (symbol != NULL) {
				Identifier id = symbol->id;

				id.idName = symbol->getName();
				id.idType = toUpper(type);
				id.isArray = symbol->isArray;
				id.arraySize = symbol->arraySize;

				symbol->id = id;

				// writeIntoparserLogFile("Identifier updated for symbol: " + symbol->getName() + "\n");
				// printIdentifier(symbol->id);
			}
		}
	}

	void printIdentifier(const Identifier& id) {
		debug("Identifier name: " + id.idName + "\n");
		debug("Identifier type: " + id.idType + "\n");
		if (id.isArray) {
			debug("Identifier is an array: true\n");
			debug("Array size: " + std::to_string(id.arraySize) + "\n");
		}
		if(id.isFunction) {
			debug("Identifier is a function: true\n");
			debug("Return type: " + id.returnType + "\n");
			debug("Parameters: \n");
			for (const Variable& param : id.parameters.get_param()) {
				debug(" - " + param.name + ": " + param.type + "\n");
			}

			if(id.isDeclared) {
				debug("Function is declared: true\n");
			}
			if(id.isDefined) {
				debug("Function is defined: true\n");
			}
		}
	}

	void printSymbolList(symbol_list list) {
		writeIntoparserLogFile("Symbol list:\n");
		for (SymbolInfo* symbol : list.get_variables()) {
			if (symbol != NULL) {
				string name = symbol->getName();
				writeIntoparserLogFile("Symbol name: " + name + "\n");
			}
		}
	}

	bool isInParamList(std::string name, param_list params) {
		for (Variable var : params.get_param()) {
			if (var.name == name) {
				return true;
			}
		}
		return false;
	}

	void declareFunction(std::string returnType, std::string functionName, param_list params, std::string line) {
		SymbolInfo* symbol = symbolTable.lookUpInCurrentScope(functionName);
		if(symbol != NULL) {
			writeIntoparserLogFile("Error at line " + line + ": Function " + functionName + " already declared\n");
			writeIntoErrorFile("Error at line " + line + ": Function " + functionName + " already declared\n");
			syntaxErrorCount++;
		} else {
			symbol = symbolTable.insert(functionName, "ID");
			if(symbol != NULL) {
				symbol->id.idName = functionName;
				symbol->id.idType = toUpper(returnType);
				symbol->id.isFunction = true;
				symbol->id.isDeclared = true;
				symbol->id.returnType = toUpper(returnType);
				symbol->id.parameters = params;
			}
		}
	}

	bool isParameterListEqual(param_list params1, param_list params2) {
		if (params1.size() != params2.size()) {
			return false;
		}
		vector<Variable> p1 = params1.get_param();
		vector<Variable> p2 = params2.get_param();
		for (int i = 0; i < p1.size(); ++i) {
			if (p1[i].name != p2[i].name) {
				return false;
			}
		}
		return true;
	}

	void defineFunction(std::string returnType, std::string functionName, param_list params, std::string line) {
		debug("Defining function: " + functionName + " with return type: " + returnType);

		SymbolInfo* symbol = symbolTable.lookUpInCurrentScope(functionName);
		if(symbol == NULL) {
			symbol = symbolTable.lookUp(functionName);
		}

		if(symbol != NULL) {
			debug("Function " + functionName + " found in symbol table");
			printIdentifier(symbol->id);
			
			if(symbol->id.isFunction) {
				if(symbol->id.isDefined) {
					writeIntoparserLogFile("Error at line " + line + ": Function " + functionName + " already defined\n");
					writeIntoErrorFile("Error at line " + line + ": Function " + functionName + " already defined\n");
					syntaxErrorCount++;
				} else if(symbol->id.isDeclared) {
					if(symbol->id.returnType != toUpper(returnType)) {
						writeIntoparserLogFile("Error at line " + line + ": Return type mismatch of " + functionName + "\n");
						writeIntoErrorFile("Error at line " + line + ": Return type mismatch of " + functionName + "\n");
						syntaxErrorCount++;
					} else if(symbol->id.parameters.size() != params.size()) {
						writeIntoparserLogFile("Error at line " + line + ": Total number of arguments mismatch with declaration in function " + functionName + "\n");
						writeIntoErrorFile("Error at line " + line + ": Total number of arguments mismatch with declaration in function " + functionName + "\n");
						syntaxErrorCount++;
					} else if(!isParameterListEqual(symbol->id.parameters, params)) {
						writeIntoparserLogFile("Error at line " + line + ": parameter list mismatch of " + functionName + "\n");
						writeIntoErrorFile("Error at line " + line + ": parameter list mismatch of " + functionName + "\n");
						syntaxErrorCount++;
					}

					symbol->id.isDefined = true;
				}
			} else {
				writeIntoparserLogFile("Error at line " + line + ": Multiple declaration of " + functionName + "\n");
				writeIntoErrorFile("Error at line " + line + ": Multiple declaration of " + functionName + "\n");
				syntaxErrorCount++;
			}
		} else {
			symbol = symbolTable.insert(functionName, "ID");
			if(symbol != NULL) {
				symbol->id.idName = functionName;
				symbol->id.idType = toUpper(returnType);
				symbol->id.isFunction = true;
				symbol->id.isDefined = true;
				symbol->id.returnType = toUpper(returnType);
				symbol->id.parameters = params;
			}
		}
	}

	void setParam(std::string line, param_list parameters) {
		params = parameters;
		insertParam = true;
	}

	void clearParam() {
		params.clear();
		insertParam = false;
	}

	void checkParam() {
		if (insertParam) {
			if (params.size() > 0) {
				for (auto param : params.get_param()) {
					SymbolInfo* symbol = symbolTable.insert(param.name, "ID");
					if (symbol != NULL) {
						symbol->id.idName = param.name;
						symbol->id.idType = param.type;
					}
				}
			}
			clearParam();
		}
	}

	void enterScope() {
		symbolTable.enterScope();
		checkParam();
	}

	void printAll() {
		symbolTable.printAllNonEmptyScopeTables(parserLogFile);
	}

	void exitScope() {
		printAll();
		symbolTable.exitScope();
	}

	bool matchDataType(std::string type1, std::string type2) {
		if(toUpper(type1) == toUpper(type2)) {
			return true;
		}
		if(toUpper(type1) == "FLOAT" && toUpper(type2) == "INT") {
			return true;
		}
		return false;
	}

	bool doesArgumentMatch(param_list params1, param_list params2) {
		if (params1.size() != params2.size()) {
			return false;
		}
		vector<Variable> p1 = params1.get_param();
		vector<Variable> p2 = params2.get_param();
		for (int i = 0; i < p1.size(); ++i) {
			if(!matchDataType(toUpper(p1[i].type), toUpper(p2[i].type))) {
				return false;
			}
		}
		return true;
	}

	int findMisMatchedArgument(param_list params1, param_list params2) {
		if (params1.size() != params2.size()) {
			return -1;
		}
		vector<Variable> p1 = params1.get_param();
		vector<Variable> p2 = params2.get_param();
		for (int i = 0; i < p1.size(); ++i) {
			if (!matchDataType(toUpper(p1[i].type), toUpper(p2[i].type))) {
				return i;
			}
		}
		return -1;
	}

	std::string callFunctionInExpression(std::string functionName, param_list args, std::string line) {
		SymbolInfo* symbol = symbolTable.lookUpInCurrentScope(functionName);
		if(symbol == NULL) {
			symbol = symbolTable.lookUp(functionName);
		}

		if(symbol == NULL || !symbol->id.isFunction) {
			writeIntoparserLogFile("Error at line " + line + ": Undefined function " + functionName + "\n");
			writeIntoErrorFile("Error at line " + line + ": Undefined function " + functionName + "\n");
			syntaxErrorCount++;
			return "EMPTY";
		}
		if(!doesArgumentMatch(symbol->id.parameters, args)) {
			int misMatchedIndex = findMisMatchedArgument(symbol->id.parameters, args) + 1;
			string misMatch = std::to_string(misMatchedIndex);

			if(symbol->id.parameters.size() != args.size()) {
				writeIntoparserLogFile("Error at line " + line + ": " + "Total number of arguments mismatch with declaration in function " + functionName + "\n");
				writeIntoErrorFile("Error at line " + line + ": " + "Total number of arguments mismatch with declaration in function " + functionName + "\n");
			}
			else if(misMatchedIndex != 0) {
				writeIntoparserLogFile("Error at line " + line + ": " + misMatch + "th argument mismatch in function " + functionName + "\n");
				writeIntoErrorFile("Error at line " + line + ": " + misMatch + "th argument mismatch in function " + functionName + "\n");
			}
			else {
				writeIntoparserLogFile("Error at line " + line + ": " + functionName + " 's argument count not matched\n");
				writeIntoErrorFile("Error at line " + line + ": " + functionName + " 's argument count not matched\n");
			}
			syntaxErrorCount++;
			return "EMPTY";
		}
		// if(symbol->id.returnType == "VOID" || symbol->id.returnType == "void") {
		// 	writeIntoparserLogFile("Error at line " + line + ": " + functionName + " 's return type is void\n");
		// 	writeIntoErrorFile("Error at line " + line + ": " + functionName + " 's return type is void\n");
		// 	syntaxErrorCount++;
		// 	return "EMPTY";			
		// }
		return toUpper(symbol->id.returnType);
	}

	void assignment(Identifier variable, Identifier expression, std::string line) {
		if(variable.idType == "EMPTY" || expression.idType == "EMPTY") {
			return;
		}
		if(variable.idType == expression.idType){
			return;
		}

		debug("VARIABLE IDENTIFIER:\n");
		printIdentifier(variable);
		debug("LOGIC EXPRESSION IDENTIFIER:\n");
		printIdentifier(expression);

		if(toUpper(expression.idType) == "VOID") {
			writeIntoparserLogFile("Error at line " + line + ": Void function used in expression" +  "\n");
			writeIntoErrorFile("Error at line " + line + ": Void function used in expression" + "\n");
			syntaxErrorCount++;
			return;
		}
		if(variable.idType == "FLOAT" && expression.idType == "INT"){
			return;
		}
		syntaxErrorCount++;
		writeIntoErrorFile("Error at line " + line + ": Type Mismatch" + "\n");
		writeIntoparserLogFile("Error at line " + line + ": Type Mismatch" + "\n");
	}

	void matchReturnType(std::string functionReturnType, std::string expressionReturnType, std::string line, std::string functionName) {
		if(toUpper(functionReturnType) == "VOID" && expressionReturnType != "EMPTY") {
			writeIntoparserLogFile("Error at line " + line + ": Cannot return value from function " + functionName + " with void return type " +"\n");
			writeIntoErrorFile("Error at line " + line + ": Cannot return value from function " + functionName + " with void return type " +"\n");
			syntaxErrorCount++;
			return;
		}
		if(toUpper(functionReturnType) == toUpper(expressionReturnType)) {
			return;
		}
		if(toUpper(functionReturnType) == "FLOAT" && toUpper(expressionReturnType) == "INT") {
			return;
		}
		if(toUpper(functionReturnType) == "INT" && toUpper(expressionReturnType) == "FLOAT") {
			writeIntoparserLogFile("Error at line " + line + ": Type mismatch in return statement, expected " + functionReturnType + " but found " + expressionReturnType + "\n");
			writeIntoErrorFile("Error at line " + line + ": Type mismatch in return statement, expected " + functionReturnType + " but found " + expressionReturnType + "\n");
			syntaxErrorCount++;
			return;
		}
	}

	int getIntegerFromString(std::string str) {
		if (str.empty() || !isInt(str)) {
			return 0;
		}
		return std::stoi(str);
	}
}


start:
	p = program {
		std::string ruleName = "start : program";
		std::string text = $p.text;
		std::string line = $p.line;

		writeRuleLog(line, ruleName);
		// writeIntoparserLogFile(text + "\n");
		printAll();

		writeIntoparserLogFile("Total number of lines: " + line);
		writeIntoparserLogFile("Total number of errors: " + std::to_string(syntaxErrorCount));
	};

program returns[std::string text, std::string line]:
	p = program u = unit {
		std::string ruleName = "program : program unit";
		$text = $p.text + "\n" + $u.text;
		$line = $u.line;

		writeRuleLog($line, ruleName);
		writeIntoparserLogFile($text + "\n");
	}
	| u = unit{
		std::string ruleName = "program : unit";
		$text = $u.text;
		$line = $u.line;

		writeRuleLog($line, ruleName);
		writeIntoparserLogFile($text + "\n");
	};

unit returns[std::string text, std::string line]:
	vdl = var_declaration {
		std::string ruleName = "unit : var_declaration";
		$text = $vdl.text;
		$line = $vdl.line;

		writeRuleLog($line, ruleName);
		writeIntoparserLogFile($text + "\n");
	}
	| fdl = func_declaration {
		std::string ruleName = "unit : func_declaration";
		$text = $fdl.text;
		$line = $fdl.line;

		writeRuleLog($line, ruleName);
		writeIntoparserLogFile($text + "\n");
	} 
	| fdf = func_definition {
		std::string ruleName = "unit : func_definition";
		$text = $fdf.text;
		$line = $fdf.line;

		writeRuleLog($line, ruleName);
		writeIntoparserLogFile($text + "\n");
	};

type_specifier returns[std::string text, std::string line]:
	INT {
		$text = $INT->getText();
		std::string ruleName = "type_specifier : INT";
		$line = std::to_string($INT->getLine());

		writeRuleLog($line, ruleName);
        writeIntoparserLogFile($text + "\n");
    }
	| FLOAT {
		$text = $FLOAT->getText();
		std::string ruleName = "type_specifier : FLOAT";
		$line = std::to_string($FLOAT->getLine());

		writeRuleLog($line, ruleName);
		writeIntoparserLogFile($text + "\n");
    }
	| VOID {
		$text = $VOID->getText();
		std::string ruleName = "type_specifier : VOID";
		$line = std::to_string($VOID->getLine());

		writeRuleLog($line, ruleName);
		writeIntoparserLogFile($text + "\n");
    };

var_declaration returns[std::string text, std::string line]:
	t = type_specifier dl = declaration_list sm = SEMICOLON {
		std::string ruleName = "var_declaration : type_specifier declaration_list SEMICOLON";
		$text = $t.text + " " + $dl.text + $sm->getText();
		$line = std::to_string($sm->getLine());

		writeRuleLog($line, ruleName);

		if($t.text == "void" || $t.text == "VOID") {
			writeIntoErrorFile("Error at line " + $line + ": Variable type cannot be void\n");
			writeIntoparserLogFile("Error at line " + $line + ": Variable type cannot be void\n");
			syntaxErrorCount++;
			// return;
		}

        writeIntoparserLogFile($text + "\n");

		specifySymbolType($dl.list, $t.text);
    }
	| t = type_specifier de = declaration_list_err sm = SEMICOLON {
        writeIntoErrorFile("Error in variable declaration");
        syntaxErrorCount++;
    };

declaration_list returns[std::string text, std::string line, symbol_list list]: 
	dl = declaration_list COMMA ID {
		$text = $dl.text + $COMMA->getText() + $ID->getText();
		std::string ruleName = "declaration_list : declaration_list COMMA ID";
		$line = std::to_string($ID->getLine());

		$list = $dl.list;
		$list.add(checkAndInsertIDVar($ID->getText(), $line));

		writeRuleLog($line, ruleName);
        writeIntoparserLogFile($text + "\n");
	}
	| dl = declaration_list COMMA ID LTHIRD CONST_INT RTHIRD {
		$text = $dl.text + $COMMA->getText() + $ID->getText() + $LTHIRD->getText() + $CONST_INT->getText() + $RTHIRD->getText();
		std::string ruleName = "declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD";
		$line = std::to_string($ID->getLine());

		$list = $dl.list;
		$list.add(checkAndInsertIDVar($ID->getText(), $line, true, atoi($CONST_INT->getText().c_str())));

		writeRuleLog($line, ruleName);
		writeIntoparserLogFile($text + "\n");	
	}
	| ID {
		$text = $ID->getText();
		std::string ruleName = "declaration_list : ID";
		$line = std::to_string($ID->getLine());

		$list.add(checkAndInsertIDVar($ID->getText(), $line));

		writeRuleLog($line, ruleName);
		writeIntoparserLogFile($text + "\n");
	}
	| ID LTHIRD CONST_INT RTHIRD {
		$text = $ID->getText() + $LTHIRD->getText() + $CONST_INT->getText() + $RTHIRD->getText();
		std::string ruleName = "declaration_list : ID LTHIRD CONST_INT RTHIRD";
		$line = std::to_string($ID->getLine());

		$list.add(checkAndInsertIDVar($ID->getText(), $line, true, atoi($CONST_INT->getText().c_str())));

		writeRuleLog($line, ruleName);
		writeIntoparserLogFile($text + "\n");
	}
	// new rules
	| dl = declaration_list ADDOP ID {
		$text = $dl.text;
		$line = std::to_string($ADDOP->getLine());
		$list = $dl.list;
		
		std::string errorMsg = "Error at line " + $line + ": syntax error, unexpected ADDOP, expecting COMMA or SEMICOLON\n";
		writeIntoparserLogFile(errorMsg);
		writeIntoErrorFile(errorMsg);
		syntaxErrorCount++;
	};		

declaration_list_err returns[std::string text, std::string line]:
	{
		$text = "Error in declaration list";
		$line = "Unknown";

		writeRuleLog($line, "declaration_list_err");
		writeIntoparserLogFile($text + "\n");
	};

parameter_list returns[std::string text, std::string line, param_list list]:
	pl = parameter_list COMMA ts = type_specifier ID {
		std::string ruleName = "parameter_list : parameter_list COMMA type_specifier ID";
		$text = $pl.text + $COMMA->getText() + $ts.text + " " + $ID->getText();
		$line = std::to_string($ID->getLine());

		$list = $pl.list;
		Variable var;
		var.name = $ID->getText();
		var.type = toUpper($ts.text);
		if(isInParamList(var.name, $list)) {
			writeIntoparserLogFile("Error at line " + $line + ": Multiple declaration of " + var.name + " in parameter" + "\n");
			writeIntoErrorFile("Error at line " + $line + ": Multiple declaration of " + var.name + " in parameter" + "\n");
			syntaxErrorCount++;
		}
		$list.add(var);

		writeRuleLog($line, ruleName);
		writeIntoparserLogFile($text + "\n");
	}
	| pl = parameter_list COMMA ts = type_specifier {
		std::string ruleName = "parameter_list : parameter_list COMMA type_specifier";
		$text = $pl.text + $COMMA->getText() + $ts.text;
		$line = $ts.line;

		writeRuleLog($line, ruleName);
		writeIntoparserLogFile($text + "\n");

		$list = $pl.list;
		Variable var;
		var.type = toUpper($ts.text);
		$list.add(var);
	}
	| ts = type_specifier ID {
		std::string ruleName = "parameter_list : type_specifier ID";
		$text = $ts.text + " " + $ID->getText();
		$line = std::to_string($ID->getLine());

		writeRuleLog($line, ruleName);
		writeIntoparserLogFile($text + "\n");

		Variable var;
		var.name = $ID->getText();
		var.type = toUpper($ts.text);
		$list.add(var);
	}
	| ts = type_specifier {
		std::string ruleName = "parameter_list : type_specifier";
		$text = $ts.text;
		$line = $ts.line;

		writeRuleLog($line, ruleName);
		writeIntoparserLogFile($text + "\n");

		Variable var;
		var.type = toUpper($ts.text);
		$list.add(var);
	}
	// new rules
	| ts = type_specifier ADDOP {
		std::string ruleName = "parameter_list : type_specifier";
		$text = $ts.text;
		$line = $ts.line;

		writeRuleLog($line, ruleName);
		writeIntoparserLogFile($text + "\n");
		
		std::string errorMsg = "Error at line " + $line + ": syntax error, unexpected ADDOP, expecting RPAREN or COMMA\n";
		writeIntoparserLogFile(errorMsg);
		writeIntoErrorFile(errorMsg);
		syntaxErrorCount++;
	};


// Function declaration rules
func_declaration returns[std::string text, std::string line]:
	ts = type_specifier ID LPAREN pl = parameter_list RPAREN SEMICOLON {
		std::string ruleName = "func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON";
		$text = $ts.text + " " + $ID->getText() + $LPAREN->getText() + $pl.text + $RPAREN->getText() + $SEMICOLON->getText();
		$line = std::to_string($ID->getLine());

		writeRuleLog($line, ruleName);
		writeIntoparserLogFile($text + "\n");

		declareFunction($ts.text, $ID->getText(), $pl.list, $line);
	}
	| ts = type_specifier ID LPAREN RPAREN SEMICOLON{
		std::string ruleName = "func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON";
		$text = $ts.text + " " + $ID->getText() + $LPAREN->getText() + $RPAREN->getText() + $SEMICOLON->getText();
		$line = std::to_string($ID->getLine());

		writeRuleLog($line, ruleName);
		writeIntoparserLogFile($text + "\n");

		declareFunction($ts.text, $ID->getText(), param_list(), $line);
	};

// Function definition rules
func_definition returns[std::string text, std::string line]:
	ts = type_specifier ID LPAREN pl = parameter_list{setParam($line, $pl.list);} RPAREN{defineFunction($ts.text, $ID->getText(), $pl.list, std::to_string($ID->getLine()));} cs = compound_statement {
		std::string ruleName = "func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement";
		$text = $ts.text + " " + $ID->getText() + $LPAREN->getText() + $pl.text + $RPAREN->getText() + $cs.text;
		$line = $cs.line;

		if($cs.id.hasReturn){
			matchReturnType($ts.text, $cs.id.returnType, $line, $ID->getText());
		}

		writeRuleLog($line, ruleName);
		writeIntoparserLogFile($text + "\n");

		clearParam();
	}
	| ts = type_specifier ID LPAREN RPAREN{defineFunction($ts.text, $ID->getText(), param_list(), std::to_string($ID->getLine()));} cs = compound_statement{
		std::string ruleName = "func_definition : type_specifier ID LPAREN RPAREN compound_statement";
		$text = $ts.text + " " + $ID->getText() + $LPAREN->getText() + $RPAREN->getText() + $cs.text;
		$line = $cs.line;

		if($cs.id.hasReturn){
			matchReturnType($ts.text, $cs.id.returnType, $line, $ID->getText());
		}

		writeRuleLog($line, ruleName);
		writeIntoparserLogFile($text + "\n");		
	};

compound_statement returns[std::string text, std::string line, Identifier id]:
	LCURL{enterScope();} s = statements RCURL {
		std::string ruleName = "compound_statement : LCURL statements RCURL";
		$text = $LCURL->getText() + "\n" + $s.text + "\n" + $RCURL->getText();
		$line = std::to_string($RCURL->getLine());

		writeRuleLog($line, ruleName);
		writeIntoparserLogFile($text + "\n");

		exitScope();

		$id = $s.id;
	} 
	| LCURL{enterScope();} RCURL{
		std::string ruleName = "compound_statement : LCURL RCURL";
		$text = $LCURL->getText() + $RCURL->getText();
		$line = std::to_string($RCURL->getLine());

		writeRuleLog($line, ruleName);
		writeIntoparserLogFile($text + "\n");

		exitScope();
	};

statements returns[std::string text, std::string line, Identifier id]:
	s = statement {
		std::string ruleName = "statements : statement";
		$text = $s.text;
		$line = $s.line;

		writeRuleLog($line, ruleName);
		writeIntoparserLogFile($text + "\n");

		$id = $s.id;
	}
	| ss = statements s = statement {
		std::string ruleName = "statements : statements statement";
		$text = $ss.text + "\n" + $s.text;
		$line = $s.line;

		writeRuleLog($line, ruleName);
		writeIntoparserLogFile($text + "\n");

		int retCount = 0;
		if($ss.id.hasReturn){
			retCount++;
			$id.hasReturn = true;
			$id.returnType = $ss.id.returnType;
		}else if($s.id.hasReturn){
			retCount++;
			$id.hasReturn = true;
			$id.returnType = $s.id.returnType;
		}
	};

statement returns[std::string text, std::string line, Identifier id]:
	vd = var_declaration {
		std::string ruleName = "statement : var_declaration";
		$text = $vd.text;
		$line = $vd.line;

		writeRuleLog($line, ruleName);
		writeIntoparserLogFile($text + "\n");
	}
	| es = expression_statement {
		std::string ruleName = "statement : expression_statement";
		$text = $es.text;
		$line = $es.line;

		writeRuleLog($line, ruleName);
		writeIntoparserLogFile($text + "\n");
	}
	| cs = compound_statement {
		std::string ruleName = "statement : compound_statement";
		$text = $cs.text;
		$line = $cs.line;

		writeRuleLog($line, ruleName);
		writeIntoparserLogFile($text + "\n");
	}
	| FOR LPAREN es1 = expression_statement es2 = expression_statement e = expression RPAREN s = statement {
		std::string ruleName = "statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement";
		$text = $FOR->getText() + $LPAREN->getText() + $es1.text + $es2.text + $e.text + $RPAREN->getText() + $s.text;
		$line = $s.line;

		writeRuleLog($line, ruleName);
		writeIntoparserLogFile($text + "\n");
	}
	| IF LPAREN e = expression RPAREN s = statement {
		std::string ruleName = "statement : IF LPAREN expression RPAREN statement";
		$text = $IF->getText() + $LPAREN->getText() + $e.text + $RPAREN->getText() + $s.text;
		$line = $s.line;

		writeRuleLog($line, ruleName);
		writeIntoparserLogFile($text + "\n");
	}
	| IF LPAREN e = expression RPAREN s1 = statement ELSE s2 = statement {
		std::string ruleName = "statement : IF LPAREN expression RPAREN statement ELSE statement";
		$text = $IF->getText() + $LPAREN->getText() + $e.text + $RPAREN->getText() + $s1.text + $ELSE->getText() + " " + $s2.text;
		$line = $s2.line;

		writeRuleLog($line, ruleName);
		writeIntoparserLogFile($text + "\n");
	}
	| WHILE LPAREN e = expression RPAREN s = statement {
		std::string ruleName = "statement : WHILE LPAREN expression RPAREN statement";
		$text = $WHILE->getText() + $LPAREN->getText() + $e.text + $RPAREN->getText() + $s.text;
		$line = $s.line;

		writeRuleLog($line, ruleName);
		writeIntoparserLogFile($text + "\n");
	}
	| PRINTLN LPAREN ID RPAREN SEMICOLON {
		std::string ruleName = "statement : PRINTLN LPAREN ID RPAREN SEMICOLON";
		$text = $PRINTLN->getText() + $LPAREN->getText() + $ID->getText() + $RPAREN->getText() + $SEMICOLON->getText();
		$line = std::to_string($PRINTLN->getLine());

		writeRuleLog($line, ruleName);

		SymbolInfo* symbol = symbolTable.lookUpInCurrentScope($ID->getText());
		if(symbol == NULL) {symbol = symbolTable.lookUp($ID->getText());}
		if(symbol == NULL) {
			writeIntoErrorFile("Error at line " + $line + ": Undeclared variable "  + $ID->getText()+ "\n");
			syntaxErrorCount++;
			writeIntoparserLogFile("Error at line " + $line + ": Undeclared variable "  + $ID->getText()+ "\n");
		}

		writeIntoparserLogFile($text + "\n");
	}
	| RETURN e = expression SEMICOLON {
		std::string ruleName = "statement : RETURN expression SEMICOLON";
		$text = $RETURN->getText() + " " +  $e.text + $SEMICOLON->getText();
		$line = std::to_string($RETURN->getLine());

		writeRuleLog($line, ruleName);
		writeIntoparserLogFile($text + "\n");

		$id.hasReturn = true;
		$id.returnType = $e.id.idType;
	};

expression_statement returns[std::string text, std::string line, Identifier id]: 
	SEMICOLON {
		std::string ruleName = "expression_statement : SEMICOLON";
		$text = $SEMICOLON->getText();
		$line = std::to_string($SEMICOLON->getLine());

		writeRuleLog($line, ruleName);
		writeIntoparserLogFile($text + "\n");
	}
	| e = expression SEMICOLON {
		std::string ruleName = "expression_statement : expression SEMICOLON";
		$text = $e.text + $SEMICOLON->getText();
		$line = $e.line;

		writeRuleLog($line, ruleName);
		writeIntoparserLogFile($text + "\n");
		$id = $e.id;
	}
	// new rules
	| e = expression {
		$text = $e.text;
		$line = $e.line;
		$id = $e.id;
	}
	;

expression returns[std::string text, std::string line, Identifier id]:
	le = logic_expression {
		std::string ruleName = "expression : logic_expression";
		$text = $le.text;
		$line = $le.line;

		$id = $le.id;

		if(!$id.isError){
			writeRuleLog($line, ruleName);
			writeIntoparserLogFile($text + "\n");
		}

		printIdentifier($id);
	}
	| v = variable ASSIGNOP le = logic_expression {
		std::string ruleName = "expression : variable ASSIGNOP logic_expression";
		$text = $v.text + $ASSIGNOP->getText() + $le.text;
		$line = std::to_string($ASSIGNOP->getLine());

		$id = $v.id;
		printIdentifier($id);	
		if(!$id.isError){
			writeRuleLog($line, ruleName);
			assignment($v.id,$le.id,$line);
			writeIntoparserLogFile($text + "\n");	
		}
	};

logic_expression returns[std::string text, std::string line, Identifier id]:
	re = rel_expression {
		std::string ruleName = "logic_expression : rel_expression";
		$text = $re.text;
		$line = $re.line;

		$id = $re.id;

		if(!$id.isError){
			writeRuleLog($line, ruleName);
			writeIntoparserLogFile($text + "\n");
		}

		printIdentifier($id);
	}
	| re1 = rel_expression LOGICOP re2 = rel_expression {
		std::string ruleName = "logic_expression : rel_expression LOGICOP rel_expression";
		$text = $re1.text + $LOGICOP->getText() + $re2.text;
		$line = std::to_string($LOGICOP->getLine());

		writeRuleLog($line, ruleName);
		writeIntoparserLogFile($text + "\n");

		// $id = $re2.id;
		$id.idType = "INT";
		printIdentifier($id);
	};

rel_expression returns[std::string text, std::string line, Identifier id]:
	// new rules
	se = simple_expression ADDOP ASSIGNOP {
		debug2("rel_expression : simple_expression ADDOP ASSIGNOP\n");

		$text = $se.text;
		$line = $se.line;
		$id = $se.id;
		$id.isError = true;
		printIdentifier($id);

		writeIntoparserLogFile("Error at line " + $line + ": syntax error, unexpected ASSIGNOP\n");
		writeIntoErrorFile("Error at line " + $line + ": syntax error, unexpected ASSIGNOP\n");		
	}
	| se = simple_expression {
		std::string ruleName = "rel_expression : simple_expression";
		$text = $se.text;
		$line = $se.line;
		
		$id = $se.id;

		if(!$id.isError){
			writeRuleLog($line, ruleName);
			writeIntoparserLogFile($text + "\n");
		}

		printIdentifier($id);
	}
	| se1 = simple_expression RELOP se2 = simple_expression {
		std::string ruleName = "rel_expression : simple_expression RELOP simple_expression";
		$text = $se1.text + $RELOP->getText() + $se2.text;
		$line = std::to_string($RELOP->getLine());

		writeRuleLog($line, ruleName);
		writeIntoparserLogFile($text + "\n");

		// $id = $se2.id;
		$id.idType = "INT";
		printIdentifier($id);
	};

simple_expression returns[std::string text, std::string line, Identifier id]:
	t = term {
		std::string ruleName = "simple_expression : term";
		$text = $t.text;
		$line = $t.line;

		writeRuleLog($line, ruleName);
		writeIntoparserLogFile($text + "\n");

		$id = $t.id;
		printIdentifier($id);
	} 
	| se = simple_expression ADDOP t = term {
		std::string ruleName = "simple_expression : simple_expression ADDOP term";
		$text = $se.text + $ADDOP->getText() + $t.text;
		$line = std::to_string($ADDOP->getLine());

		writeRuleLog($line, ruleName);
		writeIntoparserLogFile($text + "\n");

		if($t.id.idType == "FLOAT" || $se.id.idType == "FLOAT") {
			$id.idType = "FLOAT";
		} else {
			$id.idType = "INT";
		}
		printIdentifier($id);
	};

term returns[std::string text, std::string line, Identifier id]:
	ue = unary_expression {
		std::string ruleName = "term : unary_expression";
		$text = $ue.text;
		$line = $ue.line;

		writeRuleLog($line, ruleName);
		writeIntoparserLogFile($text + "\n");

		$id = $ue.id;
		printIdentifier($id);
	} 
	| t = term MULOP ue = unary_expression {
		std::string ruleName = "term : term MULOP unary_expression";
		$text = $t.text + $MULOP->getText() + $ue.text;
		$line = std::to_string($MULOP->getLine());

		writeRuleLog($line, ruleName);

		// $id = $ue.id;
		if($t.id.idType == "FLOAT" || $ue.id.idType == "FLOAT") {
			$id.idType = "FLOAT";
		} else {
			$id.idType = "INT";
		}

		printIdentifier($id);

		if($ue.id.idType == "void" || $ue.id.idType == "VOID") {
			writeIntoErrorFile("Error at line " + $line + ": Void function used in expression" + "\n");
			syntaxErrorCount++;
			writeIntoparserLogFile("Error at line " + $line + ": Void function used in expression" + "\n");
		}else if($MULOP->getText() == "%"){
			if($ue.id.idType != "INT" || $t.id.idType != "INT") {
				writeIntoErrorFile("Error at line " + $line + ": Non-Integer operand on modulus operator" + "\n");
				syntaxErrorCount++;
				writeIntoparserLogFile("Error at line " + $line + ": Non-Integer operand on modulus operator" + "\n");
			}else if(getIntegerFromString($ue.text) == 0) {
				writeIntoErrorFile("Error at line " + $line + ": Modulus by Zero" + "\n");
				syntaxErrorCount++;
				writeIntoparserLogFile("Error at line " + $line + ": Modulus by Zero" + "\n");
			}
			$id.idType = "INT";
		}else if($MULOP->getText() == "/"){
			if(getIntegerFromString($ue.text) == 0) {
				writeIntoErrorFile("Error at line " + $line + ": Division by Zero" + "\n");
				syntaxErrorCount++;
				writeIntoparserLogFile("Error at line " + $line + ": Division by Zero" + "\n");
			}
			$id.idType = "INT";
		}

		writeIntoparserLogFile($text + "\n");
	};

unary_expression returns[std::string text, std::string line, Identifier id]:
	ADDOP ue = unary_expression {
		std::string ruleName = "unary_expression : ADDOP unary_expression";
		$text = $ADDOP->getText() + $ue.text;
		$line = std::to_string($ADDOP->getLine());

		writeRuleLog($line, ruleName);
		writeIntoparserLogFile($text + "\n");

		$id = $ue.id;
		printIdentifier($id);
	}
	| NOT ue = unary_expression {
		std::string ruleName = "unary_expression : NOT unary_expression";
		$text = $NOT->getText() + $ue.text;
		$line = std::to_string($NOT->getLine());

		writeRuleLog($line, ruleName);
		writeIntoparserLogFile($text + "\n");

		$id = $ue.id;
		printIdentifier($id);
	}
	| f = factor {
		std::string ruleName = "unary_expression : factor";
		$text = $f.text;
		$line = $f.line;

		writeRuleLog($line, ruleName);
		writeIntoparserLogFile($text + "\n");

		$id = $f.id;
		printIdentifier($id);
	};

factor returns[std::string text, std::string line, Identifier id]:
	v = variable {
		std::string ruleName = "factor : variable";
		$text = $v.text;
		$line = $v.line;

		writeRuleLog($line, ruleName);
		writeIntoparserLogFile($text + "\n");

		$id = $v.id;
		printIdentifier($id);
	}
	| ID LPAREN al = argument_list RPAREN {
		std::string ruleName = "factor : ID LPAREN argument_list RPAREN";
		$text = $ID->getText() + $LPAREN->getText() + $al.text + $RPAREN->getText();
		$line = std::to_string($ID->getLine());

		writeRuleLog($line, ruleName);
		$id.idType = callFunctionInExpression($ID->getText(), $al.list, $line);
		writeIntoparserLogFile($text + "\n");

		printIdentifier($id);
	}
	| LPAREN e = expression RPAREN {
		std::string ruleName = "factor : LPAREN expression RPAREN";
		$text = $LPAREN->getText() + $e.text + $RPAREN->getText();
		$line = std::to_string($LPAREN->getLine());

		writeRuleLog($line, ruleName);
		writeIntoparserLogFile($text + "\n");

		// $id.idType = "EMPTY";
		$id = $e.id;
		printIdentifier($id);
	}
	| CONST_INT {
		std::string ruleName = "factor : CONST_INT";
		$text = $CONST_INT->getText();
		$line = std::to_string($CONST_INT->getLine());

		writeRuleLog($line, ruleName);
		writeIntoparserLogFile($text + "\n");

		$id.idType = "INT";
		printIdentifier($id);
	}
	| CONST_FLOAT {
		std::string ruleName = "factor : CONST_FLOAT";
		$text = $CONST_FLOAT->getText();
		$line = std::to_string($CONST_FLOAT->getLine());

		writeRuleLog($line, ruleName);
		writeIntoparserLogFile($text + "\n");

		$id.idType = "FLOAT";
		printIdentifier($id);
	}
	| v = variable INCOP {
		std::string ruleName = "factor : variable INCOP";
		$text = $v.text + $INCOP->getText();
		$line = std::to_string($INCOP->getLine());

		writeRuleLog($line, ruleName);
		writeIntoparserLogFile($text + "\n");

		$id.idType = "INT";
		printIdentifier($id);
	}
	| v = variable DECOP {
		std::string ruleName = "factor : variable DECOP";
		$text = $v.text + $DECOP->getText();
		$line = std::to_string($DECOP->getLine());

		writeRuleLog($line, ruleName);
		writeIntoparserLogFile($text + "\n");

		$id.idType = "INT";
		printIdentifier($id);
	};

argument_list returns[std::string text, std::string line, param_list list]:
	a = arguments {
		std::string ruleName = "argument_list : arguments";
		$text = $a.text;
		$line = $a.line;

		writeRuleLog($line, ruleName);
		writeIntoparserLogFile($text + "\n");

		$list = $a.list;
	}
	|;

arguments returns[std::string text, std::string line, param_list list]:
	a = arguments COMMA le = logic_expression {
		std::string ruleName = "arguments : arguments COMMA logic_expression";
		$text = $a.text + $COMMA->getText() + $le.text;
		$line = std::to_string($COMMA->getLine());

		writeRuleLog($line, ruleName);
		writeIntoparserLogFile($text + "\n");

		$list = $a.list;
		Variable var;
		var.type = $le.id.idType;
		$list.add(var);
	} 
	| le = logic_expression {
		std::string ruleName = "arguments : logic_expression";
		$text = $le.text;
		$line = $le.line;

		writeRuleLog($line, ruleName);
		writeIntoparserLogFile($text + "\n");

		Variable var;
		var.type = $le.id.idType;
		$list.add(var);
	};

variable returns[std::string text, std::string line, Identifier id]: 
	ID {
		std::string ruleName = "variable : ID";
		$text = $ID->getText();
		$line = std::to_string($ID->getLine());

		writeRuleLog($line, ruleName);

		SymbolInfo* symbol = symbolTable.lookUpInCurrentScope($ID->getText());
		if(symbol == NULL) {symbol = symbolTable.lookUp($ID->getText());}
		if (symbol != NULL) {$id = symbol->id;}
		printIdentifier($id);

		if(symbol == NULL) {
			writeIntoErrorFile("Error at line " + $line + ": Undeclared variable "  + $ID->getText()+ "\n");
			syntaxErrorCount++;
			writeIntoparserLogFile("Error at line " + $line + ": Undeclared variable "  + $ID->getText()+ "\n");
		}
		else if($id.isArray){
			writeIntoErrorFile("Error at line " + $line + ": Type mismatch, " + $ID->getText() + " is an array" + "\n");
			syntaxErrorCount++;
			writeIntoparserLogFile("Error at line " + $line + ": Type mismatch, " + $ID->getText() + " is an array" + "\n");
		}

		writeIntoparserLogFile($text + "\n");
	} 
	| ID LTHIRD e = expression RTHIRD {
		std::string ruleName = "variable : ID LTHIRD expression RTHIRD";
		$text = $ID->getText() + $LTHIRD->getText() + $e.text + $RTHIRD->getText();
		$line = std::to_string($ID->getLine());

		writeRuleLog($line, ruleName);

		SymbolInfo* symbol = symbolTable.lookUpInCurrentScope($ID->getText());
		if(symbol == NULL) {symbol = symbolTable.lookUp($ID->getText());}
		if (symbol != NULL) {$id = symbol->id;}
		printIdentifier($id);

		if(symbol == NULL) {
			writeIntoErrorFile("Error at line " + $line + ": Undeclared variable "  + $ID->getText()+ "\n");
			syntaxErrorCount++;
			writeIntoparserLogFile("Error at line " + $line + ": Undeclared variable "  + $ID->getText()+ "\n");
		}
		else if($id.isArray == false) {
			writeIntoErrorFile("Error at line " + $line + ": " + $ID->getText() + " not an array" + "\n");
			syntaxErrorCount++;
			writeIntoparserLogFile("Error at line " + $line + ": " + $ID->getText() + " not an array" + "\n");
		}
		else if(!isInt($e.text)) {
			writeIntoErrorFile("Error at line " + $line + ": Expression inside third brackets not an integer" + "\n");
			syntaxErrorCount++;
			writeIntoparserLogFile("Error at line " + $line + ": Expression inside third brackets not an integer" + "\n");
		}		

		writeIntoparserLogFile($text + "\n");
	};	


unrecognized_character returns[std::string text, std::string line]:
	UNRECOGNIZED {
		$text = "Unrecognized character";
		$line = std::to_string($UNRECOGNIZED->getLine());

		std::string errorMsg = "Error at line " + $line + ": Unrecognized character " + $UNRECOGNIZED->getText() + "\n";
		writeIntoErrorFile(errorMsg);
		writeIntoparserLogFile(errorMsg);
		syntaxErrorCount++;
	};