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