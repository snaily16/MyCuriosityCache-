#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *consumer(void *arg);

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int counter = 0;

//Producer
void *producer(void *arg){
  printf("Producer before mutex lock\n");
  pthread_mutex_lock(&mutex);
  printf("Producer is preparing the sauce...\n");
  sleep(2);
  counter=1;
  pthread_cond_signal(&cond);
  printf("Producer signalled condition\n");
  pthread_mutex_unlock(&mutex);
  printf("Producer after unlocking mutex lock\n");
  return NULL;
}

//Consumer
void *consumer(void *arg){
  pthread_mutex_lock(&mutex);
  while(counter==0)
      pthread_cond_wait(&cond, &mutex);
  printf("Consumer is preparing the dish...\n");
  sleep(3);
  counter=0;
  pthread_mutex_unlock(&mutex);
}

int main(){
  pthread_t producer_thread_id, consumer_thread_id, consumer_thread_id2;
  pthread_create(&producer_thread_id, NULL, producer, NULL);
  pthread_create(&consumer_thread_id, NULL, consumer, NULL);
  pthread_create(&consumer_thread_id2, NULL, consumer, NULL);

  pthread_join(producer_thread_id, NULL);
  pthread_join(consumer_thread_id, NULL);
  pthread_join(consumer_thread_id2, NULL);
  return 0;
}
