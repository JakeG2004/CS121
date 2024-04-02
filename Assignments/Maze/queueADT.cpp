/*
queueADT.cpp
Implementation of a queue using a linked list
Jake Gendreau
April 1, 2024
*/

//dependencies
#include <iostream>
#include "queueADT.h"

using namespace std;

//enqueue() - adds an item to the queue
void Queue::enqueue(DATA_TYPE x)
{
    //alloc new node
    nodePtr p = new node();

    //error check
    if(p == NULL)
    {
        cout << "ERROR: FAILED TO ALLOC NEW NODE" << endl;
        exit(-1);
    }

    //fill node
    p -> next = NULL;
    p -> data = x;

    //handle empty list
    if(head == NULL)
        head = p;
    
    //otherwise, go to last node and insert new node
    else
    {
        nodePtr n = head;
        while(n -> next != NULL)
        {
            n = n -> next;
        }

        n -> next = p;
    }

    //increment count
    count++;
}

//dequeue() - removes and returns the first item from the queue
DATA_TYPE Queue::dequeue()
{
    //error check
    if(size() <= 0)
    {
        cout << "ERROR: DEQUEING EMPTY QUEUE" << endl;
        exit(-1);
    }

    DATA_TYPE returnVal = head -> data;

    //move head and delete old head
    nodePtr n = head;
    head = head -> next;

    n -> next = NULL;
    delete n;

    //decrement counter
    count--;

    return returnVal;
}

//print() - prints the queue
void Queue::print()
{
    nodePtr n = head;

    //print data of each node
    while(n != NULL)
    {
        cout << n -> data << endl;
        n = n -> next;
    }
}

//size() - returns the size of the queue
int Queue::size()
{
    return(count);
}