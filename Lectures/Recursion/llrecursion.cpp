#include <iostream>

using namespace std;

struct node{
    int data;
    node* next;
};
typedef node* nodePtr;

void print(nodePtr h);
void printReverse(nodePtr h);
void addNodeRecurse(nodePtr &h, int x);
void deleteLastNode(nodePtr &);

int sumN(int n);

int main()
{
    nodePtr head = NULL;

    addNodeRecurse(head, 1);
    addNodeRecurse(head, 2);
    addNodeRecurse(head, 3);

    cout << "Forward: " << endl;
    print(head);

    cout << "\nReverse: " << endl;;
    printReverse(head);

    cout << "\ndeleting last node" << endl;
    deleteLastNode(head);

    cout << "\nReverse: " << endl;
    printReverse(head);

    cout << "Summation using recursion: " << endl;
    cout << sumN(4) << endl;
}

void print(nodePtr h)
{
    if(h != NULL)
    {
        cout << h -> data << endl;
        print(h -> next);
    }
}

void printReverse(nodePtr h)
{
    if(h != NULL)
    {
        printReverse(h -> next);
        cout << h -> data << endl;
    }
}

void addNodeRecurse(nodePtr &h, int x)
{
    //general case
    if(h != NULL)
        addNodeRecurse(h -> next, x);

    //base case
    else
    {
        nodePtr n;

        n = new node;
        n -> data = x;
        n -> next = NULL;

        h = n;
    }
}

void deleteLastNode(nodePtr &h)
{
    //handle empty list
    if(h != NULL)
    {
        //general case
        if(h -> next != NULL)
            deleteLastNode(h -> next);

        //base case
        else
        {
            //duplicate h
            nodePtr p = h;

            //break link on whatever h is pointing to
            p -> next = NULL;

            //break previous link
            h = NULL;

            //delete the node
            delete p;
        }
    }
}

int sumN(int n)
{
    int sum;

    if(n == 1)
        sum = n;

    else
        sum = n + sumN(n - 1);

    return sum;
}