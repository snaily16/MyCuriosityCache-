#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *critical_function(void *ptr);
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int counter = 0;

void main(){
    pthread_t thread1, thread2;
    const char *msg1 = "Thread 1";
    const char *msg2 = "Thread 2";
    int iret1, iret2;

    // Create independent threads
    iret1 = pthread_create( &thread1, NULL, critical_function, (void*) msg1);
    if (iret1) {
        fprintf(stderr, "Error - pthread_create() return code: %d\n", iret1);
        exit(EXIT_FAILURE);
    }
    iret2 = pthread_create( &thread2, NULL, critical_function, (void*) msg2);
    if (iret2) {
        fprintf(stderr, "Error - pthread_create() return code: %d\n", iret2);
        exit(EXIT_FAILURE);
    }
    printf("pthread_create for thread 1 returns: %d\n", iret1);
    printf("pthread_create for thread 2 returns: %d\n", iret2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("Final counter value: %d\n", counter);
    exit(EXIT_SUCCESS);
}

void *critical_function(void *ptr){
    char *i = (char *) ptr;
    printf("Thread %s started, id: %ld\n", i, pthread_self());
    pthread_mutex_lock( &mutex1 );
    counter++;
    printf("Counter value: %i\n", counter);
    pthread_mutex_unlock( &mutex1 );
    printf("Thread ended%s: \n", i);
}
