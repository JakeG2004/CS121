//q.cpp

#include <iostream>
#include "Queue.h"

using namespace std;

void Q::Enqueue(int x)
{
    NodePtr n = new Node();
    n -> data = x;

    if(head == NULL)
    {
        head = n;
        return;
    }

    NodePtr p = head;

    while(p -> next != NULL)
    {
        p = p -> next;
    }

    p -> next = n;
}

int Q::Dequeue()
{
    int retVal = head -> data;

    NodePtr p = head;
    head = head -> next;

    delete p;

    return retVal;
}

int Q::Size()
{
    NodePtr p = head;
    int size = 0;

    while(p != NULL)
    {
        p = p -> next;
        size++;
    }

    return size;
}

void Q::printQ()
{
    NodePtr p = head;

    while(p != NULL)
    {
        cout << p -> data << endl;
        p = p -> next;
    }
}