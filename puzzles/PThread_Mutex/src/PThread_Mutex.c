/*
 ============================================================================
 Name        : PThread_Mutex.c
 Author      : Nikhil Jagdale
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t count_mutex;
long long count;

void increment_count()
{
	pthread_mutex_lock(&count_mutex);
	count = count + 1;
	pthread_mutex_unlock(&count_mutex);
}

long long get_count()
{
	long long c;

	pthread_mutex_lock(&count_mutex);
	c = count;
	pthread_mutex_unlock(&count_mutex);
	return (c);
}


int main(void)
{
	puts(""); /* prints  */
	return EXIT_SUCCESS;
}
