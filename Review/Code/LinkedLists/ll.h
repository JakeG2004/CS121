/*
ll.h
A header file for an implementation of a linked list
*/

#include <iostream>

using namespace std;

class LinkedList
{
    private:
        struct Node
        {
            int data = 0;
            Node* next = NULL;
        }; 
        typedef Node* NodePtr;

        NodePtr head = NULL;

    public:
        LinkedList()
        {
            head = NULL;
        }

        ~LinkedList()
        {
            NodePtr p = head, n;

            while(p != NULL){
                n = p;
                p = p -> next;
                delete n;
            }
        }
        
        void printList();

        void insertHead(int);
        void insertTail(int);

        int deleteHead();
        int deleteTail();
};