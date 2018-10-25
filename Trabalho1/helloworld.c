#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>



void* hello(void * thread) {
  sleep(1);
  printf("HELLO WORLD BY THREAD %ld\n",(long)thread);

  pthread_exit(NULL);
}

int main(int argc,  char** argv) {
  int nthreads=0;
  if(argc==2)
    nthreads=atoi(argv[1]);
  else{
    printf(
    "USAGE: helloworld <threads>\n"
    "\n"
    "ARGUMENTS\n"
    "  <threads>  Number of threads to create that increment a value\n"
    "\n"
    "Creates <threads> threads and makes them print their a message with their index in the pool to stdout.\n");
    exit(0);
  } 
  pthread_t threads[nthreads];
  int i=0;

  for(i=0;i<nthreads;++i){

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