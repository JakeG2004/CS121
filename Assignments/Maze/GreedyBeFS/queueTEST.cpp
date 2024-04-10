/*
priorityQ.cpp
A program to test my implementation of queues
Jake Gendreau
April 9, 2024
*/

//boilerplate
#include <iostream>
#include "priorityQADT.cpp"

using namespace std;

int main()
{
    Queue queue = Queue();

    for(int i = 0; i < 10; i++)
    {
        queue.enqueue(0, 0, i);
    }
    
    queue.print();
    cout << endl;

    queue.enqueue(0, 0, 0);
    queue.print();

    queue.enqueue(0, 0, 5);
    queue.print();
}