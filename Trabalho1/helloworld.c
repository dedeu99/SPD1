#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* hello(void * thread) {
 printf("HELLO WORLD BY THREAD %ld",(long)thread);
}


int main() {
  pthread_t t;
  int res = pthread_create(&t, NULL, hello, (void*)t);
  if(res){
    printf("ERROR:     return code from pthread_create() is %d\n", res);
    exit(-1);
  }

  
  exit(0);
}