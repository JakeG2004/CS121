// hash.h

#ifndef HASH_H
#define HASH_H

struct nList //table entry
{
    char* name;
    char* defn;
    struct nList* next;
};

typedef nList* NListPtr;

unsigned Hash(char* s);

NListPtr Lookup(char* s);
NListPtr Insert(char* name, char* defn);

void PrintHashTable();

#endif //HASH_H