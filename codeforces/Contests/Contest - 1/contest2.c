#include<stdio.h>
#include<string.h>
int main(void)
{
	char str[100000];
	scanf("%s",str);

	int conv_count = 0;

	for (int i=0; i<= strlen (str) - 1; i++)
	{

		if ( str[i] == str[i+1] )
		{
			str[i] = '0';
			str[i+1] = '0';
			i = i + 1;
			conv_count++;
		}

	}

	int special = 1;
	int start = 0;
	int end = strlen ( str ) - 1;

	while ( start <=  end ) 
	{
		if ( str [start] != str [end] )
		{
			special = 0;
			break;
		}
		start++;
		end--;
	}
	if (strlen(str) % 2 == 0)
	{
		if ( special == 1 && ((strlen(str)/2) % 2 == 1) )
		{
			printf("Yes\n");
			return 0;
		}	
		if ( special == 1 && ((strlen(str)/2) % 2 == 0))
		{
			printf("No\n");
			return 0;
		}
	}
	if ( conv_count % 2 == 0 )
	{
		printf("No\n");
	}

	else 
	{
		printf("Yes\n");
	}
}
