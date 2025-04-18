#ifndef SCOPETABLE_H
#define SCOPETABLE_H

#include <string>
#include <iostream>
#include "SymbolInfo.h"

using namespace std;

// hash functions
unsigned int SDBMHash(string str);


class ScopeTable{

    SymbolInfo** arr;
    int size;
    unsigned int (*func)(string);
    ScopeTable* parentScope;
    static int tableCounter;
    int tableNumber;

    int getIndex(string key);

    public:

    ScopeTable(int size , int option = 1 , ScopeTable* parentScope = NULL);

    ~ScopeTable();

    int getTableNumber();

    void setParentScope(ScopeTable* parent);
    
    ScopeTable* getParentScope() ;

    SymbolInfo* lookUp(string name);

    bool insert(SymbolInfo symbol);

    bool deleteSymbol(string name);

    void printScopeTable(int n);

};

#endif