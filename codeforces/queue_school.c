#include<stdio.h>
int main(void)
{
	int n,t;
	scanf("%d %d",&n,&t);

	char str[n];
	scanf("%s",str);
	for (int j=0; j<=(t-1) ;j++)
	{

		for (int i=0; i<=(n-2); i++)
		{
			if ( str[i] == 'B' && str [i+1] == 'G' )
			{
				str[i] = 'G';
				str[i+1] = 'B';
				i++;
			}
		}
	}
	printf("%s\n",str);
}
