#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node* next;
};
struct node* head = NULL;
void insert_start (int n)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp -> data = n;
	temp -> next = head;
	head = temp;
}
void print()
{
	struct node* adress = head;
	while ( adress != NULL )
	{
		printf("%d ",adress -> data );
		adress =  adress -> next;
	}
	printf("\n");
}
int main (void)
{
	int n;
	printf("Enter the number of elements: ");
	scanf("%d",&n);

	for (int i=0; i<=(n-1); i++)
	{
		int temp;
		printf("Enter element no %d: ",i+1);
		scanf("%d",&temp);
		insert_start(temp);
	}
	print();
}
