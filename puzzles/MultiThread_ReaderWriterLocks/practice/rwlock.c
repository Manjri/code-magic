#include <pthread.h>

typedef struct rwlock{

    pthread_mutex_t     mutex;      /* overall lock */
    pthread_cond_t      read;       /* wait for read */
    pthread_cond_t      write;      /* wait for write */
    int                 valid;      /* set when valid */
    int                 r_active;   /* readers active */
    int                 w_active;   /* writes active */
    int                 r_wait;     /* readers waiting */
    int                 w_wait;     /* writers waiting */

} rwlock_t;

#define RWLOCK_VALID 0xfacade

// Initialize the lock DS
int rwl_init (rwlock_t *rwl){
    
    int status;

    rwl->r_active = 0;
    rwl->w_active = 0;
    rwl->r_wait = 0;
    rwl->w_wait = 0;
    
    status = pthread_mutex_init(&mutex);
    if(status != 0)
        return status;

    status = pthread_cond_init(&rwl->read, NULL);
    if(status != 0){
        // unable to create read CV, destroy the mutex
        pthread_mutex_destroy(&rwl->mutex);
        return status;
    }
    status = pthread_cond_init(&rwl->write, NULL);
    if(status != 0){
        // unable to create read CV, destroy read CV & mutex
        pthread_cond_destroy(&rwl->cond);
        pthread_mutex_destroy(&rwl->mutex);
        return status;
    }
    rwl->valid = RWLOCK_VALID;
    return 0;
}

// Lock a read-write lock for read access
int rwl_readlock(rwlock_t *rwl){

    int status;

    if(rwl->valid != RWLOCK_VALID)
        return EINVAL;
    // ensure we are alone here...
    status = pthread_mutex_lock(&rwl->mutex);
    if(status !=0)
        return status;
    // if writer is active, we go to sleep and ask to be woken up
    if(rwl->w_active){
        rwl->r_wait++;
        pthread_cleanup_push(rwl_readcleanup, (void*)rwl);
        while(rwl->w_active){   
            status = pthread_cond_wait(&rwl->read, &rwl->mutex);
            if(status!=0)
                break;
        }
        pthread_cleanup_pop(0);
        rwl->r_wait--;
    }
    if(status == 0)
        rwl->r_active++;
    pthread->mutex_unlock(&rwl->mutex);
    return status;
}   

// Unlock a read-write lock from read access
int rwl_readunlock(rwlock_t *rwl){
    
    int status, status2;
    if(rwl->valid != RWLOCK_VALID)
        return EINVAL;
    // ensure we are alone here...
    status = pthread_mutex_lock(&rwl->mutex);
    if(status !=0)
        return status;
    rwl->r_active--;
    if(rwl->r_active == 0 && rwl->w_wait > 0)
        status = pthread_cond_signal(&rwl->write);
    
    status2 = pthread_mutex_unlock(&rwl->mutex);
    return (status2 == 0 ? status : status2);
}

// Lock a read-write lock for write access
int rwl_writelock(rwlock_t *rwl){

    int status;
    if(rwl->valid != RWLOCK_VALID)
        return EINVAL;
    // ensure we are alone here...
    status = pthread_mutex_lock(&rwl->mutex);
    if(status !=0)
        return status;
    // we want an exclusive lock! - wake us up when ready
    if(rwl->w_active || rwl->r_active){
        rwl->w_wait++;
        pthread_cleanup_push(rwl_writecleanup, (void*)rwl);
        while(rwl->w_active || rwl->r_active){
            status = pthread_cond_wait(&rwl->read, &rwl->mutex);
            if(status !=0)
                break;
        }
        pthread_cleanup_pop(0);
        rwl->w_wait--;
    }
    if(status == 0)
        rwl->w_active = 1;
    pthread_mutex_unlock(&rwl->mutex);
    return status;
}

// Unlock a read-write lock form write access
int rwl_writeunlock(rwlock_t *rwl){

    int status;
    if(rwl->valid != RWLOCK_VALID)
        return EINVAL;
    // ensure we are alone here...
    status = pthread_mutex_lock(&rwl->mutex);
    if(status !=0)
        return status;
    rwl->w_active = 0;
    if(rwl->r_wait){
        status = pthread_cond_broadcast(&rwl->read);
        if(status != 0){
            pthread_mutex_unlock(&rwl->mutex);
            return status;
        }
    }else if(rwl->w_wait){
        status = pthread_cond_signal(&rwl->write);
        if(status != 0){
            pthread_mutex_unlock(&rwl->mutex);
            return status;
        }
    }
    status = pthread_mutex_unlock(&rwl->mutex);
    return status;
}







