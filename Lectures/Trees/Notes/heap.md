# HEAP
A special type of complete binary tree

## Head storage rules (Max-heap)
1. The entry contained by a node is greater than or equal to the entries of the node's children
2. The tree is a complete tree, so that every level except the deepest must contain as many nodes as possible. At the deepest level, all the nodes are as far left as possible.

## Heap implementation
Since a heap is a complete binary tree, and a complete binary tree is more easily implemented using an array than with pointers. If the maximum size of a heap is known in advance, then an array implementation can use a fixed-size array.

If there are *n* nodes, only the first *n* positions of an array, *A*, are used.

Useful parent-child node relationships:
- The left child of a node is 2*i* + 1
- The right child of a node is 2*i* + 2
- The parent of a node is (*i* - 1) / 2

Where *i* is the index of the node in the array

## Reheapification
Adding and removing entries from a heap often requires the heap to be *reheapified*.

**PSEUDOCODE FOR ADDING AN ENTRY**
1. Place the new entry in the heap in the first available location

    *This keeps the structure as a complete binary tree, but it might no longer be a heap since the new entry might have a higher priority than its parent.*
2. *while* (the new entry's priority is higher than its parent), swap the new entry with its parent.