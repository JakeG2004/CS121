/*
q.h
*/

#include <iostream>

using namespace std;

class Q
{
    private:
        struct Node
        {
            int data;
            Node* next;
        };

        typedef Node* NodePtr;

        NodePtr head;
        int size;

    public:
        //Constructor
        Q()
        {
            head = NULL;
            size = 0;
        }

        //Deconstructor
        ~Q()
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

        void Enqueue(int);
        int Dequeue();

        int Size();

        void printQ();
};