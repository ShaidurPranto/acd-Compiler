#include "hashFunctions.h"

#include <iostream>
#include <string>

using namespace std;

// hash functions
unsigned int SDBMHash(string str, int size)
{
    unsigned int hash = 0;

    unsigned int len = str.length();

    for (unsigned int i = 0; i < len; i++)
    {
        hash = ((str[i]) + (hash << 6) + (hash << 16) - hash) % size;
    }

    return hash;
}

unsigned int DJBHash(string str, int size) 
{
    unsigned long long hash = 5381;
    unsigned long long i = 0;
    unsigned long long len = str.length();

    for (i = 0; i < len; i++)
    {
        hash = ((hash << 5) + hash) + str[i];
    }

    return hash % size;
}

unsigned int DEKHash(string str, int size)
{
    unsigned long long hash = 0;
    unsigned long long i = 0;
    unsigned long long len = str.length();

    for (i = 0; i < len; i++)
    {
        hash = ((hash << 5) ^ (hash >> 27)) ^ str[i];
    }

    return hash % size;
}

unsigned int APHash(string str, int size)
{
    unsigned long long hash = 0;
    unsigned long long i = 0;
    unsigned long long len = str.length();

    for (i = 0; i < len; i++)
    {
        if ((i & 1) == 0)
        {
            hash ^= ((hash << 7) ^ str[i] ^ (hash >> 3));
        }
        else
        {
            hash ^= (~((hash << 11) + str[i] + (hash >> 5)));
        }
    }
    return hash % size;
}

unsigned int customHashOne(string str, int size)
{
    unsigned long long hash = 0;
    unsigned long long i = 0;
    unsigned long long len = str.length();

    for (i = 0; i < len; i++)
    {
        hash += str[i];
    }

    return hash % size;
}

unsigned int customHashTwo(string str, int size)
{
    //return 100 % size;
    return 0;
}
