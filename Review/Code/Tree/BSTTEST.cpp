#include <iostream>
#include "BST.cpp"

using namespace std;

int main()
{
    BST tree = BST();

    for(int i = 2; i <= 8; i++)
    {
        tree.insertNode(i * 10);
    }

    tree.printInOrder();

    tree.deleteNode(20);

    tree.deleteTree();
}