#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	int a,b,c=1;
	scanf("%d %d",&a,&b);
	printf("%d\n",a+b);
	char * env[]={"PATH=/home/document","USER=lei","STATUS=testing",NULL};
	if(execle("/usr/bin/env","executed by execl",NULL,env)<0)
	{
		c=2;
	}
	return 0;
}
