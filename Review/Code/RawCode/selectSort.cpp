#include <iostream>

using namespace std;

const int SIZE = 10;

void selectSort(int[]);
void swap(int&, int&);

int main()
{
    int myArr[SIZE];

    for(int i = 0; i < SIZE; i++)
    {
        myArr[i] = rand() % 10;
    }

    selectSort(myArr);

    for(int i = 0; i < SIZE; i++)
    {
        cout << myArr[i] << endl;
    }
}

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

void swap(int &x, int &y)
{
    int buffer = x;
    x = y;
    y = buffer;
}