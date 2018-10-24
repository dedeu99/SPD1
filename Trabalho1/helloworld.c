#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void* hello(void * thread) {
 printf("HELLO WORLD BY THREAD %ld",(long)thread);
 pthread_exit(NULL);
}




int main() {
  pthread_t threads[NUM_THREADS];


  for(int i=0;i<NUM_THREADS;++i){

    int res = pthread_create(&t, NULL, hello, (void*)i);
    if(res){
      printf("ERROR:     return code from pthread_create() is %d\n", res);
      exit(-1);
    }    
  }
  
  
  exit(0);
}