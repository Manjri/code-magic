#include <stdio.h>

int test_and_set(int *flag)
{
    int val = *flag;
    *flag = 1;
    return val;
}

typedef struct lock{
    int held;
}lock;

lock l;

void task1_release(void)
{
    l.held = 0;
    return;
}

void task2_release(void)
{
    l.held = 0;
    return;
}

void task1_run(void)
{
    // grab lock
    test_and_set(&l.held);
    // do stuff
    task1_release();
    return;
}

void task2_run(void)
{
    // grab lock
    test_and_set(&l.held);
    // do stuff
    task2_release();
    return;
}

int main()
{
    int num = 4096;
    //enum {KEYWORD = 01, EXTERNAL = 02, STATIC = 04};
    //enum color {RED, BLUE};
    //typedef enum color {RED, BLUE} color;
    //color c;
    //c = RED;
    printf("%d >> 10: %d", num, num>>10);
    
#if 0
    // init it
    l.held = 0;

    task1_run();
    task2_run();
#endif

    return 0;

    
    
}