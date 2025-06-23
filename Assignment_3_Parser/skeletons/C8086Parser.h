
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
    RuleVar_declaration = 4, RuleDeclaration_list = 5, RuleDeclaration_list_err = 6, 
    RuleParameter_list = 7, RuleFunc_declaration = 8, RuleFunc_definition = 9, 
    RuleCompound_statement = 10, RuleStatements = 11, RuleStatement = 12, 
    RuleExpression_statement = 13, RuleExpression = 14, RuleLogic_expression = 15, 
    RuleVariable = 16, RuleRel_expression = 17, RuleSimple_expression = 18, 
    RuleTerm = 19, RuleUnary_expression = 20, RuleFactor = 21, RuleArgument_list = 22, 
    RuleArguments = 23
  };

  explicit C8086Parser(antlr4::TokenStream *input);

  C8086Parser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~C8086Parser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  	// data types 
  	// INT
  	// FLOAT
  	// BOOL

  	bool insertParam = false;
  	param_list params;

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
  		// writeIntoparserLogFile("Identifier name: " + id.idName + "\n");
  		// writeIntoparserLogFile("Identifier type: " + id.idType + "\n");
  		// if (id.isArray) {
  		// 	writeIntoparserLogFile("Identifier is an array: true\n");
  		// 	writeIntoparserLogFile("Array size: " + std::to_string(id.arraySize) + "\n");
  		// } else {
  		// 	writeIntoparserLogFile("Identifier is an array: false\n");
  		// }
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

  	void declareFunction(std::string returnType, std::string functionName, param_list params) {
  		SymbolInfo* symbol = symbolTable.lookUpInCurrentScope(functionName);
  		if(symbol != NULL) {
  			writeIntoparserLogFile("Error: Function " + functionName + " already declared\n");
  			writeIntoErrorFile("Error: Function " + functionName + " already declared\n");
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

  	void defineFunction(std::string returnType, std::string functionName, param_list params) {
  		SymbolInfo* symbol = symbolTable.lookUpInCurrentScope(functionName);
  		if(symbol != NULL) {
  			if(symbol->id.isDefined) {
  				writeIntoparserLogFile("Error: Function " + functionName + " already defined\n");
  				writeIntoErrorFile("Error: Function " + functionName + " already defined\n");
  				syntaxErrorCount++;
  				return;
  			} else if(symbol->id.isDeclared) {
  				// check if return type matches
  				if(symbol->id.returnType != toUpper(returnType)) {
  					writeIntoparserLogFile("Error: Function " + functionName + " return type mismatch\n");
  					writeIntoErrorFile("Error: Function " + functionName + " return type mismatch\n");
  					syntaxErrorCount++;
  				} else if(!isParameterListEqual(symbol->id.parameters, params)) {
  					writeIntoparserLogFile("Error: Function " + functionName + " parameter list mismatch\n");
  					writeIntoErrorFile("Error: Function " + functionName + " parameter list mismatch\n");
  					syntaxErrorCount++;
  				}
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

  		symbolTable.enterScope();
  		for (auto &param : params.get_param()) {
  			if (symbolTable.lookUpInCurrentScope(param.name) != NULL) {
  				writeIntoparserLogFile("Error at line " + line + ": Duplicate parameter name " + param.name + "\n");
  				writeIntoErrorFile("Error at line " + line + ": Duplicate parameter name " + param.name + "\n");
  				syntaxErrorCount++;
  			}else {
  				SymbolInfo* symbol = symbolTable.insert(param.name, "ID");
  			}
  		}
  		symbolTable.exitScope();
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

  	bool doesArgumentMatch(param_list params1, param_list params2) {
  		if (params1.size() != params2.size()) {
  			return false;
  		}
  		vector<Variable> p1 = params1.get_param();
  		vector<Variable> p2 = params2.get_param();
  		for (int i = 0; i < p1.size(); ++i) {
  			if (toUpper(p1[i].type) != toUpper(p2[i].type)) {
  				return false;
  			}
  		}
  		return true;
  	}

  	std::string callFunctionInExpression(std::string functionName, param_list args, std::string line) {
  		SymbolInfo* symbol = symbolTable.lookUpInCurrentScope(functionName);
  		if(symbol == NULL) {
  			symbol = symbolTable.lookUp(functionName);
  		}

  		if(symbol == NULL || !symbol->id.isFunction) {
  			writeIntoparserLogFile("Error at line " + line + ": " + functionName + " not declared\n");
  			writeIntoErrorFile("Error at line " + line + ": " + functionName + " not declared\n");
  			syntaxErrorCount++;
  			return "EMPTY";
  		}
  		if(!doesArgumentMatch(symbol->id.parameters, args)) {
  			writeIntoparserLogFile("Error at line " + line + ": " + functionName + " 's argument not matched\n");
  			writeIntoErrorFile("Error at line " + line + ": " + functionName + " 's argument not matched\n");
  			syntaxErrorCount++;
  			return "EMPTY";
  		}
  		if(symbol->id.returnType == "VOID" || symbol->id.returnType == "void") {
  			writeIntoparserLogFile("Error at line " + line + ": " + functionName + " 's return type is void\n");
  			writeIntoErrorFile("Error at line " + line + ": " + functionName + " 's return type is void\n");
  			syntaxErrorCount++;
  			return "EMPTY";			
  		}
  		return symbol->id.returnType;
  	}

  	void assignment(Identifier variable, Identifier expression, std::string line) {
  		if(variable.idType == expression.idType){
  			return;
  		}

  		writeIntoparserLogFile("VARIABLE IDENTIFIER:\n");
  		printIdentifier(variable);
  		writeIntoparserLogFile("LOGIC EXPRESSION IDENTIFIER:\n");
  		printIdentifier(expression);

  		if(variable.idType == "FLOAT" && expression.idType == "INT"){
  			return;
  		}
  		syntaxErrorCount++;
  		writeIntoErrorFile("Error at line " + line + ": Type mismatch" + "\n");
  		writeIntoparserLogFile("Error at line " + line + ": Type mismatch" + "\n");
  	}


  class StartContext;
  class ProgramContext;
  class UnitContext;
  class Type_specifierContext;
  class Var_declarationContext;
  class Declaration_listContext;
  class Declaration_list_errContext;
  class Parameter_listContext;
  class Func_declarationContext;
  class Func_definitionContext;
  class Compound_statementContext;
  class StatementsContext;
  class StatementContext;
  class Expression_statementContext;
  class ExpressionContext;
  class Logic_expressionContext;
  class VariableContext;
  class Rel_expressionContext;
  class Simple_expressionContext;
  class TermContext;
  class Unary_expressionContext;
  class FactorContext;
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
    std::string text;
    std::string line;
    C8086Parser::ProgramContext *p = nullptr;
    C8086Parser::UnitContext *u = nullptr;
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
    std::string text;
    std::string line;
    C8086Parser::Var_declarationContext *vdl = nullptr;
    C8086Parser::Func_declarationContext *fdl = nullptr;
    C8086Parser::Func_definitionContext *fdf = nullptr;
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
    std::string text;
    std::string line;
    antlr4::Token *intToken = nullptr;
    antlr4::Token *floatToken = nullptr;
    antlr4::Token *voidToken = nullptr;
    Type_specifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *FLOAT();
    antlr4::tree::TerminalNode *VOID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Type_specifierContext* type_specifier();

  class  Var_declarationContext : public antlr4::ParserRuleContext {
  public:
    std::string text;
    std::string line;
    C8086Parser::Type_specifierContext *t = nullptr;
    C8086Parser::Declaration_listContext *dl = nullptr;
    antlr4::Token *sm = nullptr;
    C8086Parser::Declaration_list_errContext *de = nullptr;
    Var_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_specifierContext *type_specifier();
    Declaration_listContext *declaration_list();
    antlr4::tree::TerminalNode *SEMICOLON();
    Declaration_list_errContext *declaration_list_err();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Var_declarationContext* var_declaration();

  class  Declaration_listContext : public antlr4::ParserRuleContext {
  public:
    std::string text;
    std::string line;
    symbol_list list;
    C8086Parser::Declaration_listContext *dl = nullptr;
    antlr4::Token *idToken = nullptr;
    antlr4::Token *lthirdToken = nullptr;
    antlr4::Token *const_intToken = nullptr;
    antlr4::Token *rthirdToken = nullptr;
    antlr4::Token *commaToken = nullptr;
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
  class  Declaration_list_errContext : public antlr4::ParserRuleContext {
  public:
    std::string text;
    std::string line;
    Declaration_list_errContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Declaration_list_errContext* declaration_list_err();

  class  Parameter_listContext : public antlr4::ParserRuleContext {
  public:
    std::string text;
    std::string line;
    param_list list;
    C8086Parser::Parameter_listContext *pl = nullptr;
    C8086Parser::Type_specifierContext *ts = nullptr;
    antlr4::Token *idToken = nullptr;
    antlr4::Token *commaToken = nullptr;
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
    std::string text;
    std::string line;
    C8086Parser::Type_specifierContext *ts = nullptr;
    antlr4::Token *idToken = nullptr;
    antlr4::Token *lparenToken = nullptr;
    C8086Parser::Parameter_listContext *pl = nullptr;
    antlr4::Token *rparenToken = nullptr;
    antlr4::Token *semicolonToken = nullptr;
    Func_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *SEMICOLON();
    Type_specifierContext *type_specifier();
    Parameter_listContext *parameter_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Func_declarationContext* func_declaration();

  class  Func_definitionContext : public antlr4::ParserRuleContext {
  public:
    std::string text;
    std::string line;
    C8086Parser::Type_specifierContext *ts = nullptr;
    antlr4::Token *idToken = nullptr;
    antlr4::Token *lparenToken = nullptr;
    C8086Parser::Parameter_listContext *pl = nullptr;
    antlr4::Token *rparenToken = nullptr;
    C8086Parser::Compound_statementContext *cs = nullptr;
    Func_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    Type_specifierContext *type_specifier();
    Parameter_listContext *parameter_list();
    Compound_statementContext *compound_statement();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Func_definitionContext* func_definition();

  class  Compound_statementContext : public antlr4::ParserRuleContext {
  public:
    std::string text;
    std::string line;
    antlr4::Token *lcurlToken = nullptr;
    C8086Parser::StatementsContext *s = nullptr;
    antlr4::Token *rcurlToken = nullptr;
    Compound_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LCURL();
    antlr4::tree::TerminalNode *RCURL();
    StatementsContext *statements();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Compound_statementContext* compound_statement();

  class  StatementsContext : public antlr4::ParserRuleContext {
  public:
    std::string text;
    std::string line;
    C8086Parser::StatementsContext *ss = nullptr;
    C8086Parser::StatementContext *s = nullptr;
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
    std::string text;
    std::string line;
    C8086Parser::Var_declarationContext *vd = nullptr;
    C8086Parser::Expression_statementContext *es = nullptr;
    C8086Parser::Compound_statementContext *cs = nullptr;
    antlr4::Token *forToken = nullptr;
    antlr4::Token *lparenToken = nullptr;
    C8086Parser::Expression_statementContext *es1 = nullptr;
    C8086Parser::Expression_statementContext *es2 = nullptr;
    C8086Parser::ExpressionContext *e = nullptr;
    antlr4::Token *rparenToken = nullptr;
    C8086Parser::StatementContext *s = nullptr;
    antlr4::Token *ifToken = nullptr;
    C8086Parser::StatementContext *s1 = nullptr;
    antlr4::Token *elseToken = nullptr;
    C8086Parser::StatementContext *s2 = nullptr;
    antlr4::Token *whileToken = nullptr;
    antlr4::Token *printlnToken = nullptr;
    antlr4::Token *idToken = nullptr;
    antlr4::Token *semicolonToken = nullptr;
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
    ExpressionContext *expression();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);
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
    std::string text;
    std::string line;
    antlr4::Token *semicolonToken = nullptr;
    C8086Parser::ExpressionContext *e = nullptr;
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
    std::string text;
    std::string line;
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
    std::string text;
    std::string line;
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

  class  VariableContext : public antlr4::ParserRuleContext {
  public:
    std::string text;
    std::string line;
    Identifier id;
    antlr4::Token *idToken = nullptr;
    antlr4::Token *lthirdToken = nullptr;
    C8086Parser::ExpressionContext *e = nullptr;
    antlr4::Token *rthirdToken = nullptr;
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

  class  Rel_expressionContext : public antlr4::ParserRuleContext {
  public:
    std::string text;
    std::string line;
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
    std::string text;
    std::string line;
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
    std::string text;
    std::string line;
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
    std::string text;
    std::string line;
    Identifier id;
    antlr4::Token *addopToken = nullptr;
    C8086Parser::Unary_expressionContext *ue = nullptr;
    antlr4::Token *notToken = nullptr;
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
    std::string text;
    std::string line;
    Identifier id;
    C8086Parser::VariableContext *v = nullptr;
    antlr4::Token *idToken = nullptr;
    antlr4::Token *lparenToken = nullptr;
    C8086Parser::Argument_listContext *al = nullptr;
    antlr4::Token *rparenToken = nullptr;
    C8086Parser::ExpressionContext *e = nullptr;
    antlr4::Token *const_intToken = nullptr;
    antlr4::Token *const_floatToken = nullptr;
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

  class  Argument_listContext : public antlr4::ParserRuleContext {
  public:
    std::string text;
    std::string line;
    param_list list;
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
    std::string text;
    std::string line;
    param_list list;
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

