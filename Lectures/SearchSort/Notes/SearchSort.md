# Searching and Sorting
Two questions; "Why sort?"

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

### Insertion sort
Iterate through the array placing the *i*th element with respect to the *i* - 1 previous elements.

### Selection sort
Iterate through the array putting the *i*th smallest elementh in the *i*th location.

### Quick sort
Partition the list into smaller lists such that every element in the left partition is <= every element in the right partition. Repeat quicksort process on the partitions - frequently done using recursion.

### Merge sort
Useful for sorting very large amounts of data. The basic algorithm:
1. Split the file into smaller files
2. Sort the smaller files
3. Merge the sorted files

## Searching
The answer to "Why sort?"

### Common Search Techniques
- Linear search
- Binary Search
- Hash tables / Dictionaries