
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