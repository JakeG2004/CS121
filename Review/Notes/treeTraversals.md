# Tree traversals
Many kinds; but the most common are:
- In - order traversal
- Post - order traversal
- Pre - order traversal

## In - order traversal:
With an in order traversal, the left node is visited, the current node's value is printed, then the right node is visited.

Notably, this will print the values in the tree from least to greatest.

    void printInOrder(TreeNode p)
    {
        if(p != NULL)
        {
            printInOrder(p -> left);
            cout << p -> data << endl;
            printInOrder(p -> right);
        }
    }

With the following tree:

            5
        /       \
        3       7
      /  \     /  \
      1  NULL 6    10

The output would be `1 3 5 6 7 10`

## Post - order traversal:
With a post order traversal, the left node is visited, the right node is visisted, then the current node is printed.

Notably, the root value is printed last in this tree.

    void printPostOrder(TreeNode p)
    {
        if(p != NULL)
        {
            printPostOrder(p -> left);
            printPostOrder(p -> right);
            cout << p -> data << endl;
        }
    }

With the following tree:

            5
        /       \
        3       7
      /  \     /  \
      1  NULL 6    10

The output would be `1 3 6 10 7 5`

## Pre - order traversal
With a pre order traversal, the current node is printed, the left node is visited, then the right node is visisted.

Notably, the root value is printed first in this tree.

    void printPreOrder(TreeNode p)
    {
        if(p != NULL)
        {
            cout << p -> data << endl;
            printPreOrder(p -> left);
            printPreOrder(p -> right);
        }
    }

With the following tree:

            5
        /       \
        3       7
      /  \     /  \
      1  NULL 6    10

The output would be `5 3 1 7 6 10`