#include<unistd.h>
int main()
{
	char *name = "/bin/bash";
	char *const arg[] = {name, "-c", "echo Hi jojo please visit $HOSTNAME:$PORT using Firefox", NULL};
	char *const env[] = {"HOSTNAME=www.bugbountyhunter.com","PORT=4473", NULL};
	execve(name,arg,env);
	return 0;
}