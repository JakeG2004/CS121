# Searching and Sorting

## Sorting
- Why sort?
- What are some common sorting algorithms?

### Common Sorting Techniques
- Bubble sort
- Insertion sort
- Selection sort
- Quick sort
- Merge sort

### Bubble Sort
Iterate through the array examining adjacent pairs of elements. If necessary, swap them to put them in the desired order (*Brick sort*).

### Insertion Sort
Iterate through the array placing the *i*th element with respect to the *i* - 1 previous elements.

### Selection Sort
Iterate through the array putting the *i*th smallest elementh in the *i*th location.

Given an array A with N items stored in it.

* Loop over each element (*i*)
* Put the smallest first (*i*th location) each iteration

[Selection Sort Code](../Code/selectSort.cpp)

### Quick Sort
Partition the list into smaller lists such that every element in the left partition is <= every element in the right partition. Repeat quicksort process on the partitions - frequently done using recursion.

### Merge Sort
Useful for sorting very large amounts of data. The basic algorithm:
1. Split the file into smaller files
2. Sort the smaller files
3. Merge the sorted files

Originally performed on files - old computers didn't have much RAM (understatement).

#### Merge Sort Diagram
    Split:
    [7, 13, 1, 3, 10, 5, 2, 4]
    [7, 13, 1, 3] [10, 5, 2, 4]
    [7, 13] [1, 3] [10, 5] [2, 4]
    [7], [13], [1], [3], [10], [5], [2], [4]

    Merge:
    [7, 13] [1, 3] [5, 10] [2, 4]
    [1, 3, 7, 13] [2, 4, 5, 10]
    [1, 2, 3, 4, 5, 7, 10, 13]

This has a time complexity of N log(N)

[Merge Sort Code](../Code/mergeSort.cpp)

### Quicksort
Look at first value, put it in the middle of a buffer list. Place all values < this value on the left, and all >= on the right. Repeat with the two new halves of the list.

    [4, 7, 3, 10, 6, 2] Initial condition, 4 is pivot
    [3, 2, 4, 7, 10, 6] Pivot placed in middle, values sorted accordingly
    [2, 3, 4, 6, 7, 10] Process repeated with the two halves

**How to choose the pivot value?**

Many ways to choose the pivot value. Using the first value is probably the easiest.

This has a time complexity of N log(N)

[Quicksort Code](../Code/quickSort.cpp)

### Sorting Properties
* Comparisons
* Swaps
* Runtime

## Searching
The answer to "Why sort?"

[Search Code](../Code/search.cpp)

### Common Search Techniques
- Linear search
- Binary Search
- Hash tables / Dictionaries