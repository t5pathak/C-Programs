#include<iostream>
#include<vector>

using namespace std;

int main(void)
{
	int count = 0;
	int no;

	cin >> no;


	while ( no >= 10)
	{
		no = no + 1;
		count++;
		while ( no % 10 == 0 )
		{
			no = no/10;
		}
	}

	count = count + 9;
	cout << count << endl;

}
