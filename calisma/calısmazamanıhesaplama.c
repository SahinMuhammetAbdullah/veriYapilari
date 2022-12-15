#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char const *argv[])
{
	clock_t startTime, endTime;
	startTime = clock();



	endTime = clock();
	printf("%f",((float)(endTime-startTime)/CLOCKS_PER_SEC));
	return 0;
}