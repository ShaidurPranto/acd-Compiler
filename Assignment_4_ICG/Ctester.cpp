#include <iostream>
#include <fstream>
#include <string>
#include "antlr4-runtime.h"
#include "C8086Lexer.h"
#include "C8086Parser.h"
#include "./headers/2105177_SymbolTable.h"

using namespace antlr4;
using namespace std;

ofstream parserLogFile; // global output stream
ofstream errorFile; // global error stream
ofstream lexLogFile; // global lexer log stream

ofstream codeFile;
ofstream optCodeFile;
ofstream tempFile;
string tempFileName;
string codeFileName;
string optCodeFileName;

int syntaxErrorCount;

SymbolTable symbolTable(7);

int main(int argc, const char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }

    // ---- Input File ----
    ifstream inputFile(argv[1]);
    if (!inputFile.is_open()) {
        cerr << "Error opening input file: " << argv[1] << endl;
        return 1;
    }

    string outputDirectory = "output/";
    string parserLogFileName = outputDirectory + "parserLog.txt";
    string errorFileName = outputDirectory + "errorLog.txt";
    string lexLogFileName = outputDirectory + "lexerLog.txt";
    codeFileName = outputDirectory + "code.txt";
    optCodeFileName = outputDirectory + "optCode.txt";
    tempFileName = outputDirectory + "temp.txt";


    // create output directory if it doesn't exist
    system(("mkdir -p " + outputDirectory).c_str());

    // ---- Output Files ----
    parserLogFile.open(parserLogFileName);
    if (!parserLogFile.is_open()) {
        cerr << "Error opening parser log file: " << parserLogFileName << endl;
        return 1;
    }

    errorFile.open(errorFileName);
    if (!errorFile.is_open()) {
        cerr << "Error opening error log file: " << errorFileName << endl;
        return 1;
    }

    lexLogFile.open(lexLogFileName);
    if (!lexLogFile.is_open()) {
        cerr << "Error opening lexer log file: " << lexLogFileName << endl;
        return 1;
    }

    codeFile.open(codeFileName);
    if (!codeFile.is_open()) {
        cerr << "Error opening code file: " << codeFileName << endl;
        return 1;
    }

    optCodeFile.open(optCodeFileName);
    if (!optCodeFile.is_open()) {
        cerr << "Error opening optimized code file: " << optCodeFileName << endl;
        return 1;
    }

    tempFile.open(tempFileName);
    if (!tempFile.is_open()) {
        cerr << "Error opening temporary file: " << tempFileName << endl;
        return 1;
    }
   
    // ---- Parsing Flow ----
    ANTLRInputStream input(inputFile);
    C8086Lexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    C8086Parser parser(&tokens);

    // this is necessary to avoid the default error listener and use our custom error handling
    parser.removeErrorListeners();

    // start parsing at the 'start' rule
    parser.start();

    // clean up
    inputFile.close();

    parserLogFile.close();
    errorFile.close();
    lexLogFile.close();

    codeFile.close();
    optCodeFile.close();
    tempFile.close();

    cout << "Parsing completed. Check the output files for details." << endl;
    return 0;
}
