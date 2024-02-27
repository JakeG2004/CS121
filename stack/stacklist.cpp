/*
stacklist.cpp
*/

#ifndef STACK_H
#define STACK_H // file guards

#include "link.h"

class Stack {
    public:
        Stack();
        ~Stack();

        void Push(int n);
        int Pop();
        int IsEmpty();
        void Print();

    private:
        LinkedList topPtr;
};
#endif
