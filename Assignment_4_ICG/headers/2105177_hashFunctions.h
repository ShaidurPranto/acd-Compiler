#ifndef HASH_FUNCTIONS_H
#define HASH_FUNCTIONS_H

#include <string>
#include <iostream>
#include "2105177_SymbolInfo.h"

using namespace std;

unsigned int SDBMHash(string str, int size);
unsigned int DJBHash(string str, int size);
unsigned int DEKHash(string str , int size);
unsigned int APHash(string str , int size);
unsigned int customHashOne(string str , int size);
unsigned int customHashTwo(string str, int size);

#endif