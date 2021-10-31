#include<stdio.h>
int partition(int arr[], int start, int end)
{
	int pivot = arr[end];
	int p_index = start;
	for (int i = start; i<=(end-1); i++)
	{
		if ( arr[i] <= pivot )
		{
			int temp = arr[i];
			arr[i] = arr[p_index];
			arr[p_index] = temp;
			p_index++;
		}
	}
	int temp = arr[end];
	arr[end] = arr[p_index];
	arr[p_index ] = temp;
	
	return p_index;
}
void quick_sort(int arr[], int start, int end)
{
	if ( start >= end)
	{
		return;
	}
	int p_index = partition(arr, start, end);
	quick_sort(arr, start, p_index-1);
	quick_sort(arr, p_index+1, end);
}
void print (int arr[], int n)
{
	printf("Printing the sorted array\n");
	for (int i=0; i<=(n-1); i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}
int main(void)
{
	int n;
	printf("Enter the no. of elements: ");
	scanf("%d",&n);

	int arr[n];
	for (int i=0; i<=(n-1); i++)
	{
		printf("Enter element no.%d: ",i+1);
		scanf("%d",&arr[i]);
	}
	print(arr,n);
	quick_sort(arr,0,n-1);
	print(arr,n);
}
