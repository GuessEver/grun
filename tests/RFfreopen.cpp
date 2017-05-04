#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a,b,c=1;
	if(freopen("file.txt","w",stdout)==NULL)
		c=-1;
    scanf("%d %d",&a,&b);
    printf("%d\n",a+b+1);
    return 0;
}
