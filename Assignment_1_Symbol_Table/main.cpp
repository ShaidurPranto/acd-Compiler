#include<iostream>
#include"SymbolInfo.h"
#include"ScopeTable.h"
#include"SymbolTable.h"
#include<string>

using namespace std;


int main(){

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