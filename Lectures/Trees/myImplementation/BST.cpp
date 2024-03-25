#include <iostream>

using namespace std;

struct TreeNode
{
    TreeNode* left = NULL;
    TreeNode* right = NULL;
    int data = 0;
};

typedef TreeNode* TreeNodePtr;

/*
* Binary search tree
* To the left if < x
* To the right >= x
*/

//prototypes
TreeNodePtr createNode(int);
void insertNode(TreeNodePtr&, TreeNodePtr);
void printInOrder(TreeNodePtr);
void printReversed(TreeNodePtr);

void freeTree(TreeNodePtr&);

int main()
{
    TreeNodePtr head = NULL;

    int values[] = {3, 45, 9, 17, 20, 53, 53, 54, 3};
    int nA = sizeof(values) / sizeof(int);
    
    for(int i = 0; i < nA; i++)
    {
        insertNode(head, createNode(values[i]));
    }

    printInOrder(head);
    freeTree(head);
}

TreeNodePtr createNode(int x)
{
    TreeNodePtr node = new TreeNode;

    node -> left = NULL;
    node -> right = NULL;
    node -> data = x;

    return node;
}

void insertNode(TreeNodePtr &head, TreeNodePtr newNode)
{
    //check empty tree
    if(head == NULL)
    {
        head = newNode;
        return;
    }
    
    //handle left placement
    if(newNode -> data < head -> data)
    {
        if(head -> left == NULL)
        {
            head -> left = newNode;
            return;
        }

        insertNode(head -> left, newNode);
    }

    //handle right placement
    else
    {
        if(head -> right == NULL)
        {
            head -> right = newNode;
            return;
        }

        insertNode(head -> right, newNode);
    }
}

void printInOrder(TreeNodePtr head)
{
    if(head != NULL)
    {
        printInOrder(head -> left);
        cout << head -> data << endl;
        printInOrder(head -> right);
    }
}

void printReversed(TreeNodePtr head)
{
    if(head != NULL)
    {
        printReversed(head -> right);
        cout << head -> data << endl;
        printReversed(head -> left);
    }
}

void freeTree(TreeNodePtr &head)
{
    if(head != NULL)
    {
        freeTree(head -> right);
        freeTree(head -> left);

        delete(head);
        head = NULL;
    }
}