#include<stdio.h>
#include<stdlib.h>

struct person{
	char name[100];
	int age;
	double salary;
};

int main(void)
{
	printf("Starting the program\n");

	printf("Enter the nunber of employees: ");
	int n;
	scanf("%d",&n);

	struct person p;
	struct person* ad_p = &p;
	printf("Name: ");
	scanf("%s",p.name);

	printf("Age: ");
	scanf("%d",&p.age);

	printf("Salary: ");
	scanf("%lf",&p.salary);

	printf("\n");

	printf("Displaying the details..\n");
	printf("Name : %s",p.name);
	printf("\n");
	printf("Age : %d\n",p.age);
	printf("Salary : %lf\n",p.salary);
}
