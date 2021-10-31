#include<stdio.h>
int main(void)
{
	int q;
	scanf("%d",&q);
	for (int z=1; z<=q; z++)
	{
		int l1,r1,l2,r2;
		scanf("%d %d %d %d",&l1,&r1,&l2,&r2);
		
		int size_arr[4];
		size_arr[0] = l1;
		size_arr[1] = r1;
		size_arr[2] = l2;
		size_arr[3] = r2;

		int max = 0;

		for (int i=0; i<=3; i++)
		{

			if ( size_arr[i] >= max )
			{
				max = size_arr[i];
			}
		}

		int ans_1 = 0;

		for (int i=l1; i<=r1; i++)
		{
			if ( i >= l1 && i <= r1 )
			{
				ans_1 = i;
				break;
			}
		}

		int ans_2 = 0;
		for (int i=l2; i<=r2; i++)
		{
			if ( i >= l2 && i <= r2 && i != ans_1 )
			{
				ans_2 = i;
				break;
			}
		}
		printf("%d %d\n",ans_1,ans_2);
	}
}
