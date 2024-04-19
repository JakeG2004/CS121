#include <iostream>

using namespace std;

const int MAX_ARRAY = 10;

void Mergesort(int A[], int first, int last)
{
    int middle;

    if(first < last)
    {
        //assign middle values
        middle = (first + last) / 2;

        //keep splitting into smaller lists
        Mergesort(A, first, middle);
        Mergesort(A, middle + 1, last);

        //merge them
        Merge(A, first, middle, middle + 1, last);
    }
}

void Merge(int A[], int firstLeft, int lastLeft, int firstRight, int lastRight)
{
    //make buffer
    int tempArray[MAX_ARRAY];

    int index = firstLeft;
    int firstSave = firstLeft;

    //sort sublists
    while((firstLeft <= lastLeft) && (firstRight <= lastRight))
    {
        if(A[firstLeft] < A[firstRight])
        {
            tempArray[index] = A[firstLeft];
            firstLeft++;
        } 
        
        else 
        {
            tempArray[index] = A[firstRight];
            firstRight++;
        }

        index++;
    }

    //continue to sort list (assuming they aren't both done)
    while(firstLeft <= lastLeft)
    {
        tempArray[index++] = A[firstLeft];
        firstLeft++;
    }

    while(firstRight <= lastRight)
    {
        tempArray[index++] = A[firstRight];
        firstRight++;
    }

    //merge that thang
    for(index = firstSave; index <= lastRight; index++)
    {
        A[index] = tempArray[index];
    }
}