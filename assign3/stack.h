/*
stack.h
A header file for interfacing with a linked list
Jake Gendreau
Feb 26, 2024
*/

#ifndef STACK_H
#define STACK_H

using namespace std;

#include <iostream>

class Stack{
    private:
        struct node{
            string data;
            node* next;
        };
        typedef node* nodePtr;

        nodePtr head;

        int count;

    public:
        //constructor
        Stack(){
            //init
            head = NULL;
            count = 0;
        }

        //deconstructor
        ~Stack(){
            nodePtr p = head;
            nodePtr n;

            while(p != NULL){
                n = p;
                p = p -> next;
                delete n;
            }
        }

        //add node onto the front of the list
        void pushFront(string x);

        //add node onto the front of the list
        void pushBack(string x);

        string pop();

        //delete the first node found with the value x if one exists
        void deleteNode(string x);

        //return the first node found in the list
        string peek();

        //output the values in the nodes, one char per line
        void print();

        //return true if there is a node with the value x
        bool isInList(string x);

        //return count of the number of nodes in the list
        int size();

        //delete list
        void deleteList();
};

#endif