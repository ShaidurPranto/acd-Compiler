
    #pragma once
    #include <iostream>
    #include <fstream>
    #include <string>

    extern std::ofstream lexLogFile;


// Generated from C8086Lexer.g4 by ANTLR 4.13.2


#include "C8086Lexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct C8086LexerStaticData final {
  C8086LexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  C8086LexerStaticData(const C8086LexerStaticData&) = delete;
  C8086LexerStaticData(C8086LexerStaticData&&) = delete;
  C8086LexerStaticData& operator=(const C8086LexerStaticData&) = delete;
  C8086LexerStaticData& operator=(C8086LexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag c8086lexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<C8086LexerStaticData> c8086lexerLexerStaticData = nullptr;

void c8086lexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (c8086lexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(c8086lexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<C8086LexerStaticData>(
    std::vector<std::string>{
      "LINE_COMMENT", "BLOCK_COMMENT", "STRING", "WS", "IF", "ELSE", "FOR", 
      "WHILE", "PRINTLN", "RETURN", "INT", "FLOAT", "VOID", "LPAREN", "RPAREN", 
      "LCURL", "RCURL", "LTHIRD", "RTHIRD", "SEMICOLON", "COMMA", "ADDOP", 
      "SUBOP", "MULOP", "INCOP", "DECOP", "NOT", "RELOP", "LOGICOP", "ASSIGNOP", 
      "ID", "CONST_INT", "CONST_FLOAT"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,33,311,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,1,0,1,0,1,0,1,0,5,0,72,8,
  	0,10,0,12,0,75,9,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,5,1,86,8,1,10,
  	1,12,1,89,9,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,2,1,2,1,2,5,2,102,8,2,
  	10,2,12,2,105,9,2,1,2,1,2,1,2,1,2,1,2,1,3,4,3,113,8,3,11,3,12,3,114,1,
  	3,1,3,1,4,1,4,1,4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,6,1,6,1,6,1,6,
  	1,6,1,6,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,
  	8,1,8,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,10,1,10,1,10,1,10,1,10,1,
  	10,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,12,1,12,1,12,1,12,1,12,1,
  	12,1,12,1,13,1,13,1,13,1,14,1,14,1,14,1,15,1,15,1,15,1,16,1,16,1,16,1,
  	17,1,17,1,17,1,18,1,18,1,18,1,19,1,19,1,19,1,20,1,20,1,20,1,21,1,21,1,
  	21,1,22,1,22,1,22,1,23,1,23,1,23,1,24,1,24,1,24,1,24,1,24,1,25,1,25,1,
  	25,1,25,1,25,1,26,1,26,1,26,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,
  	27,1,27,1,27,3,27,241,8,27,1,28,1,28,1,28,1,28,1,28,1,28,3,28,249,8,28,
  	1,29,1,29,1,29,1,30,1,30,5,30,256,8,30,10,30,12,30,259,9,30,1,30,1,30,
  	1,31,4,31,264,8,31,11,31,12,31,265,1,31,1,31,1,32,4,32,271,8,32,11,32,
  	12,32,272,1,32,1,32,5,32,277,8,32,10,32,12,32,280,9,32,3,32,282,8,32,
  	1,32,1,32,3,32,286,8,32,1,32,4,32,289,8,32,11,32,12,32,290,3,32,293,8,
  	32,1,32,1,32,1,32,4,32,298,8,32,11,32,12,32,299,1,32,1,32,4,32,304,8,
  	32,11,32,12,32,305,1,32,1,32,3,32,310,8,32,1,87,0,33,1,1,3,2,5,3,7,4,
  	9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,25,13,27,14,29,15,31,16,33,
  	17,35,18,37,19,39,20,41,21,43,22,45,23,47,24,49,25,51,26,53,27,55,28,
  	57,29,59,30,61,31,63,32,65,33,1,0,10,2,0,10,10,13,13,4,0,10,10,13,13,
  	34,34,92,92,3,0,9,10,12,13,32,32,2,0,43,43,45,45,3,0,37,37,42,42,47,47,
  	2,0,60,60,62,62,3,0,65,90,95,95,97,122,4,0,48,57,65,90,95,95,97,122,1,
  	0,48,57,2,0,69,69,101,101,333,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,
  	1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,
  	0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,
  	29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,0,39,1,
  	0,0,0,0,41,1,0,0,0,0,43,1,0,0,0,0,45,1,0,0,0,0,47,1,0,0,0,0,49,1,0,0,
  	0,0,51,1,0,0,0,0,53,1,0,0,0,0,55,1,0,0,0,0,57,1,0,0,0,0,59,1,0,0,0,0,
  	61,1,0,0,0,0,63,1,0,0,0,0,65,1,0,0,0,1,67,1,0,0,0,3,80,1,0,0,0,5,97,1,
  	0,0,0,7,112,1,0,0,0,9,118,1,0,0,0,11,123,1,0,0,0,13,130,1,0,0,0,15,136,
  	1,0,0,0,17,144,1,0,0,0,19,153,1,0,0,0,21,162,1,0,0,0,23,168,1,0,0,0,25,
  	176,1,0,0,0,27,183,1,0,0,0,29,186,1,0,0,0,31,189,1,0,0,0,33,192,1,0,0,
  	0,35,195,1,0,0,0,37,198,1,0,0,0,39,201,1,0,0,0,41,204,1,0,0,0,43,207,
  	1,0,0,0,45,210,1,0,0,0,47,213,1,0,0,0,49,216,1,0,0,0,51,221,1,0,0,0,53,
  	226,1,0,0,0,55,240,1,0,0,0,57,248,1,0,0,0,59,250,1,0,0,0,61,253,1,0,0,
  	0,63,263,1,0,0,0,65,309,1,0,0,0,67,68,5,47,0,0,68,69,5,47,0,0,69,73,1,
  	0,0,0,70,72,8,0,0,0,71,70,1,0,0,0,72,75,1,0,0,0,73,71,1,0,0,0,73,74,1,
  	0,0,0,74,76,1,0,0,0,75,73,1,0,0,0,76,77,6,0,0,0,77,78,1,0,0,0,78,79,6,
  	0,1,0,79,2,1,0,0,0,80,81,5,47,0,0,81,82,5,42,0,0,82,87,1,0,0,0,83,86,
  	9,0,0,0,84,86,7,0,0,0,85,83,1,0,0,0,85,84,1,0,0,0,86,89,1,0,0,0,87,88,
  	1,0,0,0,87,85,1,0,0,0,88,90,1,0,0,0,89,87,1,0,0,0,90,91,5,42,0,0,91,92,
  	5,47,0,0,92,93,1,0,0,0,93,94,6,1,2,0,94,95,1,0,0,0,95,96,6,1,1,0,96,4,
  	1,0,0,0,97,103,5,34,0,0,98,99,5,92,0,0,99,102,9,0,0,0,100,102,8,1,0,0,
  	101,98,1,0,0,0,101,100,1,0,0,0,102,105,1,0,0,0,103,101,1,0,0,0,103,104,
  	1,0,0,0,104,106,1,0,0,0,105,103,1,0,0,0,106,107,5,34,0,0,107,108,6,2,
  	3,0,108,109,1,0,0,0,109,110,6,2,1,0,110,6,1,0,0,0,111,113,7,2,0,0,112,
  	111,1,0,0,0,113,114,1,0,0,0,114,112,1,0,0,0,114,115,1,0,0,0,115,116,1,
  	0,0,0,116,117,6,3,1,0,117,8,1,0,0,0,118,119,5,105,0,0,119,120,5,102,0,
  	0,120,121,1,0,0,0,121,122,6,4,4,0,122,10,1,0,0,0,123,124,5,101,0,0,124,
  	125,5,108,0,0,125,126,5,115,0,0,126,127,5,101,0,0,127,128,1,0,0,0,128,
  	129,6,5,5,0,129,12,1,0,0,0,130,131,5,102,0,0,131,132,5,111,0,0,132,133,
  	5,114,0,0,133,134,1,0,0,0,134,135,6,6,6,0,135,14,1,0,0,0,136,137,5,119,
  	0,0,137,138,5,104,0,0,138,139,5,105,0,0,139,140,5,108,0,0,140,141,5,101,
  	0,0,141,142,1,0,0,0,142,143,6,7,7,0,143,16,1,0,0,0,144,145,5,112,0,0,
  	145,146,5,114,0,0,146,147,5,105,0,0,147,148,5,110,0,0,148,149,5,116,0,
  	0,149,150,5,102,0,0,150,151,1,0,0,0,151,152,6,8,8,0,152,18,1,0,0,0,153,
  	154,5,114,0,0,154,155,5,101,0,0,155,156,5,116,0,0,156,157,5,117,0,0,157,
  	158,5,114,0,0,158,159,5,110,0,0,159,160,1,0,0,0,160,161,6,9,9,0,161,20,
  	1,0,0,0,162,163,5,105,0,0,163,164,5,110,0,0,164,165,5,116,0,0,165,166,
  	1,0,0,0,166,167,6,10,10,0,167,22,1,0,0,0,168,169,5,102,0,0,169,170,5,
  	108,0,0,170,171,5,111,0,0,171,172,5,97,0,0,172,173,5,116,0,0,173,174,
  	1,0,0,0,174,175,6,11,11,0,175,24,1,0,0,0,176,177,5,118,0,0,177,178,5,
  	111,0,0,178,179,5,105,0,0,179,180,5,100,0,0,180,181,1,0,0,0,181,182,6,
  	12,12,0,182,26,1,0,0,0,183,184,5,40,0,0,184,185,6,13,13,0,185,28,1,0,
  	0,0,186,187,5,41,0,0,187,188,6,14,14,0,188,30,1,0,0,0,189,190,5,123,0,
  	0,190,191,6,15,15,0,191,32,1,0,0,0,192,193,5,125,0,0,193,194,6,16,16,
  	0,194,34,1,0,0,0,195,196,5,91,0,0,196,197,6,17,17,0,197,36,1,0,0,0,198,
  	199,5,93,0,0,199,200,6,18,18,0,200,38,1,0,0,0,201,202,5,59,0,0,202,203,
  	6,19,19,0,203,40,1,0,0,0,204,205,5,44,0,0,205,206,6,20,20,0,206,42,1,
  	0,0,0,207,208,7,3,0,0,208,209,6,21,21,0,209,44,1,0,0,0,210,211,7,3,0,
  	0,211,212,6,22,22,0,212,46,1,0,0,0,213,214,7,4,0,0,214,215,6,23,23,0,
  	215,48,1,0,0,0,216,217,5,43,0,0,217,218,5,43,0,0,218,219,1,0,0,0,219,
  	220,6,24,24,0,220,50,1,0,0,0,221,222,5,45,0,0,222,223,5,45,0,0,223,224,
  	1,0,0,0,224,225,6,25,25,0,225,52,1,0,0,0,226,227,5,33,0,0,227,228,6,26,
  	26,0,228,54,1,0,0,0,229,230,5,60,0,0,230,241,5,61,0,0,231,232,5,61,0,
  	0,232,241,5,61,0,0,233,234,5,62,0,0,234,241,5,61,0,0,235,241,7,5,0,0,
  	236,237,5,33,0,0,237,238,5,61,0,0,238,239,1,0,0,0,239,241,6,27,27,0,240,
  	229,1,0,0,0,240,231,1,0,0,0,240,233,1,0,0,0,240,235,1,0,0,0,240,236,1,
  	0,0,0,241,56,1,0,0,0,242,243,5,38,0,0,243,249,5,38,0,0,244,245,5,124,
  	0,0,245,246,5,124,0,0,246,247,1,0,0,0,247,249,6,28,28,0,248,242,1,0,0,
  	0,248,244,1,0,0,0,249,58,1,0,0,0,250,251,5,61,0,0,251,252,6,29,29,0,252,
  	60,1,0,0,0,253,257,7,6,0,0,254,256,7,7,0,0,255,254,1,0,0,0,256,259,1,
  	0,0,0,257,255,1,0,0,0,257,258,1,0,0,0,258,260,1,0,0,0,259,257,1,0,0,0,
  	260,261,6,30,30,0,261,62,1,0,0,0,262,264,7,8,0,0,263,262,1,0,0,0,264,
  	265,1,0,0,0,265,263,1,0,0,0,265,266,1,0,0,0,266,267,1,0,0,0,267,268,6,
  	31,31,0,268,64,1,0,0,0,269,271,7,8,0,0,270,269,1,0,0,0,271,272,1,0,0,
  	0,272,270,1,0,0,0,272,273,1,0,0,0,273,281,1,0,0,0,274,278,5,46,0,0,275,
  	277,7,8,0,0,276,275,1,0,0,0,277,280,1,0,0,0,278,276,1,0,0,0,278,279,1,
  	0,0,0,279,282,1,0,0,0,280,278,1,0,0,0,281,274,1,0,0,0,281,282,1,0,0,0,
  	282,292,1,0,0,0,283,285,7,9,0,0,284,286,7,3,0,0,285,284,1,0,0,0,285,286,
  	1,0,0,0,286,288,1,0,0,0,287,289,7,8,0,0,288,287,1,0,0,0,289,290,1,0,0,
  	0,290,288,1,0,0,0,290,291,1,0,0,0,291,293,1,0,0,0,292,283,1,0,0,0,292,
  	293,1,0,0,0,293,294,1,0,0,0,294,310,6,32,32,0,295,297,5,46,0,0,296,298,
  	7,8,0,0,297,296,1,0,0,0,298,299,1,0,0,0,299,297,1,0,0,0,299,300,1,0,0,
  	0,300,301,1,0,0,0,301,310,6,32,33,0,302,304,7,8,0,0,303,302,1,0,0,0,304,
  	305,1,0,0,0,305,303,1,0,0,0,305,306,1,0,0,0,306,307,1,0,0,0,307,308,5,
  	46,0,0,308,310,6,32,34,0,309,270,1,0,0,0,309,295,1,0,0,0,309,303,1,0,
  	0,0,310,66,1,0,0,0,20,0,73,85,87,101,103,114,240,248,257,265,272,278,
  	281,285,290,292,299,305,309,35,1,0,0,6,0,0,1,1,1,1,2,2,1,4,3,1,5,4,1,
  	6,5,1,7,6,1,8,7,1,9,8,1,10,9,1,11,10,1,12,11,1,13,12,1,14,13,1,15,14,
  	1,16,15,1,17,16,1,18,17,1,19,18,1,20,19,1,21,20,1,22,21,1,23,22,1,24,
  	23,1,25,24,1,26,25,1,27,26,1,28,27,1,29,28,1,30,29,1,31,30,1,32,31,1,
  	32,32,1,32,33
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  c8086lexerLexerStaticData = std::move(staticData);
}

}

C8086Lexer::C8086Lexer(CharStream *input) : Lexer(input) {
  C8086Lexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *c8086lexerLexerStaticData->atn, c8086lexerLexerStaticData->decisionToDFA, c8086lexerLexerStaticData->sharedContextCache);
}

C8086Lexer::~C8086Lexer() {
  delete _interpreter;
}

std::string C8086Lexer::getGrammarFileName() const {
  return "C8086Lexer.g4";
}

const std::vector<std::string>& C8086Lexer::getRuleNames() const {
  return c8086lexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& C8086Lexer::getChannelNames() const {
  return c8086lexerLexerStaticData->channelNames;
}

const std::vector<std::string>& C8086Lexer::getModeNames() const {
  return c8086lexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& C8086Lexer::getVocabulary() const {
  return c8086lexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView C8086Lexer::getSerializedATN() const {
  return c8086lexerLexerStaticData->serializedATN;
}

const atn::ATN& C8086Lexer::getATN() const {
  return *c8086lexerLexerStaticData->atn;
}


void C8086Lexer::action(RuleContext *context, size_t ruleIndex, size_t actionIndex) {
  switch (ruleIndex) {
    case 0: LINE_COMMENTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 1: BLOCK_COMMENTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 2: STRINGAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 4: IFAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 5: ELSEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 6: FORAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 7: WHILEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 8: PRINTLNAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 9: RETURNAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 10: INTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 11: FLOATAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 12: VOIDAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 13: LPARENAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 14: RPARENAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 15: LCURLAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 16: RCURLAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 17: LTHIRDAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 18: RTHIRDAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 19: SEMICOLONAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 20: COMMAAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 21: ADDOPAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 22: SUBOPAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 23: MULOPAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 24: INCOPAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 25: DECOPAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 26: NOTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 27: RELOPAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 28: LOGICOPAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 29: ASSIGNOPAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 30: IDAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 31: CONST_INTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 32: CONST_FLOATAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;

  default:
    break;
  }
}

void C8086Lexer::LINE_COMMENTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 0: 
            writeIntoLexLogFile(
              "Line# " + std::to_string(getLine())
              + ": Token <SINGLE LINE COMMENT> Lexeme "
              + getText()
            );
         break;

  default:
    break;
  }
}

void C8086Lexer::BLOCK_COMMENTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 1: 
          // extra braces create a new scope for your variables
          {
            std::string txt = getText();
            std::string content = txt.substr(2, txt.size() - 4);
            writeIntoLexLogFile(
              "Line# " + std::to_string(getLine())
              + ": Token <MULTI LINE COMMENT> Lexeme /*"
              + content + "*/"
            );
          }
         break;

  default:
    break;
  }
}

void C8086Lexer::STRINGAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 2: 
            writeIntoLexLogFile(
              "Line# " + std::to_string(getLine())
              + ": Token <STRING> Lexeme " + getText()
            );
         break;

  default:
    break;
  }
}

