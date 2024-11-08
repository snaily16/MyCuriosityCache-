#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

void *print_message_fun(void *ptr);

void main(){
    pthread_t thread1, thread2;
    const char *msg1 = "Thread 1";
    const char *msg2 = "Thread 2";
    int iret1, iret2;

    // Create independent threads
    iret1 = pthread_create( &thread1, NULL, print_message_fun, (void*) msg1);
    if (iret1) {
        fprintf(stderr, "Error - pthread_create() return code: %d\n", iret1);
        exit(EXIT_FAILURE);
    }
    iret2 = pthread_create( &thread2, NULL, print_message_fun, (void*) msg2);
    if (iret2) {
        fprintf(stderr, "Error - pthread_create() return code: %d\n", iret2);
        exit(EXIT_FAILURE);
    }
    printf("pthread_create for thread 1 returns: %d\n", iret1);
    printf("pthread_create for thread 2 returns: %d\n", iret2);
    printf("%ld \n", pthread_self());
    printf("%ld \n", thread2);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    exit(EXIT_SUCCESS);
}

void *print_message_fun(void *ptr){
    char *message;
    message = (char *) ptr;
    printf("%s: %ld \n", message, pthread_self());
}
