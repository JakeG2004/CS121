#include <iostream>
#include "Queue.cpp"

using namespace std;

int main()
{
    Q queue = Q();

    queue.Enqueue(1);
    queue.Enqueue(2);

    cout << "First q" << endl;
    queue.printQ();

    cout << "Dequeing "<< queue.Dequeue() << endl;

    queue.printQ();
}