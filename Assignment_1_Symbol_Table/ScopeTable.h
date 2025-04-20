#ifndef SCOPETABLE_H
#define SCOPETABLE_H

#include <string>
#include <iostream>
#include "SymbolInfo.h"

using namespace std;

class ScopeTable{

    SymbolInfo** arr;
    int size;
    unsigned long long (*func)(string);  // hash function pointer
    ScopeTable* parentScope;

    static int tableCounter;

    int tableNumber;
    int collisionCount;

    int getIndex(string key);

    public:

    ScopeTable(int size , int option = 1 , ScopeTable* parentScope = NULL);

    ~ScopeTable();

    int getTableNumber();

    int getCollisionCount();

    int getSize();

    void setParentScope(ScopeTable* parent);
    
    ScopeTable* getParentScope() ;

    SymbolInfo* lookUp(string name);

    string getPosition(string name); // if found , returns a string 'ScopeTable# _ at position _ , _' , else 'Not found'

    bool insert(SymbolInfo symbol);

    bool deleteSymbol(string name);

    void printScopeTable(int n = 1);

};

#endif