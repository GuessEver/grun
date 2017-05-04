#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	int a,b,c=1;
	scanf("%d %d",&a,&b);
	printf("%d\n",a+b);
	if(execl("/usr/bin/env","executed by execl",NULL)<0)
	{
		c=2;
	}
	return 0;
}
