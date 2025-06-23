
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
      "start", "program", "unit", "type_specifier", "var_declaration", "declaration_list", 
      "declaration_list_err", "parameter_list", "func_declaration", "func_definition", 
      "compound_statement", "statements", "statement", "expression_statement", 
      "expression", "logic_expression", "variable", "rel_expression", "simple_expression", 
      "term", "unary_expression", "factor", "argument_list", "arguments"
    },
    std::vector<std::string>{
      "", "", "", "", "", "'if'", "'else'", "'for'", "'while'", "'printf'", 
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
  	4,1,33,400,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,
  	1,60,8,1,10,1,12,1,63,9,1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,3,2,74,
  	8,2,1,3,1,3,1,3,1,3,1,3,1,3,3,3,82,8,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,
  	4,1,4,1,4,3,4,94,8,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,3,5,104,8,5,1,5,
  	1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,5,5,117,8,5,10,5,12,5,120,9,5,
  	1,6,1,6,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,3,7,132,8,7,1,7,1,7,1,7,1,7,1,
  	7,1,7,1,7,1,7,1,7,1,7,1,7,5,7,145,8,7,10,7,12,7,148,9,7,1,8,1,8,1,8,1,
  	8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,3,8,165,8,8,1,9,1,9,1,9,
  	1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,3,9,183,8,9,1,10,
  	1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,3,10,194,8,10,1,11,1,11,1,11,
  	1,11,1,11,1,11,1,11,1,11,5,11,204,8,11,10,11,12,11,207,9,11,1,12,1,12,
  	1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,
  	1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,
  	1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,
  	1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,3,12,261,8,12,1,13,1,13,1,13,
  	1,13,1,13,1,13,3,13,269,8,13,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,
  	3,14,279,8,14,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,3,15,289,8,15,1,
  	16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,3,16,299,8,16,1,17,1,17,1,17,1,
  	17,1,17,1,17,1,17,1,17,3,17,309,8,17,1,18,1,18,1,18,1,18,1,18,1,18,1,
  	18,1,18,1,18,5,18,320,8,18,10,18,12,18,323,9,18,1,19,1,19,1,19,1,19,1,
  	19,1,19,1,19,1,19,1,19,5,19,334,8,19,10,19,12,19,337,9,19,1,20,1,20,1,
  	20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,3,20,350,8,20,1,21,1,21,1,
  	21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,
  	21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,3,21,378,8,21,1,22,1,
  	22,1,22,1,22,3,22,384,8,22,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,
  	23,5,23,395,8,23,10,23,12,23,398,9,23,1,23,0,7,2,10,14,22,36,38,46,24,
  	0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,0,
  	0,416,0,48,1,0,0,0,2,51,1,0,0,0,4,73,1,0,0,0,6,81,1,0,0,0,8,93,1,0,0,
  	0,10,103,1,0,0,0,12,121,1,0,0,0,14,131,1,0,0,0,16,164,1,0,0,0,18,182,
  	1,0,0,0,20,193,1,0,0,0,22,195,1,0,0,0,24,260,1,0,0,0,26,268,1,0,0,0,28,
  	278,1,0,0,0,30,288,1,0,0,0,32,298,1,0,0,0,34,308,1,0,0,0,36,310,1,0,0,
  	0,38,324,1,0,0,0,40,349,1,0,0,0,42,377,1,0,0,0,44,383,1,0,0,0,46,385,
  	1,0,0,0,48,49,3,2,1,0,49,50,6,0,-1,0,50,1,1,0,0,0,51,52,6,1,-1,0,52,53,
  	3,4,2,0,53,54,6,1,-1,0,54,61,1,0,0,0,55,56,10,2,0,0,56,57,3,4,2,0,57,
  	58,6,1,-1,0,58,60,1,0,0,0,59,55,1,0,0,0,60,63,1,0,0,0,61,59,1,0,0,0,61,
  	62,1,0,0,0,62,3,1,0,0,0,63,61,1,0,0,0,64,65,3,8,4,0,65,66,6,2,-1,0,66,
  	74,1,0,0,0,67,68,3,16,8,0,68,69,6,2,-1,0,69,74,1,0,0,0,70,71,3,18,9,0,
  	71,72,6,2,-1,0,72,74,1,0,0,0,73,64,1,0,0,0,73,67,1,0,0,0,73,70,1,0,0,
  	0,74,5,1,0,0,0,75,76,5,11,0,0,76,82,6,3,-1,0,77,78,5,12,0,0,78,82,6,3,
  	-1,0,79,80,5,13,0,0,80,82,6,3,-1,0,81,75,1,0,0,0,81,77,1,0,0,0,81,79,
  	1,0,0,0,82,7,1,0,0,0,83,84,3,6,3,0,84,85,3,10,5,0,85,86,5,20,0,0,86,87,
  	6,4,-1,0,87,94,1,0,0,0,88,89,3,6,3,0,89,90,3,12,6,0,90,91,5,20,0,0,91,
  	92,6,4,-1,0,92,94,1,0,0,0,93,83,1,0,0,0,93,88,1,0,0,0,94,9,1,0,0,0,95,
  	96,6,5,-1,0,96,97,5,31,0,0,97,104,6,5,-1,0,98,99,5,31,0,0,99,100,5,18,
  	0,0,100,101,5,32,0,0,101,102,5,19,0,0,102,104,6,5,-1,0,103,95,1,0,0,0,
  	103,98,1,0,0,0,104,118,1,0,0,0,105,106,10,4,0,0,106,107,5,21,0,0,107,
  	108,5,31,0,0,108,117,6,5,-1,0,109,110,10,3,0,0,110,111,5,21,0,0,111,112,
  	5,31,0,0,112,113,5,18,0,0,113,114,5,32,0,0,114,115,5,19,0,0,115,117,6,
  	5,-1,0,116,105,1,0,0,0,116,109,1,0,0,0,117,120,1,0,0,0,118,116,1,0,0,
  	0,118,119,1,0,0,0,119,11,1,0,0,0,120,118,1,0,0,0,121,122,6,6,-1,0,122,
  	13,1,0,0,0,123,124,6,7,-1,0,124,125,3,6,3,0,125,126,5,31,0,0,126,127,
  	6,7,-1,0,127,132,1,0,0,0,128,129,3,6,3,0,129,130,6,7,-1,0,130,132,1,0,
  	0,0,131,123,1,0,0,0,131,128,1,0,0,0,132,146,1,0,0,0,133,134,10,4,0,0,
  	134,135,5,21,0,0,135,136,3,6,3,0,136,137,5,31,0,0,137,138,6,7,-1,0,138,
  	145,1,0,0,0,139,140,10,3,0,0,140,141,5,21,0,0,141,142,3,6,3,0,142,143,
  	6,7,-1,0,143,145,1,0,0,0,144,133,1,0,0,0,144,139,1,0,0,0,145,148,1,0,
  	0,0,146,144,1,0,0,0,146,147,1,0,0,0,147,15,1,0,0,0,148,146,1,0,0,0,149,
  	150,3,6,3,0,150,151,5,31,0,0,151,152,5,14,0,0,152,153,3,14,7,0,153,154,
  	5,15,0,0,154,155,5,20,0,0,155,156,6,8,-1,0,156,165,1,0,0,0,157,158,3,
  	6,3,0,158,159,5,31,0,0,159,160,5,14,0,0,160,161,5,15,0,0,161,162,5,20,
  	0,0,162,163,6,8,-1,0,163,165,1,0,0,0,164,149,1,0,0,0,164,157,1,0,0,0,
  	165,17,1,0,0,0,166,167,3,6,3,0,167,168,5,31,0,0,168,169,5,14,0,0,169,
  	170,3,14,7,0,170,171,5,15,0,0,171,172,6,9,-1,0,172,173,3,20,10,0,173,
  	174,6,9,-1,0,174,183,1,0,0,0,175,176,3,6,3,0,176,177,5,31,0,0,177,178,
  	5,14,0,0,178,179,5,15,0,0,179,180,3,20,10,0,180,181,6,9,-1,0,181,183,
  	1,0,0,0,182,166,1,0,0,0,182,175,1,0,0,0,183,19,1,0,0,0,184,185,5,16,0,
  	0,185,186,6,10,-1,0,186,187,3,22,11,0,187,188,5,17,0,0,188,189,6,10,-1,
  	0,189,194,1,0,0,0,190,191,5,16,0,0,191,192,5,17,0,0,192,194,6,10,-1,0,
  	193,184,1,0,0,0,193,190,1,0,0,0,194,21,1,0,0,0,195,196,6,11,-1,0,196,
  	197,3,24,12,0,197,198,6,11,-1,0,198,205,1,0,0,0,199,200,10,1,0,0,200,
  	201,3,24,12,0,201,202,6,11,-1,0,202,204,1,0,0,0,203,199,1,0,0,0,204,207,
  	1,0,0,0,205,203,1,0,0,0,205,206,1,0,0,0,206,23,1,0,0,0,207,205,1,0,0,
  	0,208,209,3,8,4,0,209,210,6,12,-1,0,210,261,1,0,0,0,211,212,3,26,13,0,
  	212,213,6,12,-1,0,213,261,1,0,0,0,214,215,3,20,10,0,215,216,6,12,-1,0,
  	216,261,1,0,0,0,217,218,5,7,0,0,218,219,5,14,0,0,219,220,3,26,13,0,220,
  	221,3,26,13,0,221,222,3,28,14,0,222,223,5,15,0,0,223,224,3,24,12,0,224,
  	225,6,12,-1,0,225,261,1,0,0,0,226,227,5,5,0,0,227,228,5,14,0,0,228,229,
  	3,28,14,0,229,230,5,15,0,0,230,231,3,24,12,0,231,232,6,12,-1,0,232,261,
  	1,0,0,0,233,234,5,5,0,0,234,235,5,14,0,0,235,236,3,28,14,0,236,237,5,
  	15,0,0,237,238,3,24,12,0,238,239,5,6,0,0,239,240,3,24,12,0,240,241,6,
  	12,-1,0,241,261,1,0,0,0,242,243,5,8,0,0,243,244,5,14,0,0,244,245,3,28,
  	14,0,245,246,5,15,0,0,246,247,3,24,12,0,247,248,6,12,-1,0,248,261,1,0,
  	0,0,249,250,5,9,0,0,250,251,5,14,0,0,251,252,5,31,0,0,252,253,5,15,0,
  	0,253,254,5,20,0,0,254,261,6,12,-1,0,255,256,5,10,0,0,256,257,3,28,14,
  	0,257,258,5,20,0,0,258,259,6,12,-1,0,259,261,1,0,0,0,260,208,1,0,0,0,
  	260,211,1,0,0,0,260,214,1,0,0,0,260,217,1,0,0,0,260,226,1,0,0,0,260,233,
  	1,0,0,0,260,242,1,0,0,0,260,249,1,0,0,0,260,255,1,0,0,0,261,25,1,0,0,
  	0,262,263,5,20,0,0,263,269,6,13,-1,0,264,265,3,28,14,0,265,266,5,20,0,
  	0,266,267,6,13,-1,0,267,269,1,0,0,0,268,262,1,0,0,0,268,264,1,0,0,0,269,
  	27,1,0,0,0,270,271,3,30,15,0,271,272,6,14,-1,0,272,279,1,0,0,0,273,274,
  	3,32,16,0,274,275,5,30,0,0,275,276,3,30,15,0,276,277,6,14,-1,0,277,279,
  	1,0,0,0,278,270,1,0,0,0,278,273,1,0,0,0,279,29,1,0,0,0,280,281,3,34,17,
  	0,281,282,6,15,-1,0,282,289,1,0,0,0,283,284,3,34,17,0,284,285,5,29,0,
  	0,285,286,3,34,17,0,286,287,6,15,-1,0,287,289,1,0,0,0,288,280,1,0,0,0,
  	288,283,1,0,0,0,289,31,1,0,0,0,290,291,5,31,0,0,291,299,6,16,-1,0,292,
  	293,5,31,0,0,293,294,5,18,0,0,294,295,3,28,14,0,295,296,5,19,0,0,296,
  	297,6,16,-1,0,297,299,1,0,0,0,298,290,1,0,0,0,298,292,1,0,0,0,299,33,
  	1,0,0,0,300,301,3,36,18,0,301,302,6,17,-1,0,302,309,1,0,0,0,303,304,3,
  	36,18,0,304,305,5,28,0,0,305,306,3,36,18,0,306,307,6,17,-1,0,307,309,
  	1,0,0,0,308,300,1,0,0,0,308,303,1,0,0,0,309,35,1,0,0,0,310,311,6,18,-1,
  	0,311,312,3,38,19,0,312,313,6,18,-1,0,313,321,1,0,0,0,314,315,10,1,0,
  	0,315,316,5,22,0,0,316,317,3,38,19,0,317,318,6,18,-1,0,318,320,1,0,0,
  	0,319,314,1,0,0,0,320,323,1,0,0,0,321,319,1,0,0,0,321,322,1,0,0,0,322,
  	37,1,0,0,0,323,321,1,0,0,0,324,325,6,19,-1,0,325,326,3,40,20,0,326,327,
  	6,19,-1,0,327,335,1,0,0,0,328,329,10,1,0,0,329,330,5,24,0,0,330,331,3,
  	40,20,0,331,332,6,19,-1,0,332,334,1,0,0,0,333,328,1,0,0,0,334,337,1,0,
  	0,0,335,333,1,0,0,0,335,336,1,0,0,0,336,39,1,0,0,0,337,335,1,0,0,0,338,
  	339,5,22,0,0,339,340,3,40,20,0,340,341,6,20,-1,0,341,350,1,0,0,0,342,
  	343,5,27,0,0,343,344,3,40,20,0,344,345,6,20,-1,0,345,350,1,0,0,0,346,
  	347,3,42,21,0,347,348,6,20,-1,0,348,350,1,0,0,0,349,338,1,0,0,0,349,342,
  	1,0,0,0,349,346,1,0,0,0,350,41,1,0,0,0,351,352,3,32,16,0,352,353,6,21,
  	-1,0,353,378,1,0,0,0,354,355,5,31,0,0,355,356,5,14,0,0,356,357,3,44,22,
  	0,357,358,5,15,0,0,358,359,6,21,-1,0,359,378,1,0,0,0,360,361,5,14,0,0,
  	361,362,3,28,14,0,362,363,5,15,0,0,363,364,6,21,-1,0,364,378,1,0,0,0,
  	365,366,5,32,0,0,366,378,6,21,-1,0,367,368,5,33,0,0,368,378,6,21,-1,0,
  	369,370,3,32,16,0,370,371,5,25,0,0,371,372,6,21,-1,0,372,378,1,0,0,0,
  	373,374,3,32,16,0,374,375,5,26,0,0,375,376,6,21,-1,0,376,378,1,0,0,0,
  	377,351,1,0,0,0,377,354,1,0,0,0,377,360,1,0,0,0,377,365,1,0,0,0,377,367,
  	1,0,0,0,377,369,1,0,0,0,377,373,1,0,0,0,378,43,1,0,0,0,379,380,3,46,23,
  	0,380,381,6,22,-1,0,381,384,1,0,0,0,382,384,1,0,0,0,383,379,1,0,0,0,383,
  	382,1,0,0,0,384,45,1,0,0,0,385,386,6,23,-1,0,386,387,3,30,15,0,387,388,
  	6,23,-1,0,388,396,1,0,0,0,389,390,10,2,0,0,390,391,5,21,0,0,391,392,3,
  	30,15,0,392,393,6,23,-1,0,393,395,1,0,0,0,394,389,1,0,0,0,395,398,1,0,
  	0,0,396,394,1,0,0,0,396,397,1,0,0,0,397,47,1,0,0,0,398,396,1,0,0,0,26,
  	61,73,81,93,103,116,118,131,144,146,164,182,193,205,260,268,278,288,298,
  	308,321,335,349,377,383,396
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
    setState(48);
    antlrcpp::downCast<StartContext *>(_localctx)->p = program(0);

    		std::string ruleName = "start : program";
    		std::string text = antlrcpp::downCast<StartContext *>(_localctx)->p->text;
    		std::string line = antlrcpp::downCast<StartContext *>(_localctx)->p->line;

    		writeRuleLog(line, ruleName);
    		// writeIntoparserLogFile(text + "\n");
    		printAll();

    		writeIntoparserLogFile("Total number of lines: " + line);
    		writeIntoparserLogFile("Total number of errors: " + std::to_string(syntaxErrorCount));
    	
   
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
    setState(52);
    antlrcpp::downCast<ProgramContext *>(_localctx)->u = unit();

    		std::string ruleName = "program : unit";
    		antlrcpp::downCast<ProgramContext *>(_localctx)->text =  antlrcpp::downCast<ProgramContext *>(_localctx)->u->text;
    		antlrcpp::downCast<ProgramContext *>(_localctx)->line =  antlrcpp::downCast<ProgramContext *>(_localctx)->u->line;

    		writeRuleLog(_localctx->line, ruleName);
    		writeIntoparserLogFile(_localctx->text + "\n");
    	
    _ctx->stop = _input->LT(-1);
    setState(61);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ProgramContext>(parentContext, parentState);
        _localctx->p = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleProgram);
        setState(55);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(56);
        antlrcpp::downCast<ProgramContext *>(_localctx)->u = unit();

                  		std::string ruleName = "program : program unit";
                  		antlrcpp::downCast<ProgramContext *>(_localctx)->text =  antlrcpp::downCast<ProgramContext *>(_localctx)->p->text + "\n" + antlrcpp::downCast<ProgramContext *>(_localctx)->u->text;
                  		antlrcpp::downCast<ProgramContext *>(_localctx)->line =  antlrcpp::downCast<ProgramContext *>(_localctx)->u->line;

                  		writeRuleLog(_localctx->line, ruleName);
                  		writeIntoparserLogFile(_localctx->text + "\n");
                  	 
      }
      setState(63);
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
    setState(73);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(64);
      antlrcpp::downCast<UnitContext *>(_localctx)->vdl = var_declaration();

      		std::string ruleName = "unit : var_declaration";
      		antlrcpp::downCast<UnitContext *>(_localctx)->text =  antlrcpp::downCast<UnitContext *>(_localctx)->vdl->text;
      		antlrcpp::downCast<UnitContext *>(_localctx)->line =  antlrcpp::downCast<UnitContext *>(_localctx)->vdl->line;

      		writeRuleLog(_localctx->line, ruleName);
      		writeIntoparserLogFile(_localctx->text + "\n");
      	
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(67);
      antlrcpp::downCast<UnitContext *>(_localctx)->fdl = func_declaration();

      		std::string ruleName = "unit : func_declaration";
      		antlrcpp::downCast<UnitContext *>(_localctx)->text =  antlrcpp::downCast<UnitContext *>(_localctx)->fdl->text;
      		antlrcpp::downCast<UnitContext *>(_localctx)->line =  antlrcpp::downCast<UnitContext *>(_localctx)->fdl->line;

      		writeRuleLog(_localctx->line, ruleName);
      		writeIntoparserLogFile(_localctx->text + "\n");
      	
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(70);
      antlrcpp::downCast<UnitContext *>(_localctx)->fdf = func_definition();

      		std::string ruleName = "unit : func_definition";
      		antlrcpp::downCast<UnitContext *>(_localctx)->text =  antlrcpp::downCast<UnitContext *>(_localctx)->fdf->text;
      		antlrcpp::downCast<UnitContext *>(_localctx)->line =  antlrcpp::downCast<UnitContext *>(_localctx)->fdf->line;

      		writeRuleLog(_localctx->line, ruleName);
      		writeIntoparserLogFile(_localctx->text + "\n");
      	
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
    setState(81);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C8086Parser::INT: {
        enterOuterAlt(_localctx, 1);
        setState(75);
        antlrcpp::downCast<Type_specifierContext *>(_localctx)->intToken = match(C8086Parser::INT);

        		antlrcpp::downCast<Type_specifierContext *>(_localctx)->text =  antlrcpp::downCast<Type_specifierContext *>(_localctx)->intToken->getText();
        		std::string ruleName = "type_specifier : INT";
        		antlrcpp::downCast<Type_specifierContext *>(_localctx)->line =  std::to_string(antlrcpp::downCast<Type_specifierContext *>(_localctx)->intToken->getLine());

        		writeRuleLog(_localctx->line, ruleName);
                writeIntoparserLogFile(_localctx->text + "\n");
            
        break;
      }

      case C8086Parser::FLOAT: {
        enterOuterAlt(_localctx, 2);
        setState(77);
        antlrcpp::downCast<Type_specifierContext *>(_localctx)->floatToken = match(C8086Parser::FLOAT);

        		antlrcpp::downCast<Type_specifierContext *>(_localctx)->text =  antlrcpp::downCast<Type_specifierContext *>(_localctx)->floatToken->getText();
        		std::string ruleName = "type_specifier : FLOAT";
        		antlrcpp::downCast<Type_specifierContext *>(_localctx)->line =  std::to_string(antlrcpp::downCast<Type_specifierContext *>(_localctx)->floatToken->getLine());

        		writeRuleLog(_localctx->line, ruleName);
        		writeIntoparserLogFile(_localctx->text + "\n");
            
        break;
      }

      case C8086Parser::VOID: {
        enterOuterAlt(_localctx, 3);
        setState(79);
        antlrcpp::downCast<Type_specifierContext *>(_localctx)->voidToken = match(C8086Parser::VOID);

        		antlrcpp::downCast<Type_specifierContext *>(_localctx)->text =  antlrcpp::downCast<Type_specifierContext *>(_localctx)->voidToken->getText();
        		std::string ruleName = "type_specifier : VOID";
        		antlrcpp::downCast<Type_specifierContext *>(_localctx)->line =  std::to_string(antlrcpp::downCast<Type_specifierContext *>(_localctx)->voidToken->getLine());

        		writeRuleLog(_localctx->line, ruleName);
        		writeIntoparserLogFile(_localctx->text + "\n");
            
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

C8086Parser::Declaration_list_errContext* C8086Parser::Var_declarationContext::declaration_list_err() {
  return getRuleContext<C8086Parser::Declaration_list_errContext>(0);
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
  enterRule(_localctx, 8, C8086Parser::RuleVar_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(93);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(83);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->t = type_specifier();
      setState(84);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->dl = declaration_list(0);
      setState(85);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm = match(C8086Parser::SEMICOLON);

      		std::string ruleName = "var_declaration : type_specifier declaration_list SEMICOLON";
      		antlrcpp::downCast<Var_declarationContext *>(_localctx)->text =  antlrcpp::downCast<Var_declarationContext *>(_localctx)->t->text + " " + antlrcpp::downCast<Var_declarationContext *>(_localctx)->dl->text + antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm->getText();
      		antlrcpp::downCast<Var_declarationContext *>(_localctx)->line =  std::to_string(antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm->getLine());

      		writeRuleLog(_localctx->line, ruleName);
              writeIntoparserLogFile(_localctx->text + "\n");

      		specifySymbolType(antlrcpp::downCast<Var_declarationContext *>(_localctx)->dl->list, antlrcpp::downCast<Var_declarationContext *>(_localctx)->t->text);
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(88);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->t = type_specifier();
      setState(89);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->de = declaration_list_err();
      setState(90);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm = match(C8086Parser::SEMICOLON);

              writeIntoErrorFile("Error in variable declaration");
              syntaxErrorCount++;
          
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
  size_t startState = 10;
  enterRecursionRule(_localctx, 10, C8086Parser::RuleDeclaration_list, precedence);

    

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
    setState(103);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      setState(96);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken = match(C8086Parser::ID);

      		antlrcpp::downCast<Declaration_listContext *>(_localctx)->text =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText();
      		std::string ruleName = "declaration_list : ID";
      		antlrcpp::downCast<Declaration_listContext *>(_localctx)->line =  std::to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getLine());

      		_localctx->list.add(checkAndInsertIDVar(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText(), _localctx->line));

      		writeRuleLog(_localctx->line, ruleName);
      		writeIntoparserLogFile(_localctx->text + "\n");
      	
      break;
    }

    case 2: {
      setState(98);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken = match(C8086Parser::ID);
      setState(99);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->lthirdToken = match(C8086Parser::LTHIRD);
      setState(100);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->const_intToken = match(C8086Parser::CONST_INT);
      setState(101);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->rthirdToken = match(C8086Parser::RTHIRD);

      		antlrcpp::downCast<Declaration_listContext *>(_localctx)->text =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText() + antlrcpp::downCast<Declaration_listContext *>(_localctx)->lthirdToken->getText() + antlrcpp::downCast<Declaration_listContext *>(_localctx)->const_intToken->getText() + antlrcpp::downCast<Declaration_listContext *>(_localctx)->rthirdToken->getText();
      		std::string ruleName = "declaration_list : ID LTHIRD CONST_INT RTHIRD";
      		antlrcpp::downCast<Declaration_listContext *>(_localctx)->line =  std::to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getLine());

      		_localctx->list.add(checkAndInsertIDVar(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText(), _localctx->line, true, atoi(antlrcpp::downCast<Declaration_listContext *>(_localctx)->const_intToken->getText().c_str())));

      		writeRuleLog(_localctx->line, ruleName);
      		writeIntoparserLogFile(_localctx->text + "\n");
      	
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(118);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(116);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<Declaration_listContext>(parentContext, parentState);
          _localctx->dl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleDeclaration_list);
          setState(105);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(106);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->commaToken = match(C8086Parser::COMMA);
          setState(107);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken = match(C8086Parser::ID);

                    		antlrcpp::downCast<Declaration_listContext *>(_localctx)->text =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->dl->text + antlrcpp::downCast<Declaration_listContext *>(_localctx)->commaToken->getText() + antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText();
                    		std::string ruleName = "declaration_list : declaration_list COMMA ID";
                    		antlrcpp::downCast<Declaration_listContext *>(_localctx)->line =  std::to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getLine());

                    		antlrcpp::downCast<Declaration_listContext *>(_localctx)->list =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->dl->list;
                    		_localctx->list.add(checkAndInsertIDVar(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText(), _localctx->line));

                    		writeRuleLog(_localctx->line, ruleName);
                            writeIntoparserLogFile(_localctx->text + "\n");
                    	
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<Declaration_listContext>(parentContext, parentState);
          _localctx->dl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleDeclaration_list);
          setState(109);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(110);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->commaToken = match(C8086Parser::COMMA);
          setState(111);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken = match(C8086Parser::ID);
          setState(112);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->lthirdToken = match(C8086Parser::LTHIRD);
          setState(113);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->const_intToken = match(C8086Parser::CONST_INT);
          setState(114);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->rthirdToken = match(C8086Parser::RTHIRD);

                    		antlrcpp::downCast<Declaration_listContext *>(_localctx)->text =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->dl->text + antlrcpp::downCast<Declaration_listContext *>(_localctx)->commaToken->getText() + antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText() + antlrcpp::downCast<Declaration_listContext *>(_localctx)->lthirdToken->getText() + antlrcpp::downCast<Declaration_listContext *>(_localctx)->const_intToken->getText() + antlrcpp::downCast<Declaration_listContext *>(_localctx)->rthirdToken->getText();
                    		std::string ruleName = "declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD";
                    		antlrcpp::downCast<Declaration_listContext *>(_localctx)->line =  std::to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getLine());

                    		antlrcpp::downCast<Declaration_listContext *>(_localctx)->list =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->dl->list;
                    		_localctx->list.add(checkAndInsertIDVar(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText(), _localctx->line, true, atoi(antlrcpp::downCast<Declaration_listContext *>(_localctx)->const_intToken->getText().c_str())));

                    		writeRuleLog(_localctx->line, ruleName);
                    		writeIntoparserLogFile(_localctx->text + "\n");	
                    	
          break;
        }

        default:
          break;
        } 
      }
      setState(120);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Declaration_list_errContext ------------------------------------------------------------------

