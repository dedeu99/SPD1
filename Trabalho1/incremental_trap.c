
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 2
#define MAX_VALUE 10



int i=0;


void* inc(void * threadid) {
	while(i<MAX_VALUE){
		i++;
		printf("THREAD %ld incremented value to %d",(long)threadid,i);
	}
 }

int main() {
  

	pthread_t threads[NUM_THREADS];
	int i=0;

	for(i=0;i<NUM_THREADS;++i){

    	int res = pthread_create(&threads[i], NULL, inc, (void*)i);
    	if(res){
	      printf("ERROR:     return code from pthread_create() is %d\n", res);
	      exit(-1);
	    }    
	}
  
  
	pthread_exit(NULL);
}