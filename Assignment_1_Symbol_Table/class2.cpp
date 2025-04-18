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

    void setParentScope(ScopeTable* parent){
        this->parentScope = parent;
    }
    
    ScopeTable* getParentScope() {
        return this->parentScope;
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

    bool insert(SymbolInfo symbol){
        if(lookUp(symbol.getName()) != NULL){
            return false;
        }
        int index = getIndex(symbol.getName());
        SymbolInfo* newSymbol = new SymbolInfo(symbol.getName(), symbol.getType(), arr[index]);
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

    void printScopeTable(int n){
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

};

// initializing static variable
int ScopeTable::tableCounter = 1;

int main()
{
    ScopeTable ScopeTable(10);
    SymbolInfo symbol1("x", "int");
    SymbolInfo symbol2("y", "float");
    SymbolInfo symbol3("z", "char");
    SymbolInfo symbol4("x", "double");
    SymbolInfo symbol5("y", "string");
    SymbolInfo symbol6("z", "bool");
    SymbolInfo symbol7("a", "int");
    SymbolInfo symbol8("b", "float");
    SymbolInfo symbol9("c", "char");
    SymbolInfo symbol10("d", "double");
    SymbolInfo symbol11("e", "string");
    SymbolInfo symbol12("f", "bool");
    SymbolInfo symbol13("g", "int");
    SymbolInfo symbol14("h", "float");
    SymbolInfo symbol15("i", "char");
    SymbolInfo symbol16("j", "double");
    SymbolInfo symbol17("k", "string");

    ScopeTable.insert(symbol1);
    ScopeTable.insert(symbol2);
    ScopeTable.insert(symbol3);
    ScopeTable.insert(symbol4);
    ScopeTable.insert(symbol5);
    ScopeTable.insert(symbol6);
    ScopeTable.insert(symbol7);
    
    ScopeTable.printScopeTable(0);

}