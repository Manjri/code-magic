//
//  main.c
//  LibC
//
//  Created by Nikhil Jagdale on 4/12/16.
//  Copyright © 2016 Nikhil Jagdale. All rights reserved.
//

#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>

#define BIT(n) (1<<n)
#define BITS(n) (BIT(n)-1)
#define BIT_EXTRACT(n, start) (BITS(n)<<(start))

void replicateBits(unsigned char x, unsigned char y,
                   unsigned char i, unsigned char j){

    printf("x: %x\n",x);
    printf("y: %x\n",y);
    unsigned char mask = y & BIT_EXTRACT((i-j+1), j);
    printf("Mask: %x\n",mask);
    unsigned char high = x & BIT_EXTRACT((CHAR_BIT-i+1), i+1);
    printf("High: %x\n",high);
    unsigned char low = x & BIT_EXTRACT(j, 0);
    printf("Low: %x\n",low);
    x = (high | mask | low);
    printf("x: %x\n",x);
}

void testReplicateBits(){
    unsigned char x = 0b11001110;    //0xce->0xbe
    //unsigned char y = 0b11111111;    //0xff
    unsigned char y = 0b00111111;    //0xff
    replicateBits(x, y, 6, 4);
}

uint32_t swapEndian(uint32_t x){
    
    uint8_t x1 = x & 0xFF;
    uint8_t x2 = (x >> 8) & 0xFF;
    uint8_t x3 = (x >> 16) & 0xFF;
    uint8_t x4 = (x >> 24) & 0xFF;
  
    return (uint32_t)((x1<<24) | (x2<<16) | (x3<<8) | x4);
}

void reverseString(char *string, size_t start, size_t end){
    char *start_pos = string + start;
    char *end_pos = string + end;
    while(start_pos < end_pos){
        char temp = *start_pos;
        *start_pos = *end_pos;
        *end_pos = temp;
        start_pos++;
        end_pos--;
    }
}

void reverseWords(char *string){
    
    size_t count = 0;
    int i;
    // reverse the whole word!
    reverseString(string, 0, strlen(string)-1);
    
    //now parse the string and stop at space
    //reverse this word individually!
    for(i=0; i<strlen(string); i++){
        
        if(string[i]!=' '){
            continue;
        }
        reverseString(string, count, i-1);
        count = i+1;    // the next position after space
    }
    // we need to take care of reversing the last word
    // OR if this was the only word!
    reverseString(string, count, i-1);
    
}

void test_reverse(){
    char str[] = "Hello World!";
    printf("Before: %s\n",str);
    //reverseString(str, 0, strlen(str)-1);
    reverseWords(str);
    printf("After: %s\n",str);
    
}

void test_printf(){
    
    int i=1;
    printf("%d %d",i);
    
}

void test_fork(){
    
    int a = 1;
    
    if (fork() == 0)
    {
        a = a + 5;
        printf("Child: %d %p\n", a, &a);
    }
    else
    {
        a = a - 5;
        printf("Parnet: %d %p\n", a, &a);
    }
}


/**
 char * strncpy ( char * destination, const char * source, size_t num )
 
 Copies the first num characters of source to destination. If the end of the 
 source C string (which is signaled by a null-character) is found before num 
 characters have been copied, destination is padded with zeros until a total of 
 num characters have been written to it.
*/

char* mystrncpy(char *dest, char *source, size_t num){
    
    // while there are still characters left!
    while(num && dest && source){
        
        if(*source){
            *dest = *source;
            source++;
        }else{
            *dest = '\0';
        }
        dest++;
        num--;
    }
    return dest;
}


void test_mystrncpy(){
    
    char s[5] = "abcd";
    char d[5];
    
    printf("Src: %s Dest: %s\n", s, mystrncpy(d,s,5));
    (0 == strcmp(s, d)) ? printf("Passed!\n") : printf("Failed\n");
    
}


