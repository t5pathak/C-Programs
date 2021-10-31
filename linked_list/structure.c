#include<stdlib.h>
#include<stdio.h>
struct person{
	char name[100];
	int age;
	double salary;
};
int main(void)
{
	printf("Starting the program\n");
	int n;
	scanf("%d",&n);
	printf("Number of records: %d\n",n);
	struct person p1[n];

	for (int i=0; i<=(n-1); i++)
	{
		printf("Details for the %d person\n",i+1);
		printf("Name: ");
		scanf("%s",p1[i].name);
		printf("Age: ");
		scanf("%d",&p1[i].age);
		printf("Salary: ");
		scanf("%lf",&p1[i].salary);
	}

	printf("\n\nPrinting the all the details\n");

	
	for (int i=0; i<=(n-1); i++)
	{
		printf("Details for the %d person\n",i+1);
		printf("Name: %s",p1[i].name);
		printf("\nAge: %d\n",p1[i].age);
		printf("Salary: %lf\n",p1[i].salary);
	}
	return 0;
}
