#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include<iostream>
#include<string>
#include "ScopeTable.h"
#include "SymbolInfo.h"

using namespace std;

class SymbolTable{
    
    ScopeTable* currentScope;
    int option;
    int size;
    
    public:

    SymbolTable(int size , int option = 1);

    void enterScope();

    void exitScope();

    bool insert(string name, string type);

    bool remove(string name);

    SymbolInfo* lookUp(string name);

    void printCurrentScopeTable();

    void printAllScopeTables();
};

#endif