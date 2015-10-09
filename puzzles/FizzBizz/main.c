/*
Write a program that prints the numbers from 1 to 100. 
But for multiples of three print "Fizz" instead of the 
number and for the multiples of five print "Buzz". 
For numbers which are multiples of both three and 
five print "FizzBuzz". 
*/

#include <stdio.h>


int main(void){

	int i=1;
	int flag = 0;

	for(i = 1; i<=100; i++)
	{

		if (i%3 == 0)
		{
			printf("Fizz");
			flag = 1;
		}
		if (i%5 == 0)
		{
			printf("Buzz");
			flag = 1;
		}
		if (flag == 0)
			printf("%d", i);

		printf("\n");
		flag = 0;
	}

	return 0;
}
