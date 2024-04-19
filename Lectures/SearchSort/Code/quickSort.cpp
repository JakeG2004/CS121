//quicksort

void QuickSort(int A[], int first, int last)
{
    int pivot;

    //as long as the indeces haven't crossed, continue to quicksort
    if(first < last)
    {
        pivot = Pivot(A, first, last);

        QuickSort(A, first, pivot - 1);
        QuickSort(A, pivot + 1, last);
    }
}

int Pivot(int A[], int first, int last)
{
    int p = first; //pivot index
    int pivot = A[first]; //pivot value

    for(int i = first + 1; i <= last; i++)
    {
        //put all values <= pivot on the left
        if(A[i] <= pivot)
        {
            p++;
            Swap(A[i], A[p]);
        }
    }

    //put pivot after all of the < values
    Swap(A[p], A[first]);

    return p;
}

//bitwise magic
void Swap(int &x, int &y)
{
    x ^= y;
    y ^= x;
    x ^= y;
}