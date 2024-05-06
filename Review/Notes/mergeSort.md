# Mergesort
Merge sort is a sorting algorithm that follows the divide and conquer approach. It works by recursively dividing the input array into smaller subarrays and sorting those subarrays, then merging them back together to obtain the sorted array.

In simple terms, we can say that the process of merge sort is to divide the array into two halves, sort each half, then merge the sorted halves back together. This process is repeated until the entire array is sorted.

## How does merge sort work?
1. Divide the list or array recursively into two halves until it can be divided no more
2. Each subarray is sorted individually using the merge sort algorithm
3. The sorted subarrays are merged back together in sorted order. The process continues until all elements from both subarrays have been merged.

## Example

    Initial array: [38, 27, 43, 10]

    Divide: 
        [38, 27, 43, 10] is divided into [38, 27] and [43, 10]
        [38, 27] is divided into [38] and [27]
        [43, 10] is divided into [43] and [10]

    Conquer:
        [38] is already sorted
        [27] is already sorted
        [43] is already sorted
        [10] is already sorted

    Merge:
        Merge [38] and [27] to get [27, 38]
        Merge [43] and [10] to get [10, 43]
        Merge [27, 38] and [10, 43] to get the final sorted list [10, 27, 38, 43]

    Therefore, the sorted list is [10, 27, 38, 43]

## Code
[mergeSort.cpp](Code/mergeSort.cpp)
