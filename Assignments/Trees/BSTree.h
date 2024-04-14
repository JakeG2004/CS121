/*
BSTree.h
A header file for implementing a binary search tree using the "show" struct
Jake Gendreau
April 12, 2024
*/

#ifndef BST_H
#define BST_H

#include <iostream>

using namespace std;

struct node
{
    string data;
    node* next;
};

typedef node* NodePtr;

struct Show
{
    string name;
    string genre;
    string link;

    int startDate;
    int endDate;

    NodePtr actorHead;
};

class BSTree
{
    private:
        struct BSTreeNode
        {
            Show data;
            BSTreeNode* left;
            BSTreeNode* right;
        };
        typedef BSTreeNode* BSTreeNodePtr;

    public:
        BSTreeNodePtr head;

        //constructor
        BSTree()
        {
            head = NULL;
        }

        void insertNode(BSTreeNodePtr&, Show);
        void printShows(BSTreeNodePtr);
        void printActorsInShow(BSTreeNodePtr, string);
        void printShowsWithActor(BSTreeNodePtr, string);
        void printShowsReleasedBetween(BSTreeNodePtr, int, int);
        void deleteTree(BSTreeNodePtr);

        bool isInTree(BSTreeNodePtr, string);
};

#endif