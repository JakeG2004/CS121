/*
BSTree.cpp
Binary Search Tree Implementation with Deletion
*/

using namespace std;

#include <iostream>

#include "BSTree.h"

//#define DEBUG_DELETE //uncomment for extra debugging

//~BinarySearchTree() -- Delete BST object
BinarySearchTree::~BinarySearchTree()
{
    DeleteBST(rootPtr);
}

//IsLeaf() -- Test if a node is a leaf
bool BinarySearchTree::isLeaf(BSTreePtr treePtr)
{
    return((treePtr -> leftPtr == NULL) && (treePtr -> rightPtr == NULL));
}

//AddNode()
//  Insert new item into BST, whose root node is pointed to by rootPtr
//  If the data already exists, it is ignored

void BinarySearchTree::AddNode(DATA_TYPE newData)
{
    BSTreePtr newPtr;

    //make and define new node
    newPtr = new BSTreeNode;
    newPtr -> data = newData;
    newPtr -> leftPtr = NULL;
    newPtr -> rightPtr = NULL;

    //if BST is empty, insert in root
    if(rootPtr = NULL)
    {
        rootPtr = newPtr;
        return;
    }

    //otherwise, look for insertion location
    BSTreePtr treePtr = rootPtr;
    BSTreePtr targetNodePtr;

    while(treePtr != NULL)
    {
        targetNodePtr = treePtr;
        if(newData == treePtr -> data)
            // found same data; ignore it
            return;
        else if(newData < treePtr -> data)
            // search left subtree for insertion location
            treePtr = treePtr -> leftPtr;
        else // newData > treePtr -> data
            // search right subtree for insertion location
            treePtr = treePtr -> rightPtr;
        // targetNodePtr is the pointer to the
        // parent of the new node. Decide where
        // it will ne inserted
        if(newData < targetNodePtr -> data)
            targetNodePtr -> leftPtr = newPtr;
        else // insert it as its right child
            targetNodePtr -> rightPtr = newPtr;
    }
}

//DeleteBST()
// delete an entire BST. All memory is released
// using a PostOrder traversal method
void BinarySearchTree::DeleteBST(BSTreePtr& treePtr)
{
    if(treePtr != NULL)
    {
        DeleteBST(treePtr -> leftPtr);
        DeleteBST(treePtr -> rightPtr);

        delete treePtr;
        treePtr = NULL;
    }
}

void BinarySearchTree::SearchNode(DATA_TYPE query)
{
    BSTreePtr srchPtr = NULL;

    srchPtr = SearchNodeInBST(rootPtr, query);
    if(srchPtr != NULL)
    {
        cout << "\n NODE: " <<srchPtr -> data << " found in the BST" << endl;
    }
    else
    {
        cout << "\n Node: " << query << " not found" << endl;
    }
}

//SearchNodeInBST()
// Find a given node by "key" in BST. If successful, it
// returns the pointer that points to the node with "key";
// otherwise, it returns NULL. It uses preorder traversal

BinarySearchTree::BSTreePtr
BinarySearchTree::SearchNodeInBST(BSTreePtr treePtr, DATA_TYPE key)
{
    if(treePtr != NULL)
    {
        if(key == treePtr -> data)
            return treePtr;
        else if(key < treePtr -> data)
            //search for key in left subtree
            SearchNodeInBST(treePtr -> leftPtr, key);
        else // key > treePtr -> data
            //search for key in right subtree
            SearchNodeInBST(treePtr -> rightPtr, key);
    }
    else
        return NULL;
}

//PrintTree()
//  Print a BSTree using InOrder traversal by default
void BinarySearchTree::PrintTree()
{
    PrintBST_InOrder(rootPtr);
}

void BinarySearchTree::PrintInOrder()
{
    PrintBST_InOrder(rootPtr);
}

void BinarySearchTree::PrintPostOrder()
{
    PrintBST_PostOrder(rootPtr);
}

void BinarySearchTree::PrintPreOrder()
{
    PrintBST_PreOrder(rootPtr);
}

void BinarySearchTree::PrintBST_InOrder(BSTreePtr treePtr)
{
    if(treePtr != NULL)
    {
        // print left of BSTree
        PrintBST_InOrder(treePtr -> leftPtr);
        // print root node data
        cout << treePtr -> data << endl;
        // print right subtree
        PrintBST_InOrder(treePtr -> rightPtr);
    }
}

void BinarySearchTree::PrintBST_PreOrder(BSTreePtr treePtr)
{
    if(treePtr != NULL)
    {
        // print root node data
        cout << treePtr -> data << endl;
        // print left of BSTree
        PrintBST_PreOrder(treePtr -> leftPtr);
        // print right subtree
        PrintBST_PreOrder(treePtr -> rightPtr);
    }
}

void BinarySearchTree::PrintBST_PostOrder(BSTreePtr treePtr)
{
    if(treePtr != NULL)
    {
        // print left of BSTree
        PrintBST_PostOrder(treePtr -> leftPtr);
        // print right subtree
        PrintBST_PostOrder(treePtr -> rightPtr);
        // print root node data
        cout << treePtr -> data << endl;
    }
}

// Print BST using InOrder traversal
void BinarySearchTree::PrintBackwardInOrder()
{
    PrintBST_BackwardInOrder(rootPtr, 0);
}

void BinarySearchTree::PrintBST_BackwardInOrder(BSTreePtr treePtr, int depth)
{
    const int INDENT = 4;

    if(treePtr != NULL)
    {
        //print right BST subtree
        PrintBST_BackwardInOrder(treePtr -> rightPtr, depth + 1);
        //print data in root node
        //cout << setw(INDENT * depth) << " ";
        for(int i = 0; i < INDENT * depth; i++) 
        {
            cout << " ";
        }

        cout << treePtr -> data << endl;

        //print left subtree of bst
        PrintBST_BackwardInOrder(treePtr -> leftPtr, depth + 1);
    }
}