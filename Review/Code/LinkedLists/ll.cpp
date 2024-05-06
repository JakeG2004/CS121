/*
ll.cpp
the implementation of a linked list through the use of ll.h
*/

#include <iostream>
#include "ll.h"

using namespace std;

void LinkedList::printList()
{
    NodePtr p = head;

    //traverse list
    while(p != NULL)
    {
        cout << p -> data << endl;
        p = p -> next;
    }
}

void LinkedList::insertHead(int x)
{
    //define new node
    NodePtr n = new Node();

    n -> data = x;
    n -> next = head;

    //assign it to head
    head = n;
}

void LinkedList::insertTail(int x)
{
    //handle empty list
    if(head == NULL)
    {
        insertHead(x);
        return;
    }

    NodePtr p = head;

    while(p -> next != NULL)
    {
        p = p -> next;
    }

    NodePtr n = new Node();
    n -> data = x;

    p -> next = n;
}

int LinkedList::deleteHead()
{
    if(head == NULL)
    {
        cout << "Deleting from head of empty list" << endl;
        exit(-1);
    }

    int returnVal = head -> data;

    //move head and break link
    NodePtr p = head;
    head = head -> next;
    p -> next = NULL;
    delete p;

    return returnVal;
}

int LinkedList::deleteTail()
{
    //handle empty list
    if(head == NULL)
    {
        cout << "Deleting from tail of empty list" << endl;
        exit(-1);
    }

    int returnVal = 0;

    NodePtr p = head;
    NodePtr nextNode = p -> next;
    
    //handle one node
    if(nextNode == NULL)
    {
        returnVal = p -> data;
        delete p;
        return returnVal;
    }

    //navigate to last node, with p trailing by one
    while(nextNode -> next != NULL)
    {
        p = nextNode;
        nextNode = nextNode -> next;
    }

    //delete and break link to next node
    returnVal = nextNode -> data;
    p -> next = NULL;

    delete nextNode;

    return returnVal;
}