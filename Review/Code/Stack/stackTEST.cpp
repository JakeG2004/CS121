#include <iostream>
#include "stack.cpp"

using namespace std;

int main()
{
    Stack stack = Stack();

    stack.Push(1);
    stack.Push(2);

    stack.printStack();

    cout << "Top value is " << stack.Peek() << endl;
    cout << "Popping " << stack.Pop() << endl;

    stack.printStack();

    stack.Pop();

    if(stack.isEmpty())
        cout << "Stack is empty" << endl;
}