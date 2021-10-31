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
		int small=arr[i];
		for (int j=i+1; j<=(size-1); j++)
		{
			if (arr[j]<small)
			{
				int temp=arr[j];
				arr[j]=arr[i];
				arr[i]=temp;
			}
		}
	}

	for (int i=0; i<=(size-1); i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}
