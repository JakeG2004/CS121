#include <iostream>

using namespace std;

//structure

struct binaryTreeNode
{
    int data;
    binaryTreeNode* left;
    binaryTreeNode* right;
};

typedef binaryTreeNode* BinaryTreeNodePtr;

//prototypes

BinaryTreeNodePtr CreateNode(int);

bool isLeaf(BinaryTreeNodePtr);

int treeSize(BinaryTreeNodePtr);

void printPreOrder(BinaryTreeNodePtr);
void printInOrder(BinaryTreeNodePtr);
void printPostOrder(BinaryTreeNodePtr);

int main()
{
    BinaryTreeNodePtr head;
    head = NULL;
}

//create a new node
BinaryTreeNodePtr CreateNode(int newVal)
{
    BinaryTreeNodePtr newNode = new binaryTreeNode;

    newNode -> data = newVal;
    newNode -> left = NULL;
    newNode -> right = NULL;

    return newNode;
}

//return true if node is a leaf, false otherwise
bool isLeaf(BinaryTreeNodePtr node)
{
    if(node -> left == NULL && node -> right == NULL)
        return true;
        
    return false;
}

//count number of nodes in tree
int treeSize(BinaryTreeNodePtr node)
{
    if(node == NULL)
        return 0;
    else
        return 1 + treeSize(node -> left) + treeSize(node -> right);
}

void printPreOrder(BinaryTreeNodePtr t)
{
    if(t != NULL)
    {
        cout << t -> data << endl;
        printPreOrder(t -> left);
        printPreOrder(t -> right);
    }
}

void printInOrder(BinaryTreeNodePtr t)
{
    if(t != NULL)
    {
        printPreOrder(t -> left);
        cout << t -> data << endl;
        printPreOrder(t -> right);
    }
}

void printPostOrder(BinaryTreeNodePtr t)
{
    if(t != NULL)
    {
        printPreOrder(t -> left);
        printPreOrder(t -> right);
        cout << t -> data << endl;
    }
}