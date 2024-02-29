/*
stackADT.cpp
Class for a linked list of strings
*/

#include <iostream>

#include "stack.h"

using namespace std;

//add an item to the front of the list
void Stack::pushFront(string x)
{
    nodePtr n;

    //allocate new node
    n = new node;
    
    //error checking
    if(n == NULL)
    {
        cout << "ERROR: PUSH IS INVALID" << endl;
        exit(-1);
    }

    //set node
    n -> data = x;

    //set head = n if head is null
    if(head == NULL){
        head = n;
        n -> next = NULL;
    }

    //otherwise, append to the front of the list
    else{
        n -> next = head;
        head = n;
    }

    count++;
}

void Stack::pushBack(string x){
    nodePtr p = new node();
    p->next = NULL;
    p->data = x;

    if (head == NULL) {
        // If the list is empty, make the new node the head
        head = p;
    } else {
        // Otherwise, find the last node and update its next pointer
        nodePtr n = head;
        while (n->next != NULL) {
            n = n->next;
        }
        n->next = p;
    }
}

string Stack::pop()
{
    nodePtr n = head;

    //error checking
    if(n == NULL)
    {
        cout << "ERROR: POP ON EMPTY STACK" << endl;
        exit(-1);
    }

    //store data to return
    string returnChar = n -> data;

    //reposition head
    head = head -> next;

    //cut link and delete
    n -> next = NULL;
    delete(n);

    count--;

    //return data
    return returnChar;
}

//return the data in the first node
string Stack::peek()
{
    //error checking
    if(count == 0)
    {
        cout << "ERROR: PEEK ON EMPTY STACK" << endl;
        exit(-1);
    }

    //return data @ head
    return head -> data;
}

//print list
void Stack::print()
{
    nodePtr p = head;

    //traverse
    while(p != NULL)
    {
        //print data @ current node
        cout << p -> data << endl;
        p = p -> next;
    }
}

//identify if element is in list
bool Stack::isInList(string query)
{
    nodePtr p = head;

    //traverse the list
    while(p != NULL)
    {
        //return true if query is found
        if(p -> data == query)
            return true;
        p = p -> next;
    }

    //otherwise, return false
    return false;
}

int Stack::size()
{
    return count;
}

void Stack::deleteList()
{
    nodePtr p;

    //traverse through the list
    while(head != NULL)
    {
        //move head to the next node and delete current node
        p = head;
        head = head -> next;
        delete(p);
    }

    //finally, delete head
    delete(head);
}