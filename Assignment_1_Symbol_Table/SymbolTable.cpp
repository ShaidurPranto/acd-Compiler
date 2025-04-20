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

SymbolTable::~SymbolTable(){
    while(currentScope != NULL){
        ScopeTable* temp = currentScope;
        currentScope = currentScope->getParentScope();
        delete temp;
    }
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

string SymbolTable::getPositionAsString(string name){
    ScopeTable * temp = currentScope;
    while(temp != NULL){
        string position = temp->getPosition(name);
        if(position != "Not found"){
            return position;
        }
        temp = temp->getParentScope();
    }
    return "Not found";
}

void SymbolTable::printCurrentScopeTable(){
    currentScope->printScopeTable();
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

int SymbolTable::getTotalCollisions(){
    int totalCollisions = 0;
    ScopeTable* temp = currentScope;
    while(temp != NULL){
        totalCollisions += temp->getCollisionCount();
        temp = temp->getParentScope();
    }
    return totalCollisions;
}

double SymbolTable::getCollisionRatio(){
    double totalCollisions = 0;
    double totalSize = 0;
    ScopeTable* temp = currentScope;
    while(temp != NULL){
        totalCollisions += temp->getCollisionCount();
        totalSize += temp->getSize();
        temp = temp->getParentScope();
    }
    return totalCollisions / totalSize;
}