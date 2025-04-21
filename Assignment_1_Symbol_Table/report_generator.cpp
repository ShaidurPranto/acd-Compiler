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

// g++ report_generator.cpp SymbolTable.cpp ScopeTable.cpp hashFunctions.cpp SymbolInfo.cpp -o program 
// ./program

int main() {
    const int numberOfScopesToCreate = 7;
    const int numberOfSymbolToInsertInEachScope = 23;

    const int sizeOfEachTable = 16;

    const int totalSymbols = numberOfScopesToCreate * numberOfSymbolToInsertInEachScope;

    SymbolTable st1(sizeOfEachTable, 1); // SDBMHash
    SymbolTable st2(sizeOfEachTable, 2); // DJBHash
    SymbolTable st3(sizeOfEachTable, 3); // DEKHash
    SymbolTable st4(sizeOfEachTable, 4); // APHash
    SymbolTable st5(sizeOfEachTable, 5); // Custom Hash
    SymbolTable st6(sizeOfEachTable, 6); // Custom Hash 2

    testSymbolTable(st1, numberOfScopesToCreate, numberOfSymbolToInsertInEachScope);
    testSymbolTable(st2, numberOfScopesToCreate, numberOfSymbolToInsertInEachScope);
    testSymbolTable(st3, numberOfScopesToCreate, numberOfSymbolToInsertInEachScope);
    testSymbolTable(st4, numberOfScopesToCreate, numberOfSymbolToInsertInEachScope);
    testSymbolTable(st5, numberOfScopesToCreate, numberOfSymbolToInsertInEachScope);
    testSymbolTable(st6, numberOfScopesToCreate, numberOfSymbolToInsertInEachScope);

    ofstream out("collision_report.txt");
    if (out.is_open()) {
        out << fixed << setprecision(2);
        out << "Collision Report" << endl;
        out << "Total " << totalSymbols << " symbols inserted (" << numberOfSymbolToInsertInEachScope << " in each scope)" << endl;
        out << "Number of Scopes: " << numberOfScopesToCreate << endl;
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
