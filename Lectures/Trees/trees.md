# Trees
- Root node on top, branches expand downward from there
- Examples
  - Objects in Java
  - Evaluation of mathematical expressions

## Terminology
- Root
  - Base of the tree; on top.
- Leaf
  - A node with no children
- Parent
  - Node linked above another node
- Sibling
  - Two nodes with the same parent
- Ancestor
  - 2 nodes that are related
- Subtree
  - A smaller tree
- Left / right subtree
  - subtree to left or right
- Height
  - Maximum depth of any leaf

## Binary trees
- A finite set of nodes. the set might be empty. If the set is not empty, it follows these rules:
  - There is one special node - the root
  - Each node may be associated with up to two other different nodes, called its left child and its right child. If a node c is the child of another node p, then p is c's parent
  - If you start at a node and move to the node's parent (if there is one), then move again to that node's parent, and keep moving upward to each node's parent, you will eventually reach the root.
- **Full binary tree**: A binary tree of height h with no missing nodes. All leaves have the same depth and every non-leaf has two chidren.
- **Complete binary tree**: A binary tree of height h that is full to level h - 1 and has level h filled in from left to right
- **Incomplete tree**: Any tree that is not complete or full
- **Definition**: Either an empty tree of it has a root and the remaining nodes are divided into two disjoint sets named the left subtree and the right subtree.

## Tree operations
- Print a tree (traversal)
- Create a node
- Delete a node
- Test if a node is a leaf
- Search a tree
- Copy a tree