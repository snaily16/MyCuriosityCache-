#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *print_message_function(void *ptr);
const int num_threads = 100000;
int counter = 0;

int main(){
    int i;
    pthread_t tid[num_threads];

    for(i=0; i<num_threads; i++){
        pthread_create(&tid[i], NULL, print_message_function, (void*) &i);
    }

    // Joining threads
    for(i=0; i<num_threads; i++){
        pthread_join(tid[i], NULL);
    }
    printf("Done!\n");
    return 0;
}

void *print_message_function(void *ptr){
    int id = *((int *)ptr);
    counter++;
    printf("Thread %d running ... ", id);
    printf("Counter value: %d\n", counter);
    return NULL;
}
