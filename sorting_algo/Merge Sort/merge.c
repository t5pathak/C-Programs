#include<stdio.h>
void merge (int arr[], int arr1[], int* s1, int arr2[], int *s2)
{	
	int size1 = *s1;
	int size2 = *s2;

	int size = size1 + size2;
	
	printf("%d & %d is the size inside the fuction\n",size1,size2);

	int i,j,k=0;

	while ( i<size1 && j<size2)
	{
		if ( arr1[i] < arr2[j])
		{
			arr[k] = arr1[i];
			k++;
			i++;
		}
		else
		{
			arr[k] = arr2[j];
			k++;
			j++;
		}
	}
	while ( i<size1)
	{
		arr[k] = arr1[i];
		k++;
		i++;
	}
	while (j<size2)
	{
		arr[k] = arr2[j];
		k++;
		j++;
	}
	for (int p=0; p< (size); p++)
	{
		printf("%d ",arr[p]);
	}

	printf("\n");
}
int main(void)
{
	int size1,size2;
	scanf("%d %d",&size1,&size2);

	//printf("%d & %d are the sizes of the lists\n", size1,size2);

	int arr1[size1];
	int arr2[size2];

	for (int i=0; i<=(size1-1); i++)
		scanf("%d",&arr1[i]);
	
	for (int i=0; i<=(size1-1); i++)
		scanf("%d",&arr2[i]);

	//printf("Printing list 1\n");

	//for (int i=0; i<=(size1-1); i++)
	//	printf("%d ",arr1[i]);

	//printf("\n");

	//printf("Printing list 2\n");

	//for (int i=0; i<=(size1-1); i++)
	//	printf("%d ",arr2[i]);
	//printf ("\n");

	int size = size1+ size2;
	
	int arr[size];

	//printf("%d is the size of merged array \n  Entering the function...\n",size);
	merge(arr,arr1,&size1,arr2,&size2);
}
