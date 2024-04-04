# Traversals
Programs that use trees often need to process all of the nodes in a tree. This process is called a *tree traversal* (it is sometimes called *walking the tree*).

For a binary tree, there are three common ways:
- Pre-order
  - Process nodes in root, then left (recursive), then right (recursive)
- In-order
  - Process nodes in left (recursive), then root, then right (recursive)
- Post-order
  - Process nodes in left (recursive), then right (recursive), then root

**NOTE**: Tree traversals *will be* on a future quiz and test

## Typical traversal methods
- Loops for arrays and lists
- Recursion for trees
- Recursion can also be used for traversing lists (and arrays)
- Loops can also be used for traversing trees

## Examples
The tree that will be used to illustrate the tree traversal methods is shown below:

      1
     / \
    2   3

Pre-order:
- 1, 2, 3

In-order:
- 2, 1 ,3

Post-order:
- 2, 3, 1

The tree that will be used to illustrate the tree traversal methods is shown below:

            5
           / \
          17  11
         / \    \
        9   41   8
       / \
     NULL 13

Pre-order:
- 5, 17, 9, 13, 41, 11, 8

In-order:
- 9, 13, 17, 41, 5, 11, 8

Post-order:
- 13, 9, 41, 17, 8, 11, 5