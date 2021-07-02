#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

static char *path = "./newf/2.c";

int main()
{
int fd;
fd = unlink(path);

if(fd!=-1)
printf("File path has %s has been deleted", path);
else
printf("Error in unlinking file path");
exit(0);
}