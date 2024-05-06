# Binary Search Trees
A binary search tree is a special type of tree where the tree is arranged according to the following rules:

1. If a node to be inserted has a value <= the current node, it is placed on the left of the tree.
2. If a node to be inserted has a value > the current node, it is placed on the right of the tree.

Lookup, insertion, and deletion time of `log(N)`

## Examples:

            5
        /       \
        3       7
      /  \     /  \
      1  NULL 6    10

This is a valid binary search tree

            5
        /       \
        3       4
      /  \     /  \
      1  NULL 10    6

This is **NOT** a valid binary search tree