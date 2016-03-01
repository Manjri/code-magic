//http://www.cise.ufl.edu/~cop4600/cgi-bin/lxr/http/source.cgi/lib/ansi/gmtime.c#L16

#include <stdio.h>
#define YEAR0						1900
#define SECS_DAY				(24L * 60L * 60L)
#define LEAPYEAR(year)	(!((year)%4)&&(((year)%100)||!((year)%400)))	
#define YEARSIZE(year)	(LEAPYEAR(year)?366:365)
#define EPOCH_YR				1970

const int ytab[2][12] = {
													{31,28,31,30,31,30,31,31,30,31,30,31},
													{31,29,31,30,31,30,31,31,30,31,30,31}
												};

const char* DAY_NAMES[7] = {"Sunday", "Monday", "Tuesday", "Wednesday"
														"Thursday", "Friday", "Saturday"};

long getSecondsSinceEpoch(int h, int m, int s, int day, int month, int year){
    int i,leapDays;
    long days;
    long seconds;

    const static int DAYS_IN_MONTH[] = {31, 28, 31, 30, 31, 
																				30, 31, 31, 30, 31, 30, 31};

    leapDays = 0;
    days = (year - 1970) * 365;

    for (i = year; i>1970; i--){
        if ((i%4)==0) {
            leapDays++;
        }
    }
    days += leapDays;
    for (i = 1;i < month;i++) {
        days += DAYS_IN_MONTH[i - 1];
    }
    days += (day-2);
    seconds = days * 86400;

    seconds += (h * 3600);
    seconds += (m * 60);
    seconds += s;

    return seconds;
}

void getTimeFromEpoch(long seconds){

	int year = EPOCH_YR;
	long dayclock = seconds % SECS_DAY;
	long dayno = seconds / SECS_DAY;
	long mon = 0;		//months since Jan [0,11]
	long mday = 1;	//dayof the month [1,31]
	long secs = 0;	//seconds after the min [0,60]
	long min = 0;		//mins of the day [0,59]
	long hour = 0;	//hours since midnight [0,23]
	long wday = 0;	//days since Sunday [0,6]

	secs = dayclock%60;
	min = (dayclock%3600)/60;
	hour = (dayclock/3600);
	wday = (dayno + 4) % 7;	// day 0 was Thursday
	

	printf("Input Seconds: %ld\n",seconds);
	printf("Dayclock: %ld\n",dayclock);
	printf("Dayno: %ld\n",dayno);
	printf("Secs: %ld\n",secs);
	printf("Mins: %ld\n",min);
	printf("Hour: %ld\n",hour);

	while(dayno >= YEARSIZE(year)){
		dayno -= YEARSIZE(year);
		year++;
	}
	year = year - YEAR0;
	while(dayno >= ytab[LEAPYEAR(year)][mon]){
		dayno -= ytab[LEAPYEAR(year)][mon];
		mon++;
	}
	mday = dayno+1;
	printf("Day = %ld\n",mday);
	printf("Mon = %ld\n",mon+1);
	printf("Year = %d\n",year+1900);
	printf("Weekday = %s\n",DAY_NAMES[wday]);
}

int main(){

	long seconds = getSecondsSinceEpoch(14,52,0,29,2,2016);
	printf("%ld\n", seconds);
	getTimeFromEpoch(seconds);
	return 0;
}

