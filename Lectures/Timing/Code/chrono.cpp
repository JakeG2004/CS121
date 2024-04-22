//chrono.cpp

#include <iostream>
#include <chrono>

using namespace std;

int main()
{
    // compare the clocks
    cout << "chrono::system_clock::period" << endl;
    cout << chrono::system_clock::period::num << "/" <<
    chrono::system_clock::period::den << endl;

    cout << "chrono::steady_clock::period" << endl;
    cout << chrono::steady_clock::period::num << "/" <<
    chrono::steady_clock::period::den << endl;

    cout << "chrono::high_resolution_clock::period" << endl;
    cout << chrono::high_resolution_clock::period::num << "/" <<
    chrono::high_resolution_clock::period::den << endl;

    chrono::microseconds muSec(5000);
    chrono::nanoseconds nSec = muSec;
    chrono::milliseconds mSec = chrono::duration_cast<chrono::milliseconds>(muSec);

    cout << "nSec: " << nSec.count() << endl;
    cout << "muSec: " << muSec.count() << endl;
    cout << "mSec: " << mSec.count() << endl;

    chrono::system_clock::time_point tp = chrono::system_clock::now();

    cout << "tp.time_since_epoch().count(): ";
    cout << tp.time_since_epoch().count() << endl;

    tp = tp + chrono::seconds(1); // one second later

    cout << "tp.time_since_epoch().count(): ";
    cout << tp.time_since_epoch().count() << endl;
    
    return 0;
}