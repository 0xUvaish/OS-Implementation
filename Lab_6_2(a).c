#include<unistd.h>
int main()
{
	char *name = "ls";
	char *arg1 = "-a";
	char *arg2 = "/home/uvaish/Pictures";
	execlp(name,name,arg1,arg2,NULL);
	return 0;
}