#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

uint32_t convertIPAddr(char* addr){
	uint32_t result = 0;
	uint32_t byte[4] = {0};
	char* temp;
	uint32_t byteVal = 0;
	int count = 0;
	int i = 0;


	for(temp=addr;*temp;temp++){
		char tempChar = *temp;
		if(tempChar == '.'){
			// stop
			byte[count++] = byteVal;
			byteVal = 0;
		}
		else
			byteVal = 10*byteVal + (tempChar - '0');
	}
	byte[count] = byteVal;

	result = (byte[0]<<24 | byte[1]<<16
						| byte[2]<<8 | byte[3]);

	return result;
}


int main(){

	char *ipaddr = "255.255.255.255";
	//char *ipaddr = "127.0.0.0";
	uint32_t result = convertIPAddr(ipaddr);
	printf("%u\n",result);
	return 0;
}
