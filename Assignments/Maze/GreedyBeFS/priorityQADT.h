/*
priorityQADT.h
priority queue header using a linked list
Jake Gendreau
April 9, 2024
*/

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

struct cell
{
    int x;
    int y;
    int h;
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

    void enqueue(int y, int x, int h);

    DATA_TYPE dequeue();

    void print();

    int size();
};

#endif // QUEUE_H