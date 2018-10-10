#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <math.h>
#include <unistd.h>

#define NUM_ITERATIONS_TO_TEST 1000000
double rtc()
{
        struct timeval time;
        gettimeofday(&time,NULL);
        return ( (double)(time.tv_sec*1000000+time.tv_usec)/1000000 );
}

double rtcFunc( void*(*func)(void) ,int num){
	double elapsed,looptime,partialLooptime;
	

	elapsed=rtc();
	partialLooptime=rtc();

	for(int i=0;i<num;++i){
		looptime+=rtc()-partialLooptime;

		func();

		partialLooptime=rtc();
	}
	elapsed=rtc()-elapsed;

	printf( "   Elapsed function time with %d iterations: %8f  \n",num, elapsed-looptime );
	printf( "   Elapsed time with the loop factored into it: %8f  \n",	elapsed);
	printf( "   Elapsed loop time : %8f  \n",	looptime );
	printf( "   Diff between times: %8f | %8f\% \n", looptime ,looptime /elapsed);


	return (elapsed-looptime)/num;
}

int main()
{
        double elapsed, rtc(), rtcFunc();
	
        elapsed=rtcFunc((void*(*)(void))getpid,NUM_ITERATIONS_TO_TEST);
	
        printf( "   Averaged Elapsed time with %d iterations: Loop time = %8f  \n",NUM_ITERATIONS_TO_TEST,	elapsed );


	/*elapsedError=rtc();
		getpid();
        elapsedError=rtc()-elapsed;*/
	
	



        exit (0);
}



