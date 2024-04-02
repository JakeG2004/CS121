# Binary Search Trees
Binary search trees are a special kind of binary tree. They are organized using the following rules:
- Every entry in the *n*'s left subtree is less than or equal to the entry in node *n*.
- Every entry in *n*'s right subtree is greated than (or equal to) the entry in node *n*.

Example binary search tree:

        45
       /  \
      9   53
     / \   /\
    3  17 53 54
      /  \
     NULL 20

Printing this In-Order yields:
- 3, 9, 17, 20, 45, 53, 53, 54

**NOTE** This is a sorted list!

**What is the benefit of this organization?**

Contents are *sorted* when processing using an *in-order* traversal.