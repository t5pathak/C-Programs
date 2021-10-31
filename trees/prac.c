#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* left;
	struct node* right;
};

struct node* insert(struct node* root, int data )
{
	struct node* temp = (struct node* )malloc(sizeof(struct node));
	temp -> left = NULL;
	temp -> right = NULL;
	temp -> data = data;

	if ( root == NULL )
	{
		root = temp;
	}
	else if ( data < root -> data )
	{
		root -> left = insert ( root -> left, data );
	}
	else 
	{
		root -> right = insert ( root -> right, data );
	}

	return root;
}

int search ( struct node* root, int data )
{
	if ( root == NULL )
	{
		return 0;
	}
	else if ( root -> data == data )
	{
		return 1;
	}
	else if ( root -> data > data )
	{
		return search ( root -> left, data ); 
	}
	else if ( root -> data < data )
	{
		return search ( root -> right, data );
	}
}
	
int min_min (struct node* root )
{
	struct node* current = root;
	while ( current -> left != NULL )
	{
		current = current -> left;
	}
	return current -> data;
}

struct node* min (struct node* root )
{
	struct node* current = root;
	while ( current -> left != NULL )
	{
		current = current -> left;
	}
	return current;
}

int maximum (struct node* root )
{
	struct node* current = root;
	while ( current -> right != NULL )
	{
		current = current -> right;
	}
	return current -> data;
}
struct node* delete ( struct node* root , int data )
{
	if ( root == NULL )
	{
		return root;
	}
	else if ( root -> data > data )
	{
		root -> left = delete ( root -> left, data );
	}
	else if ( root -> data < data )
	{
		root -> right = delete ( root -> right, data );
	}
	else if ( root -> data == data )
	{
		//if no children
		if ( root -> right == NULL && root -> left == NULL )
		{
			root = NULL;
			free ( root );
		}
		// 1 child
		else if ( root -> right == NULL )
		{
			struct node* temp = root;
			root = root -> left;
			free (temp);
		}
		else if ( root -> left == NULL )
		{
			struct node* temp = root;
			root = root -> right;
			free ( temp );
		}
		//2 children
		else 
		{
			struct node* temp = min(root);
			root -> data = temp -> data;
			root -> right = delete ( root -> right, temp -> data );//cause we need to delete temp which is only in the right sub tree.
		}
	}
	return root;
}

int main(void)
{
	struct node* root = NULL;
	int choice = 0;
	while ( choice != 5 )
	{

		printf("---- MAIN MENU ----\n1) Insert\n2) Search\n3) MIN and MAX\n4) Delete\n5) Exit\n---------\n");

		scanf("%d",&choice);

		if ( choice == 1 )
		{
			int data;
			printf("Enter the value of insertion: ");
			scanf("%d",&data);

			root = insert (root, data );
		}
		else if ( choice == 2 )
		{
			int number;
			printf("Search for : ");
			scanf("%d",&number);

			if ( search ( root, number ) == 1 )
			{
				printf("%d found\n",number);
			}
			else
			{
				printf("%d not found\n",number);
			}
		}
		else if ( choice == 5 )
		{
			return 0;
		}
		else if ( choice == 3 )
		{
			printf("%d is minimum\n%d is maximum\n",min_min(root),maximum(root));
		}
		else if ( choice == 4 )
		{
			int val = 0;
			printf("Delete : ");
			scanf("%d",&val);
			root = delete(root,val);
		} 
	}
}
