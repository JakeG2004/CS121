#include <iostream>
#include "BST.cpp"

using namespace std;

int main()
{
    BST tree = BST();

    tree.insertNode(1);
    tree.insertNode(0);
    tree.insertNode(10);

    tree.printInOrder();

    tree.deleteTree();
}