#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

#include "SymbolTable.h"


const int numberOfScopesToCreate = 5;
const int numberOfSymbolToInsertInEachScope = 27;
const int sizeOfEachTable = 16;

const string outputFile = "report.txt";



string randomString() {
    const string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int length = 5 + rand() % 6; 

    string result;
    for (int i = 0; i < length; ++i) {
        result += chars[rand() % chars.length()];
    }
    return result;
}


void testSymbolTable(SymbolTable &st, int numberOfScopes, int sizeOfEachScope)
{
    int counter = 0;

    for (int i = 0; i < numberOfScopes; ++i)
    {
        st.enterScope();
        for (int j = 0; j < sizeOfEachScope; ++j)
        {
            string name = randomString() + to_string(counter);
            string type = (counter % 2 == 0) ? "int" : "float";
            st.insert(name, type);
            counter++;
        }
    }
}


void testByGeneratingRandomStrings()
{
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

    ofstream out(outputFile);
    if (out.is_open())
    {
        out << fixed << setprecision(2);
        out << "Collision Report" << endl;
        out << "Total " << totalSymbols << " symbols inserted (" << numberOfSymbolToInsertInEachScope << " in each scope)" << endl;
        out << "Number of Scopes: " << numberOfScopesToCreate << endl;
        out << "ScopeTable Size: " << sizeOfEachTable << endl;

        out << "----------------------------------------------------------" << endl
            << endl;
        out << "Hash Function: SDBMHash      , Total collision : " << st1.getInclusiveTotalCollisions() << endl;
        out << "Hash Function: DJBHash       , Total collision : " << st2.getInclusiveTotalCollisions() << endl;
        out << "Hash Function: DEKHash       , Total collision : " << st3.getInclusiveTotalCollisions() << endl;
        out << "Hash Function: APHash        , Total collision : " << st4.getInclusiveTotalCollisions() << endl;
        out << "Hash Function: Custom Hash   , Total collision : " << st5.getInclusiveTotalCollisions() << endl;
        out << "Hash Function: Custom Hash 2 , Total collision : " << st6.getInclusiveTotalCollisions() << endl;

        out << "----------------------------------------------------------" << endl
            << endl;

        out << "Hash Function: SDBMHash      , Average Collision Ratio: " << st1.getInclusiveCollisionRatio() << endl;
        out << "Hash Function: DJBHash       , Average Collision Ratio: " << st2.getInclusiveCollisionRatio() << endl;
        out << "Hash Function: DEKHash       , Average Collision Ratio: " << st3.getInclusiveCollisionRatio() << endl;
        out << "Hash Function: APHash        , Average Collision Ratio: " << st4.getInclusiveCollisionRatio() << endl;
        out << "Hash Function: Custom Hash   , Average Collision Ratio: " << st5.getInclusiveCollisionRatio() << endl;
        out << "Hash Function: Custom Hash 2 , Average Collision Ratio: " << st6.getInclusiveCollisionRatio() << endl;

        out << "----------------------------------------------------------" << endl;
        out << endl;
        out.close();
    }
}


int countWords(const string& input) {
    stringstream ss(input);
    string word;
    int count = 0;

    while (ss >> word) {
        count++;
    }

    return count;
}

