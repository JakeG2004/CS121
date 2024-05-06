# Recursion
Recursion is the process of calling a function within itself to solve a problem.

## Why use recursion?
Useful for simplifying code. Can do anything that a while loop can.

## Example Code: Insertion to the end of the linked list

    Recursion method:
    void InsertLLR(nodePtr p, int x)
    {
        if(p -> next == NULL)
        {
            nodePtr n = new Node();
            n -> next = NULL;
            n -> data = x;

            p -> next = n;

            return;
        }

        InsertLLR(p -> next, x);
    }

    Non-Recursive method:
    void InsertLL(nodePtr p, int x)
    {
        while(p -> next != NULL)
        {
            p = p -> next;
        }

        nodePtr n = new Node();
        n -> next = NULL;
        n -> data = x;

        p -> next = n;
    }