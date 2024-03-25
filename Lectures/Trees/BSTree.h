/*
BSTree.h

Binary search tree class interface w/ deletion
*/

using namespace std;
#include <iostream>

#ifndef _BSTREE_H_
#define _BSTREE_H_

typedef int DATA_TYPE;

class BinarySearchTree
{
    private:
        typedef struct BSTreeNode
        {
            DATA_TYPE data;
            BSTreeNode* leftPtr;
            BSTreeNode* rightPtr;
        } *BSTreePtr;

        BSTreePtr rootPtr;

        void InitBSTree()
            {rootPtr = NULL;}

        void DeleteBST(BSTreePtr& treePtr);

        void DeleteNode(BSTreePtr& treePtr, DATA_TYPE &theItem);
        
        void DeleteNodeItem(BSTreePtr &treePtr);

        void ProcessLeftMost(BSTreePtr &treePtr, DATA_TYPE &theItem);

        bool isLeaf(BSTreePtr treePtr);

        BSTreePtr SearchNodeInBST(BSTreePtr treePtr, DATA_TYPE searchKey);

        void PrintBST_InOrder(BSTreePtr treePtr);
        void PrintBST_PreOrder(BSTreePtr treePtr);
        void PrintBST_PostOrder(BSTreePtr treePtr);
        void PrintBST_BackwardInOrder(BSTreePtr treePtr, int depth);

    public:
        BinarySearchTree() {InitBSTree();}
        ~BinarySearchTree();

        bool IsEmpty()
            {return (rootPtr == NULL);}

        void AddNode(DATA_TYPE newData);
        void SearchNode(DATA_TYPE query);
        void DeleteNode(DATA_TYPE val);

        void PrintTree();

        void PrintInOrder();
        void PrintPreOrder();
        void PrintPostOrder();

        void PrintBackwardInOrder();
};

#endif