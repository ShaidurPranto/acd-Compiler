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

class ScopeTable{

    SymbolInfo** arr;
    int size;
    unsigned int (*func)(string);
    ScopeTable* parentScope;
    static int tableCounter;
    int tableNumber;

    int getIndex(string key){
        return func(key) % size;
    }

    public:

    ScopeTable(int size , int option = 1 , ScopeTable* parentScope = NULL){
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

    ~ScopeTable(){
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

    int getTableNumber(){
        return this->tableNumber;
    }

    SymbolInfo* lookUp(string name){
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
    
    bool insert(string name, string type){
        if(lookUp(name) != NULL){
            return false;
        }
        int index = getIndex(name);
        SymbolInfo* newSymbol = new SymbolInfo(name, type, arr[index]);
        arr[index] = newSymbol;
        return true;
    }
    
    bool deleteSymbol(string name){
        int index = getIndex(name);
        SymbolInfo* temp = arr[index];
        SymbolInfo* prev = NULL;
        while(temp != NULL){
            if(temp->getName() == name){
                if(prev == NULL){
                    arr[index] = temp->getNext();
                } else {
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

    void printScopeTable(){
        cout << "Scope Table #" << tableNumber << endl;
        for(int i=0;i<size;i++){
            SymbolInfo* temp = arr[i];
            if(temp != NULL){
                cout << i << " --> ";
                while(temp != NULL){
                    cout << "<" << temp->getName() << " : " << temp->getType() << "> ";
                    temp = temp->getNext();
                }
                cout << endl;
            }
        }
    }

};

// initializing static variable
int ScopeTable::tableCounter = 1;

int main()
{
    ScopeTable scopeTable(10, 1);
    scopeTable.insert("x", "int");
    scopeTable.printScopeTable();
    return 0;
}