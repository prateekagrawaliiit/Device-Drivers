/*
* @Author: Prateek Agrawal
* @Date:   2022-03-30 09:30:54
* @Last Modified by:   Prateek Agrawal
* @Last Modified time: 2022-03-30 09:35:32
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define WR_VALUE _IOW('a','a', int32_t*)
#define RD_VALUE _IOR('a','b', int32_t*)

int main()
{
	int fileDescriptor;
	int32_t val, num;
	printf("\nOpening a driver\n");
	fileDescriptor = open("/dev/random", O_RDWR);
	if (fileDescriptor < 0)
	{
		printf("Error");
		return 0;
	}
	printf("Enter value you want to send\n");
	scanf("%d", &num);
	printf("Writing\n");
	ioctl(fileDescriptor, WR_VALUE, (int32_t*)&num);
	printf("Reading value\n");
	ioctl(fileDescriptor, RD_VALUE, (int32_t*)&val);
	printf("The value is %d\n", val);
	close(fileDescriptor);
	return 0;
}
