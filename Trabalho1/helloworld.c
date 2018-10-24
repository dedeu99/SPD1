#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void* hello(void * thread) {
 printf("HELLO WORLD BY THREAD %ld\n",(long)thread);
 pthread_exit(NULL);
}
pthread_t threads[NUM_THREADS];
int i=0;
int main() {
  


  for(i=0;i<NUM_THREADS;++i){

    int res = pthread_create(&threads[i], NULL, hello, (void*)i);
    if(res){
      printf("ERROR:     return code from pthread_create() is %d\n", res);
      exit(42);
    }    
  }
  
  
  pthread_exit(NULL);
}