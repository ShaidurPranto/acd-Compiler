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

    SymbolTable(int size , int option = 1){
        currentScope = NULL;
        this->option = option;
        this->size = size;

        enterScope();
    }

    void enterScope(){
        ScopeTable* newScope = new ScopeTable(this->size, this->option, this->currentScope);
        currentScope = newScope;
    }

    void exitScope(){
        if(currentScope->getTableNumber()>1){
            ScopeTable* temp = currentScope;
            currentScope = currentScope->getParentScope();
            delete temp;
        }
    }

    bool insert(string name, string type){
        SymbolInfo symbol(name, type);
        return this->currentScope->insert(symbol);
    }

    bool remove(string name){
        return this->currentScope->deleteSymbol(name);
    }

    SymbolInfo* lookUp(string name){
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

    void printCurrentScopeTable(){
        currentScope->printScopeTable(0);
    }

    void printAllScopeTables(){
        int count = 0;
        ScopeTable* temp = currentScope;
        while(temp != NULL){
            temp->printScopeTable(count);
            count++;
            temp = temp->getParentScope();
        }
    }

};

int main() {
    // Create a SymbolTable of size 7 (hash buckets)
    SymbolTable st(7);

    cout << "\n-- Inserting symbols in current scope --\n";
    st.insert("x", "int");
    st.insert("y", "float");
    st.insert("z", "char");

    st.printCurrentScopeTable();

    cout << "\n-- Looking up symbols --\n";
    SymbolInfo* s = st.lookUp("x");
    if(s) cout << "Found: " << s->getName() << " -> " << s->getType() << endl;
    else cout << "Not found: x\n";

    s = st.lookUp("y");
    if(s) cout << "Found: " << s->getName() << " -> " << s->getType() << endl;
    else cout << "Not found: y\n";

    s = st.lookUp("a");
    if(s) cout << "Found: " << s->getName() << " -> " << s->getType() << endl;
    else cout << "Not found: a\n";

    cout << "\n-- Entering new scope --\n";
    st.enterScope();
    st.insert("x", "double"); // same name as parent scope
    st.insert("a", "bool");

    st.printCurrentScopeTable();

    cout << "\n-- Lookup should find from current first --\n";
    s = st.lookUp("x");
    if(s) cout << "Found: " << s->getName() << " -> " << s->getType() << endl;
    else cout << "Not found: x\n";

    cout << "\n-- All Scopes --\n";
    st.printAllScopeTables();

    cout << "\n-- Exiting current scope --\n";
    st.exitScope();

    st.printCurrentScopeTable();

    cout << "\n-- Removing symbol from current scope --\n";
    bool removed = st.remove("y");
    if (removed) cout << "Removed y successfully\n";
    else cout << "Failed to remove y\n";

    cout << "\n-- All Scopes after deletion --\n";
    st.printAllScopeTables();

    return 0;
}
