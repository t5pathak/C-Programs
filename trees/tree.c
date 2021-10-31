#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* right;
	struct node* left;
};

struct node* insert (struct node* root, int data )
{
	struct node* temp = (struct node* )malloc(sizeof(struct node));
	temp -> data = data;
	temp -> right = NULL;
	temp -> left = NULL;

	if ( root == NULL )
	{
		root = temp;
	}
	else if ( data < root -> data )
	{
		root -> left = insert ( root -> left , data );
	}	
	else
	{
		root -> right = insert ( root -> right , data );
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
	else if ( data < root -> data )
	{
		return search ( root -> left , data );
	}
	else if ( data >= root -> data )
	{
		return search ( root -> right, data );
	}
}
int minimum(struct node* root)
{
	struct node* current = root;
	while ( current -> left != NULL )
	{
		current = current -> left;
	}
	return current -> data;
}
int maximum(struct node* root )
{
	struct node* current = root;
	while ( current -> right != NULL )
	{
		current = current -> right;
	}
	return current -> data;
}
/*
   int height (struct node* root )
   {
   if ( root == NULL )
   {
   return -1;
   }
   else
   {
   return max ( height( root -> left ), height ( root -> right ) ) + 1;
   }
   }*/
struct node* find_min ( struct node* root )
{
	struct node* current = root;
	while ( current -> left != NULL )
	{
		current = current -> left;
	}
	return current;
}
struct node* delete ( struct node * root, int data )
{
	if ( root == NULL )
	{
		return root;
	}
	else if ( data < root -> data )
	{
		root -> left = delete ( root -> left , data );
	}
	else if ( data > root -> data )
	{
		root -> right = delete ( root -> right , data );
	}
	else if ( data == root -> data )//element found
	{
		//if no children 
		if ( root -> left == NULL && root -> right == NULL )
		{
			free ( root );
			root = NULL;
		}

		//if one child
		else if ( root -> left == NULL )
		{
			struct node* temp = root;
			root = root -> right;
			free ( temp );
		}
		else if ( root -> right == NULL )
		{
			struct node* temp = root;
			root = root -> left;
			free ( temp );
		}

		//if two children
		else
		{
			struct node* temp = find_min(root);
			root -> data = temp -> data;
//			temp -> data = root -> data;
			root -> right = delete ( root -> right ,data );//cause we need to delete temp from the right sub tree.
			free ( root );
		}
	}
	return root;
}
void inorder (struct node* root)
{
	if ( root != NULL )
	{
		inorder ( root -> left);
		printf("%d ",root -> data);
		inorder ( root -> right);
	}
}
int main(void)
{
	struct node* root = NULL;
	int choice = 0;
	while ( choice != 7 )
	{

		printf("---- MAIN MENU ----\n1) Insert\n2) Search\n3) MIN and MAX\n4) Delete\n6) Inorder\n7) Exit\n---------\n");

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
		else if ( choice == 7 )
		{
			return 0;
		}
		else if ( choice == 3 )
		{
			printf("%d is minimum\n%d is maximum\n",minimum(root),maximum(root));
		}
		else if ( choice == 4 )
		{
			int val = 0;
			printf("Delete : ");
			scanf("%d",&val);
			root = delete(root,val);
		}
		else if ( choice == 6 )
		{
			inorder ( root );
			printf("\n");

		}
	}
}