double myPow(double x, int n) {
        if(n == 0)
            return 1;
        if(n<0){
            n = -n;
            x = 1/x;
        }
        return (n%2 == 0) ? myPow(x*x, n/2) : x*myPow(x*x, n/2);
}

void ifTest(){
    
    int x = -1;
    
    if(x){
        printf("Inside if.. %d\n",x);
    }else{
        printf("Inside else.. %d\n",x);
    }
    
}

/**
 swap every two bits in an unsigned char .. 
 eg swap bits at 0 and 1st position, swap 2nd and 3rd position, 
 swap 4th and 5th position etc ..
 */
void swapBits(unsigned char x){
    // i/p x = 01100110
    // o/p   = 10011001
    
    unsigned char twoBits, highBit, lowBit, mask;
    int i = 0;
    printf("Input: %x\n", x);
    while(i<8){
        // first take 2 bits at a time by masking with 0x3
        twoBits = (x & BIT_EXTRACT(2,i))>>i;
        highBit = (twoBits&2)>>1;
        lowBit = (twoBits&1);
        mask = (lowBit<<1 | highBit)<<i;
        //first clear the positions
        x &= ~(3<<i);
        x |= mask;
        i+=2;
    }
    printf("SwapBits Output: %x\n", x);
}

void swapBits1(unsigned char x){
    //understand the order of evaluation
    //unsigned char result = (((x & 0xAA)>>1) | ((x & 0x55)<<1));
    unsigned char result = (((x & 0x55)<<1) | ((x & 0xAA)>>1));
    printf("SwapBits 1 Output: %x\n", result);
}



void reverseCharBits(unsigned char x){
    printf("Input: %x\n", x);
    
    // this is specifically for 8 bits
    x = (((x&0xf0)>>4) | ((x&0xf)<<4));
    x = (((x&0xcc)>>2) | ((x&0x33)<<2));
    x = (((x&0xaa)>>1) | ((x&0x55)<<1));
    
    printf("Reverse Output: %x\n", x);
}

void printSetBitsParallel(uint32_t v){

    uint32_t c = 0;
    // I want to break this down!
    uint32_t temp1, temp2;
    temp1 = v >> 1;
    printf("v is: %x\n",v);         //debug
    printf("v >> 1 is: %x\n",temp1);         //debug
    temp2 =temp1&0x55555555;
    printf("(v>>1)&0x55555555 is: %x\n",temp2);         //debug
    v = v - ((v>>1)&0x55555555);    //reuse input as temp
    printf("v is: %x\n",v);         //debug
    temp1 = v & 0x33333333;
    printf("v & 0x33333333; is: %x\n",temp1);         //debug
    temp2 = (v>>2);
    printf("v>>2 is: %x\n",temp2);         //debug
    temp2 = ((v>>2)&0x33333333);
    printf("(v>>2)&0x33333333) is: %x\n",temp2);         //debug
    v = (v & 0x33333333) + ((v>>2)&0x33333333); //temp
    printf("v is: %x\n",v);         //debug
    c = ((v + (v>>4)&0x0f0f0f0f)*0x01010101) >> 24; //count
    printf("Count is: %d\n",c);
}

void run_tests(){
    
    //test_fork();
    //test_mystrncpy();
    //test_reverse();
    //testReplicateBits();
    //printf("%lf\n",myPow(2, 4));
    //test_printf();
    //ifTest();
    //swapBits(0x66);
    //swapBits1(0x66);
    //reverseCharBits(0x20);  // 0010 0000 ==> 0000 0100 ==> 0x04
    //reverseCharBits(0xAC);  // 1010 1100 ==> 0011 0101 ==> 0x35
    printSetBitsParallel(0xAAAAAAAA); // 8 As => 8*2 = 16
    //printSetBitsParallel(0xFFFFFFFF); // 8 Fs => 8*4 = 32
}







int main(int argc, const char * argv[]) {
    
    //uint32_t word = 0x12345678;
    //printf("Before: %08X\tAfter: %08X\n", word, swapEndian(word));
    run_tests();
    return 0;
}
