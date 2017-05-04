#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	int c=1;
	char * arg[]={"echo", "executed_bu_execv",NULL};
	if(execv("/usr/bin/echo",arg)<0)
	{
		c=2;
	}
	int a,b;
	scanf("%d %d",&a,&b);
	printf("%d\n",a+b);
	return 0;
}
