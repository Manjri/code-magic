#include <stdio.h>
#include <time.h>

int main()
{	
	struct tm now;
	now.tm_sec = 0;
	now.tm_min = 0;
	now.tm_hour = 14;
	now.tm_mday = 26;
	now.tm_mon = 1;
	now.tm_year = 116;

	printf("%ld seconds since epoch\n", mktime(&now));
	time_t since_epoch = mktime(&now);
	printf("%s\n", asctime(gmtime(&since_epoch)));

	return 0;
}
