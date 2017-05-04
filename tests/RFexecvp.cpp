#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	int a,b,c=1;
	scanf("%d %d",&a,&b);
	printf("%d\n",a+b);
	char *execvp_str[]={"echo","executed by execvp",">>","~/abc.txt",NULL};
    if(execvp("echo",execvp_str)<0)
	{
		c=2;
	}
	return 0;
}
