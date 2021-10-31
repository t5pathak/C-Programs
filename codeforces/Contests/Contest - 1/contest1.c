#include<stdio.h>
int main(void)
{
	int n;
	scanf("%d",&n);

	int min_count = n;

	for (int i=2; i<=(n); i++)
	{
		int count = 0;
		if ( n % i == 0 && n / i <= 9 )
		{
			count = i;
			if ( count <= min_count )
			{
				min_count = count;
			}	
		}	
	}
	printf("%d\n",min_count);
	int no = n / min_count ; 
	for (int i=1; i<=(min_count); i++)
	{
		printf("%d ",no);
	}
	printf("\n");
}
