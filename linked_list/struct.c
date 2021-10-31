#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* next;
};
struct node* head = NULL;

void insert_begin(int n)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp -> data = n;
	temp -> next = head;
	head = temp;	
}

void print()
{
	struct node* adress = head;
	while (adress != NULL)
	{
		printf("%d ",adress -> data);
		adress = adress -> next;
	}
	printf("\n");
}

void delete(int n, int max)
{
	struct node* adress = head;
	if ( n == 1 )
	{
		head = head -> next;
	}
	else if ( n == max )
	{
		for (int i=1; i<=(n-2); i++)
		{
			adress = head -> next;
		}
		adress -> next = NULL;
	}
	else
	{
		for (int i=1; i<=(n); i++)
		{
			adress = adress -> next;
		}
		struct node* insert_here = head;
		for (int i=1; i<=(n-2); i++)
		{
			insert_here = insert_here -> next;
		}
		insert_here -> next = adress;
	}
}

int main(void)
{
	int n;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	for (int i=1; i<=(n); i++)
	{
		int m;
		printf("Enter the element to be added to the start: ");
		scanf("%d",&m);
		insert_begin(m);
		printf("Printing the list after entering at the begining\n");
		print();
	}
	//int del;
	//printf("Enter the position to be deleted: ");
	//scanf("%d",&del);
	//delete(del,n);
	print();
	return 0;
}
