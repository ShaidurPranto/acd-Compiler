#ifndef SCOPETABLE_H
#define SCOPETABLE_H

#include <string>
#include <iostream>
#include "2105177_SymbolInfo.h"

using namespace std;

class ScopeTable{

    SymbolInfo** arr;
    int size;
    unsigned int (*func)(string, int);  // hash function pointer
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

    double getCollisionRatio(); // returns total number of collisions in this scope / size of this scope

    void setParentScope(ScopeTable* parent);
    
    ScopeTable* getParentScope() ;

    SymbolInfo* lookUp(string name);

    string getPosition(string name); // if found , returns a string 'ScopeTable# _ at position _ , _' , else 'Not found'

    SymbolInfo* insert(SymbolInfo symbol);

    bool deleteSymbol(string name);

    void printScopeTable(int n = 1);

    void printNonEmptyScopeTable(ofstream &fout);
};

#endif