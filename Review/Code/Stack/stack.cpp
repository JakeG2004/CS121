#include <iostream>
#include "stack.h"

using namespace std;

void Stack::Push(int x)
{
    NodePtr p = new Node();
    p -> data = x;
    p  -> next = head;
    head = p;
}

int Stack::Pop()
{
    //error check
    if(head == NULL)
    {
        cout << "Error: Pop on empty stack" << endl;
        exit(-1);
    }

    //get return value
    int retVal = head -> data;

    //move head and delete old head
    NodePtr p = head;
    head = head -> next;
    delete p;

    return retVal;
}

int Stack::Peek()
{
    //error check
    if(head == NULL)
    {
        cout << "Error: Peek on empty stack" << endl;
        exit(-1);
    }

    return head -> data;
}

bool Stack::isEmpty()
{
    return(head == NULL);
}

void Stack::printStack()
{
    NodePtr p = head;

    while(p != NULL)
    {
        cout << p -> data << endl;
        p = p -> next;
    }
}