#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

struct cell
{
    char type;
    bool visited = false;
    int x;
    int y;
};

typedef cell DATA_TYPE;

class Queue
{
private:
    struct node
    {
        DATA_TYPE data;
        node* next;
    };
    typedef node* nodePtr;

    nodePtr head;

    int count;

public:
    Queue()
    {
        head = NULL;
        count = 0;
    }

    ~Queue()
    {
        nodePtr p = head;
        nodePtr n;

        while(p != NULL)
        {
            n = p;
            p = p -> next;
            delete n;
        }
    }

    void enqueue(DATA_TYPE x);

    DATA_TYPE dequeue();

    void print();

    int size();
};

#endif // QUEUE_H