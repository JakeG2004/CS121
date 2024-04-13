/*
hash.cpp

Hash table implementation from:
Kernighan & Ritchie, The C Programming Language,
Second Edition
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string.h>

#include "hash.h"

using namespace std;

const int HASH_TABLE_SIZE = 101;
NListPtr hashTable[HASH_TABLE_SIZE];

//prototypes
//char* strdup(const char*); //in string.h

// generate hash val for string s
unsigned Hash(char* s)
{
    unsigned hashVal;

    for(hashVal = 0; *s != '\0'; s++)
    {
        hashVal = *s + 31 * hashVal;
    }

    return hashVal % HASH_TABLE_SIZE;
}

NListPtr Lookup(char* s)
{
    NListPtr np;

    //look through every element, return np if it is found, otherwise return NULL
    for(np = hashTable[Hash(s)]; np != NULL; np = np -> next)
    {
        if(strcmp(s, np -> name) == 0)
        {
            return np;
        }
    }

    return NULL;
}

NListPtr Insert(char* name, char* defn)
{
    unsigned hashVal;
    NListPtr np;

    if((np = Lookup(name)) == NULL) //doesnt exist in table
    {
        //alloc new NListPtr
        np = (NListPtr)malloc(sizeof(*np));

        //error check
        if(np == NULL || (np -> name = strdup(name)) == NULL)
            return NULL;

        //get hash val
        hashVal = Hash(name);

        //set next to be the head
        np -> next = hashTable[hashVal];

        //set new node to be head
        hashTable[hashVal] = np;
    }

    else //remove previous definition
    {
        free((void*)np -> defn);
    }

    if((np -> defn = strdup(defn)) == NULL) //if failed to duplicate string, set null
        return NULL;

    return np;
}

void PrintHashTable()
{
    NListPtr np;

    cout << "HASH TABLE CONTENTS" << endl;

    for(np = hashTable[0]; np != NULL; np = np -> next)
    {
        cout << np -> name << "\t" << np -> defn << endl;
    }
}