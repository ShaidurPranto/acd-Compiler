
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


#include "C8086ParserListener.h"

#include "C8086Parser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct C8086ParserStaticData final {
  C8086ParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  C8086ParserStaticData(const C8086ParserStaticData&) = delete;
  C8086ParserStaticData(C8086ParserStaticData&&) = delete;
  C8086ParserStaticData& operator=(const C8086ParserStaticData&) = delete;
  C8086ParserStaticData& operator=(C8086ParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag c8086parserParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<C8086ParserStaticData> c8086parserParserStaticData = nullptr;

void c8086parserParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (c8086parserParserStaticData != nullptr) {
    return;
  }
#else
  assert(c8086parserParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<C8086ParserStaticData>(
    std::vector<std::string>{
      "start", "program", "unit", "type_specifier", "declaration_list", 
      "var_declaration", "parameter_list", "func_declaration", "func_definition", 
      "compound_statement", "statements", "statement", "expression_statement", 
      "expression", "logic_expression", "rel_expression", "simple_expression", 
      "term", "unary_expression", "factor", "variable", "argument_list", 
      "arguments"
    },
    std::vector<std::string>{
      "", "", "", "", "", "'if'", "'else'", "'for'", "'while'", "'println'", 
      "'return'", "'int'", "'float'", "'void'", "'('", "')'", "'{'", "'}'", 
      "'['", "']'", "';'", "','", "", "", "", "'++'", "'--'", "'!'", "", 
      "", "'='"
    },
    std::vector<std::string>{
      "", "LINE_COMMENT", "BLOCK_COMMENT", "STRING", "WS", "IF", "ELSE", 
      "FOR", "WHILE", "PRINTLN", "RETURN", "INT", "FLOAT", "VOID", "LPAREN", 
      "RPAREN", "LCURL", "RCURL", "LTHIRD", "RTHIRD", "SEMICOLON", "COMMA", 
      "ADDOP", "SUBOP", "MULOP", "INCOP", "DECOP", "NOT", "RELOP", "LOGICOP", 
      "ASSIGNOP", "ID", "CONST_INT", "CONST_FLOAT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,33,343,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,5,1,56,8,1,10,1,12,1,
  	59,9,1,1,2,1,2,1,2,3,2,64,8,2,1,3,1,3,1,3,1,3,1,3,1,3,3,3,72,8,3,1,4,
  	1,4,1,4,1,4,1,4,1,4,1,4,1,4,3,4,82,8,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,
  	4,1,4,1,4,1,4,5,4,95,8,4,10,4,12,4,98,9,4,1,5,1,5,1,5,1,5,1,5,1,6,1,6,
  	1,6,1,6,1,6,3,6,110,8,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,5,6,120,8,6,10,
  	6,12,6,123,9,6,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,3,
  	7,138,8,7,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,
  	1,8,1,8,1,8,1,8,3,8,159,8,8,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,3,9,169,8,
  	9,1,10,1,10,1,10,1,10,1,10,5,10,176,8,10,10,10,12,10,179,9,10,1,11,1,
  	11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,
  	11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,
  	11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,3,11,222,8,
  	11,1,12,1,12,1,12,1,12,3,12,228,8,12,1,13,1,13,1,13,1,13,1,13,1,13,1,
  	13,1,13,3,13,238,8,13,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,3,14,248,
  	8,14,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,3,15,258,8,15,1,16,1,16,
  	1,16,1,16,1,16,1,16,1,16,1,16,1,16,5,16,269,8,16,10,16,12,16,272,9,16,
  	1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,5,17,283,8,17,10,17,12,17,
  	286,9,17,1,18,1,18,1,18,1,18,1,18,1,18,1,18,3,18,295,8,18,1,19,1,19,1,
  	19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,
  	19,1,19,1,19,3,19,316,8,19,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,3,
  	20,326,8,20,1,21,1,21,3,21,330,8,21,1,22,1,22,1,22,1,22,1,22,1,22,5,22,
  	338,8,22,10,22,12,22,341,9,22,1,22,0,7,2,8,12,20,32,34,44,23,0,2,4,6,
  	8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,0,0,359,0,46,
  	1,0,0,0,2,50,1,0,0,0,4,63,1,0,0,0,6,71,1,0,0,0,8,81,1,0,0,0,10,99,1,0,
  	0,0,12,109,1,0,0,0,14,137,1,0,0,0,16,158,1,0,0,0,18,168,1,0,0,0,20,170,
  	1,0,0,0,22,221,1,0,0,0,24,227,1,0,0,0,26,237,1,0,0,0,28,247,1,0,0,0,30,
  	257,1,0,0,0,32,259,1,0,0,0,34,273,1,0,0,0,36,294,1,0,0,0,38,315,1,0,0,
  	0,40,325,1,0,0,0,42,329,1,0,0,0,44,331,1,0,0,0,46,47,6,0,-1,0,47,48,3,
  	2,1,0,48,49,6,0,-1,0,49,1,1,0,0,0,50,51,6,1,-1,0,51,52,3,4,2,0,52,57,
  	1,0,0,0,53,54,10,2,0,0,54,56,3,4,2,0,55,53,1,0,0,0,56,59,1,0,0,0,57,55,
  	1,0,0,0,57,58,1,0,0,0,58,3,1,0,0,0,59,57,1,0,0,0,60,64,3,10,5,0,61,64,
  	3,14,7,0,62,64,3,16,8,0,63,60,1,0,0,0,63,61,1,0,0,0,63,62,1,0,0,0,64,
  	5,1,0,0,0,65,66,5,11,0,0,66,72,6,3,-1,0,67,68,5,12,0,0,68,72,6,3,-1,0,
  	69,70,5,13,0,0,70,72,6,3,-1,0,71,65,1,0,0,0,71,67,1,0,0,0,71,69,1,0,0,
  	0,72,7,1,0,0,0,73,74,6,4,-1,0,74,75,5,31,0,0,75,82,6,4,-1,0,76,77,5,31,
  	0,0,77,78,5,18,0,0,78,79,5,32,0,0,79,80,5,19,0,0,80,82,6,4,-1,0,81,73,
  	1,0,0,0,81,76,1,0,0,0,82,96,1,0,0,0,83,84,10,4,0,0,84,85,5,21,0,0,85,
  	86,5,31,0,0,86,95,6,4,-1,0,87,88,10,3,0,0,88,89,5,21,0,0,89,90,5,31,0,
  	0,90,91,5,18,0,0,91,92,5,32,0,0,92,93,5,19,0,0,93,95,6,4,-1,0,94,83,1,
  	0,0,0,94,87,1,0,0,0,95,98,1,0,0,0,96,94,1,0,0,0,96,97,1,0,0,0,97,9,1,
  	0,0,0,98,96,1,0,0,0,99,100,3,6,3,0,100,101,3,8,4,0,101,102,5,20,0,0,102,
  	103,6,5,-1,0,103,11,1,0,0,0,104,105,6,6,-1,0,105,106,3,6,3,0,106,107,
  	5,31,0,0,107,110,1,0,0,0,108,110,3,6,3,0,109,104,1,0,0,0,109,108,1,0,
  	0,0,110,121,1,0,0,0,111,112,10,4,0,0,112,113,5,21,0,0,113,114,3,6,3,0,
  	114,115,5,31,0,0,115,120,1,0,0,0,116,117,10,3,0,0,117,118,5,21,0,0,118,
  	120,3,6,3,0,119,111,1,0,0,0,119,116,1,0,0,0,120,123,1,0,0,0,121,119,1,
  	0,0,0,121,122,1,0,0,0,122,13,1,0,0,0,123,121,1,0,0,0,124,125,3,6,3,0,
  	125,126,5,31,0,0,126,127,5,14,0,0,127,128,3,12,6,0,128,129,5,15,0,0,129,
  	130,5,20,0,0,130,138,1,0,0,0,131,132,3,6,3,0,132,133,5,31,0,0,133,134,
  	5,14,0,0,134,135,5,15,0,0,135,136,5,20,0,0,136,138,1,0,0,0,137,124,1,
  	0,0,0,137,131,1,0,0,0,138,15,1,0,0,0,139,140,3,6,3,0,140,141,5,31,0,0,
  	141,142,6,8,-1,0,142,143,5,14,0,0,143,144,3,12,6,0,144,145,5,15,0,0,145,
  	146,6,8,-1,0,146,147,3,18,9,0,147,148,6,8,-1,0,148,159,1,0,0,0,149,150,
  	3,6,3,0,150,151,5,31,0,0,151,152,6,8,-1,0,152,153,5,14,0,0,153,154,5,
  	15,0,0,154,155,6,8,-1,0,155,156,3,18,9,0,156,157,6,8,-1,0,157,159,1,0,
  	0,0,158,139,1,0,0,0,158,149,1,0,0,0,159,17,1,0,0,0,160,161,5,16,0,0,161,
  	162,6,9,-1,0,162,163,3,20,10,0,163,164,5,17,0,0,164,165,6,9,-1,0,165,
  	169,1,0,0,0,166,167,5,16,0,0,167,169,5,17,0,0,168,160,1,0,0,0,168,166,
  	1,0,0,0,169,19,1,0,0,0,170,171,6,10,-1,0,171,172,3,22,11,0,172,177,1,
  	0,0,0,173,174,10,1,0,0,174,176,3,22,11,0,175,173,1,0,0,0,176,179,1,0,
  	0,0,177,175,1,0,0,0,177,178,1,0,0,0,178,21,1,0,0,0,179,177,1,0,0,0,180,
  	222,3,10,5,0,181,222,3,24,12,0,182,222,3,18,9,0,183,184,5,7,0,0,184,185,
  	5,14,0,0,185,186,3,24,12,0,186,187,3,24,12,0,187,188,3,26,13,0,188,189,
  	5,15,0,0,189,190,3,22,11,0,190,222,1,0,0,0,191,192,5,5,0,0,192,193,5,
  	14,0,0,193,194,3,26,13,0,194,195,5,15,0,0,195,196,3,22,11,0,196,222,1,
  	0,0,0,197,198,5,5,0,0,198,199,5,14,0,0,199,200,3,26,13,0,200,201,5,15,
  	0,0,201,202,3,22,11,0,202,203,5,6,0,0,203,204,3,22,11,0,204,222,1,0,0,
  	0,205,206,5,8,0,0,206,207,5,14,0,0,207,208,3,26,13,0,208,209,5,15,0,0,
  	209,210,3,22,11,0,210,222,1,0,0,0,211,212,5,9,0,0,212,213,5,14,0,0,213,
  	214,5,31,0,0,214,215,5,15,0,0,215,216,5,20,0,0,216,222,6,11,-1,0,217,
  	218,5,10,0,0,218,219,3,26,13,0,219,220,5,20,0,0,220,222,1,0,0,0,221,180,
  	1,0,0,0,221,181,1,0,0,0,221,182,1,0,0,0,221,183,1,0,0,0,221,191,1,0,0,
  	0,221,197,1,0,0,0,221,205,1,0,0,0,221,211,1,0,0,0,221,217,1,0,0,0,222,
  	23,1,0,0,0,223,228,5,20,0,0,224,225,3,26,13,0,225,226,5,20,0,0,226,228,
  	1,0,0,0,227,223,1,0,0,0,227,224,1,0,0,0,228,25,1,0,0,0,229,230,3,28,14,
  	0,230,231,6,13,-1,0,231,238,1,0,0,0,232,233,3,40,20,0,233,234,5,30,0,
  	0,234,235,3,28,14,0,235,236,6,13,-1,0,236,238,1,0,0,0,237,229,1,0,0,0,
  	237,232,1,0,0,0,238,27,1,0,0,0,239,240,3,30,15,0,240,241,6,14,-1,0,241,
  	248,1,0,0,0,242,243,3,30,15,0,243,244,5,29,0,0,244,245,3,30,15,0,245,
  	246,6,14,-1,0,246,248,1,0,0,0,247,239,1,0,0,0,247,242,1,0,0,0,248,29,
  	1,0,0,0,249,250,3,32,16,0,250,251,6,15,-1,0,251,258,1,0,0,0,252,253,3,
  	32,16,0,253,254,5,28,0,0,254,255,3,32,16,0,255,256,6,15,-1,0,256,258,
  	1,0,0,0,257,249,1,0,0,0,257,252,1,0,0,0,258,31,1,0,0,0,259,260,6,16,-1,
  	0,260,261,3,34,17,0,261,262,6,16,-1,0,262,270,1,0,0,0,263,264,10,1,0,
  	0,264,265,5,22,0,0,265,266,3,34,17,0,266,267,6,16,-1,0,267,269,1,0,0,
  	0,268,263,1,0,0,0,269,272,1,0,0,0,270,268,1,0,0,0,270,271,1,0,0,0,271,
  	33,1,0,0,0,272,270,1,0,0,0,273,274,6,17,-1,0,274,275,3,36,18,0,275,276,
  	6,17,-1,0,276,284,1,0,0,0,277,278,10,1,0,0,278,279,5,24,0,0,279,280,3,
  	36,18,0,280,281,6,17,-1,0,281,283,1,0,0,0,282,277,1,0,0,0,283,286,1,0,
  	0,0,284,282,1,0,0,0,284,285,1,0,0,0,285,35,1,0,0,0,286,284,1,0,0,0,287,
  	288,5,22,0,0,288,295,3,36,18,0,289,290,5,27,0,0,290,295,3,36,18,0,291,
  	292,3,38,19,0,292,293,6,18,-1,0,293,295,1,0,0,0,294,287,1,0,0,0,294,289,
  	1,0,0,0,294,291,1,0,0,0,295,37,1,0,0,0,296,316,3,40,20,0,297,298,5,31,
  	0,0,298,299,5,14,0,0,299,300,3,42,21,0,300,301,5,15,0,0,301,316,1,0,0,
  	0,302,303,5,14,0,0,303,304,3,26,13,0,304,305,5,15,0,0,305,316,1,0,0,0,
  	306,307,5,32,0,0,307,316,6,19,-1,0,308,316,5,33,0,0,309,310,3,40,20,0,
  	310,311,5,25,0,0,311,316,1,0,0,0,312,313,3,40,20,0,313,314,5,26,0,0,314,
  	316,1,0,0,0,315,296,1,0,0,0,315,297,1,0,0,0,315,302,1,0,0,0,315,306,1,
  	0,0,0,315,308,1,0,0,0,315,309,1,0,0,0,315,312,1,0,0,0,316,39,1,0,0,0,
  	317,318,5,31,0,0,318,326,6,20,-1,0,319,320,5,31,0,0,320,321,5,18,0,0,
  	321,322,3,26,13,0,322,323,5,19,0,0,323,324,6,20,-1,0,324,326,1,0,0,0,
  	325,317,1,0,0,0,325,319,1,0,0,0,326,41,1,0,0,0,327,330,3,44,22,0,328,
  	330,1,0,0,0,329,327,1,0,0,0,329,328,1,0,0,0,330,43,1,0,0,0,331,332,6,
  	22,-1,0,332,333,3,28,14,0,333,339,1,0,0,0,334,335,10,2,0,0,335,336,5,
  	21,0,0,336,338,3,28,14,0,337,334,1,0,0,0,338,341,1,0,0,0,339,337,1,0,
  	0,0,339,340,1,0,0,0,340,45,1,0,0,0,341,339,1,0,0,0,25,57,63,71,81,94,
  	96,109,119,121,137,158,168,177,221,227,237,247,257,270,284,294,315,325,
  	329,339
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  c8086parserParserStaticData = std::move(staticData);
}

}

C8086Parser::C8086Parser(TokenStream *input) : C8086Parser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

C8086Parser::C8086Parser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  C8086Parser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *c8086parserParserStaticData->atn, c8086parserParserStaticData->decisionToDFA, c8086parserParserStaticData->sharedContextCache, options);
}

