#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <pthread.h>
#define MAX_VALUE 20
int i=0;
int j=0;//se >0 inc2 correu j vezes a mais que inc, se j=0 correram exactamente o mesmo numero de vezes
pthread_mutex_t value_mutex;
pthread_mutex_t value2_mutex;
void* inc(void * threadid) {

	while(i<MAX_VALUE){
		pthread_mutex_lock(&value_mutex);
		pthread_mutex_lock(&value2_mutex);
		i++:
		--j;
		
		pthread_mutex_unlock(&value2_mutex);
		pthread_mutex_unlock(&value_mutex);
		printf("THREAD %ld incremented value to %d",(long)threadid,i);
	}
}
void* inc2(void * threadid) {

	while(i<MAX_VALUE){
		pthread_mutex_lock(&value2_mutex);
		pthread_mutex_lock(&value_mutex);
		i+=2:
		++j;
		pthread_mutex_unlock(&value_mutex);
		pthread_mutex_unlock(&value2_mutex);
		printf("THREAD %ld incremented value to %d",(long)threadid,i);
	}
}


int main() {
	pthread_mutex_init(&value_mutex);
	pthread_mutex_init(&value2_mutex);
  pthread_t t,t2;
  int res = pthread_create(&t, NULL, inc, threadid);


  res = pthread_create(&t2, NULL, inc2, threadid);
  

  
  exit(0);
}