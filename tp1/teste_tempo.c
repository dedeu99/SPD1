#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <math.h>

double rtc()
{
        struct timeval time;
        gettimeofday(&time,NULL);
        return ( (double)(time.tv_sec*1000000+time.tv_usec)/1000000 );
}

int main()
{
        double elapsed, rtc();
	
        elapsed=rtc();
		/* Operation to be timed here */
        elapsed=rtc()-elapsed;

        printf( "   Elapsed time: Loop time = %8f  \n",	elapsed );

        exit (0);
}