void testFromFile(const string& inputFile)
{
    freopen(inputFile.c_str(), "r", stdin);
    freopen(outputFile.c_str(), "w", stdout);

    string first;
    getline(cin, first);
    stringstream ss(first);

    int size;
    ss >> size;

    SymbolTable symbolTable1(size, 1); // SDBMHash
    SymbolTable symbolTable2(size, 2); // DJBHash
    SymbolTable symbolTable3(size, 3); // DEKHash
    SymbolTable symbolTable4(size, 4); // APHash
    SymbolTable symbolTable5(size, 5); // Custom Hash
    SymbolTable symbolTable6(size, 6); // Custom Hash 2

    string line;

    while (getline(cin, line)) {
        if (line.empty()) continue;

        int wordCount = countWords(line);

        stringstream ss(line);
        string command;
        ss >> command;

        if (command == "I") {
            if (wordCount < 3) {
                continue;
            }

            string symbolName, symbolType;
            ss >> symbolName >> symbolType;

            string formattedType = symbolType;

            if (symbolType == "FUNCTION") {
                string returnType;
                ss >> returnType;
                string argType;
                vector<string> args;
                while (ss >> argType) {
                    args.push_back(argType);
                }
                formattedType = "FUNCTION," + returnType + "<==(";
                for (size_t i = 0; i < args.size(); ++i) {
                    formattedType += args[i];
                    if (i != args.size() - 1) formattedType += ",";
                }
                formattedType += ")";
            } else if (symbolType == "STRUCT" || symbolType == "UNION") {
                vector<pair<string, string>> fields;
                string type, name;
                while (ss >> type >> name) {
                    fields.emplace_back(type, name);
                }
                formattedType = symbolType + ",{";
                for (size_t i = 0; i < fields.size(); ++i) {
                    formattedType += "(" + fields[i].first + "," + fields[i].second + ")";
                    if (i != fields.size() - 1) formattedType += ",";
                }
                formattedType += "}";
            }

            symbolTable1.insert(symbolName, formattedType);
            symbolTable2.insert(symbolName, formattedType);
            symbolTable3.insert(symbolName, formattedType);
            symbolTable4.insert(symbolName, formattedType);
            symbolTable5.insert(symbolName, formattedType);
            symbolTable6.insert(symbolName, formattedType);

        } else if (command == "L") {
            if (wordCount != 2) {
                continue;
            }

            string symbolName;
            ss >> symbolName;

        } else if (command == "D") {
            if (wordCount != 2) {
                continue;
            }

            string symbolName;
            ss >> symbolName;

            symbolTable1.remove(symbolName);
            symbolTable2.remove(symbolName);
            symbolTable3.remove(symbolName);
            symbolTable4.remove(symbolName);
            symbolTable5.remove(symbolName);
            symbolTable6.remove(symbolName);

        } else if (command == "P") {
        } else if (command == "S") {
            if (wordCount != 1) {
                continue;
            }

            symbolTable1.enterScope();
            symbolTable2.enterScope();
            symbolTable3.enterScope();
            symbolTable4.enterScope();
            symbolTable5.enterScope();
            symbolTable6.enterScope();

        } else if (command == "E") {
            if (wordCount != 1) {
                continue;
            }

            symbolTable1.exitScope();
            symbolTable2.exitScope();
            symbolTable3.exitScope();
            symbolTable4.exitScope();
            symbolTable5.exitScope();
            symbolTable6.exitScope();

        } else if (command == "Q") {
            if (wordCount != 1) {
                continue;
            }


            ofstream out(outputFile);
            if (out.is_open())
            {
                out << fixed << setprecision(2);
                out << "Collision Report" << endl;
                out << "Input Taken from file : " << inputFile << endl;
        
                out << "----------------------------------------------------------" << endl
                    << endl;
                out << "Hash Function: SDBMHash      , Total collision : " << symbolTable1.getInclusiveTotalCollisions() << endl;
                out << "Hash Function: DJBHash       , Total collision : " << symbolTable2.getInclusiveTotalCollisions() << endl;
                out << "Hash Function: DEKHash       , Total collision : " << symbolTable3.getInclusiveTotalCollisions() << endl;
                out << "Hash Function: APHash        , Total collision : " << symbolTable4.getInclusiveTotalCollisions() << endl;
                out << "Hash Function: Custom Hash   , Total collision : " << symbolTable5.getInclusiveTotalCollisions() << endl;
                out << "Hash Function: Custom Hash 2 , Total collision : " << symbolTable6.getInclusiveTotalCollisions() << endl;
        
                out << "----------------------------------------------------------" << endl
                    << endl;
        
                out << "Hash Function: SDBMHash      , Average Collision Ratio: " << symbolTable1.getInclusiveCollisionRatio() << endl;
                out << "Hash Function: DJBHash       , Average Collision Ratio: " << symbolTable2.getInclusiveCollisionRatio() << endl;
                out << "Hash Function: DEKHash       , Average Collision Ratio: " << symbolTable3.getInclusiveCollisionRatio() << endl;
                out << "Hash Function: APHash        , Average Collision Ratio: " << symbolTable4.getInclusiveCollisionRatio() << endl;
                out << "Hash Function: Custom Hash   , Average Collision Ratio: " << symbolTable5.getInclusiveCollisionRatio() << endl;
                out << "Hash Function: Custom Hash 2 , Average Collision Ratio: " << symbolTable6.getInclusiveCollisionRatio() << endl;
        
                out << "----------------------------------------------------------" << endl;
                out << endl;
                out.close();
            }


            freopen("/dev/tty", "w", stdout);
            return;

        } else {
            cout << "\t[INVALID COMMAND]" << endl;
        }
    }
}




// g++ report_generator.cpp SymbolTable.cpp ScopeTable.cpp hashFunctions.cpp SymbolInfo.cpp -o program
// .program

int main(int argc, char *argv[])
{

    string inputFileName;
    if(argc > 1){
        inputFileName = argv[1];
        ifstream inFile(inputFileName);
        if (!inFile)
        {
            cout << "Error opening file: " << inputFileName << endl;
            cout << "Testing with random strings." << endl;
            testByGeneratingRandomStrings();
            return 1;
        }
        inFile.close();
        testFromFile(inputFileName);
    
    }else{
        testByGeneratingRandomStrings();
    }
    return 0;
}
