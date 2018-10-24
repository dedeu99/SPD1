#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <pthread.h>

void* hello(void * thread) {
 printf("HELLO WORLD BY THREAD %d",thread);
}


int main() {
  pthread_t t;
  int res = pthread_create(&t, NULL, hello, threadid);
  

  
  exit(0);
}