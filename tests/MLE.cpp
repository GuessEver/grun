#include <stdio.h>
#include <stdlib.h>
int c[100000000];
int main()
{
    int a,b,i,j,k=1,m=2;
    scanf("%d %d",&a,&b);
    for(i=0;i<100000000;i++)
    c[i]=i;
    printf("%d\n",a+b);
    return 0;
}
