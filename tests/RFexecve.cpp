#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	int a,b,c=1;
	scanf("%d %d",&a,&b);
	printf("%d\n",a+b);
	char *execve_str[]={"env",NULL};
	char *env[]={"PATH=/tmp","USER=lei","STATUS=testing",NULL};
	if(execve("/usr/bin/env",execve_str,env)<0)
	{
		c=2;
	}
	return 0;
}
