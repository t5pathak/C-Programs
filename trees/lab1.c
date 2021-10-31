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

int check_sum ( struct node* root, int sum)
{
	if ( root == NULL )
	{
		return 0;
	}
	int current_sum = 0;

	while ( root -> left != NULL || root -> right != NULL)
	{
		current_sum = current_sum + root -> data;
		printf("Root Value = %d\nCurrent sum = %d\n",root -> data, current_sum );
		if ( current_sum < sum )
		{
			root = root -> right;
		}
		else
		{
			root = root -> left;
		}
	}

	current_sum = current_sum + root -> data;
	printf("Root Value = %d\nCurrent sum = %d\n",root -> data, current_sum );

	if ( current_sum == sum)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	for (int k=1; k<=T; k++)
	{
		struct node* root = NULL;
		int n;
		scanf("%d",&n);

		int arr[n];

		for ( int i=0; i<=(n-1); i++)
		{
			int x;
			scanf("%d",&x);
			arr[i] = x;
		}

		for (int i=0; i<=(n-1); i++)
		{
			root = insert ( root ,arr[i] );
		}

		int sum;
		scanf("%d",&sum);
		
		int answer = check_sum ( root, sum );

		if ( answer  == 1 )
		{
			printf("YES\n");
		}
		else 
		{
			printf("NO\n");
		}
	}
}
