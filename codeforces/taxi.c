#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int n;
	scanf("%d",&n);

	int arr[n];
	int count_arr[5] = {0};

	for (int i=0; i<=(n-1); i++)
	{
		scanf("%d",&arr[i]);

		if ( arr[i] == 4)
		{
			count_arr[4]++;
		}

		else if ( arr[i] == 3)
		{
			count_arr[3]++;
		}

		else if ( arr[i] == 2)
		{
			count_arr[2]++;
		}

		else if ( arr[i] == 1)
		{
			count_arr[1]++;
		}
	}

	int count_taxi = 0;

	count_taxi = count_taxi + ( count_arr[4] ); // add the number of groups having size = 4 without any operation
	count_arr[4] = 0;

	count_taxi = count_taxi + ( count_arr[2] / 2);
	count_arr[2] = count_arr[2] % 2;

	int min = 0;
	if ( count_arr[3] < count_arr[1] )
	{
		min = count_arr[3];
	}
	else
	{
		min = count_arr[1];
	}
	count_taxi = count_taxi + min;
	count_arr[1] = count_arr[1] - min;
	count_arr[3] = count_arr[3] - min;

	if ( count_arr[1] == 0)
	{
		count_taxi = count_taxi + ( count_arr[2] + count_arr[3] );
	}

	else
	{
		count_taxi = count_taxi + count_arr[1] / 4;
		count_arr[1] = count_arr[1] % 4;
		if ( count_arr[2] == 1 )
		{
			if ( count_arr[1] <= 2)
			{
				count_taxi++;
			}
			else
			{
				count_taxi = count_taxi + 2;
			}
		}
		else
		{
			if (count_arr[1] != 0 )
			{
				count_taxi++;
			}
		}
	}
	printf("%d\n",count_taxi);
}
