#include<stdio.h>
void merge ( int arr[], int arr1[], int* s1, int arr2[], int* s2)
{
	int size1 = *s1;
	int size2 = *s2;

	int size_here = size1+size2;

	int i=0,j=0,k=0;

	while (i<size1 && j<size2)
	{
		if ( arr1[i] < arr2[j] )
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
	while ( i < size1)
	{
		arr[k] = arr1[i];
		k++;
		i++;
	}
	while ( j < size2)
	{
		arr[k] = arr2[j];
		k++;
		j++;
	}
}
void  mergesort(int arr[],int *s)
{
	int size = *s;
	if ( size < 2 )
	{
		return;//stopping condition for recursive call of function
	}	
	int size1 = (size/2);//mid = size1
	int size2= (size-size1);

	int arr1[size1];
	int arr2[size2];

	for (int i=0; i<=(size1-1); i++)
	{
		arr1[i] = arr[i];
	}
	for (int i= 0; i<=(size2-1); i++)
	{
		arr2[i] = arr[i+size1];
	}

	mergesort(arr1, &size1);
	mergesort(arr2, &size2);
	merge(arr ,arr1 ,&size1 ,arr2 ,&size2);
	return;
}    
void prt_arr(int arr[], int* s)
    {
        int size = *s;
        for (int i=0; i<=(size-1); i++)
        {
            printf("%d ",arr[i]);
        }
        printf("\n");
        
    }
int main(void)
{
	int size;
	scanf("%d",&size);

	int arr[size];
	for (int i=0; i<=(size-1); i++)
	{
		scanf("%d",&arr[i]);
	}

	mergesort(arr,&size);
      	prt_arr(arr,&size);
	return 0;
}
