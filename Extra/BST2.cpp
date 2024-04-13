#include <iostream>

using namespace std;

struct BSTreeNode
{
    int data;
    BSTreeNode* left;
    BSTreeNode* right;
};

typedef BSTreeNode* BSTreeNodePtr;

void insertNode(BSTreeNodePtr&, int);
void printInOrder(BSTreeNodePtr);

/*
left if < data
right if >= data
*/

int main()
{
    BSTreeNodePtr head = NULL;

    insertNode(head, 8);
    insertNode(head, 10);
    insertNode(head, 5);
    insertNode(head, 6);
    insertNode(head, -23);

    printInOrder(head);

}

void insertNode(BSTreeNodePtr &n, int data)
{
    //handle empty list
    if(n == NULL)
    {
        BSTreeNodePtr newNode = new BSTreeNode();
        newNode -> data = data;

        newNode -> left = NULL;
        newNode -> right = NULL;

        n = newNode;

        return;
    }

    //handle <
    if(data < n -> data)
    {
        insertNode(n -> left, data);
    }

    //handle >=
    if(data >= n -> data)
    {
        insertNode(n -> right, data);
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