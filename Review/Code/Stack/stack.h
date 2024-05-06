/*
stack.h
*/

#include <iostream>

using namespace std;

class Stack
{
    private:
        struct Node
        {
            int data;
            Node* next;
        };

        typedef Node* NodePtr;

        NodePtr head;

    public:
        //Constructor
        Stack()
        {
            head = NULL;
        }

        //Deconstructor
        ~Stack()
        {
            NodePtr p = head;
            NodePtr n = head;

            while(p != NULL)
            {
                n = p;
                p = p -> next;
                delete n;
            }
        }

        void Push(int);
        int Pop();
        int Peek();
        bool isEmpty();

        void printStack();
};