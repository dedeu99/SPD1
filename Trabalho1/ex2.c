#include <pthread.h>
#include <stdio.h>

#define EXIT_KEY 'Q'
#define MAX_NUM_CHARACTERS 50


char[MAX_NUM_CHARACTERS] characters;
int numCharacters=0;
bool exit=FALSE;


int main(int argc, char* argv){
	void* status;
	pthread_mutex_t exitMutex;
	int rc,rc2;
	pthread_mutex_init(&exitMutex, NULL)
	pthread_t thread,thread2;
	printf("PRESS %c AT ANY TIME TO QUIT\n");

	rc=pthread_create(thread,NULL,readInput, NULL );
	rc2=pthread_create(thread,NULL,feedback, NULL );
	if (rc || rc2){
        printf("ERROR:		 return code from pthread_create() is %d\n", rc);
        exit(-1);
    }
    pthread_join(thread, &status);
    pthread_join(thread2, &status);

    printf("PRESSED: %s",characters);
    
    pthread_mutex_destroy(&exitMutex);
    pthread_exit(NULL);
}

void *readInput(){

	int c;
	
	while(numCharacters<MAX_NUM_CHARACTERS && c = getchar( ) != EXIT_KEY){
		characters[numCharacters++]=c;
	}
	pthread_mutex_lock (&mutexsum);
	exit=TRUE;
    pthread_mutex_unlock (&mutexsum);

    pthread_exit((void*) 0);
}
void *feedback(){

	printf("LOADING");
	bool cont;

    while(cont){
    	printf('.');
    	pthread_mutex_lock (&mutexsum);
		cont=!exit;
    	pthread_mutex_unlock (&mutexsum);
    }

    printf("/n");
}