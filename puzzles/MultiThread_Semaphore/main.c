// gcc -o main main.c -Wall -Werror -lpthread

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

// prototype for thread routine
void handler(void* ptr);

// global vars
sem_t mutex;
int counter;	// shared variable

int main()
{
	int i[2];
	pthread_t thread_a;
	pthread_t thread_b;

	//args to threads
	i[0] = 0;
	i[1] = 1;

	// init mutex to 1 - binary semaphore
	// second param=0 - local semaphore
	sem_init(&mutex, 0, 1);

	pthread_create(&thread_a, NULL, (void*)&handler, (void*)&i[0]);
	pthread_create(&thread_b, NULL, (void*)&handler, (void*)&i[1]);

	pthread_join(thread_a, NULL);
	pthread_join(thread_b, NULL);

	// destroy semaphore
	sem_destroy(&mutex);

	exit(0);
}

void handler(void* ptr)
{
	int x;
	x = *((int*)ptr);

	printf("Thread %d: Waiting to enter critical region\n",x);
	// down-semaphore
	sem_wait(&mutex);
	//start critical region
	printf("Thread %d: Now in Critical Region\n",x);
	printf("Thread %d: Counter Value: %d\n",x,counter);
	printf("Thread %d: Incrementing Counter...\n",x);
	counter++;
	printf("Thread %d: New Counter Value: %d\n",x,counter);
	printf("Thread %d: Exiting critical region\n",x);
	//end critical region
	sem_post(&mutex);

	pthread_exit(0);	//exit thread
}


