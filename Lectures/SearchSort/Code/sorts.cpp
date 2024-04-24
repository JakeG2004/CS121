#include <iostream>

using namespace std;

void bubbleSort(int [], int);
void insertionSort(int arr[], int nA);
void selectionSort(int arr[], int nA);

void printArr(int arr[], int nA);

int main()
{
    int arr[10] = {5, 8, 2, 3, 0, 1, 6, 9, 4, 7};
    int nA = 10;

    //bubbleSort(arr, nA);
    selectionSort(arr, nA);
    //insertionSort(arr, nA);

    printArr(arr, nA);
}

//swap pairs, working left to right
void bubbleSort(int arr[], int nA)
{
    int swaps = 0;

    for(int i = 0; i < nA - 1; i++)
    {
        //swap if out of order
        if(arr[i + 1] < arr[i])
        {
            //magic xor to swap without a buffer
            arr[i] ^= arr[i + 1];
            arr[i + 1] ^= arr[i];
            arr[i] ^= arr[i + 1];

            swaps++;
        }
    }

    //repeat if no swaps
    if(swaps != 0)
    {
        bubbleSort(arr, nA);
    }
}

//kind of like bubble sort, but with the first i elements every time
void insertionSort(int arr[], int nA)
{
    //for every element excluding the first
    for(int i = 1; i < nA; i++)
    {
        //work backwards from i to the start of the list
        for(int j = i; j > 0; j--)
        {
            //swap values if needed
            if(arr[j] < arr[j - 1])
            {
                arr[j] ^= arr[j - 1];
                arr[j - 1] ^= arr[j];
                arr[j] ^= arr[j - 1];
            }
        }
    }
}

//finds smallest element, moves it to front
void selectionSort(int arr[], int nA)
{
    int smallestIndex;
    int buffer;

    for(int i = 0; i < nA; i++)
    {
        smallestIndex = i;

        //find smallest element and record its index
        for(int j = i; j < nA; j++)
        {
            if(arr[j] < arr[smallestIndex])
                smallestIndex = j;
        }

        //swap smallest element with whatever is at the ith position
        buffer = arr[i];
        arr[i] = arr[smallestIndex];
        arr[smallestIndex] = buffer;
    }
}

void printArr(int arr[], int nA)
{
    for(int i = 0; i < nA; i++)
    {
        cout << arr[i];
        
        if(i + 1 < nA)
            cout << ", ";
    }

    cout << endl;
}