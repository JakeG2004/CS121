#include <iostream>

using namespace std;

/*
BSTree
To left if <
To right if >=
*/

struct BSTreeNode
{
    int data;
    BSTreeNode* left;
    BSTreeNode* right;
};

typedef BSTreeNode* BSTreeNodePtr;

void insertNode(BSTreeNodePtr&, int);
void printInOrder(BSTreeNodePtr);

int main()
{
    BSTreeNodePtr head = NULL;

    insertNode(head, 5);
    insertNode(head, 6);
    insertNode(head, 3);
    insertNode(head, 30);
    insertNode(head, -20);

    printInOrder(head);
}

void insertNode(BSTreeNodePtr& n, int x)
{

    //handle empty tree
    if(n == NULL)
    {
        BSTreeNodePtr newNode = new BSTreeNode;
        newNode -> data = x;
        newNode -> left = NULL;
        newNode -> right = NULL;

        n = newNode;
        return;
    }

    //handle data < n
    if(x < n -> data)
    {
        insertNode(n -> left, x);
    }

    //handle data >= n
    if(x >= n -> data)
    {
        insertNode(n -> right, x);
    }
}

void printInOrder(BSTreeNodePtr n)
{
    if(n != NULL)
    {
        printInOrder(n -> left);
        cout << n -> data << endl;
        printInOrder(n -> right);
    }
}