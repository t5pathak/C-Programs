#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node* next;
};

struct node* head = NULL;
void insert_at_begining()
{
	int x;
	scanf("%d",&x);

	struct node* temp = (struct node* )malloc(sizeof(struct node));
	temp -> data = x;
	temp -> next = head;
	head = temp;
}

void insert()
{
	int x,n;
	scanf("%d %d",&x,&n);

	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp -> data = x;
	if ( n == 1 )
	{
		temp->next = head;
		head = temp;
	}
	else
	{
	struct node* adress = head;
	for (int i=1; i<=(n-1); i++)
	{
		adress = adress -> next;
	}
	temp -> next = adress;

	adress = head;

	for (int i=1; i<=(n-2); i++)
	{
		adress = adress -> next;
	}
	adress -> next = temp;
}
}

void delete()
{
	int n;
	scanf("%d",&n);
	
	struct node* adress = head;
	for (int i=1; i<=(n); i++)
	{
		adress = adress -> next;
	}

	struct node* adress1 = head;
	for (int i=1; i <= (n-2); i++)
	{
		adress1 = adress1 -> next;
	}
	adress1 -> next = adress;
}

void print()
{
	struct node* temp = head;

		while ( temp != NULL )
		{
			printf("%d ",temp -> data);
			temp = temp -> next;
		}
	printf("\n");

}
void reverse()
{
	struct node* next;
	struct node* current = head;
	struct node* prev = NULL;

	while ( current != NULL )
	{
		next = current -> next;
		current -> next = prev;
		prev = current;
		current = next;
	}
	head = prev;
	print();
}
int main(void)
{
	int choice = 0;
	while ( choice != 6 )
	{
		printf("***** MAIN MENU *****\n1) Insert at begining\n2) Insert at nth position\n3) Delete nth node\n4) Print the list\n5) Reverse\n6) Exit\n*******************\n");
		printf("Enter choice: ");
		scanf("%d",&choice);

		if ( choice == 1 )
		{
			insert_at_begining();
		}
		else if ( choice == 2 )
		{
			insert();
		}
		else if ( choice == 3 )
		{
			delete();
		}
		else if (choice == 4 )
		{
			print();
		}
		else if ( choice == 6 )
		{
			return 0;
		}
		else if ( choice == 5 )
		{
			reverse();
		}
	}
}
