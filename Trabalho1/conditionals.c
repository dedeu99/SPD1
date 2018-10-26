#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//FILO AKA STACK
typedef struct buffer{
	unsigned int maxSize;
	unsigned int numElems;
	int* values;

}Buffer;

Buffer* b;
pthread_mutex_t Buffermutex;
pthread_cond_t consumir, encher;



Buffer* makeBuffer(int maxSize){
	Buffer* b=(Buffer*)malloc(sizeof(Buffer));
	b->values=(int*)malloc(sizeof(int)*maxSize);	
	b->maxSize=maxSize;
	b->numElems=0;
	return b;
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
	return b->values[--	b->numElems];
}
void printBuffer(Buffer* b){
	for(int i=0;i<b->numElems;++b)
		printf("%d,",b->values[i]);
	printf("\n");
}
int isFull(Buffer* b){
	return b->numElems==b->maxSize;
}
int isEmpty(Buffer* b){
	return b->numElems==0;
}

void make(void *arg){
	push(b,(int)arg);
}

void spend(void *arg){
	pop(b);
}

void* produce(void *arg){
	pthread_mutex_lock(&Buffermutex);
	while (isFull(b))
		pthread_cond_wait(&encher, &Buffermutex);
	make(arg);
	pthread_cond_signal(&consumir);
	pthread_mutex_unlock(&Buffermutex);
	pthread_exit(NULL);
}
void *consume(void *arg) {
	pthread_mutex_lock(&Buffermutex);
	while (isEmpty(b))
		pthread_cond_wait(&consumir, &Buffermutex);
	spend(arg);
	pthread_cond_signal(&encher); 
	pthread_mutex_unlock(&Buffermutex);
	pthread_exit(NULL);
}


int main(int argc,  char** argv) {
  	int max=0,nconsumidores=0,nprodutores=0;
	
	if(argc==4){
		max=atoi(argv[1]);
		nconsumidores=atoi(argv[2]);
		nprodutores=atoi(argv[3]);

	}else{
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

	pthread_t consumidores[nconsumidores],produtores[nprodutores];
	b=makeBuffer(max);

	pthread_mutex_init(&Buffermutex, NULL);
   	pthread_cond_init (&consumir, NULL);
   	pthread_cond_init (&encher, NULL);


   	for(int t=0;t<nconsumidores;++t){

    	int res = pthread_create(&consumidores[t], NULL, consume, t);
    	if(res){
	      printf("ERROR:     return code from pthread_create() is %d\n", res);
	      exit(-1);
	    }    
	}
	for(int t=0;t<nprodutores;++t){

    	int res = pthread_create(&produtores[t], NULL, produce, t);
    	if(res){
	      printf("ERROR:     return code from pthread_create() is %d\n", res);
	      exit(-1);
	    }    
	}	





	for (int i=0; i<nconsumidores; i++) 
		pthread_join(consumidores[i], NULL);
	for (int i=0; i<nprodutores; i++) 
		pthread_join(produtores[i], NULL);
   
 	pthread_mutex_destroy(&Buffermutex);
	pthread_cond_destroy(&consumir);
	pthread_cond_destroy(&consumir);
	pthread_exit(NULL);

}
