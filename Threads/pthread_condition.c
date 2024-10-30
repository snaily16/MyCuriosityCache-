#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *critical_function1(void *ptr);
void *critical_function2(void *ptr);
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cv = PTHREAD_COND_INITIALIZER;
int counter = 0;

#define COUNT_DONE 10
#define COUNT_HALT1 3
#define COUNT_HALT2 6

void main(){
    pthread_t thread1, thread2;
    const char *msg1 = "Thread 1";
    const char *msg2 = "Thread 2";

    pthread_create( &thread1, NULL, critical_function1, (void*) msg1);
    pthread_create( &thread2, NULL, critical_function2, (void*) msg2);
    
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Final counter value: %d\n", counter);
    exit(EXIT_SUCCESS);
}

void *critical_function1(void *ptr){
    char *i = (char *) ptr;
    printf("Thread %s started, id: %ld\n", i, pthread_self());
    for(;;){
        pthread_mutex_lock( &mutex1 );
        pthread_cond_wait(&cv, &mutex1);
        counter++;
        printf("Counter value in func 1: %i\n", counter);
        pthread_mutex_unlock( &mutex1 );
        if(counter >= COUNT_DONE) return(NULL);
    }
    printf("func 1 ended%s: \n", i);
}

void *critical_function2(void *ptr){
    char *i = (char *) ptr;
    printf("Thread %s started, id: %ld\n", i, pthread_self());
    for(;;){
        pthread_mutex_lock( &mutex1 );
        if (counter < COUNT_HALT1 || counter > COUNT_HALT2 ){
            pthread_cond_signal( & cv);
        }
        else{
            counter++;
            printf("Counter value in func 2: %i\n", counter);
        }
        pthread_mutex_unlock( &mutex1 );
        if(counter >= COUNT_DONE) return(NULL);
    }
    printf("func 2 ended%s: \n", i);
}
