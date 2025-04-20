#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

#include "SymbolTable.h"

void testSymbolTable(SymbolTable& st, int numberOfScopes, int sizeOfEachScope) {
    int counter = 0;

    for (int i = 0; i < numberOfScopes; ++i) {
        st.enterScope();
        for (int j = 0; j < sizeOfEachScope; ++j) {
            string name = "var_" + to_string(counter);
            string type = (counter % 2 == 0) ? "int" : "float";
            st.insert(name, type);
            counter++;
        }
    }
}

int main() {
    const int numberOfScopes = 3;
    const int sizeOfEachScope = 26;
    const int sizeOfEachTable = 16;

    const int totalSymbols = numberOfScopes * sizeOfEachScope;

    SymbolTable st1(sizeOfEachTable, 1); // SDBMHash
    SymbolTable st2(sizeOfEachTable, 2); // DJBHash
    SymbolTable st3(sizeOfEachTable, 3); // DEKHash
    SymbolTable st4(sizeOfEachTable, 4); // APHash
    SymbolTable st5(sizeOfEachTable, 5); // Custom Hash
    SymbolTable st6(sizeOfEachTable, 6); // Custom Hash 2

    testSymbolTable(st1, numberOfScopes, sizeOfEachScope);
    testSymbolTable(st2, numberOfScopes, sizeOfEachScope);
    testSymbolTable(st3, numberOfScopes, sizeOfEachScope);
    testSymbolTable(st4, numberOfScopes, sizeOfEachScope);
    testSymbolTable(st5, numberOfScopes, sizeOfEachScope);
    testSymbolTable(st6, numberOfScopes, sizeOfEachScope);

    ofstream out("collision_report.txt");
    if (out.is_open()) {
        out << fixed << setprecision(2);
        out << "Collision Report" << endl;
        out << "Total " << totalSymbols << " symbols inserted (" << sizeOfEachScope << " in each scope)" << endl;
        out << "Number of Scopes: " << numberOfScopes << endl;
        out << "ScopeTable Size: " << sizeOfEachTable << endl;

        out << "----------------------------------------------------------" << endl << endl;
        out << "Hash Function: SDBMHash      , Total collision : " << st1.getTotalCollisions() << endl;
        out << "Hash Function: DJBHash       , Total collision : " << st2.getTotalCollisions() << endl;
        out << "Hash Function: DEKHash       , Total collision : " << st3.getTotalCollisions() << endl;
        out << "Hash Function: APHash        , Total collision : " << st4.getTotalCollisions() << endl;
        out << "Hash Function: Custom Hash   , Total collision : " << st5.getTotalCollisions() << endl;
        out << "Hash Function: Custom Hash 2 , Total collision : " << st6.getTotalCollisions() << endl;

        out << "----------------------------------------------------------" << endl << endl;

        out << "Hash Function: SDBMHash      , Average Collision Ratio: " << st1.getCollisionRatio() << endl;
        out << "Hash Function: DJBHash       , Average Collision Ratio: " << st2.getCollisionRatio() << endl;
        out << "Hash Function: DEKHash       , Average Collision Ratio: " << st3.getCollisionRatio() << endl;
        out << "Hash Function: APHash        , Average Collision Ratio: " << st4.getCollisionRatio() << endl;
        out << "Hash Function: Custom Hash   , Average Collision Ratio: " << st5.getCollisionRatio() << endl;
        out << "Hash Function: Custom Hash 2 , Average Collision Ratio: " << st6.getCollisionRatio() << endl;

        out << "----------------------------------------------------------" << endl;
        out << endl;
        out.close();
    }

    return 0;
}
