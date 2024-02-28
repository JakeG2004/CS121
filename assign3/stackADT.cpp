/*
stackADT.cpp
Class for a linked list of characters
*/

#include <iostream>

#include "stack.h"

using namespace std;

//add an item to the front of the list
void Stack::push(char x)
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

char Stack::pop()
{
    nodePtr n = head;

    //error checking
    if(n == NULL)
    {
        cout << "ERROR: POP ON EMPTY STACK" << endl;
        exit(-1);
    }

    //store data to return
    char returnChar = n -> data;

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
char Stack::peek()
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
bool Stack::isInList(char query)
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