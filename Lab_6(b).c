#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
 
int main()
{
printf("Parent PPID %d\n",getppid());
printf("I am Parent with PID : %d \n", (int) getppid());
printf("Parent going to create a child process...\n");
pid_t pid = fork();

if(pid == 0)
{
printf("fork executed successfully: Child PID: %d \n", (int) getpid());
printf("My Parent with PID : %d \n", (int) getppid());
}
else
{
wait(NULL);
printf("I am the parent, my PID %d \n",getpid()); 
}
return 0;
}