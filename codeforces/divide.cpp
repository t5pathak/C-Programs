#include<iostream>

using namespace std;

int main(void)
{
	int q;
	cin >> q;

	long long int arr[q];

	for ( int i=0; i<= (q-1); i++)
	{
		long long int temp;
		cin >> temp;
		arr[i] = temp;
	}

	cout << "Printing the array" << endl;

	for ( int i=0; i<=(q-1); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	for ( int i=0; i<=(q-1); i++)
	{
		int counter = 0;
		int divisor = 2;
		while ( arr[i] != 1 )
		{
			if ( arr[i] % divisor == 0 )
			{
				arr[i] = ((divisor - 1) * arr[i])/divisor;
				counter++;
			}
			else
			{
				divisor++;
			}
		}
		cout << counter << endl;
	}
}
