#include <iostream>

using namespace std;

const int SIZE = 10;

void selectSort(int arr[]);
void swap(int &x, int &y);
void printArr(int arr[]);

int main()
{
    //make array
    int arr[SIZE];

    for(int i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % 10;
    }

    cout << "Unsorted Array: " << endl;
    printArr(arr);

    selectSort(arr);

    cout << "Sorted Array: " << endl;
    printArr(arr);
}

void selectSort(int arr[])
{
    //iterate through every element
    for(int i = 0; i < SIZE; i++)
    {
        //find the index of the smallest value
        int smallestIndex = i;
        for(int j = i; j < SIZE; j++)
        {
            if(arr[j] < arr[smallestIndex])
            {
                smallestIndex = j;
            }
        }

        //swap first value with smallest value
        swap(arr[i], arr[smallestIndex]);
    }
}

void swap(int &x, int &y)
{
    if(x != y)
    {
        x ^= y;
        y ^= x;
        x ^= y;
    }
}

void printArr(int arr[])
{
    for(int i = 0; i < SIZE; i++)
    {
        cout << arr[i];

        if(i != SIZE - 1)
        {
            cout << ", ";
        }
    }
    cout << endl;
}