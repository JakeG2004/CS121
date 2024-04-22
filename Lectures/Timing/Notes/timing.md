# Timing
Sometimes it is useful to time the operation of code. This allows testing of different algorithms.

There are two easy ways to time operation in the Linux / Unix world. The `time` and `date` commands can be used. The `date` command is typically too coarse for exact timing.

## Using time and date
`$ time cmd`

`$ time ls`

real	0m0.003s
user	0m0.003s
sys	0m0.000s

This shows real, user, and system time elapsed.

`$ date ; cmd ; date`

`$ date ; ls ; date`

## Timing inside code
The simplest way to actually time hte operation of a section of code is to use the `clock()` function. To time the code, `clock()` is called before and after the section to be timed, then the difference is calculated and displayed.

[Sample Code](../Code/timer0.c)

### Sample output
    for loop took 2.017334 seconds to execute

    real    0m2.021s
    user    0m2.016s
    sys     0m0.004s

## `clock()`
The C library function `clock_t clock(void)` returns the number of clock ticks elapsed since hte program was launched. To get the number of seconds used by the CPU, you will need to divide by CLOCKS_PER_SEC.

On a 32 bit system where CLOCKS_PER_SEC equals 1,000,000, this function will return the same value approximately every 72 minutes.

[More sample code](../Code/timer1.c)

### Sample Output
    LONG_MAX: 9223372036854775807
    579025220 days 15:30: 7
    677014 - seconds elapsed from boot
    7 days 20: 3:34

## Using the `chrono` class
C++ has a class, `chrono`, for better timing.

[Sample Code](../Code/chrono.cpp)

### Sample Output
    chrono::system_clock::period
    1/1000000000
    chrono::steady_clock::period
    1/1000000000
    chrono::high_resolution_clock::period
    1/1000000000
    nSec: 5000000
    muSec: 5000
    mSec: 5
    tp.time_since_epoch().count(): 1713805190262802708
    tp.time_since_epoch().count(): 1713805191262802708

Note that the 2 changes to a 3 for one second - high resolution!

- ***good enough*** for our usage.
