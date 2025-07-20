
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
  	4,1,33,374,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,5,1,56,8,1,10,1,12,1,
  	59,9,1,1,2,1,2,1,2,3,2,64,8,2,1,3,1,3,1,3,1,3,1,3,1,3,3,3,72,8,3,1,4,
  	1,4,1,4,1,4,1,4,1,4,1,4,1,4,3,4,82,8,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,
  	4,1,4,1,4,1,4,5,4,95,8,4,10,4,12,4,98,9,4,1,5,1,5,1,5,1,5,1,5,1,6,1,6,
  	1,6,1,6,1,6,1,6,3,6,111,8,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,5,6,122,
  	8,6,10,6,12,6,125,9,6,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,
  	1,7,3,7,140,8,7,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,
  	8,1,8,1,8,1,8,1,8,1,8,3,8,161,8,8,1,9,1,9,1,9,1,9,1,9,1,9,3,9,169,8,9,
  	1,10,1,10,1,10,1,10,1,10,5,10,176,8,10,10,10,12,10,179,9,10,1,11,1,11,
  	1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,
  	1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,
  	1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,
  	1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,3,11,237,
  	8,11,1,12,1,12,1,12,1,12,1,12,1,12,3,12,245,8,12,1,13,1,13,1,13,1,13,
  	1,13,1,13,1,13,1,13,3,13,255,8,13,1,14,1,14,1,14,1,14,1,14,1,14,1,14,
  	1,14,1,14,3,14,266,8,14,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,3,15,
  	276,8,15,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,5,16,287,8,16,10,
  	16,12,16,290,9,16,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,5,17,301,
  	8,17,10,17,12,17,304,9,17,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,
  	3,18,315,8,18,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,
  	1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,
  	3,19,342,8,19,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,3,20,352,8,20,1,
  	21,1,21,1,21,1,21,3,21,358,8,21,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,
  	22,1,22,5,22,369,8,22,10,22,12,22,372,9,22,1,22,0,7,2,8,12,20,32,34,44,
  	23,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,0,
  	0,390,0,46,1,0,0,0,2,50,1,0,0,0,4,63,1,0,0,0,6,71,1,0,0,0,8,81,1,0,0,
  	0,10,99,1,0,0,0,12,110,1,0,0,0,14,139,1,0,0,0,16,160,1,0,0,0,18,168,1,
  	0,0,0,20,170,1,0,0,0,22,236,1,0,0,0,24,244,1,0,0,0,26,254,1,0,0,0,28,
  	265,1,0,0,0,30,275,1,0,0,0,32,277,1,0,0,0,34,291,1,0,0,0,36,314,1,0,0,
  	0,38,341,1,0,0,0,40,351,1,0,0,0,42,357,1,0,0,0,44,359,1,0,0,0,46,47,6,
  	0,-1,0,47,48,3,2,1,0,48,49,6,0,-1,0,49,1,1,0,0,0,50,51,6,1,-1,0,51,52,
  	3,4,2,0,52,57,1,0,0,0,53,54,10,2,0,0,54,56,3,4,2,0,55,53,1,0,0,0,56,59,
  	1,0,0,0,57,55,1,0,0,0,57,58,1,0,0,0,58,3,1,0,0,0,59,57,1,0,0,0,60,64,
  	3,10,5,0,61,64,3,14,7,0,62,64,3,16,8,0,63,60,1,0,0,0,63,61,1,0,0,0,63,
  	62,1,0,0,0,64,5,1,0,0,0,65,66,5,11,0,0,66,72,6,3,-1,0,67,68,5,12,0,0,
  	68,72,6,3,-1,0,69,70,5,13,0,0,70,72,6,3,-1,0,71,65,1,0,0,0,71,67,1,0,
  	0,0,71,69,1,0,0,0,72,7,1,0,0,0,73,74,6,4,-1,0,74,75,5,31,0,0,75,82,6,
  	4,-1,0,76,77,5,31,0,0,77,78,5,18,0,0,78,79,5,32,0,0,79,80,5,19,0,0,80,
  	82,6,4,-1,0,81,73,1,0,0,0,81,76,1,0,0,0,82,96,1,0,0,0,83,84,10,4,0,0,
  	84,85,5,21,0,0,85,86,5,31,0,0,86,95,6,4,-1,0,87,88,10,3,0,0,88,89,5,21,
  	0,0,89,90,5,31,0,0,90,91,5,18,0,0,91,92,5,32,0,0,92,93,5,19,0,0,93,95,
  	6,4,-1,0,94,83,1,0,0,0,94,87,1,0,0,0,95,98,1,0,0,0,96,94,1,0,0,0,96,97,
  	1,0,0,0,97,9,1,0,0,0,98,96,1,0,0,0,99,100,3,6,3,0,100,101,3,8,4,0,101,
  	102,5,20,0,0,102,103,6,5,-1,0,103,11,1,0,0,0,104,105,6,6,-1,0,105,106,
  	3,6,3,0,106,107,5,31,0,0,107,108,6,6,-1,0,108,111,1,0,0,0,109,111,3,6,
  	3,0,110,104,1,0,0,0,110,109,1,0,0,0,111,123,1,0,0,0,112,113,10,4,0,0,
  	113,114,5,21,0,0,114,115,3,6,3,0,115,116,5,31,0,0,116,117,6,6,-1,0,117,
  	122,1,0,0,0,118,119,10,3,0,0,119,120,5,21,0,0,120,122,3,6,3,0,121,112,
  	1,0,0,0,121,118,1,0,0,0,122,125,1,0,0,0,123,121,1,0,0,0,123,124,1,0,0,
  	0,124,13,1,0,0,0,125,123,1,0,0,0,126,127,3,6,3,0,127,128,5,31,0,0,128,
  	129,5,14,0,0,129,130,3,12,6,0,130,131,5,15,0,0,131,132,5,20,0,0,132,140,
  	1,0,0,0,133,134,3,6,3,0,134,135,5,31,0,0,135,136,5,14,0,0,136,137,5,15,
  	0,0,137,138,5,20,0,0,138,140,1,0,0,0,139,126,1,0,0,0,139,133,1,0,0,0,
  	140,15,1,0,0,0,141,142,3,6,3,0,142,143,5,31,0,0,143,144,6,8,-1,0,144,
  	145,5,14,0,0,145,146,3,12,6,0,146,147,6,8,-1,0,147,148,5,15,0,0,148,149,
  	3,18,9,0,149,150,6,8,-1,0,150,161,1,0,0,0,151,152,3,6,3,0,152,153,5,31,
  	0,0,153,154,6,8,-1,0,154,155,5,14,0,0,155,156,5,15,0,0,156,157,6,8,-1,
  	0,157,158,3,18,9,0,158,159,6,8,-1,0,159,161,1,0,0,0,160,141,1,0,0,0,160,
  	151,1,0,0,0,161,17,1,0,0,0,162,163,5,16,0,0,163,164,3,20,10,0,164,165,
  	5,17,0,0,165,169,1,0,0,0,166,167,5,16,0,0,167,169,5,17,0,0,168,162,1,
  	0,0,0,168,166,1,0,0,0,169,19,1,0,0,0,170,171,6,10,-1,0,171,172,3,22,11,
  	0,172,177,1,0,0,0,173,174,10,1,0,0,174,176,3,22,11,0,175,173,1,0,0,0,
  	176,179,1,0,0,0,177,175,1,0,0,0,177,178,1,0,0,0,178,21,1,0,0,0,179,177,
  	1,0,0,0,180,237,3,10,5,0,181,237,3,24,12,0,182,237,3,18,9,0,183,184,5,
  	7,0,0,184,185,6,11,-1,0,185,186,5,14,0,0,186,187,3,24,12,0,187,188,3,
  	24,12,0,188,189,6,11,-1,0,189,190,6,11,-1,0,190,191,3,26,13,0,191,192,
  	6,11,-1,0,192,193,5,15,0,0,193,194,6,11,-1,0,194,195,3,22,11,0,195,196,
  	6,11,-1,0,196,237,1,0,0,0,197,198,5,5,0,0,198,199,5,14,0,0,199,200,3,
  	26,13,0,200,201,6,11,-1,0,201,202,5,15,0,0,202,203,3,22,11,0,203,204,
  	6,11,-1,0,204,237,1,0,0,0,205,206,5,5,0,0,206,207,5,14,0,0,207,208,3,
  	26,13,0,208,209,6,11,-1,0,209,210,5,15,0,0,210,211,3,22,11,0,211,212,
  	6,11,-1,0,212,213,5,6,0,0,213,214,3,22,11,0,214,215,6,11,-1,0,215,237,
  	1,0,0,0,216,217,5,8,0,0,217,218,5,14,0,0,218,219,3,26,13,0,219,220,6,
  	11,-1,0,220,221,5,15,0,0,221,222,6,11,-1,0,222,223,3,22,11,0,223,224,
  	6,11,-1,0,224,237,1,0,0,0,225,226,5,9,0,0,226,227,5,14,0,0,227,228,5,
  	31,0,0,228,229,5,15,0,0,229,230,5,20,0,0,230,237,6,11,-1,0,231,232,5,
  	10,0,0,232,233,3,26,13,0,233,234,5,20,0,0,234,235,6,11,-1,0,235,237,1,
  	0,0,0,236,180,1,0,0,0,236,181,1,0,0,0,236,182,1,0,0,0,236,183,1,0,0,0,
  	236,197,1,0,0,0,236,205,1,0,0,0,236,216,1,0,0,0,236,225,1,0,0,0,236,231,
  	1,0,0,0,237,23,1,0,0,0,238,239,5,20,0,0,239,245,6,12,-1,0,240,241,3,26,
  	13,0,241,242,5,20,0,0,242,243,6,12,-1,0,243,245,1,0,0,0,244,238,1,0,0,
  	0,244,240,1,0,0,0,245,25,1,0,0,0,246,247,3,28,14,0,247,248,6,13,-1,0,
  	248,255,1,0,0,0,249,250,3,40,20,0,250,251,5,30,0,0,251,252,3,28,14,0,
  	252,253,6,13,-1,0,253,255,1,0,0,0,254,246,1,0,0,0,254,249,1,0,0,0,255,
  	27,1,0,0,0,256,257,3,30,15,0,257,258,6,14,-1,0,258,266,1,0,0,0,259,260,
  	3,30,15,0,260,261,6,14,-1,0,261,262,5,29,0,0,262,263,3,30,15,0,263,264,
  	6,14,-1,0,264,266,1,0,0,0,265,256,1,0,0,0,265,259,1,0,0,0,266,29,1,0,
  	0,0,267,268,3,32,16,0,268,269,6,15,-1,0,269,276,1,0,0,0,270,271,3,32,
  	16,0,271,272,5,28,0,0,272,273,3,32,16,0,273,274,6,15,-1,0,274,276,1,0,
  	0,0,275,267,1,0,0,0,275,270,1,0,0,0,276,31,1,0,0,0,277,278,6,16,-1,0,
  	278,279,3,34,17,0,279,280,6,16,-1,0,280,288,1,0,0,0,281,282,10,1,0,0,
  	282,283,5,22,0,0,283,284,3,34,17,0,284,285,6,16,-1,0,285,287,1,0,0,0,
  	286,281,1,0,0,0,287,290,1,0,0,0,288,286,1,0,0,0,288,289,1,0,0,0,289,33,
  	1,0,0,0,290,288,1,0,0,0,291,292,6,17,-1,0,292,293,3,36,18,0,293,294,6,
  	17,-1,0,294,302,1,0,0,0,295,296,10,1,0,0,296,297,5,24,0,0,297,298,3,36,
  	18,0,298,299,6,17,-1,0,299,301,1,0,0,0,300,295,1,0,0,0,301,304,1,0,0,
  	0,302,300,1,0,0,0,302,303,1,0,0,0,303,35,1,0,0,0,304,302,1,0,0,0,305,
  	306,5,22,0,0,306,307,3,36,18,0,307,308,6,18,-1,0,308,315,1,0,0,0,309,
  	310,5,27,0,0,310,315,3,36,18,0,311,312,3,38,19,0,312,313,6,18,-1,0,313,
  	315,1,0,0,0,314,305,1,0,0,0,314,309,1,0,0,0,314,311,1,0,0,0,315,37,1,
  	0,0,0,316,317,3,40,20,0,317,318,6,19,-1,0,318,342,1,0,0,0,319,320,5,31,
  	0,0,320,321,5,14,0,0,321,322,3,42,21,0,322,323,5,15,0,0,323,324,6,19,
  	-1,0,324,342,1,0,0,0,325,326,5,14,0,0,326,327,3,26,13,0,327,328,5,15,
  	0,0,328,329,6,19,-1,0,329,342,1,0,0,0,330,331,5,32,0,0,331,342,6,19,-1,
  	0,332,342,5,33,0,0,333,334,3,40,20,0,334,335,5,25,0,0,335,336,6,19,-1,
  	0,336,342,1,0,0,0,337,338,3,40,20,0,338,339,5,26,0,0,339,340,6,19,-1,
  	0,340,342,1,0,0,0,341,316,1,0,0,0,341,319,1,0,0,0,341,325,1,0,0,0,341,
  	330,1,0,0,0,341,332,1,0,0,0,341,333,1,0,0,0,341,337,1,0,0,0,342,39,1,
  	0,0,0,343,344,5,31,0,0,344,352,6,20,-1,0,345,346,5,31,0,0,346,347,5,18,
  	0,0,347,348,3,26,13,0,348,349,5,19,0,0,349,350,6,20,-1,0,350,352,1,0,
  	0,0,351,343,1,0,0,0,351,345,1,0,0,0,352,41,1,0,0,0,353,354,3,44,22,0,
  	354,355,6,21,-1,0,355,358,1,0,0,0,356,358,1,0,0,0,357,353,1,0,0,0,357,
  	356,1,0,0,0,358,43,1,0,0,0,359,360,6,22,-1,0,360,361,3,28,14,0,361,362,
  	6,22,-1,0,362,370,1,0,0,0,363,364,10,2,0,0,364,365,5,21,0,0,365,366,3,
  	28,14,0,366,367,6,22,-1,0,367,369,1,0,0,0,368,363,1,0,0,0,369,372,1,0,
  	0,0,370,368,1,0,0,0,370,371,1,0,0,0,371,45,1,0,0,0,372,370,1,0,0,0,25,
  	57,63,71,81,94,96,110,121,123,139,160,168,177,236,244,254,265,275,288,
  	302,314,341,351,357,370
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
    		moveMainProcAfterCode(tempFileName);
            mergeTempFileToCodeFile();
    		cleanFileFromNonText(codeFileName);
    		cleanFileFromNonText(optCodeFileName);
    		cleanFileFromNonText(tempFileName);
        
   
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

