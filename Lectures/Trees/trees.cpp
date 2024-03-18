#include <iostream>

using namespace std;

struct binaryTreeNode
{
    int data;
    binaryTreeNode* left;
    binaryTreeNode* right;
};

typedef binaryTreeNode* BinaryTreeNodePtr;

int main()
{
    BinaryTreeNodePtr head;
    head = NULL;
}

BinaryTreeNodePtr CreateNode(int newVal)
{
    BinaryTreeNodePtr newNode = new binaryTreeNode;

    newNode -> data = newVal;
    newNode -> left = NULL;
    newNode -> right = NULL;

    return newNode;
}

bool isLeaf(BinaryTreeNodePtr node)
{
    if(node -> left == NULL && node -> right == NULL)
        return false;
        
    return true;
}

int treeSize(BinaryTreeNodePtr node)
{
    if(node == NULL)
        return 0;
    else
        return 1 + treeSize(node -> left) + treeSize(node -> right);
}