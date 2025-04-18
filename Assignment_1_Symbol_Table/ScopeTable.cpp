#include"ScopeTable.h"

#include<iostream>
#include"SymbolInfo.h"

using namespace std;

// hash functions
unsigned int SDBMHash(string str) {
    unsigned int hash = 0;
    unsigned int i = 0;
    unsigned int len = str.length();

    for (i = 0; i < len; i++)
    {
        hash = (str[i]) + (hash << 6) + (hash << 16) - hash;
    }

    return hash;
}

// initializing static variable
int ScopeTable::tableCounter = 1;

// ScopeTable class implementation
int ScopeTable::getIndex(string key){
    return func(key) % size;
}

ScopeTable::ScopeTable(int size , int option , ScopeTable* parentScope){
    this->size = size;
    arr = new SymbolInfo*[size];
    this->parentScope = parentScope;
    this->tableNumber = tableCounter;
    tableCounter++;

    for(int i=0;i<size;i++){
        arr[i] = NULL;
    }
    if(option == 1){
        this->func = SDBMHash;
    }
}

ScopeTable::~ScopeTable(){
    for(int i=0;i<size;i++){
        SymbolInfo* temp = arr[i];
        while(temp != NULL){
            SymbolInfo* toDelete = temp;
            temp = temp->getNext();
            delete toDelete;
        }
    }
    delete[] arr;
}

int ScopeTable::getTableNumber(){
    return this->tableNumber;
}

void ScopeTable::setParentScope(ScopeTable* parent){
    this->parentScope = parent;
}

ScopeTable* ScopeTable::getParentScope() {
    return this->parentScope;
}

SymbolInfo* ScopeTable::lookUp(string name){
    int index = getIndex(name);
    SymbolInfo* temp = arr[index];
    while(temp != NULL){
        if(temp->getName() == name){
            return temp;
        }
        temp = temp->getNext();
    }
    return NULL;
}

bool ScopeTable::insert(SymbolInfo symbol){
    if(lookUp(symbol.getName()) != NULL){
        return false;
    }
    int index = getIndex(symbol.getName());
    SymbolInfo* newSymbol = new SymbolInfo(symbol.getName(), symbol.getType(), arr[index]);
    arr[index] = newSymbol;
    return true;
}

bool ScopeTable::deleteSymbol(string name){
    int index = getIndex(name);
    SymbolInfo* temp = arr[index];
    SymbolInfo* prev = NULL;
    while(temp != NULL){
        if(temp->getName() == name){
            if(prev == NULL){
                arr[index] = temp->getNext();
            }else{
                prev->setNext(temp->getNext());
            }
            delete temp;
            return true;
        }
        prev = temp;
        temp = temp->getNext();
    }
    return false;
}

void ScopeTable::printScopeTable(int n){
    string tabs(n, '\t');

    cout << tabs << "Scope Table #" << tableNumber << endl;
    for(int i=0;i<size;i++){
        cout << tabs << i + 1 << " --> ";
        SymbolInfo* temp = arr[i];
        while(temp != NULL){
            cout << "<" << temp->getName() << "," << temp->getType() << "> ";
            temp = temp->getNext();
        }
        cout << endl;
    }
}