tree::TerminalNode* C8086Parser::Parameter_listContext::ID() {
  return getToken(C8086Parser::ID, 0);
}

C8086Parser::Type_specifierContext* C8086Parser::Parameter_listContext::type_specifier() {
  return getRuleContext<C8086Parser::Type_specifierContext>(0);
}

tree::TerminalNode* C8086Parser::Parameter_listContext::COMMA() {
  return getToken(C8086Parser::COMMA, 0);
}

C8086Parser::Parameter_listContext* C8086Parser::Parameter_listContext::parameter_list() {
  return getRuleContext<C8086Parser::Parameter_listContext>(0);
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
    setState(110);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      setState(105);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->t = type_specifier();
      setState(106);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken = match(C8086Parser::ID);

      		Identifier id;
      		id.idName = antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken->getText();
      		id.idType = antlrcpp::downCast<Parameter_listContext *>(_localctx)->t->type;
      		_localctx->ids.add(id);
      	
      break;
    }

    case 2: {
      setState(109);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->t = type_specifier();
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(123);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(121);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<Parameter_listContext>(parentContext, parentState);
          _localctx->pl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleParameter_list);
          setState(112);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(113);
          match(C8086Parser::COMMA);
          setState(114);
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts = type_specifier();
          setState(115);
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken = match(C8086Parser::ID);

                            antlrcpp::downCast<Parameter_listContext *>(_localctx)->ids =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->pl->ids;
                    		Identifier id;
                    		id.idName = antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken->getText();
                    		id.idType = antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->type;
                            _localctx->ids.add(id);		
                    	
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<Parameter_listContext>(parentContext, parentState);
          _localctx->pl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleParameter_list);
          setState(118);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(119);
          match(C8086Parser::COMMA);
          setState(120);
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts = type_specifier();
          break;
        }

        default:
          break;
        } 
      }
      setState(125);
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
    setState(139);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(126);
      type_specifier();
      setState(127);
      match(C8086Parser::ID);
      setState(128);
      match(C8086Parser::LPAREN);
      setState(129);
      parameter_list(0);
      setState(130);
      match(C8086Parser::RPAREN);
      setState(131);
      match(C8086Parser::SEMICOLON);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(133);
      type_specifier();
      setState(134);
      match(C8086Parser::ID);
      setState(135);
      match(C8086Parser::LPAREN);
      setState(136);
      match(C8086Parser::RPAREN);
      setState(137);
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

