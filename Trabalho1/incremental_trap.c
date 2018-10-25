
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 2


int nthreads=NUM_THREADS;
int i=0;

void* inc(void * threadid) {
		i++;
	pthread_exit(NULL);
}
int t=0;
int main(int argc,  char** argv) {
  
	if(argc==2)
		nthreads=atoi(argv[1]);
	else{
		printf("USAGE: int_trap <threads>\n"
      "\n"
      "ARGUMENTS\n"
      "  <threads>  Number of threads to create that increment a value\n"
      "\n"
      "Since every thread increment the same variable only once its expected that the final result will be == to <threads>\n"
      "Try running '$int_trap 10' to confirm such behaviour\n"
      "Afterwards try running '$int_trap 999' several times and see what happends\n"
      "To ease the repetion of commands try the following:\n"
      "'$int_trap 999'\n"
      "'$!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;'\n");


	}	
	
	pthread_t threads[nthreads];
	

	for(t=0;t<nthreads;++t){

    	int res = pthread_create(&threads[t], NULL, inc, (void*)t);
    	if(res){
	      printf("ERROR:     return code from pthread_create() is %d\n", res);
	      exit(-1);
	    }    
	}	
	for(t=0;t<nthreads;++t)
  		pthread_join(threads[t], NULL);

  	printf("------%d\n",i);
	pthread_exit(NULL);
}