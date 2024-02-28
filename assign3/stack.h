/*
stack.h
A header file for interfacing with a linked list
Jake Gendreau
Feb 26, 2024
*/

#ifndef STACK_H
#define STACK_H

#include <iostream>

class Stack{
    private:
        struct node{
            char data;
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
        void push(char x);

        char pop();

        //delete the first node found with the value x if one exists
        void deleteNode(char x);

        //return the first node found in the list
        char peek();

        //output the values in the nodes, one char per line
        void print();

        //return true if there is a node with the value x
        bool isInList(char x);

        //return count of the number of nodes in the list
        int size();

        //delete list
        void deleteList();
};

#endif