C8086Parser::~C8086Parser() {
  delete _interpreter;
}

const atn::ATN& C8086Parser::getATN() const {
  return *c8086parserParserStaticData->atn;
}

std::string C8086Parser::getGrammarFileName() const {
  return "C8086Parser.g4";
}

const std::vector<std::string>& C8086Parser::getRuleNames() const {
  return c8086parserParserStaticData->ruleNames;
}

const dfa::Vocabulary& C8086Parser::getVocabulary() const {
  return c8086parserParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView C8086Parser::getSerializedATN() const {
  return c8086parserParserStaticData->serializedATN;
}


//----------------- StartContext ------------------------------------------------------------------

C8086Parser::StartContext::StartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::ProgramContext* C8086Parser::StartContext::program() {
  return getRuleContext<C8086Parser::ProgramContext>(0);
}


size_t C8086Parser::StartContext::getRuleIndex() const {
  return C8086Parser::RuleStart;
}

void C8086Parser::StartContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStart(this);
}

void C8086Parser::StartContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStart(this);
}

C8086Parser::StartContext* C8086Parser::start() {
  StartContext *_localctx = _tracker.createInstance<StartContext>(_ctx, getState());
  enterRule(_localctx, 0, C8086Parser::RuleStart);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
     initializeCodeFile(); initializeTempFile(); 
    setState(47);
    antlrcpp::downCast<StartContext *>(_localctx)->p = program(0);

            finalizeTempFile();
            mergeTempFileToCodeFile();
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgramContext ------------------------------------------------------------------

C8086Parser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::UnitContext* C8086Parser::ProgramContext::unit() {
  return getRuleContext<C8086Parser::UnitContext>(0);
}

C8086Parser::ProgramContext* C8086Parser::ProgramContext::program() {
  return getRuleContext<C8086Parser::ProgramContext>(0);
}


size_t C8086Parser::ProgramContext::getRuleIndex() const {
  return C8086Parser::RuleProgram;
}

void C8086Parser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void C8086Parser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


C8086Parser::ProgramContext* C8086Parser::program() {
   return program(0);
}

C8086Parser::ProgramContext* C8086Parser::program(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C8086Parser::ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, parentState);
  C8086Parser::ProgramContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, C8086Parser::RuleProgram, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(51);
    unit();
    _ctx->stop = _input->LT(-1);
    setState(57);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ProgramContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleProgram);
        setState(53);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(54);
        unit(); 
      }
      setState(59);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- UnitContext ------------------------------------------------------------------

