/*
llT.h
This is a class for a sorted linked list of type LLT. The data type LLT must allow a > comparison
*/

#include <iostream>

template <class LLT>
class LinkedList
{
    private:
        struct node
        {
            LLT info;
            node* next;
        };

        typedef node* nodePtr;

        nodePtr head;

        int count;

    public:
        LinkedList()
        {
            head = NULL;
        }

        ~LinkedList()
        {}

    //he went too fast :(
};