/*
Link.cppp
Class for a sorted linked list of integers
*/

#include <iostream>

#include "link.h"

using namespace std;

//add an item to the FRONT of the list
void LinkedList::addNode(int x){
    nodePtr n;

    //allocate new node
    n = new node;
    n -> info = x;
    count++;

    //set head = n if head is null
    if(head == NULL){
        head = n;
        n -> next = NULL;
    } 
    
    //otherwise, set n -> next = head and adjust head
    else {
        nodePtr tmp = head;
        n -> next = tmp;
        head = n;
    }
}

void LinkedList::deleteNode(int x){
    nodePtr prev, curr = head;

    while(curr != NULL && x > curr -> info){
        prev = curr;
        curr = curr -> next;
    }

    if(x == curr -> info){
        if(curr == head)
            head = head -> next;
        else
            prev -> next = curr -> next;

        delete curr;
        count--;
    }
}

int LinkedList::firstNode(){
    return head -> info;
}

void LinkedList::print(){
    nodePtr p = head;

    //traverse through list, printing
    while(p != NULL){
        cout << p -> info << endl;
        p = p -> next;
    }
}

bool LinkedList::isInList(int x){
    nodePtr p = head;

    while(p != NULL && x > p -> info)
        p = p -> next;

    return(x == p -> info);
}

int LinkedList::size(){
    return count;
}
