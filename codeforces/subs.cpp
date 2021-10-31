#include<iostream>
using namespace std;

int main()
{
	unsigned long long int n,x,y;
	scanf("%llu %llu %llu",&n,&x,&y);
	
	unsigned long long int no;
	scanf("%llu",&no);

	long long int arr[n];
	
	long long int index = n;

	for ( int i=1; i<=n; i++)
	{
		index = index - 1;
		arr[index] = no % 10;
		no = no / 10;
	}
	
/*	for ( int i=0; i<=(n-1); i++)
	{
		printf("%lld ",arr[i] );
	}
	printf("\n");*/
	
	int changes = 0;
	
	long long int rev_arr[n];
	for (int i=0; i<=(n-1); i++)
	{
		rev_arr[i] = arr[n-1-i];
	}
	
	for ( int i=0; i<=(n-1); i++)
	{
		printf("%lld ",rev_arr[i]);
	}
	printf("\n");
	
	if ( rev_arr[y] == 0 )
	{
		rev_arr[y] = 1;
		changes++;
	}

	for ( int i=0; i<=(x-1); i++)
	{
		if ( rev_arr[i] == 1 && i != (y) )
		{
			rev_arr[i] = 0;
			changes++;
		}
	}
/*	for ( int i=0; i<=(n-1); i++)
	{
		printf("%lld ",rev_arr[i] );
	}
	printf("\n");*/
	printf("%d\n",changes);
}
