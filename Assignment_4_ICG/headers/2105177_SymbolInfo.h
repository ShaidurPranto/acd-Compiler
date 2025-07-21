#ifndef SYMBOLINFO_H
#define SYMBOLINFO_H

#include <string>
#include <vector>

using namespace std;


struct Identifier {
    string idName = "EMPTY";
    string idType = "EMPTY";
    bool isGlobal = false;
    int stackOffset = 0; 
    bool isArray = false;
    string arrayIndex = "EMPTY";
    int arraySize = 0;
    string constValue = "EMPTY";
    bool isInStack = false;
    string trueLabel = "EMPTY";
    string falseLabel = "EMPTY";
    string nextLabel = "EMPTY";
    string startLabel = "EMPTY";
    bool isIncDec = false;
    bool isEvaluated = false;
    string incDecOp = "EMPTY";
};

class SymbolInfo {   
    string name;
    string type;
    SymbolInfo* next; // points to next symbol of the chain

public:
    bool isArray = false;
    int arraySize = 0; 
    Identifier id;

    // methods
    SymbolInfo(string name, string type, SymbolInfo* next = NULL);
    ~SymbolInfo();

    string getName();
    void setName(string name);

    string getType();
    void setType(string type);

    SymbolInfo* getNext();
    void setNext(SymbolInfo* next);
};



#endif
