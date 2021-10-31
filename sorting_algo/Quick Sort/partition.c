#include<stdio.h>
void partition(int arr[], int start, int end)
{
	int pivot = arr[end];
	int p_index = start;
	for (int i=start; i<=(end-1); i++)
	{
		if ( arr[i] <= pivot )
		{
			int temp = arr[i];
			arr[i] = arr[p_index];
			arr[p_index] = temp;
			p_index++;
		}
	}
	int temp = arr[p_index];
	arr[p_index] = arr[end];
	arr[end] = temp;
}
void print( int arr[], int n)
{
	printf("Printing the partitioned list\n");
	for (int i=0; i<=(n-1); i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int main(void)
{
	int n;
	printf("No. of elements: ");
	scanf("%d",&n);

	int arr[n];
	for (int i=0; i<=(n-1); i++)
	{
		printf("Enter element No.%d: ",(i+1));
		scanf("%d",&arr[i]);
	}
	printf("Printing pre-partition array\n");
	for (int i=0; i<=(n-1); i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	partition(arr,0,n-1);
	print(arr,n);
	return 0;
}
