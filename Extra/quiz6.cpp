#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next = NULL;
};

typedef Node* nodePtr;

void insertNode(nodePtr&, int);
void printList(nodePtr);
int lastVal(nodePtr&);

int* copyNElements(nodePtr, int);

int main()
{
    nodePtr head = NULL;
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 3);

    printList(head);

    cout << lastVal(head) << endl;

    copyNElements(head, 2);
}

int lastVal(nodePtr &head)
{
    int returnVal;
    nodePtr p = head;
    nodePtr nextNode = p -> next;

    while(nextNode -> next != NULL)
    {
        p = nextNode;
        nextNode = p -> next;
    }

    returnVal = nextNode -> data;
    delete nextNode;
    p -> next = NULL;
    return returnVal;
}

void insertNode(nodePtr &n, int x)
{
    nodePtr p = new Node();

    p -> data = x;
    p -> next = n;
    n = p;
}

void printList(nodePtr n)
{
    while(n != NULL)
    {
        cout << n -> data << endl;
        n = n -> next;
    }
}

int* copyNElements(nodePtr p, int num)
{
    if(p == NULL)
    {
        cout << "Empty list" << endl;
        exit(-1);
    }

    int* arr = (int*)(malloc(sizeof(int) * num));

    for(int i = 0; i < num; i++)
    {
        arr[i] = p -> data;
        if(p -> next == NULL && i + 1 < num)
        {
            delete arr;
            cout << "Not enough elements" << endl;
            exit(-1);
        }

        p = p -> next;
    }

    return arr;
}