C8086Parser::UnitContext::UnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::Var_declarationContext* C8086Parser::UnitContext::var_declaration() {
  return getRuleContext<C8086Parser::Var_declarationContext>(0);
}

C8086Parser::Func_declarationContext* C8086Parser::UnitContext::func_declaration() {
  return getRuleContext<C8086Parser::Func_declarationContext>(0);
}

C8086Parser::Func_definitionContext* C8086Parser::UnitContext::func_definition() {
  return getRuleContext<C8086Parser::Func_definitionContext>(0);
}


size_t C8086Parser::UnitContext::getRuleIndex() const {
  return C8086Parser::RuleUnit;
}

void C8086Parser::UnitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnit(this);
}

void C8086Parser::UnitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnit(this);
}

C8086Parser::UnitContext* C8086Parser::unit() {
  UnitContext *_localctx = _tracker.createInstance<UnitContext>(_ctx, getState());
  enterRule(_localctx, 4, C8086Parser::RuleUnit);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(63);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(60);
      var_declaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(61);
      func_declaration();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(62);
      func_definition();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_specifierContext ------------------------------------------------------------------

C8086Parser::Type_specifierContext::Type_specifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C8086Parser::Type_specifierContext::INT() {
  return getToken(C8086Parser::INT, 0);
}

tree::TerminalNode* C8086Parser::Type_specifierContext::FLOAT() {
  return getToken(C8086Parser::FLOAT, 0);
}

tree::TerminalNode* C8086Parser::Type_specifierContext::VOID() {
  return getToken(C8086Parser::VOID, 0);
}


size_t C8086Parser::Type_specifierContext::getRuleIndex() const {
  return C8086Parser::RuleType_specifier;
}

void C8086Parser::Type_specifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_specifier(this);
}

void C8086Parser::Type_specifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_specifier(this);
}

C8086Parser::Type_specifierContext* C8086Parser::type_specifier() {
  Type_specifierContext *_localctx = _tracker.createInstance<Type_specifierContext>(_ctx, getState());
  enterRule(_localctx, 6, C8086Parser::RuleType_specifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(71);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C8086Parser::INT: {
        enterOuterAlt(_localctx, 1);
        setState(65);
        match(C8086Parser::INT);
         antlrcpp::downCast<Type_specifierContext *>(_localctx)->type =  "INT"; 
        break;
      }

      case C8086Parser::FLOAT: {
        enterOuterAlt(_localctx, 2);
        setState(67);
        match(C8086Parser::FLOAT);
         antlrcpp::downCast<Type_specifierContext *>(_localctx)->type =  "FLOAT"; 
        break;
      }

      case C8086Parser::VOID: {
        enterOuterAlt(_localctx, 3);
        setState(69);
        match(C8086Parser::VOID);
         antlrcpp::downCast<Type_specifierContext *>(_localctx)->type =  "VOID"; 
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Declaration_listContext ------------------------------------------------------------------

C8086Parser::Declaration_listContext::Declaration_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C8086Parser::Declaration_listContext::ID() {
  return getToken(C8086Parser::ID, 0);
}

tree::TerminalNode* C8086Parser::Declaration_listContext::LTHIRD() {
  return getToken(C8086Parser::LTHIRD, 0);
}

tree::TerminalNode* C8086Parser::Declaration_listContext::CONST_INT() {
  return getToken(C8086Parser::CONST_INT, 0);
}

tree::TerminalNode* C8086Parser::Declaration_listContext::RTHIRD() {
  return getToken(C8086Parser::RTHIRD, 0);
}

tree::TerminalNode* C8086Parser::Declaration_listContext::COMMA() {
  return getToken(C8086Parser::COMMA, 0);
}

C8086Parser::Declaration_listContext* C8086Parser::Declaration_listContext::declaration_list() {
  return getRuleContext<C8086Parser::Declaration_listContext>(0);
}


size_t C8086Parser::Declaration_listContext::getRuleIndex() const {
  return C8086Parser::RuleDeclaration_list;
}

void C8086Parser::Declaration_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaration_list(this);
}

void C8086Parser::Declaration_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaration_list(this);
}


C8086Parser::Declaration_listContext* C8086Parser::declaration_list() {
   return declaration_list(0);
}

C8086Parser::Declaration_listContext* C8086Parser::declaration_list(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C8086Parser::Declaration_listContext *_localctx = _tracker.createInstance<Declaration_listContext>(_ctx, parentState);
  C8086Parser::Declaration_listContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 8;
  enterRecursionRule(_localctx, 8, C8086Parser::RuleDeclaration_list, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(81);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      setState(74);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken = match(C8086Parser::ID);

      		Identifier id;
      		id.idName = antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText();
      		_localctx->ids.add(id);
      	
      break;
    }

    case 2: {
      setState(76);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken = match(C8086Parser::ID);
      setState(77);
      match(C8086Parser::LTHIRD);
      setState(78);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->const_intToken = match(C8086Parser::CONST_INT);
      setState(79);
      match(C8086Parser::RTHIRD);

      		Identifier id;
      		id.idName = antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText();
      		id.isArray = true;
      		id.arraySize = std::stoi(antlrcpp::downCast<Declaration_listContext *>(_localctx)->const_intToken->getText());
      		_localctx->ids.add(id);
      	
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(96);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(94);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<Declaration_listContext>(parentContext, parentState);
          _localctx->dl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleDeclaration_list);
          setState(83);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(84);
          match(C8086Parser::COMMA);
          setState(85);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken = match(C8086Parser::ID);

                            antlrcpp::downCast<Declaration_listContext *>(_localctx)->ids =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->dl->ids;
                    		Identifier id;
                    		id.idName = antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText();
                            _localctx->ids.add(id);
                        
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<Declaration_listContext>(parentContext, parentState);
          _localctx->dl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleDeclaration_list);
          setState(87);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(88);
          match(C8086Parser::COMMA);
          setState(89);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken = match(C8086Parser::ID);
          setState(90);
          match(C8086Parser::LTHIRD);
          setState(91);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->const_intToken = match(C8086Parser::CONST_INT);
          setState(92);
          match(C8086Parser::RTHIRD);

                    		antlrcpp::downCast<Declaration_listContext *>(_localctx)->ids =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->dl->ids;
                    		Identifier id;
                    		id.idName = antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText();
                    		id.isArray = true;
                    		id.arraySize = std::stoi(antlrcpp::downCast<Declaration_listContext *>(_localctx)->const_intToken->getText());
                    		_localctx->ids.add(id);
                    	
          break;
        }

        default:
          break;
        } 
      }
      setState(98);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Var_declarationContext ------------------------------------------------------------------

