#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
 
int main(int argc, char *argv[])
{

int n;
printf("Enter no of Child Process to create: ");
scanf("%d", &n);
for(int i=1;i<=n;i++)
{
pid_t pid = fork();
if(pid==0)
{
printf("\nChild PID: %d \n", (int) getpid());
execlp(argv[1],"arguments",NULL);
break;
}

else if (pid>0)
{
wait(NULL);
//printf("Parent resumes from there");
printf("Parent PID: %d \n", (int) getpid());
execl(argv[2],"some arguments",NULL);
}
}

return 0;
}