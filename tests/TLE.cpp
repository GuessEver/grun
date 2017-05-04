#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a,b,c=1;
    scanf("%d %d",&a,&b);
	while(1)
		c=-c;
    printf("%d\n",a+b+1);
    return 0;
}
