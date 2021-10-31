#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};

struct node* head = NULL;

void insert_at_begining(int x)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp -> data = x;
	temp -> next = head;
	head = temp;
}

void insert ( int data, int n)
{
	struct node* adress = head;
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp -> data = data;
	for (int i=1; i<=(n-1) ; i++)
	{
		adress = head -> next;
	}
	temp -> next = adress;
	for (int i=1; i<=(n-2); i++)
	{
		adress = 
	}

}

void print()
{
	struct node* adress = head;
	while (adress != NULL)
	{
		printf("%d ",adress -> data);
		adress = adress -> next;
	}
}

int main()
{
	int n;
	printf("Enter the number of elements: ");
	scanf("%d",&n);

	for (int i=0; i<=(n-1); i++)
	{
		int m;
		printf("Enter a number: ");
		scanf("%d\n",&m);
		insert_at_begining(m);
	}
	printf("\nPrinting the elements\n");
	print();
	
	int pos,element;
	printf("Insert at this position: ");
	scanf("%d",&pos);
	printf("Enter the element to be inserted: ");
	scanf("%d",&element);
	insert(element,pos);
}
