#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int max=0;
int i=0;
pthread_mutex_t i_mutex;




void* inc(void * i) {
	int value=(int)i;
	while(value<max)
	{
		pthread_mutex_lock(&i_mutex);
		value++;
		pthread_mutex_unlock(&i_mutex);
	}
	pthread_exit(value);
}

void* referee1(void * n){
	int nthreads=(int)n;
	pthread_t threads[nthreads];

	for(int t=0;t<nthreads;++t){
		int res = pthread_create(&threads[0], NULL, inc, NULL);
		if(res){
	      printf("ERROR:     return code from pthread_create() is %d\n", res);
	      exit(-1);
	    }
	}

	for(int t=0;t<nthreads;++t)
  		pthread_join(threads[t], NULL);
}

int main(int argc,  char** argv) {
  	
	
	if(argc==2)
		max=atoi(argv[1]);
	else{
		printf("USAGE: deadlock <max_number>\n"
		"\n"
		"ARGUMENTS\n"
		"   <max_number>  maximum number two threads can count up to\n"
		"\n"
		"One thread increments a counter be one and one increments a counter by two up to <max_number>.\n"
		"We count the difference between the number of times thread1 counted and thread2 executed.\n"
		"If result ==0, both threads executed the same number of times.\n"
		"If result < 0, thread1 executed abs(result) more times .\n"
		"If result > 0, thread2 executed abs(result) more times .\n"
		"Afterwards try running '$no_deadlock <n>' and see what happens for n=9999 several times\n"
		"To ease the repetion of commands try the following:\n"
		"'$no_deadlock 9999'\n"
		"'$!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;'\n");
		exit(0);
	}	
	int nthreads=2;
	pthread_t threads[nthreads];
	
	pthread_mutex_init(&i_mutex,NULL);
	pthread_mutex_init(&j_mutex,NULL);


	int res = pthread_create(&threads[0], NULL, inc, NULL);
	if(res){
      printf("ERROR:     return code from pthread_create() is %d\n", res);
      exit(-1);
    }  
    
    res = pthread_create(&threads[1], NULL, inc2, NULL);
	if(res){
      printf("ERROR:     return code from pthread_create() is %d\n", res);
      exit(-1);
    }  

	for(int t=0;t<nthreads;++t)
  		pthread_join(threads[t], NULL);
  	printf("Number of threads:%d   incremental result:%d    diff in number of executions:%d\n",nthreads,i,j);
  	pthread_mutex_destroy(&i_mutex);
	pthread_exit(NULL);
}