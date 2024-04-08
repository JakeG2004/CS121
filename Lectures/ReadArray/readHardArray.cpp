#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;

int main()
{
    ifstream inFile;
    inFile.open("testHard.in", ios::in);

    int A[10];
    int i = 0;
    int n;

    #define DO_EASY 0 
    #define DO_COMPLICATED 1

    #if DO_EASY
        while(inFile >> n)
        {
            A[i++] = n;
        }

        out << "Read: " << i << " values" << endl;
    #endif

    #if DO_COMPLICATED
        string s;

        while(getline(inFile, s))
        {
            stringstream ss(s);
            ss >> n;
            A[i] = n;
            i++;
        }

        cout << "Read: " << i << " values" << endl;

    #endif

    for(int x = 0; x < i; x++)
    {
        cout << A[x] << endl;
    }
}