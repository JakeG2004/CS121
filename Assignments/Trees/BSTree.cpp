/*
BSTree.cpp
Implementation of a BSTree for assignment 5 using a Show struct
Jake Gendreau
April 12, 2024
*/

#include <iostream>
#include "BSTree.h"

using namespace std;

void BSTree::insertNode(BSTreeNodePtr &n, Show show)
{
    //check empty tree
    if(n == NULL)
    {
        BSTreeNodePtr newNode = new BSTreeNode();

        //error check
        if(newNode == NULL)
        {
            cout << "FAILED TO ALLOC NEW NODE IN insertNode(). EXITING PROGRAM..." << endl;
            exit(-1);
        }

        //set data members of newNode
        newNode -> data = show;
        newNode -> left = NULL;
        newNode -> right = NULL;

        //assign it to list
        n = newNode;

        return;
    }

    //handle less than case
    if(show.name < n -> data.name)
    {
        insertNode(n -> left, show);
    }

    //handle greater than or equal to case
    if(show.name >= n -> data.name)
    {
        insertNode(n -> right, show);
    }
}

void BSTree::printShows(BSTreeNodePtr n)
{
    //print names in order
    if(n != NULL)
    {
        printShows(n -> left);
        cout << n -> data.name << endl;
        printShows(n -> right);
    }
}

void BSTree::printActorsInShow(BSTreeNodePtr n, string showName)
{
    if(n == NULL)
    {
        return;
    }

    //if show found
    if(n -> data.name == showName)
    {
        NodePtr p = n -> data.actorHead;

        //print out the actors in the show
        while(p != NULL)
        {
            cout << "\t" << p -> data << endl;
            p = p -> next;
        }
    }

    //if showname < current show
    if(showName < n -> data.name)
    {
        printActorsInShow(n -> left, showName);
    }

    //handle showName >= current show
    if(showName >= n -> data.name)
    {
        printActorsInShow(n -> right, showName);
    }
}

void BSTree::printShowsWithActor(BSTreeNodePtr n, string actorName)
{
    //error check
    if(n == NULL)
    {
        cout << "ERROR: printShowsWithActor() ON EMPTY TREE. EXITING PROGRAM..." << endl;
        exit(-1);
    }
    
    //traverse through the linked list
    NodePtr p = n -> data.actorHead;

    while(p != NULL)
    {
        //if actor is found, print the name of the show
        if(p -> data == actorName)
        {
            cout << "\t" << n -> data.name << endl;
        }

        p = p -> next;
    }

    //go to child nodes
    if(n -> left != NULL)
        printShowsWithActor(n -> left, actorName);

    if(n -> right != NULL)
        printShowsWithActor(n -> right, actorName);
}

void BSTree::printShowsReleasedBetween(BSTreeNodePtr n, int start, int end)
{
    //error check
    if(n == NULL)
    {
        cout << "ERROR: printShowsReleasedBetween() ON EMPTY TREE. EXITING PROGRAM..." << endl;
        exit(-1);
    }

    //handle success case
    if(n -> data.startDate >= start && n -> data.startDate <= end)
    {
        cout << "\t" << n -> data.name << endl;
    }

    //go to child nodes
    if(n -> left != NULL)
        printShowsReleasedBetween(n -> left, start, end);
    
    if(n -> right != NULL)
        printShowsReleasedBetween(n -> right, start, end);
}

void BSTree::deleteTree(BSTreeNodePtr n)
{
    //if NULL, return
    if(n == NULL)
        return;

    //delete children
    deleteTree(n -> left);
    deleteTree(n -> right);

    //delete current node
    delete n;
}