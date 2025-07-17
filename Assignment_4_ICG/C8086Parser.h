
    #include <iostream>
    #include <fstream>
    #include <string>
    #include <cstdlib>
    #include "C8086Lexer.h"
	#include "./headers/2105177_SymbolTable.h"
	#include "./headers/util.cpp"
	#include "./headers/2105177_SymbolInfo.h"

	extern std::ofstream codeFile;
	extern std::ofstream optCodeFile;
	extern std::ofstream tempFile;
	extern std::string tempFileName;

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


  	int stackMemberCount;

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
  	void writeIntoTempFile(const std::string& code) {
  		if (!tempFile) {
  			std::cout << "Error opening tempFile.txt" << std::endl;
  			return;
  		}
  		tempFile << code;
  		tempFile.flush();
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
  	void preserveBasePointer() {
  		std::string code = "    PUSH BP\n    MOV BP, SP\n";
  		writeIntoTempFile(code);
  	}
  	void restoreBasePointer() {
  		std::string code = "    POP BP\n";
  		writeIntoTempFile(code);
  	}
  	void initializeFunction(const std::string &functionName) {
  		if (functionName == "main") {
  			initializeDataSegment();
  		}
  		preserveBasePointer();
  	}
  	void exitMainFunction() {
  		std::string code = "    ;exit program\n    MOV AX,4CH\n    INT 21H\n";
  		writeIntoTempFile(code);
  	}

  	void enterScope() {
  		stackMemberCount = 0;
  		symbolTable.enterScope();
  	}

  	void exitScope() {
  		symbolTable.exitScope();
  	}

  	bool isGlobalScope() {
  		return symbolTable.isRootScope();
  	}

  	void globalVariableDeclaration(Identifier id, std::string line) {
  		// handles only int
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
  		// handles only int
  		SymbolInfo* symbol = symbolTable.insert(id.idName, "ID");
  		if (symbol != NULL) {
  			symbol->id = id;
  			symbol->id.isGlobal = false;
  			if(id.isArray) {
  				for(int i = 0; i < id.arraySize; i++) {
  					symbol->id.stackOffset = 2 * stackMemberCount;
  					stackMemberCount++;
  					std::string code = "    SUB SP, 2"+ getComment(line) +"\n";
  					writeIntoTempFile(code);
  				}
  			} else {
  				symbol->id.stackOffset = 2 * stackMemberCount;
  				stackMemberCount++;
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

  	std::string variableAddress(Identifier id) {
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
  				address = "[BP - "  + std::to_string(id.stackOffset) + "]";
  			}
  		}
  		return address;
  	}
  	void printVariable(Identifier id, std::string line) {
  		std::string code = "    PUSH AX" + getComment(line) + "\n"; 
  		writeIntoTempFile(code);
  		code = "    MOV AX, " + variableAddress(id) + getComment(line) + "\n";
  		writeIntoTempFile(code);
  		code = "    CALL print_output" + getComment(line) + "\n";
  		writeIntoTempFile(code);
  		code = "    CALL new_line" + getComment(line) + "\n";
  		writeIntoTempFile(code);
  	}
  	void assignVariable(Identifier var, Identifier value, std::string line) {
  		std::string code = "    MOV WORD PTR " + variableAddress(var) + ", " + variableAddress(value) + getComment(line) + "\n";
  		writeIntoTempFile(code);
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
    Parameter_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_specifierContext *type_specifier();
    antlr4::tree::TerminalNode *ID();
    Parameter_listContext *parameter_list();
    antlr4::tree::TerminalNode *COMMA();

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
    antlr4::Token *idToken = nullptr;
    Func_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_specifierContext *type_specifier();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LPAREN();
    Parameter_listContext *parameter_list();
    antlr4::tree::TerminalNode *RPAREN();
    Compound_statementContext *compound_statement();

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
    antlr4::Token *printlnToken = nullptr;
    antlr4::Token *idToken = nullptr;
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Var_declarationContext *var_declaration();
    std::vector<Expression_statementContext *> expression_statement();
    Expression_statementContext* expression_statement(size_t i);
    Compound_statementContext *compound_statement();
    antlr4::tree::TerminalNode *FOR();
    antlr4::tree::TerminalNode *LPAREN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RPAREN();
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
    C8086Parser::Logic_expressionContext *logic_expressionContext = nullptr;
    C8086Parser::VariableContext *variableContext = nullptr;
    antlr4::Token *assignopToken = nullptr;
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Logic_expressionContext *logic_expression();
    VariableContext *variable();
    antlr4::tree::TerminalNode *ASSIGNOP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ExpressionContext* expression();

  class  Logic_expressionContext : public antlr4::ParserRuleContext {
  public:
    Identifier id;
    C8086Parser::Rel_expressionContext *rel_expressionContext = nullptr;
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
    C8086Parser::Simple_expressionContext *simple_expressionContext = nullptr;
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
    C8086Parser::TermContext *termContext = nullptr;
    Simple_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TermContext *term();
    Simple_expressionContext *simple_expression();
    antlr4::tree::TerminalNode *ADDOP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Simple_expressionContext* simple_expression();
  Simple_expressionContext* simple_expression(int precedence);
  class  TermContext : public antlr4::ParserRuleContext {
  public:
    Identifier id;
    C8086Parser::Unary_expressionContext *unary_expressionContext = nullptr;
    TermContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Unary_expressionContext *unary_expression();
    TermContext *term();
    antlr4::tree::TerminalNode *MULOP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TermContext* term();
  TermContext* term(int precedence);
  class  Unary_expressionContext : public antlr4::ParserRuleContext {
  public:
    Identifier id;
    C8086Parser::FactorContext *factorContext = nullptr;
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
    antlr4::Token *const_intToken = nullptr;
    FactorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VariableContext *variable();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LPAREN();
    Argument_listContext *argument_list();
    antlr4::tree::TerminalNode *RPAREN();
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
    Argument_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ArgumentsContext *arguments();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Argument_listContext* argument_list();

  class  ArgumentsContext : public antlr4::ParserRuleContext {
  public:
    ArgumentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Logic_expressionContext *logic_expression();
    ArgumentsContext *arguments();
    antlr4::tree::TerminalNode *COMMA();

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