C8086Parser::Declaration_list_errContext::Declaration_list_errContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t C8086Parser::Declaration_list_errContext::getRuleIndex() const {
  return C8086Parser::RuleDeclaration_list_err;
}

void C8086Parser::Declaration_list_errContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaration_list_err(this);
}

void C8086Parser::Declaration_list_errContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaration_list_err(this);
}

C8086Parser::Declaration_list_errContext* C8086Parser::declaration_list_err() {
  Declaration_list_errContext *_localctx = _tracker.createInstance<Declaration_list_errContext>(_ctx, getState());
  enterRule(_localctx, 12, C8086Parser::RuleDeclaration_list_err);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);

    		antlrcpp::downCast<Declaration_list_errContext *>(_localctx)->text =  "Error in declaration list";
    		antlrcpp::downCast<Declaration_list_errContext *>(_localctx)->line =  "Unknown";

    		writeRuleLog(_localctx->line, "declaration_list_err");
    		writeIntoparserLogFile(_localctx->text + "\n");
    	
   
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
  size_t startState = 14;
  enterRecursionRule(_localctx, 14, C8086Parser::RuleParameter_list, precedence);

    

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
    setState(131);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      setState(124);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts = type_specifier();
      setState(125);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken = match(C8086Parser::ID);

      		std::string ruleName = "parameter_list : type_specifier ID";
      		antlrcpp::downCast<Parameter_listContext *>(_localctx)->text =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->text + " " + antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken->getText();
      		antlrcpp::downCast<Parameter_listContext *>(_localctx)->line =  std::to_string(antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken->getLine());

      		writeRuleLog(_localctx->line, ruleName);
      		writeIntoparserLogFile(_localctx->text + "\n");

      		Variable var;
      		var.name = antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken->getText();
      		var.type = toUpper(antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->text);
      		_localctx->list.add(var);
      	
      break;
    }

    case 2: {
      setState(128);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts = type_specifier();

      		std::string ruleName = "parameter_list : type_specifier";
      		antlrcpp::downCast<Parameter_listContext *>(_localctx)->text =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->text;
      		antlrcpp::downCast<Parameter_listContext *>(_localctx)->line =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->line;

      		writeRuleLog(_localctx->line, ruleName);
      		writeIntoparserLogFile(_localctx->text + "\n");

      		Variable var;
      		var.type = toUpper(antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->text);
      		_localctx->list.add(var);
      	
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(146);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(144);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<Parameter_listContext>(parentContext, parentState);
          _localctx->pl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleParameter_list);
          setState(133);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(134);
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->commaToken = match(C8086Parser::COMMA);
          setState(135);
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts = type_specifier();
          setState(136);
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken = match(C8086Parser::ID);

                    		std::string ruleName = "parameter_list : parameter_list COMMA type_specifier ID";
                    		antlrcpp::downCast<Parameter_listContext *>(_localctx)->text =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->pl->text + antlrcpp::downCast<Parameter_listContext *>(_localctx)->commaToken->getText() + antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->text + " " + antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken->getText();
                    		antlrcpp::downCast<Parameter_listContext *>(_localctx)->line =  std::to_string(antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken->getLine());

                    		writeRuleLog(_localctx->line, ruleName);
                    		writeIntoparserLogFile(_localctx->text + "\n");

                    		antlrcpp::downCast<Parameter_listContext *>(_localctx)->list =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->pl->list;
                    		Variable var;
                    		var.name = antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken->getText();
                    		var.type = toUpper(antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->text);
                    		_localctx->list.add(var);
                    	
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<Parameter_listContext>(parentContext, parentState);
          _localctx->pl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleParameter_list);
          setState(139);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(140);
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->commaToken = match(C8086Parser::COMMA);
          setState(141);
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts = type_specifier();

                    		std::string ruleName = "parameter_list : parameter_list COMMA type_specifier";
                    		antlrcpp::downCast<Parameter_listContext *>(_localctx)->text =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->pl->text + antlrcpp::downCast<Parameter_listContext *>(_localctx)->commaToken->getText() + antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->text;
                    		antlrcpp::downCast<Parameter_listContext *>(_localctx)->line =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->line;

                    		writeRuleLog(_localctx->line, ruleName);
                    		writeIntoparserLogFile(_localctx->text + "\n");

                    		antlrcpp::downCast<Parameter_listContext *>(_localctx)->list =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->pl->list;
                    		Variable var;
                    		var.type = toUpper(antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->text);
                    		_localctx->list.add(var);
                    	
          break;
        }

        default:
          break;
        } 
      }
      setState(148);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
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

