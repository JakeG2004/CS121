/*
queueADT.h
A header file for interfacing with a linked list through a queue
Jake Gendreau
April 1, 2024
*/

//file guards
#ifndef QUEUE_H
#define QUEUE_H

//boilerplate
using namespace std;

#include<iostream>

typedef int DATA_TYPE;

//class
class Queue
{
    private:
        //linked list boilerplate
        struct node
        {
            DATA_TYPE data;
            node* next;
        };
        typedef node* nodePtr;

        nodePtr head;

        int count;

    public:
        //constructor
        Queue()
        {
            //init
            head = NULL;
            count = 0;
        }

        //deconstructor
        ~Queue()
        {
            nodePtr p = head;
            nodePtr n;

            //delete the list
            while(p != NULL)
            {
                n = p;
                p = p -> next;
                delete n;
            }
        }

        //enqueue() - adds an item to the queue
        void enqueue(DATA_TYPE x);

        //dequeue() - removes and returns the first item from the queue
        DATA_TYPE dequeue();

        //print() - prints the queue
        void print();

        //size() - returns the size of the queue
        int size();

};



#endif