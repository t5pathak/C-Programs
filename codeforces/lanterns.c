#include<stdio.h>
void merge(int arr[], int left[], int left_size, int right[], int right_size)
{
	int i=0;
	int j=0;
	int k=0;

	while ( i < left_size && j < right_size )
	{
		if ( left[i] < right[j] )
		{
			arr[k] = left[i];
			k++;
			i++;
		}
		else
		{
			arr[k] = right[j];
			k++;
			j++;
		}
	}
	while ( i < left_size )
	{
		arr[k] = left[i];
		k++;
		i++;
	}
	while ( j < right_size )
	{
		arr[k] = right[j];
		k++;
		j++;
	}
}
void merge_sort(int arr[], int n)
{
	if ( n < 2 )
	{
		return;
	}
	int mid = n/2;
	int left[mid];
	int right[n - mid];

	for (int i=0; i<=(mid-1); i++)
	{
		left[i] = arr[i];
	}

	for (int i=mid; i<=(n-1); i++)
	{
		right[i - mid] = arr[i];
	}
	merge_sort(left,mid);
	merge_sort(right,(n-mid));
	merge(arr,left,mid,right,n-mid);
}
int main(void)
{
	int n, l;
	scanf("%d %d",&n,&l);

	int arr[n];


	for (int i=0; i<=(n-1); i++)
	{
		scanf("%d",&arr[i]);
	}

	merge_sort(arr,n+2);

	float max_diff = 0.0;
	int max_loc = 0;
	
	for (int i=0; i<=(n-1); i++)
	{
		int diff = 0;
		diff = (arr[i+1] - arr[i]);
		if ( diff > max_diff )
		{
			max_diff = diff;
			max_loc = i;
		}
	}
	if ( max_loc == 0 || max_loc == l )
	{
		printf("%.10f\n",max_diff);
	}
	else
	{
	
		printf("%.10f\n",max_diff/2);
	}
}