void C8086Lexer::IFAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 3:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <IF> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C8086Lexer::ELSEAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 4:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <ELSE> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C8086Lexer::FORAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 5:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <FOR> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C8086Lexer::WHILEAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 6:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <WHILE> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C8086Lexer::PRINTLNAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 7:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <PRINTLN> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C8086Lexer::RETURNAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 8:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <RETURN> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C8086Lexer::INTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 9:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <INT> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C8086Lexer::FLOATAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 10:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <FLOAT> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C8086Lexer::VOIDAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 11:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <VOID> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C8086Lexer::LPARENAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 12:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <LPAREN> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C8086Lexer::RPARENAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 13:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <RPAREN> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C8086Lexer::LCURLAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 14:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <LCURL> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C8086Lexer::RCURLAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 15:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <RCURL> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C8086Lexer::LTHIRDAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 16:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <LTHIRD> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C8086Lexer::RTHIRDAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 17:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <RTHIRD> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C8086Lexer::SEMICOLONAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 18:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <SEMICOLON> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C8086Lexer::COMMAAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 19:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <COMMA> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C8086Lexer::ADDOPAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 20:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <ADDOP> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C8086Lexer::SUBOPAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 21:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <SUBOP> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C8086Lexer::MULOPAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 22:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <MULOP> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C8086Lexer::INCOPAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 23:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <INCOP> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C8086Lexer::DECOPAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 24:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <DECOP> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C8086Lexer::NOTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 25:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <NOT> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C8086Lexer::RELOPAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 26:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <RELOP> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C8086Lexer::LOGICOPAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 27:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <LOGICOP> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C8086Lexer::ASSIGNOPAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 28:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <ASSIGNOP> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C8086Lexer::IDAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 29:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <ID> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C8086Lexer::CONST_INTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 30:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <CONST_INT> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C8086Lexer::CONST_FLOATAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 31: 
            writeIntoLexLogFile(
              "Line# " + std::to_string(getLine())
              + ": Token <CONST_FLOAT> Lexeme " + getText()
            );
         break;
    case 32: 
            writeIntoLexLogFile(
              "Line# " + std::to_string(getLine())
              + ": Token <CONST_FLOAT> Lexeme " + getText()
            );
         break;
    case 33: 
            writeIntoLexLogFile(
              "Line# " + std::to_string(getLine())
              + ": Token <CONST_FLOAT> Lexeme " + getText()
            );
         break;

  default:
    break;
  }
}



void C8086Lexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  c8086lexerLexerInitialize();
#else
  ::antlr4::internal::call_once(c8086lexerLexerOnceFlag, c8086lexerLexerInitialize);
#endif
}
