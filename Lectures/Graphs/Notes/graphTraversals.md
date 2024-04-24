# Graph Traversals
## Graphs in Problem Solving
Often, a problem can be represented as a graph. The solution to the problem is obtained by solving the problem on the graph.

### Example: Undirected state graph
A simple game using three coins. At the start of the game, the middle coin is "tails", and the other two are "heads".

    (H) (T) (H)

The goal of the game is to change the configuration of the coins so that the middle coin is heads and the other two are tails, like this:

    (T) (H) (T)

#### Rules of the game:
1. You may flip the middle coin (from heads to tails, or vice versa) whenever you want.
2. You may flip one of the end coins, as long as the other two are the same.

#### Solution (as represented by a graph)

        HTH
         |
        HHH
       /   \
    THH     HHT
     |       |
    TTH     HTT
       \   /
        TTT
         |
        THT

## Graph Traversals
Graph vertices don't have children like tree nodes, so typical tree traversal algorithms are not generally appllicable to graphs.

There are two common ways to traverse graphs:
1. **Breadth-First Search** uses a queue to keep track of vertices that still need to be visited.
2. **Depth-First Search** uses a stack to keep track of vertices. It can also be implemented recursively so that it does not explicitely use a stack of vertices. (I made one of these for the Candyland assignment in 120!)

Traversal algorithms must be careful tha they don't enter a repetitive cycle. It is necessary to *mark* each vertex as it is processed.

The progress of a traversal after the start vertex depends on the traversal method that is used.