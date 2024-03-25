/*
TestBSTree.cpp
Test binary Search Tree (BST)
*/

#include <iostream>
#include "BSTree.h"

int main()
{
    // init arrays
    static DATA_TYPE A[] = {15, 53, 13, 61, 57, 47, 21, 51};
    static int nA = sizeof(A) / sizeof(DATA_TYPE);

    static DATA_TYPE B[] = {48, 54, 14, 52, 8, 16, 63, 10, 1};
    static int nB = sizeof(B) / sizeof(DATA_TYPE);

    // build trees
    BinarySearchTree t1;
    BinarySearchTree t2;

    for(int i = 0; i < nA; i++)
        t1.AddNode(A[i]);

    for(int i = 0; i < nB; i++)
        t2.AddNode(B[i]);

    // test display methods
    cout << "\n The Binary Search Tree Using ";
    cout << "a Backward InOrder traversal:" << endl;
    t1.PrintBackwardInOrder();

    cout << "\n The BST using: ";
    cout << "an InOrder traversal:" << endl;
    t1.PrintInOrder();

    cout << "\n The BST using ";
    cout << "a PreOrder traversal:" << endl;
    t1.PrintPreOrder();

    cout << "\n The BST using ";
    cout << "a PostOrder traversal:" << endl;
    t1.PrintPostOrder();

    // test deletion
    cout << "\n\n Deleting entire tree" << endl;
    cout <<"        (Tree should be empty)" << endl;
    t1.~BinarySearchTree();
    t1.PrintInOrder();

    // display second tree
    cout << "\n the BST using";
    cout << "a backward inOrder traversal:" << endl;
    t2.PrintBackwardInOrder();

    t2.SearchNode(45);
    t2.SearchNode(48);

    return EXIT_SUCCESS;
}