C8086Parser::Var_declarationContext::Var_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::Type_specifierContext* C8086Parser::Var_declarationContext::type_specifier() {
  return getRuleContext<C8086Parser::Type_specifierContext>(0);
}

C8086Parser::Declaration_listContext* C8086Parser::Var_declarationContext::declaration_list() {
  return getRuleContext<C8086Parser::Declaration_listContext>(0);
}

tree::TerminalNode* C8086Parser::Var_declarationContext::SEMICOLON() {
  return getToken(C8086Parser::SEMICOLON, 0);
}


size_t C8086Parser::Var_declarationContext::getRuleIndex() const {
  return C8086Parser::RuleVar_declaration;
}

void C8086Parser::Var_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVar_declaration(this);
}

void C8086Parser::Var_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVar_declaration(this);
}

C8086Parser::Var_declarationContext* C8086Parser::var_declaration() {
  Var_declarationContext *_localctx = _tracker.createInstance<Var_declarationContext>(_ctx, getState());
  enterRule(_localctx, 10, C8086Parser::RuleVar_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(99);
    antlrcpp::downCast<Var_declarationContext *>(_localctx)->t = type_specifier();
    setState(100);
    antlrcpp::downCast<Var_declarationContext *>(_localctx)->dl = declaration_list(0);
    setState(101);
    antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm = match(C8086Parser::SEMICOLON);

    		variableDeclaration(antlrcpp::downCast<Var_declarationContext *>(_localctx)->t->type, antlrcpp::downCast<Var_declarationContext *>(_localctx)->dl->ids, to_string(antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm->getLine()));
    	
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Parameter_listContext ------------------------------------------------------------------

C8086Parser::Parameter_listContext::Parameter_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::Type_specifierContext* C8086Parser::Parameter_listContext::type_specifier() {
  return getRuleContext<C8086Parser::Type_specifierContext>(0);
}

tree::TerminalNode* C8086Parser::Parameter_listContext::ID() {
  return getToken(C8086Parser::ID, 0);
}

C8086Parser::Parameter_listContext* C8086Parser::Parameter_listContext::parameter_list() {
  return getRuleContext<C8086Parser::Parameter_listContext>(0);
}

tree::TerminalNode* C8086Parser::Parameter_listContext::COMMA() {
  return getToken(C8086Parser::COMMA, 0);
}


size_t C8086Parser::Parameter_listContext::getRuleIndex() const {
  return C8086Parser::RuleParameter_list;
}

void C8086Parser::Parameter_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameter_list(this);
}

void C8086Parser::Parameter_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameter_list(this);
}


C8086Parser::Parameter_listContext* C8086Parser::parameter_list() {
   return parameter_list(0);
}

C8086Parser::Parameter_listContext* C8086Parser::parameter_list(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C8086Parser::Parameter_listContext *_localctx = _tracker.createInstance<Parameter_listContext>(_ctx, parentState);
  C8086Parser::Parameter_listContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 12;
  enterRecursionRule(_localctx, 12, C8086Parser::RuleParameter_list, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(109);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      setState(105);
      type_specifier();
      setState(106);
      match(C8086Parser::ID);
      break;
    }

    case 2: {
      setState(108);
      type_specifier();
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(121);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(119);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<Parameter_listContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleParameter_list);
          setState(111);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(112);
          match(C8086Parser::COMMA);
          setState(113);
          type_specifier();
          setState(114);
          match(C8086Parser::ID);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<Parameter_listContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleParameter_list);
          setState(116);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(117);
          match(C8086Parser::COMMA);
          setState(118);
          type_specifier();
          break;
        }

        default:
          break;
        } 
      }
      setState(123);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Func_declarationContext ------------------------------------------------------------------

C8086Parser::Func_declarationContext::Func_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::Type_specifierContext* C8086Parser::Func_declarationContext::type_specifier() {
  return getRuleContext<C8086Parser::Type_specifierContext>(0);
}

tree::TerminalNode* C8086Parser::Func_declarationContext::ID() {
  return getToken(C8086Parser::ID, 0);
}

tree::TerminalNode* C8086Parser::Func_declarationContext::LPAREN() {
  return getToken(C8086Parser::LPAREN, 0);
}

C8086Parser::Parameter_listContext* C8086Parser::Func_declarationContext::parameter_list() {
  return getRuleContext<C8086Parser::Parameter_listContext>(0);
}

tree::TerminalNode* C8086Parser::Func_declarationContext::RPAREN() {
  return getToken(C8086Parser::RPAREN, 0);
}

tree::TerminalNode* C8086Parser::Func_declarationContext::SEMICOLON() {
  return getToken(C8086Parser::SEMICOLON, 0);
}


size_t C8086Parser::Func_declarationContext::getRuleIndex() const {
  return C8086Parser::RuleFunc_declaration;
}

void C8086Parser::Func_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunc_declaration(this);
}

void C8086Parser::Func_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunc_declaration(this);
}

