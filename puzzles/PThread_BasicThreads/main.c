#include <stdio.h>
#include <pthread.h>

/**
int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                          void *(*start_routine) (void *), void *arg)
Compile and link with -pthread.
*/


void* entry_point(void* arg){
    printf("Hello World\n");
    return NULL;
}

int main(int argc, char **argv){
    
    pthread_t thr;
    if(pthread_create(&thr, NULL, &entry_point, NULL)){
        //non-zero value means it failed!
        printf("Couldn't create threads\n");
        return -1;
    }
    if(pthread_join(thr, NULL)){
        printf("Couldn't join thread\n");
        return -1;
    }
    return 0;
}
