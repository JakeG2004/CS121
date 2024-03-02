#include <iostream>

using namespace std;

int factorial(int n);
int fib(int n);

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        cout << "Invalid usage! ./a.out <integer>" << endl;
        exit(-1);
    }

    int num = stoi(argv[1]);

    cout << "Factorial: " << factorial(num) << endl;
    cout << "Fibonnaci: " << fib(num) << endl;
}

int factorial(int n){
    //base case
    if(n == 0 || n == 1)
        return 1;

    //general case
    else
        return n * factorial(n-1);
}

int fib(int n)
{
    //base case
    if(n == 0 || n == 1)
        return 1;
    
    //general case
    else
        return(fib(n-1) + fib(n-2));
}