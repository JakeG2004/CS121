void SelectionSort(int A[], int nA)
{
    int iSmallest;

    for(int i = 0; i < nA; i++)
    {
        iSmallest = IndexOfSmallest(A, i, nA - 1);
        Swap(A[i], A[iSmallest]);
    }
}

int IndexOfSmallest(int A[], int iStart, int iEnd)
{
    int index = -1;
    int aMin = A[iStart];

    for(int i = iStart; i <= iEnd; i++)
    {
        if(A[i] < aMin)
        {
            index = i;
            aMin = A[i];
        }
    }

    return index;
}

void Swap(int &start, int &smallest)
{
    start ^= smallest;
    smallest ^= start;
    start ^= smallest;
}