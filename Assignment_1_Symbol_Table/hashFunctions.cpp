#include"hashFunctions.h"

#include<iostream>
#include<string>

using namespace std;

// hash functions
unsigned long long SDBMHash(string str) {
	unsigned long long hash = 0;
	unsigned long long i = 0;
	unsigned long long len = str.length();

	for (i = 0; i < len; i++)
	{
		hash = (str[i]) + (hash << 6) + (hash << 16) - hash;
	}

	return hash;
}

unsigned long long DJBHash(string str) {
    unsigned long long hash = 5381;
    unsigned long long i = 0;
    unsigned long long len = str.length();

    for (i = 0; i < len; i++)
    {
        hash = ((hash << 5) + hash) + str[i]; 
    }

    return hash;
}

unsigned long long DEKHash(string str) {
    unsigned long long hash = 0;
    unsigned long long i = 0;
    unsigned long long len = str.length();

    for (i = 0; i < len; i++)
    {
        hash = ((hash << 5) ^ (hash >> 27)) ^ str[i]; 
    }

    return hash;
}

unsigned long long APHash(string str) {
    unsigned long long hash = 0;
    unsigned long long i = 0;
    unsigned long long len = str.length();

    for (i = 0; i < len; i++) {
        if ((i & 1) == 0) {
            hash ^= ((hash << 7) ^ str[i] ^ (hash >> 3));
        } else {
            hash ^= (~((hash << 11) + str[i] + (hash >> 5)));
        }
    }
    return hash;
}

unsigned long long customHashOne(string str) {
    unsigned long long hash = 1;
    unsigned long long i = 0;
    unsigned long long len = str.length();

    for (i = 0; i < len; i++)
    {
        hash = hash * 31 * str[i];
    }

    return hash;
}

unsigned long long customHashTwo(string str) {
    return 100;
}

