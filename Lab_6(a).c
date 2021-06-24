#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
int main()
{
 pid_t pid = fork();
if(pid == 0){
printf("fork executed successfully: This is Child process with PID: %d \n", getpid());
printf("This is Child process. My Parent PID: %d \n", getppid());
}
else if(pid>0)
{
wait(NULL);
printf("I am Parent process with PID : %d \n", getpid());
 
}
return 0;
}