C8086Parser::Func_declarationContext* C8086Parser::func_declaration() {
  Func_declarationContext *_localctx = _tracker.createInstance<Func_declarationContext>(_ctx, getState());
  enterRule(_localctx, 14, C8086Parser::RuleFunc_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(137);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(124);
      type_specifier();
      setState(125);
      match(C8086Parser::ID);
      setState(126);
      match(C8086Parser::LPAREN);
      setState(127);
      parameter_list(0);
      setState(128);
      match(C8086Parser::RPAREN);
      setState(129);
      match(C8086Parser::SEMICOLON);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(131);
      type_specifier();
      setState(132);
      match(C8086Parser::ID);
      setState(133);
      match(C8086Parser::LPAREN);
      setState(134);
      match(C8086Parser::RPAREN);
      setState(135);
      match(C8086Parser::SEMICOLON);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Func_definitionContext ------------------------------------------------------------------

C8086Parser::Func_definitionContext::Func_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::Type_specifierContext* C8086Parser::Func_definitionContext::type_specifier() {
  return getRuleContext<C8086Parser::Type_specifierContext>(0);
}

tree::TerminalNode* C8086Parser::Func_definitionContext::ID() {
  return getToken(C8086Parser::ID, 0);
}

tree::TerminalNode* C8086Parser::Func_definitionContext::LPAREN() {
  return getToken(C8086Parser::LPAREN, 0);
}

C8086Parser::Parameter_listContext* C8086Parser::Func_definitionContext::parameter_list() {
  return getRuleContext<C8086Parser::Parameter_listContext>(0);
}

tree::TerminalNode* C8086Parser::Func_definitionContext::RPAREN() {
  return getToken(C8086Parser::RPAREN, 0);
}

C8086Parser::Compound_statementContext* C8086Parser::Func_definitionContext::compound_statement() {
  return getRuleContext<C8086Parser::Compound_statementContext>(0);
}


size_t C8086Parser::Func_definitionContext::getRuleIndex() const {
  return C8086Parser::RuleFunc_definition;
}

void C8086Parser::Func_definitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunc_definition(this);
}

void C8086Parser::Func_definitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunc_definition(this);
}

C8086Parser::Func_definitionContext* C8086Parser::func_definition() {
  Func_definitionContext *_localctx = _tracker.createInstance<Func_definitionContext>(_ctx, getState());
  enterRule(_localctx, 16, C8086Parser::RuleFunc_definition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(158);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(139);
      type_specifier();
      setState(140);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken = match(C8086Parser::ID);
      writeIntoTempFile(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() + " PROC\n");
      setState(142);
      match(C8086Parser::LPAREN);
      setState(143);
      parameter_list(0);
      setState(144);
      match(C8086Parser::RPAREN);
      initializeFunction(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText());
      setState(146);
      compound_statement();

      		restoreBasePointer();
      		writeIntoTempFile(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() + " ENDP\n\n");
      	
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(149);
      type_specifier();
      setState(150);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken = match(C8086Parser::ID);
      writeIntoTempFile(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() + " PROC\n");
      setState(152);
      match(C8086Parser::LPAREN);
      setState(153);
      match(C8086Parser::RPAREN);
      initializeFunction(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText());
      setState(155);
      compound_statement();

      		restoreBasePointer();
      		if (antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() == "main") {
      			exitMainFunction();
      		}
      		writeIntoTempFile(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() + " ENDP\n\n");
      	
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Compound_statementContext ------------------------------------------------------------------

C8086Parser::Compound_statementContext::Compound_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C8086Parser::Compound_statementContext::LCURL() {
  return getToken(C8086Parser::LCURL, 0);
}

C8086Parser::StatementsContext* C8086Parser::Compound_statementContext::statements() {
  return getRuleContext<C8086Parser::StatementsContext>(0);
}

tree::TerminalNode* C8086Parser::Compound_statementContext::RCURL() {
  return getToken(C8086Parser::RCURL, 0);
}


size_t C8086Parser::Compound_statementContext::getRuleIndex() const {
  return C8086Parser::RuleCompound_statement;
}

void C8086Parser::Compound_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompound_statement(this);
}

void C8086Parser::Compound_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompound_statement(this);
}

C8086Parser::Compound_statementContext* C8086Parser::compound_statement() {
  Compound_statementContext *_localctx = _tracker.createInstance<Compound_statementContext>(_ctx, getState());
  enterRule(_localctx, 18, C8086Parser::RuleCompound_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(168);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(160);
      match(C8086Parser::LCURL);
      enterScope();
      setState(162);
      statements(0);
      setState(163);
      match(C8086Parser::RCURL);

      		exitScope();
      	
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(166);
      match(C8086Parser::LCURL);
      setState(167);
      match(C8086Parser::RCURL);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementsContext ------------------------------------------------------------------

C8086Parser::StatementsContext::StatementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::StatementContext* C8086Parser::StatementsContext::statement() {
  return getRuleContext<C8086Parser::StatementContext>(0);
}

C8086Parser::StatementsContext* C8086Parser::StatementsContext::statements() {
  return getRuleContext<C8086Parser::StatementsContext>(0);
}


size_t C8086Parser::StatementsContext::getRuleIndex() const {
  return C8086Parser::RuleStatements;
}

void C8086Parser::StatementsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatements(this);
}

void C8086Parser::StatementsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatements(this);
}


C8086Parser::StatementsContext* C8086Parser::statements() {
   return statements(0);
}

C8086Parser::StatementsContext* C8086Parser::statements(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C8086Parser::StatementsContext *_localctx = _tracker.createInstance<StatementsContext>(_ctx, parentState);
  C8086Parser::StatementsContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 20;
  enterRecursionRule(_localctx, 20, C8086Parser::RuleStatements, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(171);
    statement();
    _ctx->stop = _input->LT(-1);
    setState(177);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<StatementsContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleStatements);
        setState(173);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(174);
        statement(); 
      }
      setState(179);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

C8086Parser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::Var_declarationContext* C8086Parser::StatementContext::var_declaration() {
  return getRuleContext<C8086Parser::Var_declarationContext>(0);
}

std::vector<C8086Parser::Expression_statementContext *> C8086Parser::StatementContext::expression_statement() {
  return getRuleContexts<C8086Parser::Expression_statementContext>();
}

C8086Parser::Expression_statementContext* C8086Parser::StatementContext::expression_statement(size_t i) {
  return getRuleContext<C8086Parser::Expression_statementContext>(i);
}

C8086Parser::Compound_statementContext* C8086Parser::StatementContext::compound_statement() {
  return getRuleContext<C8086Parser::Compound_statementContext>(0);
}

tree::TerminalNode* C8086Parser::StatementContext::FOR() {
  return getToken(C8086Parser::FOR, 0);
}

tree::TerminalNode* C8086Parser::StatementContext::LPAREN() {
  return getToken(C8086Parser::LPAREN, 0);
}

C8086Parser::ExpressionContext* C8086Parser::StatementContext::expression() {
  return getRuleContext<C8086Parser::ExpressionContext>(0);
}

tree::TerminalNode* C8086Parser::StatementContext::RPAREN() {
  return getToken(C8086Parser::RPAREN, 0);
}

std::vector<C8086Parser::StatementContext *> C8086Parser::StatementContext::statement() {
  return getRuleContexts<C8086Parser::StatementContext>();
}

C8086Parser::StatementContext* C8086Parser::StatementContext::statement(size_t i) {
  return getRuleContext<C8086Parser::StatementContext>(i);
}

tree::TerminalNode* C8086Parser::StatementContext::IF() {
  return getToken(C8086Parser::IF, 0);
}

tree::TerminalNode* C8086Parser::StatementContext::ELSE() {
  return getToken(C8086Parser::ELSE, 0);
}

tree::TerminalNode* C8086Parser::StatementContext::WHILE() {
  return getToken(C8086Parser::WHILE, 0);
}

tree::TerminalNode* C8086Parser::StatementContext::PRINTLN() {
  return getToken(C8086Parser::PRINTLN, 0);
}

tree::TerminalNode* C8086Parser::StatementContext::ID() {
  return getToken(C8086Parser::ID, 0);
}

tree::TerminalNode* C8086Parser::StatementContext::SEMICOLON() {
  return getToken(C8086Parser::SEMICOLON, 0);
}

tree::TerminalNode* C8086Parser::StatementContext::RETURN() {
  return getToken(C8086Parser::RETURN, 0);
}


size_t C8086Parser::StatementContext::getRuleIndex() const {
  return C8086Parser::RuleStatement;
}

void C8086Parser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void C8086Parser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}

