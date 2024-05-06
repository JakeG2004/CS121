# Heaps
A heap is a special kind of ***complete binary tree***.

Reminder: A complete binary tree is one that is of height *h*, is full to level *h* - 1, and has level *h* filled from left to right. *h* does not need to be full.

Each node in a heap contains a key, and these keys are organized in a particular manner. Notice that this is *not* a binary search tree, but the keys have some semblance of order.

This is a useful property because the largest (or smallest) node is always at the top. Because of this, a heap can easily implement a priority queue.

The operations for both insertion and deletion are $O(log(N))$

## Heap Storage Rules (*Max*-Heap)
- The entry contained by a node is greater than or equal to the entries of the node's children.
- The tree is a complete tree

## Heap Storage Rules (*Min*-Heap)
- The entry contained by a node is less than or equal to the entries of the node's children
- The tree is a complete tree.

## Heap Implementation
Since a heap is a complete binary tree, and a complete binary tree is more easily implemented using an array than with pointers, if the max size of a heap is known in advance, then an array implementation can use a fixed-size array.

If there are *n* nodes, only the first *n* positions of an array, A, are used.

Useful parent-child node relationships:
- The left child of a node is 2*i* + 1
- The right child of a node is 2*i* + 2
- The parent of a node is (*i* - 1) / 2

where *i* is the index of the node in the array. This means that each layer is written into the array together, left to right.

Adding and removing entries from a heap often requires *reheapification*.

Reheapification is the process of re-arranging the tree so that it adheres to the rules defined above.

## Pseudocode for Adding an entry
- Place the new entry in the heap in the first available location
- While the new entry's priority > its parent, swap the new entry with its parent.

## Pseudocode for Deleting the top entry
- Move the last node of the tree into the root.
- Move the out-of-place node downward, swapping with its *larger* child until the new node reaches an acceptable location.