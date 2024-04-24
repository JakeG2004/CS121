# Graphs
What are graphs useful for?
- Representation of connectivity (network (social), travel, problem solutions)
- Language definition
- Games (state / room connectivity)

## Terminology
A *graph* consists of a set *V*, called *vertices* (or nodes), and a set numer of pairs from *V* (*edges* or *arcs*).

Two types of graphs
- Directed
- Uniderected (also called *digraphs*)

In a directed graph, there is an order to the pairs.

## Example: The Seven Bridges of Koenigsberg
Original graph problem solved by Leonard Euler in 1735.

The city of Koenigsberg in Prussia (now Kaliningrad, Russia)
was set on both sides of the Pregel River, and included two large
islands which were connected to each other and the mainland
by seven bridges.

### The problem:
Determine if a person could walk through the city that would
cross each bridge once and only once. The islands could not be
reached by any route other than the bridges, and every bridge
must have been crossed completely every time (one could not
walk half way onto the bridge and then turn around and later
cross the other half from the other side).

Euler proved that the problem has **no** solution.

## More Terminology
*Adjacent*: Vertices are *adjacent* if in a pair.

*Path*: A sequence of edges that begin at one vertex and end at another vertex.

*Simple Path*: May not pass through the same vertex twice.

*Cycle*: Begins and ends at the same vertex and doesn't pass through the same vertex twice.

*Rooted Graph*: Has a unique node, the *root* such that there is a path from the root to all nodes within the graph.

*Free tree*: Connected, undirected graph with no cycles. Trees cannot have cycles.

## State Space Representation of Problems
The nodes of a graph correspond to partial problem solution *states* and the edges correspond to steps in a problem solving process. One or more *initial states*, corresponding to the given information in a problem instance, form the root of the graph. The graph also degines one or more *goal* conditions, which are solutions to the problem. *State space search* characterizes problem solving as the process of finding a *solution path* from the start state to a goal state.

Game trees and shortes path problems are two examples that are frequently solved using a state space representation.

## Adjacency Matrix
An **adjacency matrix** is a square grid of true / false values that represent the edges of a graph. If the graph contains *n* vertices, then the grid contains *n* rows and *n* columns. For the two vertex numbers *i* and *j*, the component at row *i* and column *j* is true if there is an edge from vertex *i* to vertex *j*; otherwise the component is false.

        A | B | C | D | E
    A   1   0   0   1   0
    B   0   1   1   0   0
    C   0   1   0   1   0
    D   1   0   1   1   0
    E   0   0   0   0   1

**NOTE: THIS MATRIX IS SYMMETRIC AKA IT IS = ITS TRANSPOSE**

## Edge lists
A directed graph with *n* vertices can be represented by *n* difference linked lists. List number *i* provides the connection for vertex *i*. Specifically, for each entry  *j* in list number *i*, there is an edge from *i* to *j*.

    Example for the matrix above:

    A -> A -> D
    B -> B -> C
    C -> B -> D
    D -> A -> C -> D
    E -> E

The lists could be linked together.

    A -> A -> D
    V
    B -> B -> C
    V
    C -> B -> D
    V
    D -> A -> C -> D
    V
    E -> E