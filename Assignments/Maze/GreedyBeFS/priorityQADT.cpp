/*
priorityQADT.cpp
Implementation of a priority queue using a linked list
Jake Gendreau
April 9, 2024
*/

//dependencies
#include <iostream>
#include "priorityQADT.h"

using namespace std;

//enqueue() - adds an item to the queue
void Queue::enqueue(int y, int x, int h)
{
    cell data = cell();

    data.x = x;
    data.y = y;
    data.h = h;

    nodePtr p = new node();

    //error check
    if (p == NULL)
    {
        cout << "ERROR: FAILED TO ALLOCATE NEW NODE" << endl;
        exit(-1);
    }

    p -> data = data;
    p -> next = NULL;

    //handle empty list
    if(head == NULL)
    {
        head = p;
        count++;
        return;
    }
    
    //insertion at the beginning of the list if h < head -> data.h
    if(h <= head -> data.h)
    {
        p -> next = head;
        head = p;
        count++;
        return;
    }

    //find correct insert spot
    nodePtr n = head;
    while(n -> next != NULL && h > n -> next -> data.h)
    {
        n = n->next;
    }

    //insert the new node after n
    p -> next = n -> next;
    n -> next = p;

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
        cout << n -> data.h << endl;
        n = n -> next;
    }
}

//size() - returns the size of the queue
int Queue::size()
{
    return(count);
}