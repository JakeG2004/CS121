/*
queueTEST.cpp
A program to test my implementation of queues
Jake Gendreau
April 1, 2024
*/

//boilerplate
#include <iostream>
#include "queueADT.cpp"

using namespace std;

int main()
{
    Queue queue = Queue();

    cout << "QUEUE SIZE: " << queue.size() << endl;

    queue.enqueue(6);
    queue.enqueue(8);
    queue.enqueue(10);

    cout << "QUEUE SIZE: " << queue.size() << endl;
    queue.print();

    queue.dequeue();
    queue.print();

    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
}