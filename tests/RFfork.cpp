#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	printf("%d\n",a+b);
	fork();
	a=b;
	b=2;
	//printf("hello world\n");
	return 0;
}
