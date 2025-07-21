#!/bin/bash
antlr4 -Dlanguage=Cpp C8086Lexer.g4
antlr4 -Dlanguage=Cpp C8086Parser.g4
g++ -c ./headers/2105177_hashFunctions.cpp
g++ -c ./headers/2105177_SymbolInfo.cpp
g++ -c ./headers/2105177_ScopeTable.cpp
g++ -c ./headers/2105177_SymbolTable.cpp
g++ -std=c++17 -w -I/usr/local/include/antlr4-runtime -c C8086Lexer.cpp C8086Parser.cpp Ctester.cpp
g++ -std=c++17 -w C8086Lexer.o C8086Parser.o Ctester.o 2105177_hashFunctions.o 2105177_SymbolInfo.o 2105177_ScopeTable.o 2105177_SymbolTable.o -L/usr/local/lib/ -lantlr4-runtime -o Ctester.out -pthread
LD_LIBRARY_PATH=/usr/local/lib ./Ctester.out ./input/input.c
