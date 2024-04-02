# Deleting Node in BST
Deletion of nodes is more complicated than the insertion of nodes in Binary Search Trees.

Why?

## Simple algorithm
A simple approach to deletion may be described as follows:
    
    if the item is in the tree, remove it.

Unfortunately, things are not that simple. There are 3 things to consider

    - N is a leaf
    - N has only one child
    - N has two children

### Case 1: Leaf node
This case is easy. To remove a leaf, set the pointer from its parent to NULL, and delete the dynamically allocated memory.

### Case 2: 1 child
This case is a bit more difficult as there are two possibilities, a left child and a right child. It can be shown that all we need to do is set the child to N's parent.

### Case 3: 2 children
The last case is the most difficult. Since there are two children, N's parent cannot take them both.

    1. One strategy is to find another node M that is eaiser to remove from the tree than N.
    2. Copy the info that is in M to N (deleting original N)
    3. Remove M from the tree

Note that M can't be just any node - the binary search tree properties must be preserved.

**PSEUDOCODE**

    DeleteItem(TreePtr, key)
        if(key is in node N)
            DeleteNodeItem(N)
        else
            do nothing / error message

    DeleteNodeItem(TreePtr N)
        if(N is a leaf)
            remove N from the tree
        else if(N has only one child (C))
            if(N is the left child if its parent P)
                make C the left child of P
            else
                make C the left child of P
        else //N has two children
            find M, the node that is N's inorder successor
            copy info from M into N
            remove M from the tree**REAL CODE**
    void deleteNode(Tree)