C8086Parser::StatementContext* C8086Parser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 22, C8086Parser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(221);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(180);
      var_declaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(181);
      expression_statement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(182);
      compound_statement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(183);
      match(C8086Parser::FOR);
      setState(184);
      match(C8086Parser::LPAREN);
      setState(185);
      expression_statement();
      setState(186);
      expression_statement();
      setState(187);
      expression();
      setState(188);
      match(C8086Parser::RPAREN);
      setState(189);
      statement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(191);
      match(C8086Parser::IF);
      setState(192);
      match(C8086Parser::LPAREN);
      setState(193);
      expression();
      setState(194);
      match(C8086Parser::RPAREN);
      setState(195);
      statement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(197);
      match(C8086Parser::IF);
      setState(198);
      match(C8086Parser::LPAREN);
      setState(199);
      expression();
      setState(200);
      match(C8086Parser::RPAREN);
      setState(201);
      statement();
      setState(202);
      match(C8086Parser::ELSE);
      setState(203);
      statement();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(205);
      match(C8086Parser::WHILE);
      setState(206);
      match(C8086Parser::LPAREN);
      setState(207);
      expression();
      setState(208);
      match(C8086Parser::RPAREN);
      setState(209);
      statement();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(211);
      antlrcpp::downCast<StatementContext *>(_localctx)->printlnToken = match(C8086Parser::PRINTLN);
      setState(212);
      match(C8086Parser::LPAREN);
      setState(213);
      antlrcpp::downCast<StatementContext *>(_localctx)->idToken = match(C8086Parser::ID);
      setState(214);
      match(C8086Parser::RPAREN);
      setState(215);
      match(C8086Parser::SEMICOLON);

      		Identifier id;
      		SymbolInfo* symbol = symbolTable.lookUp(antlrcpp::downCast<StatementContext *>(_localctx)->idToken->getText());
      		if (symbol != NULL) {
      			id = symbol->id;
      			printVariable(id, to_string(antlrcpp::downCast<StatementContext *>(_localctx)->printlnToken->getLine()));
      		}else {
      			std::cerr << "Error: Variable '" << antlrcpp::downCast<StatementContext *>(_localctx)->idToken->getText() << "' not declared." << std::endl;
      			exit(EXIT_FAILURE);
      		}
      	
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(217);
      match(C8086Parser::RETURN);
      setState(218);
      expression();
      setState(219);
      match(C8086Parser::SEMICOLON);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expression_statementContext ------------------------------------------------------------------

C8086Parser::Expression_statementContext::Expression_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C8086Parser::Expression_statementContext::SEMICOLON() {
  return getToken(C8086Parser::SEMICOLON, 0);
}

C8086Parser::ExpressionContext* C8086Parser::Expression_statementContext::expression() {
  return getRuleContext<C8086Parser::ExpressionContext>(0);
}


size_t C8086Parser::Expression_statementContext::getRuleIndex() const {
  return C8086Parser::RuleExpression_statement;
}

void C8086Parser::Expression_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression_statement(this);
}

void C8086Parser::Expression_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression_statement(this);
}

C8086Parser::Expression_statementContext* C8086Parser::expression_statement() {
  Expression_statementContext *_localctx = _tracker.createInstance<Expression_statementContext>(_ctx, getState());
  enterRule(_localctx, 24, C8086Parser::RuleExpression_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(227);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C8086Parser::SEMICOLON: {
        enterOuterAlt(_localctx, 1);
        setState(223);
        match(C8086Parser::SEMICOLON);
        break;
      }

      case C8086Parser::LPAREN:
      case C8086Parser::ADDOP:
      case C8086Parser::NOT:
      case C8086Parser::ID:
      case C8086Parser::CONST_INT:
      case C8086Parser::CONST_FLOAT: {
        enterOuterAlt(_localctx, 2);
        setState(224);
        expression();
        setState(225);
        match(C8086Parser::SEMICOLON);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

C8086Parser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::Logic_expressionContext* C8086Parser::ExpressionContext::logic_expression() {
  return getRuleContext<C8086Parser::Logic_expressionContext>(0);
}

C8086Parser::VariableContext* C8086Parser::ExpressionContext::variable() {
  return getRuleContext<C8086Parser::VariableContext>(0);
}

tree::TerminalNode* C8086Parser::ExpressionContext::ASSIGNOP() {
  return getToken(C8086Parser::ASSIGNOP, 0);
}


size_t C8086Parser::ExpressionContext::getRuleIndex() const {
  return C8086Parser::RuleExpression;
}

void C8086Parser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void C8086Parser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}

C8086Parser::ExpressionContext* C8086Parser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 26, C8086Parser::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(237);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(229);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->logic_expressionContext = logic_expression();

      		antlrcpp::downCast<ExpressionContext *>(_localctx)->id =  antlrcpp::downCast<ExpressionContext *>(_localctx)->logic_expressionContext->id;
      	
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(232);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->variableContext = variable();
      setState(233);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->assignopToken = match(C8086Parser::ASSIGNOP);
      setState(234);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->logic_expressionContext = logic_expression();

      		assignVariable(antlrcpp::downCast<ExpressionContext *>(_localctx)->variableContext->id, antlrcpp::downCast<ExpressionContext *>(_localctx)->logic_expressionContext->id, to_string(antlrcpp::downCast<ExpressionContext *>(_localctx)->assignopToken->getLine()));
      	
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Logic_expressionContext ------------------------------------------------------------------

C8086Parser::Logic_expressionContext::Logic_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<C8086Parser::Rel_expressionContext *> C8086Parser::Logic_expressionContext::rel_expression() {
  return getRuleContexts<C8086Parser::Rel_expressionContext>();
}

C8086Parser::Rel_expressionContext* C8086Parser::Logic_expressionContext::rel_expression(size_t i) {
  return getRuleContext<C8086Parser::Rel_expressionContext>(i);
}

tree::TerminalNode* C8086Parser::Logic_expressionContext::LOGICOP() {
  return getToken(C8086Parser::LOGICOP, 0);
}


size_t C8086Parser::Logic_expressionContext::getRuleIndex() const {
  return C8086Parser::RuleLogic_expression;
}

void C8086Parser::Logic_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogic_expression(this);
}

void C8086Parser::Logic_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogic_expression(this);
}

C8086Parser::Logic_expressionContext* C8086Parser::logic_expression() {
  Logic_expressionContext *_localctx = _tracker.createInstance<Logic_expressionContext>(_ctx, getState());
  enterRule(_localctx, 28, C8086Parser::RuleLogic_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(247);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(239);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->rel_expressionContext = rel_expression();

              antlrcpp::downCast<Logic_expressionContext *>(_localctx)->id =  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->rel_expressionContext->id;
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(242);
      rel_expression();
      setState(243);
      match(C8086Parser::LOGICOP);
      setState(244);
      rel_expression();

      		// handle this case later
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Rel_expressionContext ------------------------------------------------------------------

C8086Parser::Rel_expressionContext::Rel_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<C8086Parser::Simple_expressionContext *> C8086Parser::Rel_expressionContext::simple_expression() {
  return getRuleContexts<C8086Parser::Simple_expressionContext>();
}

C8086Parser::Simple_expressionContext* C8086Parser::Rel_expressionContext::simple_expression(size_t i) {
  return getRuleContext<C8086Parser::Simple_expressionContext>(i);
}

tree::TerminalNode* C8086Parser::Rel_expressionContext::RELOP() {
  return getToken(C8086Parser::RELOP, 0);
}


size_t C8086Parser::Rel_expressionContext::getRuleIndex() const {
  return C8086Parser::RuleRel_expression;
}

void C8086Parser::Rel_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRel_expression(this);
}

void C8086Parser::Rel_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRel_expression(this);
}

