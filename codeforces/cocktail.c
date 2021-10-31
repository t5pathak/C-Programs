#include<stdio.h>
int main(void)
{
	int n;
	scanf("%d",&n);

	float arr[n];

	for (int i=0; i<=(n-1); i++)
	{
		scanf("%f",&arr[i]);
	}

	float sum = 0.0;
	float avg = 0.0;

	for (int i=0; i<=(n-1); i++)
	{
		sum = sum + arr[i];
	}

	avg = sum / n;

	printf("%lf\n",avg);
}
