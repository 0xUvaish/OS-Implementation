#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include<time.h>
#include<sys/wait.h>
#include<signal.h>
#define MaxItems 5
#define BufferSize 5
time_t t;

volatile int count;

volatile int buffer[BufferSize];

pthread_t con;
pthread_t prod;


void *producer(void *pno)
{
	int item;
	while(1)
	{
		
		if(count == BufferSize)
		{
			printf("\nProducer paused");
			pause();
			//wait(NULL);
		}
		item = rand();

		buffer[count] = item;
		printf("\nProducer Inserted Item %d at %d\n",buffer[count],count);
		count = (count+1);
		count%=BufferSize;
		
		if(count>=1) {
			printf("\ncalling Consumer");
			pthread_kill(con,0);
		}
		
	}
}
void *consumer(void *cno)
{
	while(1)
	{
		printf("consumer count=%d",count);
		if(count == 0) 
		{
			printf("\nConsumer paused");
			pause();
		}
		int item = buffer[count];
		printf("\nConsumer Removed Item %d from %d\n",item,count);
		count = (count-1)%BufferSize;
		if(count < BufferSize-1) 
		{
			printf("\ncalling Producer");
			pthread_kill(prod,0);
		}
	}
}
int a=0;
int main () {
   t =time(NULL)+0.005;
   pthread_create(&prod, NULL, (void *)producer,(void*)&a);
   pthread_create(&con,NULL,(void *)consumer,(void*)&a);
   pthread_exit(NULL);
   

   return 0; 
}