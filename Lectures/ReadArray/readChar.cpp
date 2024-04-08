#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    //open file
    ifstream inFile;
    inFile.open("testHard.in", ios::in);

    //init needed vars
    char A[10];
    int i = 0;
    char c;

    //read char by char
    while(inFile >> c)
    {
        A[i++] = c;
    }

    //close the file
    inFile.close();

    //print that thang
    cout << "Read: " << i << " values" << endl;

    cout << "Array contents: " << endl;
    for(int x = 0; x < i; x++)
    {
        cout << A[x] << endl;
    }
}