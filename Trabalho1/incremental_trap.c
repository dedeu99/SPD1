#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <pthread.h>
#define MAX_VALUE 20
int i=0;
void* inc(void * threadid) {
	while(i<MAX_VALUE){
		i++;
		printf("THREAD %ld incremented value to %d",(long)threadid,i);
	}
 }


int main() {
  pthread_t t,t2;
  int res = pthread_create(&t, NULL, inc, threadid);


  res = pthread_create(&t2, NULL, inc, threadid);
  

  
  exit(0);
}