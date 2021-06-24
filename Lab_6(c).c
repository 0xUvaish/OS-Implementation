#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
 
int main(int argc, char *argv[])
{
pid_t pid = fork();
if(pid==0)
{
printf("Child PID: %d \n", (int) getpid());
execlp(argv[1],"arguments",NULL); 
}
else if (pid>0)
{
wait(NULL);
printf("Parent PID: %d \n", (int) getpid());
execl(argv[2],"some arguments",NULL);
}
return 0;
}