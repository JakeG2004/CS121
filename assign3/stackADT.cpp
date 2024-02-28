/*
stackADT.cpp
Class for a linked list of characters
*/

#include <iostream>

#include "stack.h"

using namespace std;

//add an item to the front of the list
void Stack::push(char x){
    nodePtr n;

    //allocate new node
    n = new node;
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

char Stack::pop(){
    nodePtr n = head;

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
char Stack::peek(){
    return head -> data;
}

//print list
void Stack::print(){
    nodePtr p = head;

    //traverse the list
    while(p != NULL){
        cout << p -> data << endl;
        p = p -> next;
    }
}

//identify if element is in list
bool Stack::isInList(char x){
    nodePtr p = head;

    //traverse through, comparing along the way
    while(p != NULL){
        if(p -> data == x)
            return true;
        p = p -> next;
    }

    return false;
}

int Stack::size(){
    return count;
}

void Stack::deleteList(){
    nodePtr p;

    while(head != NULL){
        p = head;
        head = head -> next;
        delete(p);
    }

    delete(head);
}