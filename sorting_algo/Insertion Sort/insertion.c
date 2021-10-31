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

	for (int i=1; i<=(size-1); i++)
	{
		int value = arr[i];
		int hole = i;

		while (hole > 0 && arr[hole-1] > value)
		{
			arr[hole]=arr[hole-1];
			hole = hole-1;
		}
		arr[hole] = value;
	}
	for (int i=0; i<=(size-1); i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}
