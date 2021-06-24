#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
 
int main()
{
int n;
printf("Enter no of Child Process to create: ");
scanf("%d", &n);
for(int i=1; i<=n;i++)
{
 pid_t pid = fork();
if(pid == 0)
{
printf("fork executed successfully: This is Child process with PID: %d \n", getpid());
printf("This is Child process. My Parent PID: %d \n", getppid());
break;
}
else if(pid>0)
{
wait(NULL);
printf("\nI am Parent process with PID : %d \n\n", getpid()); 
}
}
return 0;
}