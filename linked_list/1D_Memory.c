#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int n;
	scanf("%d",&n);

	int *p = (int*)calloc(n,sizeof(int));
	
	printf("%d is the starting adress of the memory \n",p);
	
	printf("Printing the current values in the memory array by dereferencing \n");

	for (int i=0; i<=(n-1); i++)
	{
		printf("%d ",p[i]);
	}
	printf("\nEnter the values into the memeory array\n");
	
	for (int i=0; i<=(n-1); i++)
	{
		p[i] =  i+1;
	}

	printf("Printing the memory block\n");

	for (int i=0; i<=(n-1); i++)
	{
		printf("%d ",p[i]);
	}
	printf("\nFree the memory block\n");
	//free(p);
	//printf("Now printing the value of in the memory block\n");
	//for (int i=0; i<=(n-1); i++)
	//{
	//	printf("%d ",p[i]);
	//}
	printf("\nMemory is being reallocated\n");

	int *a = (int*)realloc(p,2*n*sizeof(int));//The new memmory block 'a' contains the memory from 'p' but now is not refrenced by 'p'.
	
	printf("Printing the new memory block\n");


	for (int i=0; i<=(2*n-1); i++)
	{
		printf("%d ",p[i]);
	}
	printf("\n");

	printf("Deleting the memory block using realloc\n");

	int *b = (int*) realloc(a,0);//The old memory block 'a' is deallocated

	printf("Printing the values in the memory block after deleting using realloc\n");

	for (int i=0; i<=(2*n-1); i++)
	{
		printf("%d ",b[i]);
	}
	printf("\n");


}
