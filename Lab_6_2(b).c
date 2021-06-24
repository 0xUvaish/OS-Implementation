#include<unistd.h>
int main()
{
	char *name = "/bin/bash";
	char *arg1 = "-c";
	char *arg2 = "echo Hi jojo please visit $HOSTNAME:$PORT using Firefox";
	char *const env[] = {"HOSTNAME=www.bugbountyhunter.com","PORT=4473", NULL};
	execle(name,name,arg1,arg2,NULL,env);
	return 0;
}