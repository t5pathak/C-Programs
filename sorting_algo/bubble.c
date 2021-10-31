#include<stdio.h>
int main(void)
{
	int size;
	scanf("%d",&size);

	int arr[size];
	for (int i=0; i<=(size-1); i++)
	{
		scanf("%d",&arr[i]);
	}

	for (int i=0; i<=(size-2); i++)
	{
		for (int j=0; j<=(size-2); j++)
		{
			if (arr[j+1] < arr[j])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}

	for (int i=0; i<=(size-1); i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}
