#ifndef HASH_FUNCTIONS_H
#define HASH_FUNCTIONS_H

#include <string>
#include <iostream>
#include "SymbolInfo.h"

using namespace std;

unsigned long long SDBMHash(string str);
unsigned long long DJBHash(string str);
unsigned long long DEKHash(string str);
unsigned long long APHash(string str);
unsigned long long customHashOne(string str);
unsigned long long customHashTwo(string str);

#endif