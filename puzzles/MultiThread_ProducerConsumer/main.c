// Producer-Consumer with condition variables
/*

char buffer[SIZE] //shared data
int count = 0, head = 0, tail = 0;
struct lock l;
struct condition notEmpty;
struct condition notFull;

// inits
lock_init(&l);
condition_init(&notEmpty);
condition_init(&notFull);

//PRODUCER
void putChar(char c){

    lock_acquire(&l);
    while(count==SIZE){
        condition_wait(&notFull, &l);
    }
    count++;
    buffer[head] = c;
    head = (head+1)%SIZE;
    condition_signal(&notEmpty, &l);
    lock_release(&l);
}

//CONSUMER
char getchar(){
    char c;
    lock_acquire(&l);
    while(count==0){
        condition_wait(&notEmpty, &l);
    }   
    count--;
    c = buffer[tail];
    tail = (tail+1)%SIZE;
    condition_signal(&notFull, &l);
    lock_release(&l);
    return c;
}











*/