C8086Parser::Rel_expressionContext* C8086Parser::rel_expression() {
  Rel_expressionContext *_localctx = _tracker.createInstance<Rel_expressionContext>(_ctx, getState());
  enterRule(_localctx, 30, C8086Parser::RuleRel_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(257);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(249);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->simple_expressionContext = simple_expression(0);

      		antlrcpp::downCast<Rel_expressionContext *>(_localctx)->id =  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->simple_expressionContext->id;
      	
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(252);
      simple_expression(0);
      setState(253);
      match(C8086Parser::RELOP);
      setState(254);
      simple_expression(0);

      		// handle this case later
      	
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Simple_expressionContext ------------------------------------------------------------------

C8086Parser::Simple_expressionContext::Simple_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::TermContext* C8086Parser::Simple_expressionContext::term() {
  return getRuleContext<C8086Parser::TermContext>(0);
}

C8086Parser::Simple_expressionContext* C8086Parser::Simple_expressionContext::simple_expression() {
  return getRuleContext<C8086Parser::Simple_expressionContext>(0);
}

tree::TerminalNode* C8086Parser::Simple_expressionContext::ADDOP() {
  return getToken(C8086Parser::ADDOP, 0);
}


size_t C8086Parser::Simple_expressionContext::getRuleIndex() const {
  return C8086Parser::RuleSimple_expression;
}

void C8086Parser::Simple_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimple_expression(this);
}

void C8086Parser::Simple_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimple_expression(this);
}


C8086Parser::Simple_expressionContext* C8086Parser::simple_expression() {
   return simple_expression(0);
}

C8086Parser::Simple_expressionContext* C8086Parser::simple_expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C8086Parser::Simple_expressionContext *_localctx = _tracker.createInstance<Simple_expressionContext>(_ctx, parentState);
  C8086Parser::Simple_expressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 32;
  enterRecursionRule(_localctx, 32, C8086Parser::RuleSimple_expression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(260);
    antlrcpp::downCast<Simple_expressionContext *>(_localctx)->termContext = term(0);

            antlrcpp::downCast<Simple_expressionContext *>(_localctx)->id =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->termContext->id;
        
    _ctx->stop = _input->LT(-1);
    setState(270);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Simple_expressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleSimple_expression);
        setState(263);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(264);
        match(C8086Parser::ADDOP);
        setState(265);
        antlrcpp::downCast<Simple_expressionContext *>(_localctx)->termContext = term(0);

                  		// handle this case later
                       
      }
      setState(272);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- TermContext ------------------------------------------------------------------

C8086Parser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::Unary_expressionContext* C8086Parser::TermContext::unary_expression() {
  return getRuleContext<C8086Parser::Unary_expressionContext>(0);
}

C8086Parser::TermContext* C8086Parser::TermContext::term() {
  return getRuleContext<C8086Parser::TermContext>(0);
}

tree::TerminalNode* C8086Parser::TermContext::MULOP() {
  return getToken(C8086Parser::MULOP, 0);
}


size_t C8086Parser::TermContext::getRuleIndex() const {
  return C8086Parser::RuleTerm;
}

void C8086Parser::TermContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTerm(this);
}

void C8086Parser::TermContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTerm(this);
}


C8086Parser::TermContext* C8086Parser::term() {
   return term(0);
}

C8086Parser::TermContext* C8086Parser::term(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C8086Parser::TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, parentState);
  C8086Parser::TermContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 34;
  enterRecursionRule(_localctx, 34, C8086Parser::RuleTerm, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(274);
    antlrcpp::downCast<TermContext *>(_localctx)->unary_expressionContext = unary_expression();

    		antlrcpp::downCast<TermContext *>(_localctx)->id =  antlrcpp::downCast<TermContext *>(_localctx)->unary_expressionContext->id;
    	
    _ctx->stop = _input->LT(-1);
    setState(284);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<TermContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleTerm);
        setState(277);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(278);
        match(C8086Parser::MULOP);
        setState(279);
        antlrcpp::downCast<TermContext *>(_localctx)->unary_expressionContext = unary_expression();

                  		// handle this case later
                  	 
      }
      setState(286);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Unary_expressionContext ------------------------------------------------------------------

C8086Parser::Unary_expressionContext::Unary_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C8086Parser::Unary_expressionContext::ADDOP() {
  return getToken(C8086Parser::ADDOP, 0);
}

C8086Parser::Unary_expressionContext* C8086Parser::Unary_expressionContext::unary_expression() {
  return getRuleContext<C8086Parser::Unary_expressionContext>(0);
}

tree::TerminalNode* C8086Parser::Unary_expressionContext::NOT() {
  return getToken(C8086Parser::NOT, 0);
}

C8086Parser::FactorContext* C8086Parser::Unary_expressionContext::factor() {
  return getRuleContext<C8086Parser::FactorContext>(0);
}


size_t C8086Parser::Unary_expressionContext::getRuleIndex() const {
  return C8086Parser::RuleUnary_expression;
}

void C8086Parser::Unary_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnary_expression(this);
}

void C8086Parser::Unary_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnary_expression(this);
}

C8086Parser::Unary_expressionContext* C8086Parser::unary_expression() {
  Unary_expressionContext *_localctx = _tracker.createInstance<Unary_expressionContext>(_ctx, getState());
  enterRule(_localctx, 36, C8086Parser::RuleUnary_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(294);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C8086Parser::ADDOP: {
        enterOuterAlt(_localctx, 1);
        setState(287);
        match(C8086Parser::ADDOP);
        setState(288);
        unary_expression();
        break;
      }

      case C8086Parser::NOT: {
        enterOuterAlt(_localctx, 2);
        setState(289);
        match(C8086Parser::NOT);
        setState(290);
        unary_expression();
        break;
      }

      case C8086Parser::LPAREN:
      case C8086Parser::ID:
      case C8086Parser::CONST_INT:
      case C8086Parser::CONST_FLOAT: {
        enterOuterAlt(_localctx, 3);
        setState(291);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->factorContext = factor();

        		antlrcpp::downCast<Unary_expressionContext *>(_localctx)->id =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->factorContext->id;
        	
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FactorContext ------------------------------------------------------------------

C8086Parser::FactorContext::FactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::VariableContext* C8086Parser::FactorContext::variable() {
  return getRuleContext<C8086Parser::VariableContext>(0);
}

tree::TerminalNode* C8086Parser::FactorContext::ID() {
  return getToken(C8086Parser::ID, 0);
}

tree::TerminalNode* C8086Parser::FactorContext::LPAREN() {
  return getToken(C8086Parser::LPAREN, 0);
}

C8086Parser::Argument_listContext* C8086Parser::FactorContext::argument_list() {
  return getRuleContext<C8086Parser::Argument_listContext>(0);
}

tree::TerminalNode* C8086Parser::FactorContext::RPAREN() {
  return getToken(C8086Parser::RPAREN, 0);
}

C8086Parser::ExpressionContext* C8086Parser::FactorContext::expression() {
  return getRuleContext<C8086Parser::ExpressionContext>(0);
}

tree::TerminalNode* C8086Parser::FactorContext::CONST_INT() {
  return getToken(C8086Parser::CONST_INT, 0);
}

tree::TerminalNode* C8086Parser::FactorContext::CONST_FLOAT() {
  return getToken(C8086Parser::CONST_FLOAT, 0);
}

tree::TerminalNode* C8086Parser::FactorContext::INCOP() {
  return getToken(C8086Parser::INCOP, 0);
}

tree::TerminalNode* C8086Parser::FactorContext::DECOP() {
  return getToken(C8086Parser::DECOP, 0);
}


size_t C8086Parser::FactorContext::getRuleIndex() const {
  return C8086Parser::RuleFactor;
}

void C8086Parser::FactorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFactor(this);
}

void C8086Parser::FactorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFactor(this);
}

C8086Parser::FactorContext* C8086Parser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 38, C8086Parser::RuleFactor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(315);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(296);
      variable();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(297);
      match(C8086Parser::ID);
      setState(298);
      match(C8086Parser::LPAREN);
      setState(299);
      argument_list();
      setState(300);
      match(C8086Parser::RPAREN);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(302);
      match(C8086Parser::LPAREN);
      setState(303);
      expression();
      setState(304);
      match(C8086Parser::RPAREN);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(306);
      antlrcpp::downCast<FactorContext *>(_localctx)->const_intToken = match(C8086Parser::CONST_INT);

      		Identifier id;
      		id.constValue = antlrcpp::downCast<FactorContext *>(_localctx)->const_intToken->getText();
      		antlrcpp::downCast<FactorContext *>(_localctx)->id =  id;
      	
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(308);
      match(C8086Parser::CONST_FLOAT);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(309);
      variable();
      setState(310);
      match(C8086Parser::INCOP);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(312);
      variable();
      setState(313);
      match(C8086Parser::DECOP);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableContext ------------------------------------------------------------------

C8086Parser::VariableContext::VariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C8086Parser::VariableContext::ID() {
  return getToken(C8086Parser::ID, 0);
}

tree::TerminalNode* C8086Parser::VariableContext::LTHIRD() {
  return getToken(C8086Parser::LTHIRD, 0);
}

tree::TerminalNode* C8086Parser::VariableContext::RTHIRD() {
  return getToken(C8086Parser::RTHIRD, 0);
}

C8086Parser::ExpressionContext* C8086Parser::VariableContext::expression() {
  return getRuleContext<C8086Parser::ExpressionContext>(0);
}


size_t C8086Parser::VariableContext::getRuleIndex() const {
  return C8086Parser::RuleVariable;
}

void C8086Parser::VariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable(this);
}

