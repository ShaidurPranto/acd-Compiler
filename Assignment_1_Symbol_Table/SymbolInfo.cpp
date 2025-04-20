#include "SymbolInfo.h"
using namespace std;

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