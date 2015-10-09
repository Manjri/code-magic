
// this implementation stores (max_size - 1) to detect the difference between
// empty and full queue

#include <stdio.h>

unsigned int max_size = 3;  // will hold only 2 elements at the max
unsigned int count = 0;

char arr[3] = {'0', '0', '0'};

int readPos = 0;
int writePos = 0;


void add_elem(char c)
{
    if( readPos == ((writePos + 1) % max_size) )
    {
        printf("\nAdding %c, fail! Queue Full!",c);
        return;
    }
    printf("\nAdding %c in queue...",c);
    arr[writePos] = c;
    writePos = (writePos + 1) % max_size;
}

char remove_elem(void)
{
    if(readPos == writePos)
    {
        printf("\nQueue Empty!");
        return NULL;
    }
    
    char temp;
    
    temp = arr[readPos];
    arr[readPos] = '0';
    readPos = (readPos + 1) % max_size;
    
    return temp;
}

void print_arr()
{
    int i;
    
    printf("\nPrinting Queue..");
    
    for(i=0; i<max_size; i++)
        printf("%c ", arr[i]);
    
    printf("\n");
}

// To execute C, please define "int main()"

int main() {
    add_elem('a');
    add_elem('b');
    add_elem('c');
    print_arr();
    printf("\nRemoved Elem: %c",remove_elem());
    printf("\nRemoved Elem: %c",remove_elem());
    add_elem('d');
    print_arr();
    add_elem('e');
    print_arr();
    add_elem('f');
    print_arr();
    return 0;
}
