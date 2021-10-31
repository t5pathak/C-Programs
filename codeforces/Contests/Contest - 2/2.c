#include<stdio.h>
int main (void)
{
	int n;
	scanf("%d",&n);

	int arr[n];
	for ( int i=0; i<=(n-1); i++)
	{
		scanf("%d",&arr[i]);
//		if ( arr[i] == 1 )
//		{
//			arr[i] = 0;
//		}
	}

	int max = 0;
	for (int i=0; i<=(n-1); i++)
	{
		if ( arr[i] > max )
		{
			max = arr[i];
		}
	}

	int div_1 = max;

	for (int i=0; i<=(n-1); i++)
	{
		if ( arr[i] == 1 )
		{
			arr[i] = 0;
		}
	}

	for (int i=1; i<=(max/2+1); i++)
	{
		if ( max % i == 0 )
		{
			int temp = max / i;
			for (int j=0; j<=(n-1); j++)
			{
				if ( arr[j] == temp )
				{
					arr[j] = 0;
					break;
				}
				
//				for (int k=0; k<=(n-1); k++)
//				{
//					printf("%d ",arr[k]);
//				}
//				printf("\n");
			}
		}
	}

	int div_2;
	int max_2 = 0;
	for ( int i=0; i<=(n-1); i++)
	{
		if ( arr[i] > max_2 )
		{
			max_2 = arr[i];
		}
	}
	div_2 = max_2;
	if ( div_2  == 0 )
	{
		div_2 = 1;
	}
	printf("%d %d\n",div_1,div_2);
}