tree::TerminalNode* C8086Parser::Func_definitionContext::ID() {
  return getToken(C8086Parser::ID, 0);
}

tree::TerminalNode* C8086Parser::Func_definitionContext::LPAREN() {
  return getToken(C8086Parser::LPAREN, 0);
}

tree::TerminalNode* C8086Parser::Func_definitionContext::RPAREN() {
  return getToken(C8086Parser::RPAREN, 0);
}

C8086Parser::Compound_statementContext* C8086Parser::Func_definitionContext::compound_statement() {
  return getRuleContext<C8086Parser::Compound_statementContext>(0);
}

C8086Parser::Type_specifierContext* C8086Parser::Func_definitionContext::type_specifier() {
  return getRuleContext<C8086Parser::Type_specifierContext>(0);
}

C8086Parser::Parameter_listContext* C8086Parser::Func_definitionContext::parameter_list() {
  return getRuleContext<C8086Parser::Parameter_listContext>(0);
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
    setState(160);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(141);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->t = type_specifier();
      setState(142);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken = match(C8086Parser::ID);
      writeIntoTempFile(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() + " PROC\n");enterScope(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText(),antlrcpp::downCast<Func_definitionContext *>(_localctx)->t->type);
      setState(144);
      match(C8086Parser::LPAREN);
      setState(145);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->pl = parameter_list(0);
      parameterDeclaration(antlrcpp::downCast<Func_definitionContext *>(_localctx)->pl->ids,std::to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getLine()));
      setState(147);
      match(C8086Parser::RPAREN);
      setState(148);
      compound_statement();

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
      		writeIntoTempFile(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() + " ENDP\n\n");
      		numberOfArguments = 0;
      		symbolTable.exitScope();
      	
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(151);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->t = type_specifier();
      setState(152);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken = match(C8086Parser::ID);
      writeIntoTempFile(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() + " PROC\n");
      setState(154);
      match(C8086Parser::LPAREN);
      setState(155);
      match(C8086Parser::RPAREN);
      initializeMainFunction(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText());enterScope(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText(),antlrcpp::downCast<Func_definitionContext *>(_localctx)->t->type);
      setState(157);
      compound_statement();

      		if(!isReturned) {
      			exitScope();
      			if (antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() == "main") {
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
      		writeIntoTempFile(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() + " ENDP\n\n");
      		numberOfArguments = 0;
      		symbolTable.exitScope();
      	
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
      setState(162);
      match(C8086Parser::LCURL);
      setState(163);
      statements(0);
      setState(164);
      match(C8086Parser::RCURL);
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

tree::TerminalNode* C8086Parser::StatementContext::RPAREN() {
  return getToken(C8086Parser::RPAREN, 0);
}

std::vector<C8086Parser::StatementContext *> C8086Parser::StatementContext::statement() {
  return getRuleContexts<C8086Parser::StatementContext>();
}

C8086Parser::StatementContext* C8086Parser::StatementContext::statement(size_t i) {
  return getRuleContext<C8086Parser::StatementContext>(i);
}

C8086Parser::ExpressionContext* C8086Parser::StatementContext::expression() {
  return getRuleContext<C8086Parser::ExpressionContext>(0);
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
    setState(236);
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
      antlrcpp::downCast<StatementContext *>(_localctx)->forToken = match(C8086Parser::FOR);
      setLoopLabels();
      setState(185);
      match(C8086Parser::LPAREN);
      setState(186);
      expression_statement();
      setState(187);
      antlrcpp::downCast<StatementContext *>(_localctx)->es = expression_statement();

      		antlrcpp::downCast<StatementContext *>(_localctx)->es->id = generateLoopExpression(antlrcpp::downCast<StatementContext *>(_localctx)->es->id, to_string(antlrcpp::downCast<StatementContext *>(_localctx)->forToken->getLine()));
      	
      handleBeforeLoopExpression(antlrcpp::downCast<StatementContext *>(_localctx)->es->id);
      setState(190);
      antlrcpp::downCast<StatementContext *>(_localctx)->e = expression();

      		if(antlrcpp::downCast<StatementContext *>(_localctx)->e->id.isIncDec){evaluateIncDec(antlrcpp::downCast<StatementContext *>(_localctx)->e->id, to_string(antlrcpp::downCast<StatementContext *>(_localctx)->forToken->getLine()));};handleAfterLoopExpression(antlrcpp::downCast<StatementContext *>(_localctx)->es->id);
      	
      setState(192);
      match(C8086Parser::RPAREN);
      handleBeforeLoopStatement(antlrcpp::downCast<StatementContext *>(_localctx)->es->id);
      setState(194);
      statement();

      		handleAfterLoopStatement(antlrcpp::downCast<StatementContext *>(_localctx)->es->id);
      		clearLoopLabels();
      	
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(197);
      match(C8086Parser::IF);
      setState(198);
      match(C8086Parser::LPAREN);
      setState(199);
      antlrcpp::downCast<StatementContext *>(_localctx)->e = expression();

      		antlrcpp::downCast<StatementContext *>(_localctx)->e->id = generateRelationalCodeForSimpleExpression(antlrcpp::downCast<StatementContext *>(_localctx)->e->id);
      		generateCodeAfterIfExpression(antlrcpp::downCast<StatementContext *>(_localctx)->e->id);
      	
      setState(201);
      match(C8086Parser::RPAREN);
      setState(202);
      antlrcpp::downCast<StatementContext *>(_localctx)->s = statement();

      		generateCodeAfterIfStatement(antlrcpp::downCast<StatementContext *>(_localctx)->e->id);
      		generateCodeAfterElseStatement(antlrcpp::downCast<StatementContext *>(_localctx)->e->id);
      	
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(205);
      match(C8086Parser::IF);
      setState(206);
      match(C8086Parser::LPAREN);
      setState(207);
      antlrcpp::downCast<StatementContext *>(_localctx)->e = expression();

      		antlrcpp::downCast<StatementContext *>(_localctx)->e->id = generateRelationalCodeForSimpleExpression(antlrcpp::downCast<StatementContext *>(_localctx)->e->id);
      		generateCodeAfterIfExpression(antlrcpp::downCast<StatementContext *>(_localctx)->e->id);
      	
      setState(209);
      match(C8086Parser::RPAREN);
      setState(210);
      statement();

      		generateCodeAfterIfStatement(antlrcpp::downCast<StatementContext *>(_localctx)->e->id);
      	
      setState(212);
      match(C8086Parser::ELSE);
      setState(213);
      statement();

      		generateCodeAfterElseStatement(antlrcpp::downCast<StatementContext *>(_localctx)->e->id);
      	
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(216);
      antlrcpp::downCast<StatementContext *>(_localctx)->whileToken = match(C8086Parser::WHILE);
      setState(217);
      match(C8086Parser::LPAREN);
      setState(218);
      antlrcpp::downCast<StatementContext *>(_localctx)->e = expression();
      antlrcpp::downCast<StatementContext *>(_localctx)->e->id = generateLoopExpression(antlrcpp::downCast<StatementContext *>(_localctx)->e->id, to_string(antlrcpp::downCast<StatementContext *>(_localctx)->whileToken->getLine()));
      setState(220);
      match(C8086Parser::RPAREN);
      handleBeforeWhileLoopExpression(antlrcpp::downCast<StatementContext *>(_localctx)->e->id);
      setState(222);
      statement();

      		handleAfterWhileLoopExpression(antlrcpp::downCast<StatementContext *>(_localctx)->e->id);
      		if(antlrcpp::downCast<StatementContext *>(_localctx)->e->id.isIncDec) {
      			simpleIncDecEvaluation(antlrcpp::downCast<StatementContext *>(_localctx)->e->id, to_string(antlrcpp::downCast<StatementContext *>(_localctx)->whileToken->getLine()));
      		}
      	
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(225);
      antlrcpp::downCast<StatementContext *>(_localctx)->printlnToken = match(C8086Parser::PRINTLN);
      setState(226);
      match(C8086Parser::LPAREN);
      setState(227);
      antlrcpp::downCast<StatementContext *>(_localctx)->idToken = match(C8086Parser::ID);
      setState(228);
      match(C8086Parser::RPAREN);
      setState(229);
      match(C8086Parser::SEMICOLON);

      		Identifier id;
      		SymbolInfo* symbol = symbolTable.lookUp(antlrcpp::downCast<StatementContext *>(_localctx)->idToken->getText());
      		id = symbol->id;
      		printVariable(id, to_string(antlrcpp::downCast<StatementContext *>(_localctx)->printlnToken->getLine()));		
      	
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(231);
      antlrcpp::downCast<StatementContext *>(_localctx)->returnToken = match(C8086Parser::RETURN);
      setState(232);
      antlrcpp::downCast<StatementContext *>(_localctx)->e = expression();
      setState(233);
      match(C8086Parser::SEMICOLON);

      		handleReturnExpresssion(antlrcpp::downCast<StatementContext *>(_localctx)->e->id,std::to_string(antlrcpp::downCast<StatementContext *>(_localctx)->returnToken->getLine()));
      		if(antlrcpp::downCast<StatementContext *>(_localctx)->e->id.isIncDec) {
      			evaluateIncDec(antlrcpp::downCast<StatementContext *>(_localctx)->e->id, to_string(antlrcpp::downCast<StatementContext *>(_localctx)->returnToken->getLine()));
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
    setState(244);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C8086Parser::SEMICOLON: {
        enterOuterAlt(_localctx, 1);
        setState(238);
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
        setState(240);
        antlrcpp::downCast<Expression_statementContext *>(_localctx)->e = expression();
        setState(241);
        antlrcpp::downCast<Expression_statementContext *>(_localctx)->semicolonToken = match(C8086Parser::SEMICOLON);

        		antlrcpp::downCast<Expression_statementContext *>(_localctx)->id =  antlrcpp::downCast<Expression_statementContext *>(_localctx)->e->id;
        		if(_localctx->id.isIncDec) {
        			antlrcpp::downCast<Expression_statementContext *>(_localctx)->id =  evaluateIncDec(_localctx->id, to_string(antlrcpp::downCast<Expression_statementContext *>(_localctx)->semicolonToken->getLine()));
        		}
        	
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

tree::TerminalNode* C8086Parser::ExpressionContext::ASSIGNOP() {
  return getToken(C8086Parser::ASSIGNOP, 0);
}

C8086Parser::VariableContext* C8086Parser::ExpressionContext::variable() {
  return getRuleContext<C8086Parser::VariableContext>(0);
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
    setState(254);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(246);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->le = logic_expression();

      		antlrcpp::downCast<ExpressionContext *>(_localctx)->id =  antlrcpp::downCast<ExpressionContext *>(_localctx)->le->id;
      	
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(249);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->v = variable();
      setState(250);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->assignopToken = match(C8086Parser::ASSIGNOP);
      setState(251);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->le = logic_expression();

      		if(antlrcpp::downCast<ExpressionContext *>(_localctx)->le->id.trueLabel == "EMPTY" && antlrcpp::downCast<ExpressionContext *>(_localctx)->le->id.falseLabel == "EMPTY") {
      			assignVariable(antlrcpp::downCast<ExpressionContext *>(_localctx)->v->id, antlrcpp::downCast<ExpressionContext *>(_localctx)->le->id, to_string(antlrcpp::downCast<ExpressionContext *>(_localctx)->assignopToken->getLine()));
      		} else {
      			assignLogicalVariable(antlrcpp::downCast<ExpressionContext *>(_localctx)->v->id, antlrcpp::downCast<ExpressionContext *>(_localctx)->le->id, to_string(antlrcpp::downCast<ExpressionContext *>(_localctx)->assignopToken->getLine()));
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
    setState(265);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(256);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re = rel_expression();

              antlrcpp::downCast<Logic_expressionContext *>(_localctx)->id =  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re->id;
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(259);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re1 = rel_expression();

      		antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re1->id = generateRelationalCodeForSimpleExpression(antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re1->id);
      	
      setState(261);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->logicopToken = match(C8086Parser::LOGICOP);
      setState(262);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re2 = rel_expression();

      		antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re2->id = generateRelationalCodeForSimpleExpression(antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re2->id);

      		// debug("starting to generate logical code\n");
      		// debug("left identifier:\n");
      		// printIdentifierLabel(antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re1->id);
      		// debug("\n\nright Identifier:\n");
      		// printIdentifierLabel(antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re2->id);
      		antlrcpp::downCast<Logic_expressionContext *>(_localctx)->id =  generateLogicalCode(antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re1->id, antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re2->id, to_string(antlrcpp::downCast<Logic_expressionContext *>(_localctx)->logicopToken->getLine()), antlrcpp::downCast<Logic_expressionContext *>(_localctx)->logicopToken->getText());
      		// debug("\nreceived merged logical identifer is:\n");
      		// printIdentifierLabel(_localctx->id);
          
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
    setState(275);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(267);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->se = simple_expression(0);

      		antlrcpp::downCast<Rel_expressionContext *>(_localctx)->id =  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->se->id;
      	
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(270);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->se1 = simple_expression(0);
      setState(271);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken = match(C8086Parser::RELOP);
      setState(272);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->se2 = simple_expression(0);

      		Identifier id;
      		id.startLabel = generateLabel();
      		id.trueLabel = generateLabel();
      		id.falseLabel = generateLabel();
      		id.nextLabel = generateLabel();
      		antlrcpp::downCast<Rel_expressionContext *>(_localctx)->id =  id;
      		generateRelationalCode(id,antlrcpp::downCast<Rel_expressionContext *>(_localctx)->se1->id, antlrcpp::downCast<Rel_expressionContext *>(_localctx)->se2->id, to_string(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken->getLine()), antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken->getText());		
      	
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

tree::TerminalNode* C8086Parser::Simple_expressionContext::ADDOP() {
  return getToken(C8086Parser::ADDOP, 0);
}

C8086Parser::Simple_expressionContext* C8086Parser::Simple_expressionContext::simple_expression() {
  return getRuleContext<C8086Parser::Simple_expressionContext>(0);
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
    setState(278);
    antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t = term(0);

            antlrcpp::downCast<Simple_expressionContext *>(_localctx)->id =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->id;
        
    _ctx->stop = _input->LT(-1);
    setState(288);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Simple_expressionContext>(parentContext, parentState);
        _localctx->se = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleSimple_expression);
        setState(281);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(282);
        antlrcpp::downCast<Simple_expressionContext *>(_localctx)->addopToken = match(C8086Parser::ADDOP);
        setState(283);
        antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t = term(0);

                  		concatenatingAddMul(antlrcpp::downCast<Simple_expressionContext *>(_localctx)->se->id, antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->id, to_string(antlrcpp::downCast<Simple_expressionContext *>(_localctx)->addopToken->getLine()), antlrcpp::downCast<Simple_expressionContext *>(_localctx)->addopToken->getText());
                  		_localctx->id.isInStack = true;
                  	 
      }
      setState(290);
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

tree::TerminalNode* C8086Parser::TermContext::MULOP() {
  return getToken(C8086Parser::MULOP, 0);
}

C8086Parser::TermContext* C8086Parser::TermContext::term() {
  return getRuleContext<C8086Parser::TermContext>(0);
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
    setState(292);
    antlrcpp::downCast<TermContext *>(_localctx)->ue = unary_expression();

    		antlrcpp::downCast<TermContext *>(_localctx)->id =  antlrcpp::downCast<TermContext *>(_localctx)->ue->id;
    	
    _ctx->stop = _input->LT(-1);
    setState(302);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<TermContext>(parentContext, parentState);
        _localctx->t = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleTerm);
        setState(295);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(296);
        antlrcpp::downCast<TermContext *>(_localctx)->mulopToken = match(C8086Parser::MULOP);
        setState(297);
        antlrcpp::downCast<TermContext *>(_localctx)->ue = unary_expression();

                  		concatenatingAddMul(antlrcpp::downCast<TermContext *>(_localctx)->t->id, antlrcpp::downCast<TermContext *>(_localctx)->ue->id, to_string(antlrcpp::downCast<TermContext *>(_localctx)->mulopToken->getLine()), antlrcpp::downCast<TermContext *>(_localctx)->mulopToken->getText());
                  		_localctx->id.isInStack = true;
                  	 
      }
      setState(304);
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
    setState(314);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C8086Parser::ADDOP: {
        enterOuterAlt(_localctx, 1);
        setState(305);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->addopToken = match(C8086Parser::ADDOP);
        setState(306);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->ue = unary_expression();

        		generateCodeForAddOp(antlrcpp::downCast<Unary_expressionContext *>(_localctx)->ue->id, to_string(antlrcpp::downCast<Unary_expressionContext *>(_localctx)->addopToken->getLine()));
        		_localctx->id.isInStack = true;
        	
        break;
      }

      case C8086Parser::NOT: {
        enterOuterAlt(_localctx, 2);
        setState(309);
        match(C8086Parser::NOT);
        setState(310);
        unary_expression();
        break;
      }

      case C8086Parser::LPAREN:
      case C8086Parser::ID:
      case C8086Parser::CONST_INT:
      case C8086Parser::CONST_FLOAT: {
        enterOuterAlt(_localctx, 3);
        setState(311);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->f = factor();

        		antlrcpp::downCast<Unary_expressionContext *>(_localctx)->id =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->f->id;
        	
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

tree::TerminalNode* C8086Parser::FactorContext::RPAREN() {
  return getToken(C8086Parser::RPAREN, 0);
}

C8086Parser::Argument_listContext* C8086Parser::FactorContext::argument_list() {
  return getRuleContext<C8086Parser::Argument_listContext>(0);
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
    setState(341);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(316);
      antlrcpp::downCast<FactorContext *>(_localctx)->v = variable();

      		antlrcpp::downCast<FactorContext *>(_localctx)->id =  antlrcpp::downCast<FactorContext *>(_localctx)->v->id;
      	
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(319);
      antlrcpp::downCast<FactorContext *>(_localctx)->idToken = match(C8086Parser::ID);
      setState(320);
      match(C8086Parser::LPAREN);
      setState(321);
      antlrcpp::downCast<FactorContext *>(_localctx)->al = argument_list();
      setState(322);
      match(C8086Parser::RPAREN);

      		std::string code;
      		std::string line = std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getLine());
      		preserveTemporaryRegisters();
      		code = "    CALL " + antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getText() + getComment(line) + "\n"; writeIntoTempFile(code);
      		SymbolInfo* symbol = lookupSymbol(antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getText());
      		if(toUpper(symbol->getType()) != "VOID") {
      			code = "    PUSH AX\n"; writeIntoTempFile(code);
      			_localctx->id.isInStack = true;
      		}
      		restoreTemporaryRegisters();
      	
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(325);
      match(C8086Parser::LPAREN);
      setState(326);
      antlrcpp::downCast<FactorContext *>(_localctx)->e = expression();
      setState(327);
      match(C8086Parser::RPAREN);

      		antlrcpp::downCast<FactorContext *>(_localctx)->id =  antlrcpp::downCast<FactorContext *>(_localctx)->e->id;
      	
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(330);
      antlrcpp::downCast<FactorContext *>(_localctx)->const_intToken = match(C8086Parser::CONST_INT);

      		Identifier id;
      		id.constValue = antlrcpp::downCast<FactorContext *>(_localctx)->const_intToken->getText();
      		antlrcpp::downCast<FactorContext *>(_localctx)->id =  id;
      	
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(332);
      match(C8086Parser::CONST_FLOAT);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(333);
      antlrcpp::downCast<FactorContext *>(_localctx)->v = variable();
      setState(334);
      antlrcpp::downCast<FactorContext *>(_localctx)->incopToken = match(C8086Parser::INCOP);

      		antlrcpp::downCast<FactorContext *>(_localctx)->id =  generateCodeForIncDecOp(antlrcpp::downCast<FactorContext *>(_localctx)->v->id, "ADD", to_string(antlrcpp::downCast<FactorContext *>(_localctx)->incopToken->getLine()));
      	
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(337);
      antlrcpp::downCast<FactorContext *>(_localctx)->v = variable();
      setState(338);
      antlrcpp::downCast<FactorContext *>(_localctx)->decopToken = match(C8086Parser::DECOP);

      		antlrcpp::downCast<FactorContext *>(_localctx)->id =  generateCodeForIncDecOp(antlrcpp::downCast<FactorContext *>(_localctx)->v->id, "SUB", to_string(antlrcpp::downCast<FactorContext *>(_localctx)->decopToken->getLine()));
      	
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
    setState(351);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(343);
      antlrcpp::downCast<VariableContext *>(_localctx)->idToken = match(C8086Parser::ID);

      		SymbolInfo* symbol = lookupSymbol(antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText());
      		antlrcpp::downCast<VariableContext *>(_localctx)->id =  symbol->id;
      	
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(345);
      antlrcpp::downCast<VariableContext *>(_localctx)->idToken = match(C8086Parser::ID);
      setState(346);
      match(C8086Parser::LTHIRD);
      setState(347);
      antlrcpp::downCast<VariableContext *>(_localctx)->e = expression();
      setState(348);
      match(C8086Parser::RTHIRD);

      		SymbolInfo* symbol = lookupSymbol(antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText());
      		antlrcpp::downCast<VariableContext *>(_localctx)->id =  symbol->id;
      		_localctx->id.isArray = true;
      		_localctx->id.arrayIndex = antlrcpp::downCast<VariableContext *>(_localctx)->e->id.constValue; 		
      	
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
    setState(357);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C8086Parser::LPAREN:
      case C8086Parser::ADDOP:
      case C8086Parser::NOT:
      case C8086Parser::ID:
      case C8086Parser::CONST_INT:
      case C8086Parser::CONST_FLOAT: {
        enterOuterAlt(_localctx, 1);
        setState(353);
        antlrcpp::downCast<Argument_listContext *>(_localctx)->a = arguments(0);

        		antlrcpp::downCast<Argument_listContext *>(_localctx)->ids =  antlrcpp::downCast<Argument_listContext *>(_localctx)->a->ids;
        	
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

tree::TerminalNode* C8086Parser::ArgumentsContext::COMMA() {
  return getToken(C8086Parser::COMMA, 0);
}

C8086Parser::ArgumentsContext* C8086Parser::ArgumentsContext::arguments() {
  return getRuleContext<C8086Parser::ArgumentsContext>(0);
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
    setState(360);
    antlrcpp::downCast<ArgumentsContext *>(_localctx)->le = logic_expression();

    		std::string code;
    		if(antlrcpp::downCast<ArgumentsContext *>(_localctx)->le->id.isInStack) {
    			code = "    POP AX\n"; writeIntoTempFile(code);
    		} else {
    			code = "    MOV AX, " + identifierAddress(antlrcpp::downCast<ArgumentsContext *>(_localctx)->le->id) + "\n"; writeIntoTempFile(code);
    		}
    		code = "    PUSH AX\n"; writeIntoTempFile(code);
    	
    _ctx->stop = _input->LT(-1);
    setState(370);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ArgumentsContext>(parentContext, parentState);
        _localctx->a = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleArguments);
        setState(363);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(364);
        antlrcpp::downCast<ArgumentsContext *>(_localctx)->commaToken = match(C8086Parser::COMMA);
        setState(365);
        antlrcpp::downCast<ArgumentsContext *>(_localctx)->le = logic_expression();

                  		std::string code;
                  		std::string line = std::to_string(antlrcpp::downCast<ArgumentsContext *>(_localctx)->commaToken->getLine());
                  		if(antlrcpp::downCast<ArgumentsContext *>(_localctx)->le->id.isInStack) {
                  			code = "    POP AX" + getComment(line) + "\n"; writeIntoTempFile(code);
                  		} else {
                  			code = "    MOV AX, " + identifierAddress(antlrcpp::downCast<ArgumentsContext *>(_localctx)->le->id) + getComment(line) + "\n"; writeIntoTempFile(code);
                  		}
                  		code = "    PUSH AX" + getComment(line) + "\n"; writeIntoTempFile(code);
                  	 
      }
      setState(372);
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
