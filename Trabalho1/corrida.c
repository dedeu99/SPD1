#include <pthread.h>
#include <stdio.h>


#define NUM_THREADS 3
#define FINISH_VALUE 100

pthread_t threads[NUM_THREADS];

pthread_attr_t attr;
pthread_cond_t count_reached;

void* count(){

	for(int i=0;i<FINISH_VALUE;++i);

	pthread_cond_signal(&count_reached);

	pthread_exit(NULL);
}


int main(){



	pthread_attr_init(&attr);
	pthread_cond_init (&count_reached, NULL);

	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);



	int errcode;
	for(int i=0;i<NUM_THREADS;++i)
		if(errcode=pthread_create(&threads[i],NULL,count, NULL )){
        	printf("ERROR:		 return code from pthread_create() is %d\n", errcode);
        	exit(-1);
    	}

    while(pthread_cond_wait(&count_reached,NULL));

    for (int i=0; i<NUM_THREADS; i++) {
     pthread_join(threads[i], NULL);


   pthread_attr_destroy(&attr);
   pthread_cond_destroy(&count_reached);
   pthread_exit(NULL);

}