#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//FILO AKA STACK
typedef struct buffer{
	unsigned int maxSize=0;
	unsigned int numElems=0;
	int* values;

}Buffer;

Buffer* makeBuffer(int maxSize){
	Buffer* b=(Buffer*)malloc(sizeof(Buffer));
	b->values=(int*)malloc(sizeof(int)*maxSize)
	b->maxSize=maxSize;
	b->numElems=0;
}
int push(Buffer* b,int value){
	if(b->numElems>=b->maxSize)
		return 0;

	b->values[b->numElems++]=value;
	return 1;
}
int pop(Buffer* b){
	if(b->numElems==0)
		return 0;
	return b->values[b->numElems--];
}

/*void *make(void *arg){


}

void *consume(void *arg){


}*/
int main(int argc,  char** argv) {
  	
	
	if(argc==2)
		max=atoi(argv[1]);
	/*else{
		printf("USAGE: deadlock <max_number>\n"
		"\n"
		"ARGUMENTS\n"
		"   <max_number>  maximum number two threads can count up to\n"
		"\n"
		"One thread increments a counter be one and one increments a counter by two up to <max_number>.\n"
		"We count the difference between the number of times thread1 counted and thread2 executed.\n"
		"If result ==0, both threads executed the same number of times.\n"
		"If result < 0, thread1 executed abs(result) more times .\n"
		"If result > 0, thread2 executed abs(result) more times .\n"
		"Afterwards try running '$no_deadlock <n>' and see what happens for n=9999 several times\n"
		"To ease the repetion of commands try the following:\n"
		"'$no_deadlock 9999'\n"
		"'$!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;!!;'\n");
		exit(0);
	}
	int buffer[max];
	int nthreads=2;
	pthread_t threads[nthreads];
	
	pthread_mutex_init(&i_mutex,NULL);
	pthread_mutex_init(&j_mutex,NULL);


	int res = pthread_create(&threads[0], NULL, inc, NULL);
	if(res){
      printf("ERROR:     return code from pthread_create() is %d\n", res);
      exit(-1);
    }  
    
    res = pthread_create(&threads[1], NULL, inc2, NULL);
	if(res){
      printf("ERROR:     return code from pthread_create() is %d\n", res);
      exit(-1);
    }  

	for(int t=0;t<nthreads;++t)
  		pthread_join(threads[t], NULL);
  	printf("Number of threads:%d   incremental result:%d    diff in number of executions:%d\n",nthreads,i,j);
  	pthread_mutex_destroy(&i_mutex);
	pthread_exit(NULL);*/


	Buffer* b=makeBuffer(max);
	push(b,5);
	push(b,6);
	push(b,7);
	printf("%d\n",pop(b));
	printf("%d\n",pop(b));
	printf("%d\n",pop(b));	


}
