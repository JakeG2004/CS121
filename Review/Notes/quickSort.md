# Quicksort
Quicksort partitions the list into smallers lists such that every element in the left partition is less than or equal to the right partition. Repeat Quicksort process on the partitions. Frequently done using recursion.

## Process
- Choose a value, called *pivot*
- Sort everything less than the pivot to the left, and everything greater to the right
- Repeat with the left of the pivot and the right of the pivot.

## Code
[quickSort.cpp](Code/quickSort.cpp)