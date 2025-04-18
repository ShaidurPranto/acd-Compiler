#include "SymbolTable.h"

#include<iostream>
#include<string>
#include "ScopeTable.h"
#include "SymbolInfo.h"

using namespace std;

SymbolTable::SymbolTable(int size , int option){
    currentScope = NULL;
    this->option = option;
    this->size = size;

    enterScope();
}

void SymbolTable::enterScope(){
    ScopeTable* newScope = new ScopeTable(this->size, this->option, this->currentScope);
    currentScope = newScope;
}

void SymbolTable::exitScope(){
    if(currentScope->getTableNumber()>1){
        ScopeTable* temp = currentScope;
        currentScope = currentScope->getParentScope();
        delete temp;
    }
}

bool SymbolTable::insert(string name, string type){
    SymbolInfo symbol(name, type);
    return this->currentScope->insert(symbol);
}

bool SymbolTable::remove(string name){
    return this->currentScope->deleteSymbol(name);
}

SymbolInfo* SymbolTable::lookUp(string name){
    ScopeTable * temp = currentScope;
    while(temp != NULL){
        SymbolInfo* symbol = temp->lookUp(name);
        if(symbol != NULL){
            return symbol;
        }
        temp = temp->getParentScope();
    }
    return NULL;
}

void SymbolTable::printCurrentScopeTable(){
    currentScope->printScopeTable(0);
}

void SymbolTable::printAllScopeTables(){
    int count = 1;
    ScopeTable* temp = currentScope;
    while(temp != NULL){
        temp->printScopeTable(count);
        count++;
        temp = temp->getParentScope();
    }
}
