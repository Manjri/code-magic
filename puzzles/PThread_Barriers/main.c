#include <pthread.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

#define __APPLE_BARRIERS


#ifdef __APPLE_BARRIERS

#include <unistd.h>
#define PTHREAD_BARRIER_SERIAL_THREAD 1
typedef int pthread_barrierattr_t;
typedef struct
{
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int count;
    int tripCount;
} pthread_barrier_t;


int pthread_barrier_init(pthread_barrier_t *barrier, 
            const pthread_barrierattr_t *attr, unsigned int count)
{
    if(count == 0)
    {
        errno = EINVAL;
        return -1;
    }
    if(pthread_mutex_init(&barrier->mutex, 0) < 0)
    {
        return -1;
    }
    if(pthread_cond_init(&barrier->cond, 0) < 0)
    {
        pthread_mutex_destroy(&barrier->mutex);
        return -1;
    }
    barrier->tripCount = count;
    barrier->count = 0;

    return 0;
}

int pthread_barrier_destroy(pthread_barrier_t *barrier)
{
    pthread_cond_destroy(&barrier->cond);
    pthread_mutex_destroy(&barrier->mutex);
    return 0;
}

int pthread_barrier_wait(pthread_barrier_t *barrier)
{
    pthread_mutex_lock(&barrier->mutex);
    ++(barrier->count);
    if(barrier->count >= barrier->tripCount)
    {
        barrier->count = 0;
        pthread_cond_broadcast(&barrier->cond);
        pthread_mutex_unlock(&barrier->mutex);
        return 1;
    }
    else
    {
        pthread_cond_wait(&barrier->cond, &(barrier->mutex));
        pthread_mutex_unlock(&barrier->mutex);
        return 0;
    }
}

#endif

static pthread_barrier_t barrier;

static void* threadFunc(void* arg){
    
    long threadNum = (long)arg;
    int s, nsecs;
	
		srandom(time(NULL) + threadNum);

    printf("Thead %ld started\n",threadNum);

		nsecs = random()%5 + 1;	// sleep for 1-5 seconds
		sleep(nsecs);

		printf("Thread %ld about to wait on barrier "
		          "after sleeping %d seconds\n", threadNum, nsecs);

    s = pthread_barrier_wait(&barrier);

    if(s == 0)
        printf("Thread %ld passing the the barrier with return val 0\n"                   ,threadNum); 
    else if(s == PTHREAD_BARRIER_SERIAL_THREAD){
    		printf("\n!! Thread %ld passing barrier with return value"
                    " PTHREAD_BARRIER_SERIAL_THREAD!!\n", threadNum);
    			
    		//usleep(100000);
    		printf("\n");
    }

		usleep(200000);
    printf("Thread %ld resuming!\n", threadNum);

    return NULL;
}


int main(){
    
    int numThreads = 10, s;
    pthread_t *tid;
    long threadNum;
        
    // allocate an array to hold thread ids
    tid = calloc(sizeof(pthread_t), numThreads);

    // initialize the barrier
    s = pthread_barrier_init(&barrier, NULL, numThreads);

    if(s!=0)
        printf("PThread Barrier Init failied\n");

    // create the threads now
    for(threadNum=0; threadNum<numThreads; threadNum++){
            
        s = pthread_create(&tid[threadNum], NULL, threadFunc, 
                (void*)threadNum);

        if(s!=0)
            printf("Pthread create failied\n");

    }    
		usleep(100000);
		printf("\n");

		// Wait for all threads to terminate
		for(threadNum=0; threadNum<numThreads; threadNum++){
			s = pthread_join(tid[threadNum], NULL);
		}

    return 0;
}
