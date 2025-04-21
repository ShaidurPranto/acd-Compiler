#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include<iostream>
#include<string>
#include "ScopeTable.h"
#include "SymbolInfo.h"

using namespace std;

class SymbolTable{
    
    ScopeTable* currentScope;
    int option; // hash function option (1-6) : 1 = SDBMHash , 2 = DJBHash , 3 = DEKHash , 4 = APHash , 5 = customHashOne , 6 = customHashTwo
    int size; // size of the symbol table 

    int deletedCollisions; // total number of collisions in deleted scopes
    int deletedTableCounts; // total number of deleted scopes
    double deletedCollisionRatio; // average collision ratio of deleted scopes
    
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

    double getCollisionRatio(); // returns total number of collisions in all scopes / total size of all scopes

    int getInclusiveTotalCollisions(); // returns total number of collisions in all scopes including deleted scopes

    int getActiveNumberOfScopes(); // returns total number of active scopes

    double getInclusiveCollisionRatio(); // returns total number of collisions in all scopes including deleted scopes / total size of all scopes including deleted scopes
};

#endif