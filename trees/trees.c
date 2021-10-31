#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* left;
	struct node* right;
};

struct node* insert(struct node* root, int data)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp -> data = data;
	temp -> right = NULL;
	temp -> left = NULL;

	if ( root == NULL )
	{
		root = temp;
	}
	else if ( data <= root -> data )
	{
		root -> left = insert( root -> left ,data);
	}
	else if ( data > root -> data )
	{
		root -> right = insert ( root -> right, data );
	}
	return root;

}
int search( struct node* root, int data )
{
	if ( root == NULL )
	{
		return 0;
	}
	else if ( data == root -> data )
	{
		return 1;
	}
	else if ( data <= root -> data )
	{
		return search (root -> left, data);
	}
	else if ( data > root->data )
	{
		return search (root -> right, data);
	}
}

struct node* findmin ( struct node* root )
{
	struct node* current = root;
	while ( current -> left != NULL )
	{
		current = current -> left;
	}
	return current;
}
struct node* delete (struct node* root, int data )
{
	if ( root == NULL )
	{
		return root;
	}
	else if ( data < root -> data )
	{
		root -> left = delete ( root -> left, data );
	}
	else if ( data > root -> data )
	{
		root -> right = delete ( root -> right , data );
	}
	else 
	{
		if ( root -> left == NULL && root -> right == NULL )
		{
			free (root);
			root = NULL;
		}
		else if ( root -> left == NULL )
		{
			struct node* temp = root ;
			root = root -> right;
			free ( root );
		}
		else if ( root -> right == NULL )
		{
			struct node* temp = root;
			root = root -> left;
			free ( root );
		}
		else 
		{
			struct node * temp = findmin( root );
			root -> data = temp -> data;
			root -> right = delete ( root -> right ,data );
		}
	}
	return root;
}
int main(void)
{
	struct node* root = NULL;
	root = insert(root,15);
	root = insert(root,10);
	root = insert(root,20);
	root = insert(root,25);
	root = insert(root,8);
	root = insert(root,12);

	if ( search(root,20) == 1 )
	{
		printf("FOUND\n");
	}
	else
	{
		printf("NOT FOUND\n");
	}
	root = delete ( root , 20 );
	if ( search(root,20) == 1 )
	{
		printf("FOUND\n");
	}
	else
	{
		printf("NOT FOUND\n");
	}

}
