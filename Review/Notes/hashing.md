# Hashing + Hash tables
Searching for elements in a tree can be very fast, but slows down as the number of items increases. Reminder of how [Big O](BigO.md) works.

## Why hash?
- Trees can become unbalanced, and require work to rebalance
- No direct access to data in trees

Hashing allows us to use an array to solve these issues.

## Hashing
A Hash function transforms keys into an array index.

One example of this is summing up the ascii values in a string, and *modding* it by the table size.

One problem with all hash functions is that they lead to **collisions**, since they are a many-to-one mapping. A collision is the result of two or more keys hashing to the same value.

How do we handle collision?

### Collision resolution
Two common strategiess:
- Linear resolution
- Open hashing

#### Linear Resolution
This is the simplest strategy for collision resolution. When hashing, if a collision occurs, go to the next vacant space if it exists.

#### Open hashing
Open hashing is a better way to solve this problem. Also referred to as chaining, open hashing stores an array of linked lists, which are then added to / removed from as is necessary. This means that multiple values can hash to one value and still avoid collisions.