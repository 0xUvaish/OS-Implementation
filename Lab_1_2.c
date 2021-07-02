#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

static char *oldpath = "./2.c";
static char *newpath = "./newf/2.c";

int main()
{
int fd;
fd = link(oldpath, newpath);

if(fd!=-1)
printf("File path has been updated to %s", newpath);
else
printf("Error in linking file path");
exit(0);
}