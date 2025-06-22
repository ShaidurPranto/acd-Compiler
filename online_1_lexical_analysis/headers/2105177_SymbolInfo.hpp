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



// implementations



SymbolInfo::SymbolInfo(string name, string type, SymbolInfo* next) {
    this->name = name;
    this->type = type;
    this->next = next;
}

SymbolInfo::~SymbolInfo() {
}

string SymbolInfo::getName() {
    return this->name;
}

void SymbolInfo::setName(string name) {
    this->name = name;
}

string SymbolInfo::getType() {
    return this->type;
}

void SymbolInfo::setType(string type) {
    this->type = type;
}

SymbolInfo* SymbolInfo::getNext() {
    return this->next;
}

void SymbolInfo::setNext(SymbolInfo* next) {
    this->next = next;
}


#endif
