# Selection Sort
Selection sort is a sorting algorithm that works by repeatedly selecting the smallest (or largest) element from the unosrted portion of the list and moving it to the sorted portion of the list

## Reference code

    void selectSort(int myArr[])
    {
        for(int i = 0; i < SIZE; i++)
        {
            int smallestIndex = i;

            for(int j = i + 1; j < SIZE; j++)
            {
                if(myArr[smallestIndex] > myArr[j])
                {
                    smallestIndex = j;
                }
            }

            swap(myArr[smallestIndex], myArr[i]);
        }
    }

This code works on the following process
- Look at each element
    - Look at each of the following elements, keeping track of the index of the smallest item
    - Swap the first element and the smallest element