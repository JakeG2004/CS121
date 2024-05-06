#include <iostream>
#include "BST.h"

void BST::deleteTree()
{
    deleteTree(head);
    delete head;
    head = NULL;
}

void BST::deleteTree(BSTreeNodePtr &n)
{
    if(n != NULL)
    {
        deleteTree(n -> right);
        deleteTree(n -> left);

        delete(n);
        n = NULL;
    }
}

bool BST::isLeaf(BSTreeNodePtr n)
{
    if(n -> left == NULL && n -> right == NULL)
        return true;
    
    return false;
}

void BST::insertNode(int x)
{
    insertNode(x, head);
}

void BST::insertNode(int x, BSTreeNodePtr &n)
{
    if(n == NULL)
    {
        BSTreeNodePtr p = new BSTreeNode();
        p -> left = NULL;
        p -> right = NULL;
        p -> data = x;

        n = p;
        return;
    }

    if(x <= n -> data)
        insertNode(x, n -> left);

    if(x > n -> data)
        insertNode(x, n -> right);
}

void BST::printInOrder()
{
    printInOrder(head);
}

void BST::printInOrder(BSTreeNodePtr n)
{
    if(n != NULL)
    {
        printInOrder(n -> left);
        cout << n -> data << endl;
        printInOrder(n -> right);
    }
}