void C8086Parser::VariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable(this);
}

C8086Parser::VariableContext* C8086Parser::variable() {
  VariableContext *_localctx = _tracker.createInstance<VariableContext>(_ctx, getState());
  enterRule(_localctx, 40, C8086Parser::RuleVariable);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(325);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(317);
      antlrcpp::downCast<VariableContext *>(_localctx)->idToken = match(C8086Parser::ID);

      		SymbolInfo* symbol = symbolTable.lookUp(antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText());
      		if (symbol != NULL) {
      			antlrcpp::downCast<VariableContext *>(_localctx)->id =  symbol->id;
      		}
      		else {
      			std::cerr << "Error: Variable '" << antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText() << "' not declared." << std::endl;
      			exit(EXIT_FAILURE);
      		}
      	
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(319);
      antlrcpp::downCast<VariableContext *>(_localctx)->idToken = match(C8086Parser::ID);
      setState(320);
      match(C8086Parser::LTHIRD);
      setState(321);
      antlrcpp::downCast<VariableContext *>(_localctx)->e = expression();
      setState(322);
      match(C8086Parser::RTHIRD);

      		SymbolInfo* symbol = symbolTable.lookUp(antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText());
      		if (symbol != NULL) {
      			antlrcpp::downCast<VariableContext *>(_localctx)->id =  symbol->id;
      			_localctx->id.isArray = true;
      			_localctx->id.arrayIndex = antlrcpp::downCast<VariableContext *>(_localctx)->e->id.constValue; 
      		}
      		else {
      			std::cerr << "Error: Variable '" << antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText() << "' not declared." << std::endl;
      			exit(EXIT_FAILURE);
      		}
      	
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Argument_listContext ------------------------------------------------------------------

C8086Parser::Argument_listContext::Argument_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::ArgumentsContext* C8086Parser::Argument_listContext::arguments() {
  return getRuleContext<C8086Parser::ArgumentsContext>(0);
}


size_t C8086Parser::Argument_listContext::getRuleIndex() const {
  return C8086Parser::RuleArgument_list;
}

void C8086Parser::Argument_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArgument_list(this);
}

void C8086Parser::Argument_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArgument_list(this);
}

C8086Parser::Argument_listContext* C8086Parser::argument_list() {
  Argument_listContext *_localctx = _tracker.createInstance<Argument_listContext>(_ctx, getState());
  enterRule(_localctx, 42, C8086Parser::RuleArgument_list);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(329);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C8086Parser::LPAREN:
      case C8086Parser::ADDOP:
      case C8086Parser::NOT:
      case C8086Parser::ID:
      case C8086Parser::CONST_INT:
      case C8086Parser::CONST_FLOAT: {
        enterOuterAlt(_localctx, 1);
        setState(327);
        arguments(0);
        break;
      }

      case C8086Parser::RPAREN: {
        enterOuterAlt(_localctx, 2);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentsContext ------------------------------------------------------------------

C8086Parser::ArgumentsContext::ArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::Logic_expressionContext* C8086Parser::ArgumentsContext::logic_expression() {
  return getRuleContext<C8086Parser::Logic_expressionContext>(0);
}

C8086Parser::ArgumentsContext* C8086Parser::ArgumentsContext::arguments() {
  return getRuleContext<C8086Parser::ArgumentsContext>(0);
}

tree::TerminalNode* C8086Parser::ArgumentsContext::COMMA() {
  return getToken(C8086Parser::COMMA, 0);
}


size_t C8086Parser::ArgumentsContext::getRuleIndex() const {
  return C8086Parser::RuleArguments;
}

void C8086Parser::ArgumentsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArguments(this);
}

void C8086Parser::ArgumentsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArguments(this);
}


C8086Parser::ArgumentsContext* C8086Parser::arguments() {
   return arguments(0);
}

C8086Parser::ArgumentsContext* C8086Parser::arguments(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C8086Parser::ArgumentsContext *_localctx = _tracker.createInstance<ArgumentsContext>(_ctx, parentState);
  C8086Parser::ArgumentsContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 44;
  enterRecursionRule(_localctx, 44, C8086Parser::RuleArguments, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(332);
    logic_expression();
    _ctx->stop = _input->LT(-1);
    setState(339);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ArgumentsContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleArguments);
        setState(334);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(335);
        match(C8086Parser::COMMA);
        setState(336);
        logic_expression(); 
      }
      setState(341);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool C8086Parser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return programSempred(antlrcpp::downCast<ProgramContext *>(context), predicateIndex);
    case 4: return declaration_listSempred(antlrcpp::downCast<Declaration_listContext *>(context), predicateIndex);
    case 6: return parameter_listSempred(antlrcpp::downCast<Parameter_listContext *>(context), predicateIndex);
    case 10: return statementsSempred(antlrcpp::downCast<StatementsContext *>(context), predicateIndex);
    case 16: return simple_expressionSempred(antlrcpp::downCast<Simple_expressionContext *>(context), predicateIndex);
    case 17: return termSempred(antlrcpp::downCast<TermContext *>(context), predicateIndex);
    case 22: return argumentsSempred(antlrcpp::downCast<ArgumentsContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool C8086Parser::programSempred(ProgramContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool C8086Parser::declaration_listSempred(Declaration_listContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 4);
    case 2: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

bool C8086Parser::parameter_listSempred(Parameter_listContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return precpred(_ctx, 4);
    case 4: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

bool C8086Parser::statementsSempred(StatementsContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 5: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool C8086Parser::simple_expressionSempred(Simple_expressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 6: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool C8086Parser::termSempred(TermContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 7: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool C8086Parser::argumentsSempred(ArgumentsContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 8: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

void C8086Parser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  c8086parserParserInitialize();
#else
  ::antlr4::internal::call_once(c8086parserParserOnceFlag, c8086parserParserInitialize);
#endif
}
