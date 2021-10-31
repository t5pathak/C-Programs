#include<stdio.h>
int partition (arr, start, end)
{
	int i=0,j=0;k=0;
	while ( i < n && j < m )
	{
		if ( arr[i] < arr[m] )
		{
			arr1[k] = arr[i];
			k++;
			i++;
		}
		else
		{
			arr1[k] = arr[j];
			k++;
			j++;
		}
	}
	while ( i < n )
	{
		arr1[k] = arr[i];
		i++;
		k++;
	}
	while ( j < m )
	{
		arr1[k] = arr[j];
		j++;
		k++;
	}
}
void quick_sort (int arr[], int n)
{
	if ( start <= end )
	{
		return;
	}
	int p_index = partition( arr, start, end );



}
void print(int arr[], int n)
{
	for (int i=0; i<=(n-1); i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n")
}
int main(void)
{
	int n;
	printf("Enter the number of elements: ");
	scanf("%d",n);

	int arr[n];
	for (int i=0; i<=(n-1); i++)
	{
		printf("Enter %D element: ",i+1);
		scanf("%d",&arr[i]);
	}

	printf("Printing the orignal array\n");
	print(arr,n);
	quick_sort(arr, 0, n-1);
}

