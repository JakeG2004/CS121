# Graph Traversals (DFS and BFS)
Graphs can be traversed with several methods, the two that we need to learn are BFS (Breadth First Search), and DFS (Depth First Search).

## BFS (Breadth First Search)
BFS uses a Queue data structure.

### BFS Process
- One node is selected and marked as visited
- Adjacent nodes are added to the queue

This is slower than DFS, but is guaranteed to find a solution

## DFS (Depth First Search)
DFS uses a Stack data structure.

### DFS Process
- One node is selected and marked as visited
- Adjacent nodes are added to the stack

Generally faster than BFS, but not guaranteed to find a solution.