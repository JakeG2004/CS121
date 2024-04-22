/* timer1.c
Reference:
https://man7.org/linux/man-pages/man3/clock_gettime.3.html
*/

//this code is absolutely insane and does not work in the slightest!

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <limits.h>

int main()
{
    struct timespec elapsed_from_boot;
    printf( "LONG_MAX: %ld\n", LONG_MAX ); // Value? in limits.h
    SecsToDays( nSecs );
    clock_gettime(CLOCK_MONOTONIC, &elapsed_from_boot); // macOS
    //clock_gettime(CLOCK_BOOTTIME, &elapsed_from_boot); // Linux
    printf( "%ld - seconds elapsed from boot\n", elapsed_from_boot.tv_sec );
    //printf( "%d - seconds elapsed from boot\n", elapsed_from_boot.tv_sec );
    long nSecs = elapsed_from_boot.tv_sec;
    SecsToDays( nSecs );
    return 0;
}