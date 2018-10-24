#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <pthread.h>
#define MAX_VALUE 20
int i=0;

pthread_mutex_t value_mutex;
void* inc(void * threadid) {

	while(i<MAX_VALUE){
		pthread_mutex_lock(&value_mutex);
		i++:
		pthread_mutex_unlock(&value_mutex);
		printf("THREAD %ld incremented value to %d",(long)threadid,i);
	}
}


int main() {
	pthread_mutex_init(&value_mutex);
  pthread_t t,t2;
  int res = pthread_create(&t, NULL, inc, threadid);


  res = pthread_create(&t2, NULL, inc, threadid);
  

  
  exit(0);
}