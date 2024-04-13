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

One problem with all the hash functions is that they lead to **collisions**. A collision is hte result of two or more keys hashing to the same value (location). Note how SONEJ is the same hash value as JONES.

How do we handle collisions?

## Collision resolution
Need some sort of **collision resolution strategy** to handle collisions when they occur. There are two common strategies.

- Linear resolution
- Open hashing

### Linear Resolution
The simplest strategy is linear resolution:

If *h(x)*, for some key *x*, points to a location that is laready occupied, inspect the next location in the array. If that location is full, try the one after that, and so on, until we find a vacant location or find that the array **(hash table)** is completely full.

**Example:**
The hash function given by `h(x) = x % 7`. The table has seven locations. Insert the integers (keys) 23, 14, 8, 6, 30, 12, and 18 into the table, *T* (recall that its indeces are 0...7)

1. h(23) = 23, so key 23 would be stored in T[2]
2. h(14) = 0, so key 14 would be stored in T[0]
3. h(9) = 2, but T[2] is already populated, so key 9 would be stored in T[3]
4. h(6) = 6, so key 6 would be stored in T[6]
5. h(30) = 2, but T[2] and T[3] are already populated, so it would go in T[4]
6. h(12) = 5, so key 12 would be stored in T[5]
7. h(18) = 4, but T[4], T[5], and T[6] are full, so it would go into T[0] (wrap-around)

It took 14 probes to fill this hash table. It's likely that most of the elements will be clustered together.

### Open hashing
Another way to resolve the collision / clustering problem is to use **Open Hashing** (also referred to as *chaining*). We ignore the collision and simply place the value in a *bucket* (which is what table cells are usually called), along with the values that are already there. This technique is usually accomplished by using a linked list for every bucket, accessed by pointers in the hash table.

**Example:**
The hash function given by `h(x) = x % 7`. The table has seven locations. Insert the integers (keys) 23, 14, 8, 6, 30, 12, and 18 into the table, *T* (recall that its indeces are 0...7)
1. h(23) = 2, so key 23 would be stored in T[2]
2. h(14) = 0, so key 14 would be stored in T[0]
3. h(9) = 2, so key 9 would be stored in T[2][1]
4. h(6) = 6, so key 6 would be stored in T[6]
5. h(30) = 2, so key 30 would be stored in T[2][2]
6. h(12) = 5, so key 12 would be stored in T[5]
7. h(18) = 4, so key 18 would be stored in T[4]

**Example code is given in `hash.h` and `hash.cpp`**