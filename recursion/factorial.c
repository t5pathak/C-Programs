#include<stdio.h>
int factorial (int x)
{
	if ( x == 0 )
	{
		return 1;
	}
	else 
	{
		return  x * factorial (x-1);
	}
}
int main (void)
{
	int x;
	scanf("%d",&x);
	int ans = factorial(x);
	printf("%d",ans);
	return 0;

}
