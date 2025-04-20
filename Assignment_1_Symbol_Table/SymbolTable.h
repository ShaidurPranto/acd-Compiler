#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include<iostream>
#include<string>
#include "ScopeTable.h"
#include "SymbolInfo.h"

using namespace std;

class SymbolTable{
    
    ScopeTable* currentScope;
    int option; // hash function option
    int size; // size of the symbol table 
    
    public:

    SymbolTable(int size , int option = 1);

    ~SymbolTable();

    void enterScope();

    void exitScope();

    bool insert(string name, string type);

    bool remove(string name);

    SymbolInfo* lookUp(string name); // look up in all scopes

    string getPositionAsString(string name); // if found , returns a string 'ScopeTable# _ at position _ , _' , else 'Not found'

    void printCurrentScopeTable();

    void printAllScopeTables();

    int getTotalCollisions(); // returns total number of collisions in all scopes

    double getCollisionRatio(); // returns total number of collisions in all scopes / total number of symbols in all scopes
};

#endif