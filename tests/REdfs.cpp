#include<stdio.h>  
#include<stdlib.h>  

void dfs(int x) {
	dfs(x + 1);
}
int main()  
{
  	dfs(1);
	return 0;
}   
