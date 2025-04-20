#include<iostream>
#include"SymbolInfo.h"
#include"ScopeTable.h"
#include"SymbolTable.h"
#include<string>
#include<iomanip>
#include<sstream>

using namespace std;


// int main(){

//     // Create a SymbolTable of size 7 (hash buckets)
//     SymbolTable st(7);

//     cout << "\n-- Inserting symbols in current scope --\n";
//     st.insert("x", "int");
//     st.insert("y", "float");
//     st.insert("z", "char");

//     st.printCurrentScopeTable();

//     cout << "\n-- Looking up symbols --\n";
//     SymbolInfo* s = st.lookUp("x");
//     if(s) cout << "Found: " << s->getName() << " -> " << s->getType() << endl;
//     else cout << "Not found: x\n";

//     s = st.lookUp("y");
//     if(s) cout << "Found: " << s->getName() << " -> " << s->getType() << endl;
//     else cout << "Not found: y\n";

//     s = st.lookUp("a");
//     if(s) cout << "Found: " << s->getName() << " -> " << s->getType() << endl;
//     else cout << "Not found: a\n";

//     cout << "\n-- Entering new scope --\n";
//     st.enterScope();
//     st.insert("x", "double"); // same name as parent scope
//     st.insert("a", "bool");

//     st.printCurrentScopeTable();

//     cout << "\n-- Lookup should find from current first --\n";
//     s = st.lookUp("x");
//     if(s) cout << "Found: " << s->getName() << " -> " << s->getType() << endl;
//     else cout << "Not found: x\n";

//     cout << "\n-- All Scopes --\n";
//     st.printAllScopeTables();

//     cout << "\n-- Exiting current scope --\n";
//     st.exitScope();

//     st.printCurrentScopeTable();

//     cout << "\n-- Removing symbol from current scope --\n";
//     bool removed = st.remove("y");
//     if (removed) cout << "Removed y successfully\n";
//     else cout << "Failed to remove y\n";

//     cout << "\n-- All Scopes after deletion --\n";
//     st.printAllScopeTables();

//     cout << "\n-- Collision Ratio --\n";
//     double ratio = st.getCollisionRatio();
//     //print first 2 decimal points
//     cout << "Collision Ratio: " << fixed << setprecision(2) << ratio << endl;

//     return 0;
// }



int main(){

    SymbolTable st(17);  // Use a prime number for better hash distribution

    cout << "\n-- Inserting 100+ symbols into scope 1 --\n";
    for(int i = 0; i < 100; ++i){
        string name = "var" + to_string(i);
        string type = (i % 2 == 0) ? "int" : "float";
        st.insert(name, type);
    }

    st.printCurrentScopeTable();

    cout << "\n-- Looking up some symbols --\n";
    for(int i = 0; i < 5; ++i){
        string name = "var" + to_string(i * 3);
        SymbolInfo* s = st.lookUp(name);
        if(s) cout << "Found: " << s->getName() << " -> " << s->getType() << endl;
        else cout << "Not found: " << name << endl;
    }

    cout << "\n-- Entering new scope (scope 2) and shadowing some variables --\n";
    st.enterScope();
    for(int i = 0; i < 10; ++i){
        string name = "var" + to_string(i * 3); // shadowing same names
        st.insert(name, "char");
    }
    st.insert("temp", "double");

    st.printCurrentScopeTable();

    cout << "\n-- Looking up shadowed and new variables --\n";
    for(int i = 0; i < 10; ++i){
        string name = "var" + to_string(i * 3);
        SymbolInfo* s = st.lookUp(name);
        if(s) cout << "Found: " << s->getName() << " -> " << s->getType() << endl;
        else cout << "Not found: " << name << endl;
    }

    SymbolInfo* tempSym = st.lookUp("temp");
    if(tempSym) cout << "Found temp: " << tempSym->getName() << " -> " << tempSym->getType() << endl;

    cout << "\n-- All Scopes --\n";
    st.printAllScopeTables();

    cout << "\n-- Deleting some variables from scope 2 --\n";
    for(int i = 0; i < 5; ++i){
        string name = "var" + to_string(i * 3);
        if(st.remove(name)) cout << "Deleted: " << name << endl;
        else cout << "Delete failed: " << name << endl;
    }

    cout << "\n-- Exiting current scope (back to scope 1) --\n";
    st.exitScope();

    st.printCurrentScopeTable();

    cout << "\n-- Final Lookup test in scope 1 --\n";
    SymbolInfo* s = st.lookUp("temp");
    if(s) cout << "Found: " << s->getName() << " -> " << s->getType() << endl;
    else cout << "Not found: temp (as expected)\n";

    for(int i = 90; i < 100; ++i){
        string name = "var" + to_string(i);
        s = st.lookUp(name);
        if(s) cout << "Found: " << s->getName() << " -> " << s->getType() << endl;
        else cout << "Not found: " << name << endl;
    }

    cout << "\n-- Collision Ratio --\n";
    double ratio = st.getCollisionRatio();
    cout << "Collision Ratio: " << fixed << setprecision(2) << ratio << endl;

    return 0;
}


// int main(){
    
//     return 0;
// }
