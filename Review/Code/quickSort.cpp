#include <iostream>

using namespace std;

void Quicksort(int[], int, int);
void swap(int &x, int &y);
void printArr(int myArr[]);
int Pivot(int myArr[], int first, int last);

const int SIZE = 10;

int main()
{
    int myArr[SIZE];

    for(int i = 0; i < SIZE; i++)
    {
        myArr[i] = rand() % 20;
    }

    printArr(myArr);

    Quicksort(myArr, 0, SIZE - 1);

    cout << "\nSorted array" << endl;
    printArr(myArr);
}

void Quicksort(int a[], int first, int last)
{
    int pivot;

    if(first < last)
    {
        pivot = Pivot(a, first, last);
        Quicksort(a, first, pivot - 1);
        Quicksort(a, pivot + 1, last);
    }
}

int Pivot(int a[], int first, int last)
{
    int p = first;
    int pivot = a[first];

    for(int i = first + 1; i <= last; i++)
    {
        if(a[i] <= pivot)
        {
            p++;
            swap(a[i], a[p]);
        }
    }

    swap(a[p], a[first]);

    return p;
}

void swap(int &x, int &y)
{
    int buffer = x;
    x = y;
    y = buffer;
}

void printArr(int myArr[])
{
    for(int i = 0; i < SIZE; i++)
    {
        cout << myArr[i] << "\t";
    }
}