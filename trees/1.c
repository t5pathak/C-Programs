#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
};

struct node* insert ( struct node* root, int data )
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp -> data = data;
	temp -> left = NULL;
	temp -> right = NULL;

	if ( root == NULL )
	{
		root = temp;
	}
	else if ( root -> data > data )
	{
		root -> left = insert ( root -> left , data );
	}
	else 
	{
		root -> right = insert (root -> right , data );
	}

	return root;
}

int search ( struct node* root, int data )
{
	struct node* current = root;

	if ( current == NULL )
	{
		return 0;
	}
	else if ( current -> data == data )
	{
		return 1;
	}
	else if ( current -> data > data )
	{
		return search ( current -> left, data );
	}
	else if ( current -> data < data )
	{
		return search ( current -> right, data );
	}
}
void minimum ( struct node* root )
{
	struct node* current = root;
	
	while ( current -> left != NULL )
	{
		current = current -> left;
	}
	printf("Minimum element = %d",current -> data );
}

void maximum ( struct node* root )
{
	struct node* current = root;

	while ( current -> right != NULL )
	{
		current = current -> right;
	}
	printf("\nMaximum element = %d \n",current -> data );
}

int main(void)
{
	struct node* root = NULL;

	for (int i=5; i<=10; i++)
	{
		root = insert ( root, i );
	}
	for (int i=1; i<5; i++)
	{
		root = insert ( root , i );
	}

	if ( search ( root, 7 ) == 1 )
	{
		printf("7 found\n");
	}
	else
	{
		printf("7 Not Found\n");
	}

	if ( search ( root, 20 ) == 1 )
	{
		printf("20 found\n");
	}
	else
	{
		printf("20 not Found\n");
	}
	minimum(root);
	maximum(root);

}
