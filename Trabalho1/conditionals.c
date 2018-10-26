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
void freeBuffer(Buffer* b){
	free(b->values);
	free(b);
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
	if(b->numElems==0){
		printf("EMPTY\n");
		return;
	}

	for(int i=0;i<b->numElems;++i)
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
	//printf("put %d\n",(int)arg);
}

void spend(void *arg){
	pop(b);
}

void* produce(void *arg){
	pthread_mutex_lock(&Buffermutex);
	while (isFull(b)){
		
		pthread_cond_wait(&encher, &Buffermutex);
	}
	make(arg);
	pthread_cond_broadcast(&consumir);
	pthread_mutex_unlock(&Buffermutex);
	pthread_exit(NULL);
}
void *consume(void *arg) {
	pthread_mutex_lock(&Buffermutex);
	while (isEmpty(b)){
		 
		pthread_cond_wait(&consumir, &Buffermutex);
	}
	spend(arg);
	pthread_cond_broadcast(&encher);
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
		printf("USAGE: conditionals <max> <nproducers> <nconsumers>\n"
		"\n"
		"ARGUMENTS\n"
		"   <max_number>  buffer length\n"
		"   <nproducers>  number of threads writing to buffer\n"
		"   <nconsumers>  number of threads reading (consuming) the buffer\n"
		"\n"
		"Producer threads put their own index code in the producers pool inside the buffer.\n"
		"Consumers threads read and delete the read value from the buffer.\n"
		"When a producer thread needs to insert a value but the buffer is full it signals the consumers threads to read.\n"
		"When a consumer thread needs to read a value but the buffer is empty it signals the producer threads to write.\n");
		exit(0);
	}

	pthread_t consumidores[nconsumidores],produtores[nprodutores];
	b=makeBuffer(max);

	pthread_mutex_init(&Buffermutex, NULL);
   	pthread_cond_init (&consumir, NULL);
   	pthread_cond_init (&encher, NULL);


   	
	
	for(int t=0;t<nconsumidores;t++){

    	int res = pthread_create(&consumidores[t], NULL, consume, t);
    	if(res){
	      printf("ERROR:     return code from pthread_create() is %d\n", res);
	      exit(-1);
	    }    
	}
	for(int t=0;t<nprodutores;t++){

    	int res = pthread_create(&produtores[t], NULL, produce, t);
    	if(res){
	      printf("ERROR:     return code from pthread_create() is %d\n", res);
	      exit(-1);
	    }    
	}	
	

	for (int i=0; i<nprodutores; i++) 
		pthread_join(produtores[i], NULL);
	for (int i=0; i<nconsumidores; i++) 
		pthread_join(consumidores[i], NULL);
	
   for(int t=0;t<15;t++)
		printBuffer(b);
 	pthread_mutex_destroy(&Buffermutex);
	pthread_cond_destroy(&consumir);
	pthread_cond_destroy(&encher);
	free(b);
	pthread_exit(NULL);

}
