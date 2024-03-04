/*
Link.h
Interface for linked list of integers class
*/

#ifndef LINK_H
#define LINK_H

#include <iostream>

class LinkedList{
    private:
        struct node{
            int info;
            node* next;
        };
        typedef node* nodePtr;

        nodePtr head;

        int count;

    public:
        //Constructor
        LinkedList(){
            head = NULL;
            count = 0;
        }

        //Deconstructor
        ~LinkedList(){
            nodePtr p = head, n;

            while(p != NULL){
                n = p;
                p = p -> next;
                delete n;
            }
        }

        //add node onto the front of the linked list
        void addNode(int x);

        //delete the first node found with value x if one exists
        void deleteNode(int x);

        //return the first node found in the list
        int firstNode();

        //Output the values in the nodes, one int per line
        void print();

        //return true if there is a node with the value x
        bool isInList(int x);

        //return count of the number of nodes in the list
        int size();

};

#endif