#include <iostream>
#include "ll.cpp"

using namespace std;

int main()
{
    LinkedList ll = LinkedList();

    ll.insertHead(2);
    ll.insertHead(1);

    ll.insertTail(3);

    cout << "Initial list" << endl;
    ll.printList();
    
    cout << "Deleting " << ll.deleteHead() << " from head" << endl;
    cout << "New list" << endl;
    ll.printList();

    cout << "Deleting " << ll.deleteTail() << " from tail" << endl;
    cout << "New list" << endl;
    ll.printList();
}