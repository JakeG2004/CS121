#include <iostream>

using namespace std;

class BST
{
    private:
        struct BSTreeNode
        {
            int data;
            BSTreeNode* left;
            BSTreeNode* right;
        };

        typedef BSTreeNode* BSTreeNodePtr;

        BSTreeNodePtr head;

        void deleteTree(BSTreeNodePtr&);
        void insertNode(int, BSTreeNodePtr&);
        void printInOrder(BSTreeNodePtr);

    public:
        BST()
        {
            head = NULL;
        }

        ~BST()
        {
            deleteTree();
        }

        void deleteTree();

        bool isLeaf(BSTreeNodePtr);

        void insertNode(int);

        void printInOrder();

        void deleteNode(int);

        int getNumChildren(BSTreeNodePtr);
};