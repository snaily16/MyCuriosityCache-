#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#define NUM_THREADS     4

char *message[NUM_THREADS];
void *print_message_fun(void *ptr);

struct thread_data{
    int thread_id;
    int sum;
    char* message;
};
struct thread_data thread_data_array[NUM_THREADS];

void main(){
    pthread_t thread[NUM_THREADS];
    int *taskids[NUM_THREADS];
    int rc, t, sum;
    
    sum=0;
    message[0] = "English: Hello World!";
    message[1] = "Japan: Sekai e konnichiwa!";
    message[2] = "French: Bonjour, le monde!!";
    message[3] = "Spanish: Hola al mundo";

    for(t=0; t<NUM_THREADS; t++){
        sum = sum+t;
        thread_data_array[t].thread_id = t;
        thread_data_array[t].sum = sum;
        thread_data_array[t].message = message[t];
        printf("Creating thread %d\n", t);
        rc = pthread_create(&thread[t], NULL, print_message_fun, (void *) &thread_data_array[t]);
        if(rc){
            printf("Error; return code is %d\n", rc);
            exit(-1);
        }
    }
    pthread_exit(NULL);
}

void *print_message_fun(void *ptr){
    int taskid, sum;
    char *msg;
    struct thread_data *my_data;

    sleep(1);
    my_data = (struct thread_data *) ptr;
    taskid = my_data->thread_id;
    sum = my_data->sum;
    msg = my_data->message;
    printf("Thread %d: %s , Sum=%d\n",taskid, msg, sum);
    pthread_exit(NULL);
}
