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

int BST::getNumChildren(BSTreeNodePtr n)
{
    int numChildren = 0;

    if(n -> left != NULL)
        numChildren++;

    if(n -> right != NULL)
        numChildren++;

    return numChildren;
}

void BST::deleteNode(int key)
{
    if(head == NULL)
    {
        cout << "deleting node on empty tree" << endl;
        exit(-1);
    }

    BSTreeNodePtr nodeToDelete = head;

    //find the node with the matching key
    while(nodeToDelete -> data != key)
    {
        if(key <= nodeToDelete -> data)
        {
            nodeToDelete = nodeToDelete -> left;
        }

        if(key > nodeToDelete -> data)
        {
            nodeToDelete = nodeToDelete -> right;
        }

        if(nodeToDelete == NULL)
        {
            cout << "Value not in tree" << endl;
            exit(-1);
        }
    }

    //handle leaf case
    if(getNumChildren(nodeToDelete) == 0)
    {
        delete nodeToDelete;
        nodeToDelete = NULL;
        cout << "Deleting leaf" << endl;
        return;
    }

    //handle 1 child
    else if(getNumChildren(nodeToDelete) == 1)
    {
        cout << "Deleting one child" << endl;
        BSTreeNodePtr p = nodeToDelete;
        if(nodeToDelete -> left != NULL)
        {
            nodeToDelete -> left = nodeToDelete -> left -> left;
            nodeToDelete -> right = nodeToDelete -> right -> right;
        }

        else if(nodeToDelete -> right != NULL)
        {
            nodeToDelete = nodeToDelete -> right;
        }

        delete p;
        return;
    }
}