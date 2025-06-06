#ifndef SYMBOLINFO_H
#define SYMBOLINFO_H

#include <string>

using namespace std;

class SymbolInfo {
    string name;
    string type;
    SymbolInfo* next; // points to next symbol of the chain

public:
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
