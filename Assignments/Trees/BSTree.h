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

        BSTreeNodePtr head;

    public:
        //constructor
        BSTree()
        {
            head = NULL;
        }

        //prototypes with overloads
        void insertNode(BSTreeNodePtr&, Show);
        void insertNode(Show);

        void printShows(BSTreeNodePtr);
        void printShows();

        void printActorsInShow(BSTreeNodePtr, string);
        void printActorsInShow(string);

        void printShowsWithActor(BSTreeNodePtr, string);
        void printShowsWithActor(string);

        void printShowsReleasedBetween(BSTreeNodePtr, int, int);
        void printShowsReleasedBetween(int, int);

        void deleteTree(BSTreeNodePtr);
        void deleteTree();

        bool isInTree(BSTreeNodePtr, string);
        bool isInTree(string);
};

#endif