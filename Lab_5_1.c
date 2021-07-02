#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <stdio.h>

#define BUF_SIZE 5
#define MAXINT 50
int b[BUF_SIZE];
int in = 0, out = 0;

pthread_t consumer;
pthread_t producer;

void * consumer_body (void *arg) {

  int tmp;
  int self = *((int *) arg);

  printf("consumer thread starts\n"); 
  for (int i=0;i<MAXINT;i++) {
      while (out == in);
      tmp = b[out];
      out = (out + 1) % BUF_SIZE;     
      printf("\nConsumer removed %d from buffer at index %d",b[out],out);
  }
  printf("\nconsumer thread exits\n"); 
  return NULL;
}

void * producer_body (void * arg) {
   int i;
   printf("producer thread starts\n"); 
   for (i = 0; i < MAXINT; i++) {
     while (((in + 1) % BUF_SIZE) == out);
     b[in] = i;
     in = (in + 1) % BUF_SIZE;     
     printf("\nProducer inserted %d into buffer at index %d",b[in],in);
  }
  printf("\nProducer thread exits\n"); 
  return NULL;
}
int a=0;
int main () 
{
   pthread_attr_t attrs;
   pthread_attr_init (&attrs);
   pthread_create (&producer, &attrs,producer_body,(void*)&a);
   pthread_create (&consumer,&attrs,consumer_body,(void*)&a) ;
   pthread_exit(NULL);
   return 0;
}