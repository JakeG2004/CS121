# HASH TABLES
Searching for an element in a tree can be very fast, but slows down as number of items increases (at best, O(log n)).

**Why?**
- Tree imbalance
- No direct access

**What about using an array?**
- Direct access
- Not working with just numbers

Need / want some sort of conversation scheme to use an array.

## HASHING
A **Hash Function** transforms keys into an array index.

One possible implementation is to sum the ASCII values of each char in a string and *mod* it by the table size. For example, an array with 120 elements and the string JONES:
- J - 74
- O - 79
- N - 78
- E - 69
- s - 83

74 + 79 + 78 + 69 + 83 = 383

383 % 120 = 23.

One problem with all the hash functions is that they lead to **collisions**. A collision is hte result of two or more keys hashing to the same value (location).

How do we handle collisions?