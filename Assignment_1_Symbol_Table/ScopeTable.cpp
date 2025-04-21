#include"ScopeTable.h"

#include<iostream>
#include"SymbolInfo.h"
#include"hashFunctions.h"

using namespace std;


// initializing static variable
int ScopeTable::tableCounter = 1;

// ScopeTable class implementation

ScopeTable::ScopeTable(int size , int option , ScopeTable* parentScope){
    this->size = size;
    arr = new SymbolInfo*[size];
    this->parentScope = parentScope;
    this->tableNumber = tableCounter;
    tableCounter++;
    this->collisionCount = 0;

    for(int i=0;i<size;i++){
        arr[i] = NULL;
    }

    if(option == 1){
        this->func = SDBMHash;
    }else if(option == 2){
        this->func = DJBHash;
    }else if(option == 3){
        this->func = DEKHash;
    }else if(option == 4){
        this->func = APHash;
    }else if(option == 5){
        this->func = customHashOne;
    }else if(option == 6){
        this->func = customHashTwo;
    }else{
        cout << "Invalid hash function option" << endl;
        exit(1);
    }

    cout << "\tScopeTable# " << this->tableNumber << " created" << endl;
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
    cout << "\tScopeTable# " << this->tableNumber << " removed" << endl;
}

int ScopeTable::getIndex(string key){
    return func(key, this->size);
}

int ScopeTable::getTableNumber(){
    return this->tableNumber;
}

int ScopeTable::getCollisionCount(){
    return this->collisionCount;
}

int ScopeTable::getSize(){
    return this->size;
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

string ScopeTable::getPosition(string name){
    int index = getIndex(name);
    SymbolInfo* temp = arr[index];
    int i = 1;
    while(temp != NULL){
        if(temp->getName() == name){
            return "ScopeTable# " + to_string(tableNumber) + " at position " + to_string(index + 1) + ", " + to_string(i);
        }
        temp = temp->getNext();
        i++;
    }
    return "Not found";
}

 
/*                      inserts at the front of the chain                       */

// bool ScopeTable::insert(SymbolInfo symbol){
//     if(lookUp(symbol.getName()) != NULL){
//         return false;
//     }
//     int index = getIndex(symbol.getName());
//     SymbolInfo* newSymbol = new SymbolInfo(symbol.getName(), symbol.getType(), arr[index]);
//     arr[index] = newSymbol;

//     // collision count
//     if(arr[index]->getNext() != NULL){
//         cout<<"Collision occurred at index " << index << " in ScopeTable #" << tableNumber << endl;
//         this->collisionCount++;
//     }
//     return true;
// }


/*                      inserts at the end of the chain                       */

bool ScopeTable::insert(SymbolInfo symbol){
    if(lookUp(symbol.getName()) != NULL){
        return false;
    }

    int index = getIndex(symbol.getName());
    SymbolInfo* temp = arr[index];
    if(temp != NULL){
        collisionCount++;
        //cout << "Collision occurred at index " << index << " in ScopeTable #" << tableNumber << endl;
    }

    while(temp != NULL){
        if(temp->getNext() == NULL){
            break;
        }
        temp = temp->getNext();
    }
    SymbolInfo* newSymbol = new SymbolInfo(symbol.getName(), symbol.getType(), NULL);

    if(temp == NULL){
        arr[index] = newSymbol;
    } else {
        temp->setNext(newSymbol);
    }

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

    cout << tabs << "ScopeTable# " << tableNumber << endl;
    for(int i=0;i<size;i++){
        cout << tabs << i + 1 << "--> ";
        SymbolInfo* temp = arr[i];
        while(temp != NULL){
            cout << "<" << temp->getName() << "," << temp->getType() << "> ";
            temp = temp->getNext();
        }
        cout << endl;
    }
}