tree::TerminalNode* C8086Parser::Func_declarationContext::ID() {
  return getToken(C8086Parser::ID, 0);
}

tree::TerminalNode* C8086Parser::Func_declarationContext::LPAREN() {
  return getToken(C8086Parser::LPAREN, 0);
}

tree::TerminalNode* C8086Parser::Func_declarationContext::RPAREN() {
  return getToken(C8086Parser::RPAREN, 0);
}

tree::TerminalNode* C8086Parser::Func_declarationContext::SEMICOLON() {
  return getToken(C8086Parser::SEMICOLON, 0);
}

C8086Parser::Type_specifierContext* C8086Parser::Func_declarationContext::type_specifier() {
  return getRuleContext<C8086Parser::Type_specifierContext>(0);
}

C8086Parser::Parameter_listContext* C8086Parser::Func_declarationContext::parameter_list() {
  return getRuleContext<C8086Parser::Parameter_listContext>(0);
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
  enterRule(_localctx, 16, C8086Parser::RuleFunc_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(164);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(149);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->ts = type_specifier();
      setState(150);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken = match(C8086Parser::ID);
      setState(151);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->lparenToken = match(C8086Parser::LPAREN);
      setState(152);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->pl = parameter_list(0);
      setState(153);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->rparenToken = match(C8086Parser::RPAREN);
      setState(154);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->semicolonToken = match(C8086Parser::SEMICOLON);

      		std::string ruleName = "func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON";
      		antlrcpp::downCast<Func_declarationContext *>(_localctx)->text =  antlrcpp::downCast<Func_declarationContext *>(_localctx)->ts->text + " " + antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken->getText() + antlrcpp::downCast<Func_declarationContext *>(_localctx)->lparenToken->getText() + antlrcpp::downCast<Func_declarationContext *>(_localctx)->pl->text + antlrcpp::downCast<Func_declarationContext *>(_localctx)->rparenToken->getText() + antlrcpp::downCast<Func_declarationContext *>(_localctx)->semicolonToken->getText();
      		antlrcpp::downCast<Func_declarationContext *>(_localctx)->line =  std::to_string(antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken->getLine());

      		writeRuleLog(_localctx->line, ruleName);
      		writeIntoparserLogFile(_localctx->text + "\n");

      		declareFunction(antlrcpp::downCast<Func_declarationContext *>(_localctx)->ts->text, antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken->getText(), antlrcpp::downCast<Func_declarationContext *>(_localctx)->pl->list);
      	
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(157);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->ts = type_specifier();
      setState(158);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken = match(C8086Parser::ID);
      setState(159);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->lparenToken = match(C8086Parser::LPAREN);
      setState(160);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->rparenToken = match(C8086Parser::RPAREN);
      setState(161);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->semicolonToken = match(C8086Parser::SEMICOLON);

      		std::string ruleName = "func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON";
      		antlrcpp::downCast<Func_declarationContext *>(_localctx)->text =  antlrcpp::downCast<Func_declarationContext *>(_localctx)->ts->text + " " + antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken->getText() + antlrcpp::downCast<Func_declarationContext *>(_localctx)->lparenToken->getText() + antlrcpp::downCast<Func_declarationContext *>(_localctx)->rparenToken->getText() + antlrcpp::downCast<Func_declarationContext *>(_localctx)->semicolonToken->getText();
      		antlrcpp::downCast<Func_declarationContext *>(_localctx)->line =  std::to_string(antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken->getLine());

      		writeRuleLog(_localctx->line, ruleName);
      		writeIntoparserLogFile(_localctx->text + "\n");

      		declareFunction(antlrcpp::downCast<Func_declarationContext *>(_localctx)->ts->text, antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken->getText(), param_list());
      	
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

C8086Parser::Type_specifierContext* C8086Parser::Func_definitionContext::type_specifier() {
  return getRuleContext<C8086Parser::Type_specifierContext>(0);
}

C8086Parser::Parameter_listContext* C8086Parser::Func_definitionContext::parameter_list() {
  return getRuleContext<C8086Parser::Parameter_listContext>(0);
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
  enterRule(_localctx, 18, C8086Parser::RuleFunc_definition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(182);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(166);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->ts = type_specifier();
      setState(167);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken = match(C8086Parser::ID);
      setState(168);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->lparenToken = match(C8086Parser::LPAREN);
      setState(169);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->pl = parameter_list(0);
      setState(170);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->rparenToken = match(C8086Parser::RPAREN);
      setParam(_localctx->line, antlrcpp::downCast<Func_definitionContext *>(_localctx)->pl->list);
      setState(172);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs = compound_statement();

      		std::string ruleName = "func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement";
      		antlrcpp::downCast<Func_definitionContext *>(_localctx)->text =  antlrcpp::downCast<Func_definitionContext *>(_localctx)->ts->text + " " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() + antlrcpp::downCast<Func_definitionContext *>(_localctx)->lparenToken->getText() + antlrcpp::downCast<Func_definitionContext *>(_localctx)->pl->text + antlrcpp::downCast<Func_definitionContext *>(_localctx)->rparenToken->getText() + antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs->text;
      		antlrcpp::downCast<Func_definitionContext *>(_localctx)->line =  antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs->line;

      		writeRuleLog(_localctx->line, ruleName);
      		writeIntoparserLogFile(_localctx->text + "\n");

      		defineFunction(antlrcpp::downCast<Func_definitionContext *>(_localctx)->ts->text, antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText(), antlrcpp::downCast<Func_definitionContext *>(_localctx)->pl->list);
      		clearParam();
      	
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(175);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->ts = type_specifier();
      setState(176);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken = match(C8086Parser::ID);
      setState(177);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->lparenToken = match(C8086Parser::LPAREN);
      setState(178);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->rparenToken = match(C8086Parser::RPAREN);
      setState(179);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs = compound_statement();

      		std::string ruleName = "func_definition : type_specifier ID LPAREN RPAREN compound_statement";
      		antlrcpp::downCast<Func_definitionContext *>(_localctx)->text =  antlrcpp::downCast<Func_definitionContext *>(_localctx)->ts->text + " " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() + antlrcpp::downCast<Func_definitionContext *>(_localctx)->lparenToken->getText() + antlrcpp::downCast<Func_definitionContext *>(_localctx)->rparenToken->getText() + antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs->text;
      		antlrcpp::downCast<Func_definitionContext *>(_localctx)->line =  antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs->line;

      		writeRuleLog(_localctx->line, ruleName);
      		writeIntoparserLogFile(_localctx->text + "\n");

      		defineFunction(antlrcpp::downCast<Func_definitionContext *>(_localctx)->ts->text, antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText(), param_list());
      	
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

tree::TerminalNode* C8086Parser::Compound_statementContext::RCURL() {
  return getToken(C8086Parser::RCURL, 0);
}

C8086Parser::StatementsContext* C8086Parser::Compound_statementContext::statements() {
  return getRuleContext<C8086Parser::StatementsContext>(0);
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
  enterRule(_localctx, 20, C8086Parser::RuleCompound_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(193);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(184);
      antlrcpp::downCast<Compound_statementContext *>(_localctx)->lcurlToken = match(C8086Parser::LCURL);
      enterScope();
      setState(186);
      antlrcpp::downCast<Compound_statementContext *>(_localctx)->s = statements(0);
      setState(187);
      antlrcpp::downCast<Compound_statementContext *>(_localctx)->rcurlToken = match(C8086Parser::RCURL);

      		std::string ruleName = "compound_statement : LCURL statements RCURL";
      		antlrcpp::downCast<Compound_statementContext *>(_localctx)->text =  antlrcpp::downCast<Compound_statementContext *>(_localctx)->lcurlToken->getText() + "\n" + antlrcpp::downCast<Compound_statementContext *>(_localctx)->s->text + "\n" + antlrcpp::downCast<Compound_statementContext *>(_localctx)->rcurlToken->getText();
      		antlrcpp::downCast<Compound_statementContext *>(_localctx)->line =  std::to_string(antlrcpp::downCast<Compound_statementContext *>(_localctx)->rcurlToken->getLine());

      		writeRuleLog(_localctx->line, ruleName);
      		writeIntoparserLogFile(_localctx->text + "\n");

      		exitScope();
      	
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(190);
      antlrcpp::downCast<Compound_statementContext *>(_localctx)->lcurlToken = match(C8086Parser::LCURL);
      setState(191);
      antlrcpp::downCast<Compound_statementContext *>(_localctx)->rcurlToken = match(C8086Parser::RCURL);

      		std::string ruleName = "compound_statement : LCURL RCURL";
      		antlrcpp::downCast<Compound_statementContext *>(_localctx)->text =  antlrcpp::downCast<Compound_statementContext *>(_localctx)->lcurlToken->getText() + antlrcpp::downCast<Compound_statementContext *>(_localctx)->rcurlToken->getText();
      		antlrcpp::downCast<Compound_statementContext *>(_localctx)->line =  std::to_string(antlrcpp::downCast<Compound_statementContext *>(_localctx)->rcurlToken->getLine());

      		writeRuleLog(_localctx->line, ruleName);
      		writeIntoparserLogFile(_localctx->text + "\n");
      	
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
  size_t startState = 22;
  enterRecursionRule(_localctx, 22, C8086Parser::RuleStatements, precedence);

    

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
    setState(196);
    antlrcpp::downCast<StatementsContext *>(_localctx)->s = statement();

    		std::string ruleName = "statements : statement";
    		antlrcpp::downCast<StatementsContext *>(_localctx)->text =  antlrcpp::downCast<StatementsContext *>(_localctx)->s->text;
    		antlrcpp::downCast<StatementsContext *>(_localctx)->line =  antlrcpp::downCast<StatementsContext *>(_localctx)->s->line;

    		writeRuleLog(_localctx->line, ruleName);
    		writeIntoparserLogFile(_localctx->text + "\n");
    	
    _ctx->stop = _input->LT(-1);
    setState(205);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<StatementsContext>(parentContext, parentState);
        _localctx->ss = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleStatements);
        setState(199);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(200);
        antlrcpp::downCast<StatementsContext *>(_localctx)->s = statement();

                  		std::string ruleName = "statements : statements statement";
                  		antlrcpp::downCast<StatementsContext *>(_localctx)->text =  antlrcpp::downCast<StatementsContext *>(_localctx)->ss->text + "\n" + antlrcpp::downCast<StatementsContext *>(_localctx)->s->text;
                  		antlrcpp::downCast<StatementsContext *>(_localctx)->line =  antlrcpp::downCast<StatementsContext *>(_localctx)->s->line;

                  		writeRuleLog(_localctx->line, ruleName);
                  		writeIntoparserLogFile(_localctx->text + "\n");
                  	 
      }
      setState(207);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
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

C8086Parser::ExpressionContext* C8086Parser::StatementContext::expression() {
  return getRuleContext<C8086Parser::ExpressionContext>(0);
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
  enterRule(_localctx, 24, C8086Parser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(260);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(208);
      antlrcpp::downCast<StatementContext *>(_localctx)->vd = var_declaration();

      		std::string ruleName = "statement : var_declaration";
      		antlrcpp::downCast<StatementContext *>(_localctx)->text =  antlrcpp::downCast<StatementContext *>(_localctx)->vd->text;
      		antlrcpp::downCast<StatementContext *>(_localctx)->line =  antlrcpp::downCast<StatementContext *>(_localctx)->vd->line;

      		writeRuleLog(_localctx->line, ruleName);
      		writeIntoparserLogFile(_localctx->text + "\n");
      	
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(211);
      antlrcpp::downCast<StatementContext *>(_localctx)->es = expression_statement();

      		std::string ruleName = "statement : expression_statement";
      		antlrcpp::downCast<StatementContext *>(_localctx)->text =  antlrcpp::downCast<StatementContext *>(_localctx)->es->text;
      		antlrcpp::downCast<StatementContext *>(_localctx)->line =  antlrcpp::downCast<StatementContext *>(_localctx)->es->line;

      		writeRuleLog(_localctx->line, ruleName);
      		writeIntoparserLogFile(_localctx->text + "\n");
      	
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(214);
      antlrcpp::downCast<StatementContext *>(_localctx)->cs = compound_statement();

      		std::string ruleName = "statement : compound_statement";
      		antlrcpp::downCast<StatementContext *>(_localctx)->text =  antlrcpp::downCast<StatementContext *>(_localctx)->cs->text;
      		antlrcpp::downCast<StatementContext *>(_localctx)->line =  antlrcpp::downCast<StatementContext *>(_localctx)->cs->line;

      		writeRuleLog(_localctx->line, ruleName);
      		writeIntoparserLogFile(_localctx->text + "\n");
      	
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(217);
      antlrcpp::downCast<StatementContext *>(_localctx)->forToken = match(C8086Parser::FOR);
      setState(218);
      antlrcpp::downCast<StatementContext *>(_localctx)->lparenToken = match(C8086Parser::LPAREN);
      setState(219);
      antlrcpp::downCast<StatementContext *>(_localctx)->es1 = expression_statement();
      setState(220);
      antlrcpp::downCast<StatementContext *>(_localctx)->es2 = expression_statement();
      setState(221);
      antlrcpp::downCast<StatementContext *>(_localctx)->e = expression();
      setState(222);
      antlrcpp::downCast<StatementContext *>(_localctx)->rparenToken = match(C8086Parser::RPAREN);
      setState(223);
      antlrcpp::downCast<StatementContext *>(_localctx)->s = statement();

      		std::string ruleName = "statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement";
      		antlrcpp::downCast<StatementContext *>(_localctx)->text =  antlrcpp::downCast<StatementContext *>(_localctx)->forToken->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->lparenToken->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->es1->text + antlrcpp::downCast<StatementContext *>(_localctx)->es2->text + antlrcpp::downCast<StatementContext *>(_localctx)->e->text + antlrcpp::downCast<StatementContext *>(_localctx)->rparenToken->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->s->text;
      		antlrcpp::downCast<StatementContext *>(_localctx)->line =  antlrcpp::downCast<StatementContext *>(_localctx)->s->line;

      		writeRuleLog(_localctx->line, ruleName);
      		writeIntoparserLogFile(_localctx->text + "\n");
      	
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(226);
      antlrcpp::downCast<StatementContext *>(_localctx)->ifToken = match(C8086Parser::IF);
      setState(227);
      antlrcpp::downCast<StatementContext *>(_localctx)->lparenToken = match(C8086Parser::LPAREN);
      setState(228);
      antlrcpp::downCast<StatementContext *>(_localctx)->e = expression();
      setState(229);
      antlrcpp::downCast<StatementContext *>(_localctx)->rparenToken = match(C8086Parser::RPAREN);
      setState(230);
      antlrcpp::downCast<StatementContext *>(_localctx)->s = statement();

      		std::string ruleName = "statement : IF LPAREN expression RPAREN statement";
      		antlrcpp::downCast<StatementContext *>(_localctx)->text =  antlrcpp::downCast<StatementContext *>(_localctx)->ifToken->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->lparenToken->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->e->text + antlrcpp::downCast<StatementContext *>(_localctx)->rparenToken->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->s->text;
      		antlrcpp::downCast<StatementContext *>(_localctx)->line =  antlrcpp::downCast<StatementContext *>(_localctx)->s->line;

      		writeRuleLog(_localctx->line, ruleName);
      		writeIntoparserLogFile(_localctx->text + "\n");
      	
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(233);
      antlrcpp::downCast<StatementContext *>(_localctx)->ifToken = match(C8086Parser::IF);
      setState(234);
      antlrcpp::downCast<StatementContext *>(_localctx)->lparenToken = match(C8086Parser::LPAREN);
      setState(235);
      antlrcpp::downCast<StatementContext *>(_localctx)->e = expression();
      setState(236);
      antlrcpp::downCast<StatementContext *>(_localctx)->rparenToken = match(C8086Parser::RPAREN);
      setState(237);
      antlrcpp::downCast<StatementContext *>(_localctx)->s1 = statement();
      setState(238);
      antlrcpp::downCast<StatementContext *>(_localctx)->elseToken = match(C8086Parser::ELSE);
      setState(239);
      antlrcpp::downCast<StatementContext *>(_localctx)->s2 = statement();

      		std::string ruleName = "statement : IF LPAREN expression RPAREN statement ELSE statement";
      		antlrcpp::downCast<StatementContext *>(_localctx)->text =  antlrcpp::downCast<StatementContext *>(_localctx)->ifToken->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->lparenToken->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->e->text + antlrcpp::downCast<StatementContext *>(_localctx)->rparenToken->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->s1->text + antlrcpp::downCast<StatementContext *>(_localctx)->elseToken->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->s2->text;
      		antlrcpp::downCast<StatementContext *>(_localctx)->line =  antlrcpp::downCast<StatementContext *>(_localctx)->s2->line;

      		writeRuleLog(_localctx->line, ruleName);
      		writeIntoparserLogFile(_localctx->text + "\n");
      	
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(242);
      antlrcpp::downCast<StatementContext *>(_localctx)->whileToken = match(C8086Parser::WHILE);
      setState(243);
      antlrcpp::downCast<StatementContext *>(_localctx)->lparenToken = match(C8086Parser::LPAREN);
      setState(244);
      antlrcpp::downCast<StatementContext *>(_localctx)->e = expression();
      setState(245);
      antlrcpp::downCast<StatementContext *>(_localctx)->rparenToken = match(C8086Parser::RPAREN);
      setState(246);
      antlrcpp::downCast<StatementContext *>(_localctx)->s = statement();

      		std::string ruleName = "statement : WHILE LPAREN expression RPAREN statement";
      		antlrcpp::downCast<StatementContext *>(_localctx)->text =  antlrcpp::downCast<StatementContext *>(_localctx)->whileToken->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->lparenToken->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->e->text + antlrcpp::downCast<StatementContext *>(_localctx)->rparenToken->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->s->text;
      		antlrcpp::downCast<StatementContext *>(_localctx)->line =  antlrcpp::downCast<StatementContext *>(_localctx)->s->line;

      		writeRuleLog(_localctx->line, ruleName);
      		writeIntoparserLogFile(_localctx->text + "\n");
      	
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(249);
      antlrcpp::downCast<StatementContext *>(_localctx)->printlnToken = match(C8086Parser::PRINTLN);
      setState(250);
      antlrcpp::downCast<StatementContext *>(_localctx)->lparenToken = match(C8086Parser::LPAREN);
      setState(251);
      antlrcpp::downCast<StatementContext *>(_localctx)->idToken = match(C8086Parser::ID);
      setState(252);
      antlrcpp::downCast<StatementContext *>(_localctx)->rparenToken = match(C8086Parser::RPAREN);
      setState(253);
      antlrcpp::downCast<StatementContext *>(_localctx)->semicolonToken = match(C8086Parser::SEMICOLON);

      		std::string ruleName = "statement : PRINTLN LPAREN ID RPAREN SEMICOLON";
      		antlrcpp::downCast<StatementContext *>(_localctx)->text =  antlrcpp::downCast<StatementContext *>(_localctx)->printlnToken->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->lparenToken->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->idToken->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->rparenToken->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->semicolonToken->getText();
      		antlrcpp::downCast<StatementContext *>(_localctx)->line =  std::to_string(antlrcpp::downCast<StatementContext *>(_localctx)->printlnToken->getLine());

      		writeRuleLog(_localctx->line, ruleName);
      		writeIntoparserLogFile(_localctx->text + "\n");
      	
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(255);
      antlrcpp::downCast<StatementContext *>(_localctx)->returnToken = match(C8086Parser::RETURN);
      setState(256);
      antlrcpp::downCast<StatementContext *>(_localctx)->e = expression();
      setState(257);
      antlrcpp::downCast<StatementContext *>(_localctx)->semicolonToken = match(C8086Parser::SEMICOLON);

      		std::string ruleName = "statement : RETURN expression SEMICOLON";
      		antlrcpp::downCast<StatementContext *>(_localctx)->text =  antlrcpp::downCast<StatementContext *>(_localctx)->returnToken->getText() + " " +  antlrcpp::downCast<StatementContext *>(_localctx)->e->text + antlrcpp::downCast<StatementContext *>(_localctx)->semicolonToken->getText();
      		antlrcpp::downCast<StatementContext *>(_localctx)->line =  std::to_string(antlrcpp::downCast<StatementContext *>(_localctx)->returnToken->getLine());

      		writeRuleLog(_localctx->line, ruleName);
      		writeIntoparserLogFile(_localctx->text + "\n");
      	
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
  enterRule(_localctx, 26, C8086Parser::RuleExpression_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(268);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C8086Parser::SEMICOLON: {
        enterOuterAlt(_localctx, 1);
        setState(262);
        antlrcpp::downCast<Expression_statementContext *>(_localctx)->semicolonToken = match(C8086Parser::SEMICOLON);

        		std::string ruleName = "expression_statement : SEMICOLON";
        		antlrcpp::downCast<Expression_statementContext *>(_localctx)->text =  antlrcpp::downCast<Expression_statementContext *>(_localctx)->semicolonToken->getText();
        		antlrcpp::downCast<Expression_statementContext *>(_localctx)->line =  std::to_string(antlrcpp::downCast<Expression_statementContext *>(_localctx)->semicolonToken->getLine());

        		writeRuleLog(_localctx->line, ruleName);
        		writeIntoparserLogFile(_localctx->text + "\n");
        	
        break;
      }

      case C8086Parser::LPAREN:
      case C8086Parser::ADDOP:
      case C8086Parser::NOT:
      case C8086Parser::ID:
      case C8086Parser::CONST_INT:
      case C8086Parser::CONST_FLOAT: {
        enterOuterAlt(_localctx, 2);
        setState(264);
        antlrcpp::downCast<Expression_statementContext *>(_localctx)->e = expression();
        setState(265);
        antlrcpp::downCast<Expression_statementContext *>(_localctx)->semicolonToken = match(C8086Parser::SEMICOLON);

        		std::string ruleName = "expression_statement : expression SEMICOLON";
        		antlrcpp::downCast<Expression_statementContext *>(_localctx)->text =  antlrcpp::downCast<Expression_statementContext *>(_localctx)->e->text + antlrcpp::downCast<Expression_statementContext *>(_localctx)->semicolonToken->getText();
        		antlrcpp::downCast<Expression_statementContext *>(_localctx)->line =  antlrcpp::downCast<Expression_statementContext *>(_localctx)->e->line;

        		writeRuleLog(_localctx->line, ruleName);
        		writeIntoparserLogFile(_localctx->text + "\n");
        	
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
  enterRule(_localctx, 28, C8086Parser::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(278);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(270);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->le = logic_expression();

      		std::string ruleName = "expression : logic_expression";
      		antlrcpp::downCast<ExpressionContext *>(_localctx)->text =  antlrcpp::downCast<ExpressionContext *>(_localctx)->le->text;
      		antlrcpp::downCast<ExpressionContext *>(_localctx)->line =  antlrcpp::downCast<ExpressionContext *>(_localctx)->le->line;

      		writeRuleLog(_localctx->line, ruleName);
      		writeIntoparserLogFile(_localctx->text + "\n");

      		antlrcpp::downCast<ExpressionContext *>(_localctx)->id =  antlrcpp::downCast<ExpressionContext *>(_localctx)->le->id;
      		printIdentifier(_localctx->id);
      	
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(273);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->v = variable();
      setState(274);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->assignopToken = match(C8086Parser::ASSIGNOP);
      setState(275);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->le = logic_expression();

      		std::string ruleName = "expression : variable ASSIGNOP logic_expression";
      		antlrcpp::downCast<ExpressionContext *>(_localctx)->text =  antlrcpp::downCast<ExpressionContext *>(_localctx)->v->text + antlrcpp::downCast<ExpressionContext *>(_localctx)->assignopToken->getText() + antlrcpp::downCast<ExpressionContext *>(_localctx)->le->text;
      		antlrcpp::downCast<ExpressionContext *>(_localctx)->line =  std::to_string(antlrcpp::downCast<ExpressionContext *>(_localctx)->assignopToken->getLine());

      		writeRuleLog(_localctx->line, ruleName);

      		assignment(antlrcpp::downCast<ExpressionContext *>(_localctx)->v->id,antlrcpp::downCast<ExpressionContext *>(_localctx)->le->id,_localctx->line);

      		writeIntoparserLogFile(_localctx->text + "\n");	

      		antlrcpp::downCast<ExpressionContext *>(_localctx)->id =  antlrcpp::downCast<ExpressionContext *>(_localctx)->v->id;
      		printIdentifier(_localctx->id);	
      	
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
  enterRule(_localctx, 30, C8086Parser::RuleLogic_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(288);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(280);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re = rel_expression();

      		std::string ruleName = "logic_expression : rel_expression";
      		antlrcpp::downCast<Logic_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re->text;
      		antlrcpp::downCast<Logic_expressionContext *>(_localctx)->line =  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re->line;

      		writeRuleLog(_localctx->line, ruleName);
      		writeIntoparserLogFile(_localctx->text + "\n");

      		antlrcpp::downCast<Logic_expressionContext *>(_localctx)->id =  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re->id;
      		printIdentifier(_localctx->id);
      	
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(283);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re1 = rel_expression();
      setState(284);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->logicopToken = match(C8086Parser::LOGICOP);
      setState(285);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re2 = rel_expression();

      		std::string ruleName = "logic_expression : rel_expression LOGICOP rel_expression";
      		antlrcpp::downCast<Logic_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re1->text + antlrcpp::downCast<Logic_expressionContext *>(_localctx)->logicopToken->getText() + antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re2->text;
      		antlrcpp::downCast<Logic_expressionContext *>(_localctx)->line =  std::to_string(antlrcpp::downCast<Logic_expressionContext *>(_localctx)->logicopToken->getLine());

      		writeRuleLog(_localctx->line, ruleName);
      		writeIntoparserLogFile(_localctx->text + "\n");

      		// antlrcpp::downCast<Logic_expressionContext *>(_localctx)->id =  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re2->id;
      		_localctx->id.idType = "INT";
      		printIdentifier(_localctx->id);
      	
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
  enterRule(_localctx, 32, C8086Parser::RuleVariable);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(298);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(290);
      antlrcpp::downCast<VariableContext *>(_localctx)->idToken = match(C8086Parser::ID);

      		std::string ruleName = "variable : ID";
      		antlrcpp::downCast<VariableContext *>(_localctx)->text =  antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText();
      		antlrcpp::downCast<VariableContext *>(_localctx)->line =  std::to_string(antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getLine());

      		writeRuleLog(_localctx->line, ruleName);

      		SymbolInfo* symbol = symbolTable.lookUpInCurrentScope(antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText());
      		if(symbol == NULL) {symbol = symbolTable.lookUp(antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText());}
      		if (symbol != NULL) {antlrcpp::downCast<VariableContext *>(_localctx)->id =  symbol->id;}
      		printIdentifier(_localctx->id);

      		if(symbol == NULL) {
      			writeIntoErrorFile("Error at line " + _localctx->line + ": Undeclared variable "  + antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText()+ "\n");
      			syntaxErrorCount++;
      			writeIntoparserLogFile("Error at line " + _localctx->line + ": Identifier " + antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText() + " not declared" + "\n");
      		}
      		else if(_localctx->id.isArray){
      			writeIntoErrorFile("Error at line " + _localctx->line + ": Type mismatch " + antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText() + " is an array" + "\n");
      			syntaxErrorCount++;
      			writeIntoparserLogFile("Error at line " + _localctx->line + ": Type mismatch " + antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText() + " is an array" + "\n");
      		}

      		writeIntoparserLogFile(_localctx->text + "\n");
      	
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(292);
      antlrcpp::downCast<VariableContext *>(_localctx)->idToken = match(C8086Parser::ID);
      setState(293);
      antlrcpp::downCast<VariableContext *>(_localctx)->lthirdToken = match(C8086Parser::LTHIRD);
      setState(294);
      antlrcpp::downCast<VariableContext *>(_localctx)->e = expression();
      setState(295);
      antlrcpp::downCast<VariableContext *>(_localctx)->rthirdToken = match(C8086Parser::RTHIRD);

      		std::string ruleName = "variable : ID LTHIRD expression RTHIRD";
      		antlrcpp::downCast<VariableContext *>(_localctx)->text =  antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText() + antlrcpp::downCast<VariableContext *>(_localctx)->lthirdToken->getText() + antlrcpp::downCast<VariableContext *>(_localctx)->e->text + antlrcpp::downCast<VariableContext *>(_localctx)->rthirdToken->getText();
      		antlrcpp::downCast<VariableContext *>(_localctx)->line =  std::to_string(antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getLine());

      		writeRuleLog(_localctx->line, ruleName);

      		SymbolInfo* symbol = symbolTable.lookUpInCurrentScope(antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText());
      		if(symbol == NULL) {symbol = symbolTable.lookUp(antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText());}
      		if (symbol != NULL) {antlrcpp::downCast<VariableContext *>(_localctx)->id =  symbol->id;}
      		printIdentifier(_localctx->id);

      		if(symbol == NULL) {
      			writeIntoErrorFile("Error at line " + _localctx->line + ": Undeclared variable "  + antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText()+ "\n");
      			syntaxErrorCount++;
      			writeIntoparserLogFile("Error at line " + _localctx->line + ": Identifier " + antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText() + " not declared" + "\n");
      		}
      		else if(_localctx->id.isArray == false) {
      			writeIntoErrorFile("Error at line " + _localctx->line + ": Type mismatch " + antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText() + " is not an array" + "\n");
      			syntaxErrorCount++;
      			writeIntoparserLogFile("Error at line " + _localctx->line + ": Type mismatch " + antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText() + " is not an array" + "\n");
      		}
      		else if(!isInt(antlrcpp::downCast<VariableContext *>(_localctx)->e->text)) {
      			writeIntoErrorFile("Error at line " + _localctx->line + ": Expression inside third brackets not an integer" + "\n");
      			syntaxErrorCount++;
      			writeIntoparserLogFile("Error at line " + _localctx->line + ": Expression inside third brackets not an integer" + "\n");
      		}		

      		writeIntoparserLogFile(_localctx->text + "\n");
      	
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
  enterRule(_localctx, 34, C8086Parser::RuleRel_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(308);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(300);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->se = simple_expression(0);

      		std::string ruleName = "rel_expression : simple_expression";
      		antlrcpp::downCast<Rel_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->se->text;
      		antlrcpp::downCast<Rel_expressionContext *>(_localctx)->line =  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->se->line;

      		writeRuleLog(_localctx->line, ruleName);
      		writeIntoparserLogFile(_localctx->text + "\n");

      		antlrcpp::downCast<Rel_expressionContext *>(_localctx)->id =  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->se->id;
      		printIdentifier(_localctx->id);
      	
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(303);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->se1 = simple_expression(0);
      setState(304);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken = match(C8086Parser::RELOP);
      setState(305);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->se2 = simple_expression(0);

      		std::string ruleName = "rel_expression : simple_expression RELOP simple_expression";
      		antlrcpp::downCast<Rel_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->se1->text + antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken->getText() + antlrcpp::downCast<Rel_expressionContext *>(_localctx)->se2->text;
      		antlrcpp::downCast<Rel_expressionContext *>(_localctx)->line =  std::to_string(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken->getLine());

      		writeRuleLog(_localctx->line, ruleName);
      		writeIntoparserLogFile(_localctx->text + "\n");

      		// antlrcpp::downCast<Rel_expressionContext *>(_localctx)->id =  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->se2->id;
      		_localctx->id.idType = "INT";
      		printIdentifier(_localctx->id);
      	
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
  size_t startState = 36;
  enterRecursionRule(_localctx, 36, C8086Parser::RuleSimple_expression, precedence);

    

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
    setState(311);
    antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t = term(0);

    		std::string ruleName = "simple_expression : term";
    		antlrcpp::downCast<Simple_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->text;
    		antlrcpp::downCast<Simple_expressionContext *>(_localctx)->line =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->line;

    		writeRuleLog(_localctx->line, ruleName);
    		writeIntoparserLogFile(_localctx->text + "\n");

    		antlrcpp::downCast<Simple_expressionContext *>(_localctx)->id =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->id;
    		printIdentifier(_localctx->id);
    	
    _ctx->stop = _input->LT(-1);
    setState(321);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Simple_expressionContext>(parentContext, parentState);
        _localctx->se = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleSimple_expression);
        setState(314);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(315);
        antlrcpp::downCast<Simple_expressionContext *>(_localctx)->addopToken = match(C8086Parser::ADDOP);
        setState(316);
        antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t = term(0);

                  		std::string ruleName = "simple_expression : simple_expression ADDOP term";
                  		antlrcpp::downCast<Simple_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->se->text + antlrcpp::downCast<Simple_expressionContext *>(_localctx)->addopToken->getText() + antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->text;
                  		antlrcpp::downCast<Simple_expressionContext *>(_localctx)->line =  std::to_string(antlrcpp::downCast<Simple_expressionContext *>(_localctx)->addopToken->getLine());

                  		writeRuleLog(_localctx->line, ruleName);
                  		writeIntoparserLogFile(_localctx->text + "\n");

                  		if(antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->id.idType == "FLOAT" || antlrcpp::downCast<Simple_expressionContext *>(_localctx)->se->id.idType == "FLOAT") {
                  			_localctx->id.idType = "FLOAT";
                  		} else {
                  			_localctx->id.idType = "INT";
                  		}
                  		printIdentifier(_localctx->id);
                  	 
      }
      setState(323);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
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
  size_t startState = 38;
  enterRecursionRule(_localctx, 38, C8086Parser::RuleTerm, precedence);

    

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
    setState(325);
    antlrcpp::downCast<TermContext *>(_localctx)->ue = unary_expression();

    		std::string ruleName = "term : unary_expression";
    		antlrcpp::downCast<TermContext *>(_localctx)->text =  antlrcpp::downCast<TermContext *>(_localctx)->ue->text;
    		antlrcpp::downCast<TermContext *>(_localctx)->line =  antlrcpp::downCast<TermContext *>(_localctx)->ue->line;

    		writeRuleLog(_localctx->line, ruleName);
    		writeIntoparserLogFile(_localctx->text + "\n");

    		antlrcpp::downCast<TermContext *>(_localctx)->id =  antlrcpp::downCast<TermContext *>(_localctx)->ue->id;
    		printIdentifier(_localctx->id);
    	
    _ctx->stop = _input->LT(-1);
    setState(335);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<TermContext>(parentContext, parentState);
        _localctx->t = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleTerm);
        setState(328);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(329);
        antlrcpp::downCast<TermContext *>(_localctx)->mulopToken = match(C8086Parser::MULOP);
        setState(330);
        antlrcpp::downCast<TermContext *>(_localctx)->ue = unary_expression();

                  		std::string ruleName = "term : term MULOP unary_expression";
                  		antlrcpp::downCast<TermContext *>(_localctx)->text =  antlrcpp::downCast<TermContext *>(_localctx)->t->text + antlrcpp::downCast<TermContext *>(_localctx)->mulopToken->getText() + antlrcpp::downCast<TermContext *>(_localctx)->ue->text;
                  		antlrcpp::downCast<TermContext *>(_localctx)->line =  std::to_string(antlrcpp::downCast<TermContext *>(_localctx)->mulopToken->getLine());

                  		writeRuleLog(_localctx->line, ruleName);

                  		// antlrcpp::downCast<TermContext *>(_localctx)->id =  antlrcpp::downCast<TermContext *>(_localctx)->ue->id;
                  		if(antlrcpp::downCast<TermContext *>(_localctx)->t->id.idType == "FLOAT" || antlrcpp::downCast<TermContext *>(_localctx)->ue->id.idType == "FLOAT") {
                  			_localctx->id.idType = "FLOAT";
                  		} else {
                  			_localctx->id.idType = "INT";
                  		}
                  		printIdentifier(_localctx->id);
                  		if(antlrcpp::downCast<TermContext *>(_localctx)->mulopToken->getText() == "%"){
                  			if(antlrcpp::downCast<TermContext *>(_localctx)->ue->id.idType != "INT" || antlrcpp::downCast<TermContext *>(_localctx)->t->id.idType != "INT") {
                  				writeIntoErrorFile("Error at line " + _localctx->line + ": Non-Integer operand on modulus operator" + "\n");
                  				syntaxErrorCount++;
                  				writeIntoparserLogFile("Error at line " + _localctx->line + ": Non-Integer operand on modulus operator" + "\n");
                  			}
                  			_localctx->id.idType = "INT";
                  		}

                  		writeIntoparserLogFile(_localctx->text + "\n");
                  	 
      }
      setState(337);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
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
  enterRule(_localctx, 40, C8086Parser::RuleUnary_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(349);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C8086Parser::ADDOP: {
        enterOuterAlt(_localctx, 1);
        setState(338);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->addopToken = match(C8086Parser::ADDOP);
        setState(339);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->ue = unary_expression();

        		std::string ruleName = "unary_expression : ADDOP unary_expression";
        		antlrcpp::downCast<Unary_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->addopToken->getText() + antlrcpp::downCast<Unary_expressionContext *>(_localctx)->ue->text;
        		antlrcpp::downCast<Unary_expressionContext *>(_localctx)->line =  std::to_string(antlrcpp::downCast<Unary_expressionContext *>(_localctx)->addopToken->getLine());

        		writeRuleLog(_localctx->line, ruleName);
        		writeIntoparserLogFile(_localctx->text + "\n");

        		antlrcpp::downCast<Unary_expressionContext *>(_localctx)->id =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->ue->id;
        		printIdentifier(_localctx->id);
        	
        break;
      }

      case C8086Parser::NOT: {
        enterOuterAlt(_localctx, 2);
        setState(342);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->notToken = match(C8086Parser::NOT);
        setState(343);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->ue = unary_expression();

        		std::string ruleName = "unary_expression : NOT unary_expression";
        		antlrcpp::downCast<Unary_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->notToken->getText() + antlrcpp::downCast<Unary_expressionContext *>(_localctx)->ue->text;
        		antlrcpp::downCast<Unary_expressionContext *>(_localctx)->line =  std::to_string(antlrcpp::downCast<Unary_expressionContext *>(_localctx)->notToken->getLine());

        		writeRuleLog(_localctx->line, ruleName);
        		writeIntoparserLogFile(_localctx->text + "\n");

        		antlrcpp::downCast<Unary_expressionContext *>(_localctx)->id =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->ue->id;
        		printIdentifier(_localctx->id);
        	
        break;
      }

      case C8086Parser::LPAREN:
      case C8086Parser::ID:
      case C8086Parser::CONST_INT:
      case C8086Parser::CONST_FLOAT: {
        enterOuterAlt(_localctx, 3);
        setState(346);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->f = factor();

        		std::string ruleName = "unary_expression : factor";
        		antlrcpp::downCast<Unary_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->f->text;
        		antlrcpp::downCast<Unary_expressionContext *>(_localctx)->line =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->f->line;

        		writeRuleLog(_localctx->line, ruleName);
        		writeIntoparserLogFile(_localctx->text + "\n");

        		antlrcpp::downCast<Unary_expressionContext *>(_localctx)->id =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->f->id;
        		printIdentifier(_localctx->id);
        	
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
  enterRule(_localctx, 42, C8086Parser::RuleFactor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(377);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(351);
      antlrcpp::downCast<FactorContext *>(_localctx)->v = variable();

      		std::string ruleName = "factor : variable";
      		antlrcpp::downCast<FactorContext *>(_localctx)->text =  antlrcpp::downCast<FactorContext *>(_localctx)->v->text;
      		antlrcpp::downCast<FactorContext *>(_localctx)->line =  antlrcpp::downCast<FactorContext *>(_localctx)->v->line;

      		writeRuleLog(_localctx->line, ruleName);
      		writeIntoparserLogFile(_localctx->text + "\n");

      		antlrcpp::downCast<FactorContext *>(_localctx)->id =  antlrcpp::downCast<FactorContext *>(_localctx)->v->id;
      		printIdentifier(_localctx->id);
      	
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(354);
      antlrcpp::downCast<FactorContext *>(_localctx)->idToken = match(C8086Parser::ID);
      setState(355);
      antlrcpp::downCast<FactorContext *>(_localctx)->lparenToken = match(C8086Parser::LPAREN);
      setState(356);
      antlrcpp::downCast<FactorContext *>(_localctx)->al = argument_list();
      setState(357);
      antlrcpp::downCast<FactorContext *>(_localctx)->rparenToken = match(C8086Parser::RPAREN);

      		std::string ruleName = "factor : ID LPAREN argument_list RPAREN";
      		antlrcpp::downCast<FactorContext *>(_localctx)->text =  antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getText() + antlrcpp::downCast<FactorContext *>(_localctx)->lparenToken->getText() + antlrcpp::downCast<FactorContext *>(_localctx)->al->text + antlrcpp::downCast<FactorContext *>(_localctx)->rparenToken->getText();
      		antlrcpp::downCast<FactorContext *>(_localctx)->line =  std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getLine());

      		writeRuleLog(_localctx->line, ruleName);
      		writeIntoparserLogFile(_localctx->text + "\n");

      		_localctx->id.idType = callFunctionInExpression(antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getText(), antlrcpp::downCast<FactorContext *>(_localctx)->al->list, _localctx->line);
      		printIdentifier(_localctx->id);
      	
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(360);
      antlrcpp::downCast<FactorContext *>(_localctx)->lparenToken = match(C8086Parser::LPAREN);
      setState(361);
      antlrcpp::downCast<FactorContext *>(_localctx)->e = expression();
      setState(362);
      antlrcpp::downCast<FactorContext *>(_localctx)->rparenToken = match(C8086Parser::RPAREN);

      		std::string ruleName = "factor : LPAREN expression RPAREN";
      		antlrcpp::downCast<FactorContext *>(_localctx)->text =  antlrcpp::downCast<FactorContext *>(_localctx)->lparenToken->getText() + antlrcpp::downCast<FactorContext *>(_localctx)->e->text + antlrcpp::downCast<FactorContext *>(_localctx)->rparenToken->getText();
      		antlrcpp::downCast<FactorContext *>(_localctx)->line =  std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->lparenToken->getLine());

      		writeRuleLog(_localctx->line, ruleName);
      		writeIntoparserLogFile(_localctx->text + "\n");

      		// _localctx->id.idType = "EMPTY";
      		antlrcpp::downCast<FactorContext *>(_localctx)->id =  antlrcpp::downCast<FactorContext *>(_localctx)->e->id;
      		printIdentifier(_localctx->id);
      	
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(365);
      antlrcpp::downCast<FactorContext *>(_localctx)->const_intToken = match(C8086Parser::CONST_INT);

      		std::string ruleName = "factor : CONST_INT";
      		antlrcpp::downCast<FactorContext *>(_localctx)->text =  antlrcpp::downCast<FactorContext *>(_localctx)->const_intToken->getText();
      		antlrcpp::downCast<FactorContext *>(_localctx)->line =  std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->const_intToken->getLine());

      		writeRuleLog(_localctx->line, ruleName);
      		writeIntoparserLogFile(_localctx->text + "\n");

      		_localctx->id.idType = "INT";
      		printIdentifier(_localctx->id);
      	
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(367);
      antlrcpp::downCast<FactorContext *>(_localctx)->const_floatToken = match(C8086Parser::CONST_FLOAT);

      		std::string ruleName = "factor : CONST_FLOAT";
      		antlrcpp::downCast<FactorContext *>(_localctx)->text =  antlrcpp::downCast<FactorContext *>(_localctx)->const_floatToken->getText();
      		antlrcpp::downCast<FactorContext *>(_localctx)->line =  std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->const_floatToken->getLine());

      		writeRuleLog(_localctx->line, ruleName);
      		writeIntoparserLogFile(_localctx->text + "\n");

      		_localctx->id.idType = "FLOAT";
      		printIdentifier(_localctx->id);
      	
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(369);
      antlrcpp::downCast<FactorContext *>(_localctx)->v = variable();
      setState(370);
      antlrcpp::downCast<FactorContext *>(_localctx)->incopToken = match(C8086Parser::INCOP);

      		std::string ruleName = "factor : variable INCOP";
      		antlrcpp::downCast<FactorContext *>(_localctx)->text =  antlrcpp::downCast<FactorContext *>(_localctx)->v->text + antlrcpp::downCast<FactorContext *>(_localctx)->incopToken->getText();
      		antlrcpp::downCast<FactorContext *>(_localctx)->line =  std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->incopToken->getLine());

      		writeRuleLog(_localctx->line, ruleName);
      		writeIntoparserLogFile(_localctx->text + "\n");

      		_localctx->id.idType = "INT";
      		printIdentifier(_localctx->id);
      	
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(373);
      antlrcpp::downCast<FactorContext *>(_localctx)->v = variable();
      setState(374);
      antlrcpp::downCast<FactorContext *>(_localctx)->decopToken = match(C8086Parser::DECOP);

      		std::string ruleName = "factor : variable DECOP";
      		antlrcpp::downCast<FactorContext *>(_localctx)->text =  antlrcpp::downCast<FactorContext *>(_localctx)->v->text + antlrcpp::downCast<FactorContext *>(_localctx)->decopToken->getText();
      		antlrcpp::downCast<FactorContext *>(_localctx)->line =  std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->decopToken->getLine());

      		writeRuleLog(_localctx->line, ruleName);
      		writeIntoparserLogFile(_localctx->text + "\n");

      		_localctx->id.idType = "INT";
      		printIdentifier(_localctx->id);
      	
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
  enterRule(_localctx, 44, C8086Parser::RuleArgument_list);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(383);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C8086Parser::LPAREN:
      case C8086Parser::ADDOP:
      case C8086Parser::NOT:
      case C8086Parser::ID:
      case C8086Parser::CONST_INT:
      case C8086Parser::CONST_FLOAT: {
        enterOuterAlt(_localctx, 1);
        setState(379);
        antlrcpp::downCast<Argument_listContext *>(_localctx)->a = arguments(0);

        		std::string ruleName = "argument_list : arguments";
        		antlrcpp::downCast<Argument_listContext *>(_localctx)->text =  antlrcpp::downCast<Argument_listContext *>(_localctx)->a->text;
        		antlrcpp::downCast<Argument_listContext *>(_localctx)->line =  antlrcpp::downCast<Argument_listContext *>(_localctx)->a->line;

        		writeRuleLog(_localctx->line, ruleName);
        		writeIntoparserLogFile(_localctx->text + "\n");

        		antlrcpp::downCast<Argument_listContext *>(_localctx)->list =  antlrcpp::downCast<Argument_listContext *>(_localctx)->a->list;
        	
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
  size_t startState = 46;
  enterRecursionRule(_localctx, 46, C8086Parser::RuleArguments, precedence);

    

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
    setState(386);
    antlrcpp::downCast<ArgumentsContext *>(_localctx)->le = logic_expression();

    		std::string ruleName = "arguments : logic_expression";
    		antlrcpp::downCast<ArgumentsContext *>(_localctx)->text =  antlrcpp::downCast<ArgumentsContext *>(_localctx)->le->text;
    		antlrcpp::downCast<ArgumentsContext *>(_localctx)->line =  antlrcpp::downCast<ArgumentsContext *>(_localctx)->le->line;

    		writeRuleLog(_localctx->line, ruleName);
    		writeIntoparserLogFile(_localctx->text + "\n");

    		Variable var;
    		var.type = antlrcpp::downCast<ArgumentsContext *>(_localctx)->le->id.idType;
    		_localctx->list.add(var);
    	
    _ctx->stop = _input->LT(-1);
    setState(396);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ArgumentsContext>(parentContext, parentState);
        _localctx->a = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleArguments);
        setState(389);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(390);
        antlrcpp::downCast<ArgumentsContext *>(_localctx)->commaToken = match(C8086Parser::COMMA);
        setState(391);
        antlrcpp::downCast<ArgumentsContext *>(_localctx)->le = logic_expression();

                  		std::string ruleName = "arguments : arguments COMMA logic_expression";
                  		antlrcpp::downCast<ArgumentsContext *>(_localctx)->text =  antlrcpp::downCast<ArgumentsContext *>(_localctx)->a->text + antlrcpp::downCast<ArgumentsContext *>(_localctx)->commaToken->getText() + antlrcpp::downCast<ArgumentsContext *>(_localctx)->le->text;
                  		antlrcpp::downCast<ArgumentsContext *>(_localctx)->line =  std::to_string(antlrcpp::downCast<ArgumentsContext *>(_localctx)->commaToken->getLine());

                  		writeRuleLog(_localctx->line, ruleName);
                  		writeIntoparserLogFile(_localctx->text + "\n");

                  		antlrcpp::downCast<ArgumentsContext *>(_localctx)->list =  antlrcpp::downCast<ArgumentsContext *>(_localctx)->a->list;
                  		Variable var;
                  		var.type = antlrcpp::downCast<ArgumentsContext *>(_localctx)->le->id.idType;
                  		_localctx->list.add(var);
                  	 
      }
      setState(398);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
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
    case 5: return declaration_listSempred(antlrcpp::downCast<Declaration_listContext *>(context), predicateIndex);
    case 7: return parameter_listSempred(antlrcpp::downCast<Parameter_listContext *>(context), predicateIndex);
    case 11: return statementsSempred(antlrcpp::downCast<StatementsContext *>(context), predicateIndex);
    case 18: return simple_expressionSempred(antlrcpp::downCast<Simple_expressionContext *>(context), predicateIndex);
    case 19: return termSempred(antlrcpp::downCast<TermContext *>(context), predicateIndex);
    case 23: return argumentsSempred(antlrcpp::downCast<ArgumentsContext *>(context), predicateIndex);

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
