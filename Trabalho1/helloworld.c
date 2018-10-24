#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void* hello(void * thread) {

  printf("HELLO WORLD BY THREAD %ld\n",(long)thread);
  
  pthread_exit(NULL);
}

int main() {
  
  pthread_t threads[NUM_THREADS];
  int i=0;

  for(i=0;i<NUM_THREADS;++i){

    int res = pthread_create(&threads[i], NULL, hello, (void*)i);
    if(res){
      printf("ERROR:     return code from pthread_create() is %d\n", res);
      exit(-1);
    }    
  }
  
  
/*calling exit(0) will terminate the whole process and, consequently, the threads.
Use pthread_exit to make sure the process only gets terminated upon all threads completion.*/
    pthread_exit(NULL); 
}