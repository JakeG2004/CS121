#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

enum{
    ROLLS = 100000,
    SIDES = 6
};

void printArray(int arr[]);

int main(){

    int arr[SIDES] = {0};
    cout << "Init array contents: " << endl;
    printArray(arr);

    srand(time(NULL));

    for(int i=0; i< SIDES * ROLLS; i++){
        int iRand = (rand() % SIDES);
        arr[iRand]++;
    }

    cout << "Final array contents: " << endl;
    printArray(arr);
}

void printArray(int arr[]){
    for(int i=0; i<SIDES; i++){
        cout << i+1 << "\t" << arr[i] << endl;
    }
}