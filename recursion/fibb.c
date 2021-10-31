#include<stdio.h>
int fibb (int n)
{
	if ( n == 1)
	{
		return 1;
	}
	else if ( n == 2 )
	{
		return 1;
	}
	else 
	{
		return fibb (n-1) + fibb (n-2);
	}
}
int main(void)
{
	int x;
	scanf("%d",&x);
	int ans = fibb(x);
	printf("%d",ans);
	return 0;
}
