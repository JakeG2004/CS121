// Linear search

int LinearSearch(const int A[], const int nA, const int val)
{
    for(int i = 0; i < nA; i++)
    {
        if(A[i] == val)
            return i;
    }

    return -1;
}

//Binary search
int BinarySearch(int A[], int nA, int val)
{
    int mid, low = 0, high = nA - 1;

    while(low <= high)
    {
        mid = (low + high) / 2;
        
        if(val > A[mid])
            low = mid + 1;

        else if(val < A[mid])
            high = mid - 1;

        else
            return mid;
    }

    return -1;
}