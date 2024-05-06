# Data structures
A data structures is a digital structure in which data is stored.

Some examples are Linked Lists, Queues, Stacks, and Trees.

## Linked Lists
2 Types: Singly linked list and doubly linked list.


### Singly linked list: 

    1 -> 2 -> 3 -> 4 -> NULL

A series of nodes defined as

    struct Node
    {
        int data;
        Node* next;
    }

Where the `next` field is used to point to the following node.

### Doubly linked list:

    1 <-> 2 <-> 3 <-> 4-> NULL

A series of nodes defined as

    struct Node
    {
        int data;
        Node* previous;
        Node* next;
    }

Where the `next` field points to the following node, and the `previous` field points to the parent node.

