#include<stdio.h>
//why codeforces be so stupid

int main(void)
{
	int n,m;
	scanf("%d %d",&n,&m);

	int arr[m+1];

	arr[0] = 1;

	for (int i=0; i<=(m-1); i++)
	{
		scanf("%d",&arr[i]);
	}
	
	int counter = 0;

	for (int i=0; i<=(m-1); i++)
	{
		int diff = 0;

		diff = ( arr[i+1] - arr[i] );

		if ( diff < 0 )
		{
			diff = n + diff;
		}

		counter = counter + diff;
	}

	printf("%d\n",counter);
}
