#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include"SymbolInfo.h"
#include"ScopeTable.h"
#include"SymbolTable.h"

using namespace std;

int countWords(const string& input) {
    stringstream ss(input);
    string word;
    int count = 0;

    while (ss >> word) {
        count++;
    }

    return count;
}


void printReport(SymbolTable& symbolTable , int hashFunctionOption) {
    if(hashFunctionOption == 1) {
        cout << "Hash Function: SDBMHash" << endl;
    } else if(hashFunctionOption == 2) {
        cout << "Hash Function: DJBHash" << endl;
    } else if(hashFunctionOption == 3) {
        cout << "Hash Function: DEKHash" << endl;
    } else if(hashFunctionOption == 4) {
        cout << "Hash Function: APHash" << endl;
    } else if(hashFunctionOption == 5) {
        cout << "Hash Function: customHashOne" << endl;
    } else if(hashFunctionOption == 6) {
        cout << "Hash Function: customHashTwo" << endl;
    }

    cout << "Total number of collisions: " << symbolTable.getInclusiveTotalCollisions() << endl;
    cout << "Collision ratio: " << symbolTable.getInclusiveCollisionRatio() << endl;
}

// g++ main.cpp SymbolTable.cpp ScopeTable.cpp hashFunctions.cpp SymbolInfo.cpp -o program 
// ./program sample_input.txt my_output.txt 1


int main(int argc , char* argv[]) {

    string inputFile = argv[1];
    string outputFile = argv[2];
    int hashFunctionOption = 1;
    if(argc == 4){
        int choice = atoi(argv[3]);
        if (choice < 1 || choice > 6) {
            cerr << "Error: Invalid hash function option. Please choose between 1 and 6." << endl;
            return 1;
        }
        hashFunctionOption = choice;
    }

    ifstream file(inputFile);
    if (!file) {
        cerr << "Error: Input file not found." << endl;
        return 1;
    }

    file.close();
    
    freopen(inputFile.c_str(), "r", stdin);
    freopen(outputFile.c_str(), "w", stdout);

    int size;
    cin >> size;
    cin.ignore(); 

    SymbolTable symbolTable(size, hashFunctionOption);

    string line;
    int lineCount = 0;

    while (getline(cin, line)) {
        if (line.empty()) continue;
        lineCount++;

        cout<<"Cmd "<<lineCount<<": "<<line<<endl;
        int wordCount = countWords(line);

        stringstream ss(line);
        char command;
        ss >> command;

        switch (command) {
            case 'I': {
                if (wordCount < 3) {
                    cout << "Number of parameters mismatch for the command I" << endl;
                    break;
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

                if (symbolTable.insert(symbolName, formattedType)) {
                    cout << "\tInserted in " << symbolTable.getPositionAsString(symbolName) << endl;
                } else {
                    cout << "\t'" << symbolName << "' already exists in the current ScopeTable" << endl;
                }
            
                break;
            }
            
            case 'L': {
                if (wordCount != 2) {
                    cout << "\tNumber of parameters mismatch for the command L" << endl;
                    break;
                }

                string symbolName;
                ss >> symbolName;
                SymbolInfo* symbol = symbolTable.lookUp(symbolName);
                if (symbol) {
                    cout << "\t'" << symbolName << "' found in " << symbolTable.getPositionAsString(symbolName) << endl;
                } else {
                    cout << "\t'" << symbolName << "' not found in any of the ScopeTables" << endl;
                }
                break;
            }
            case 'D': {
                if (wordCount != 2) {
                    cout << "\tNumber of parameters mismatch for the command D" << endl;
                    break;
                }

                string symbolName;
                ss >> symbolName;
                SymbolInfo* symbol = symbolTable.lookUp(symbolName);
                if (symbol) {
                    string position = symbolTable.getPositionAsString(symbolName);
                    if (symbolTable.remove(symbolName)) {
                        cout << "\tDeleted '" << symbolName << "' from " << position << endl;
                    } else {
                        cout << "\tNot found in the current ScopeTable" << endl;
                    }
                } else {
                    // cout << "\t'" << symbolName << "' not found in any of the ScopeTables" << endl;
                    cout << "\tNot found in the current ScopeTable" << endl;
                }
                break;
            }
            case 'P': {
                if (wordCount != 2) {
                    cout << "\tNumber of parameters mismatch for the command P" << endl;
                    break;
                }

                char printType;
                ss >> printType;
                if (printType == 'A') {
                    symbolTable.printAllScopeTables();
                } else if (printType == 'C') {
                    symbolTable.printCurrentScopeTable();
                }
                break;
            }
            case 'S': {
                if (wordCount != 1) {
                    cout << "\tNumber of parameters mismatch for the command S" << endl;
                    break;
                }
                symbolTable.enterScope();
                break;
            }
            case 'E': {
                if (wordCount != 1) {
                    cout << "\tNumber of parameters mismatch for the command E" << endl;
                    break;
                }
                symbolTable.exitScope();
                break;
            }
            case 'Q': {
                if (wordCount != 1) {
                    cout << "\tNumber of parameters mismatch for the command Q" << endl;
                    break;
                }

                freopen("/dev/tty", "w", stdout);
                printReport(symbolTable, hashFunctionOption);

                return 0;
            }
            default:
                cout << "\t[INVALID COMMAND]" << endl;
                break;
        }
    }

    return 0;
}
