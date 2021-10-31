#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	long long int n,m;
	cin >> n >> m;
	
	long long int arr_b[n];
	long long int arr_g[m];

	for ( long long int i=0; i<=(n-1); i++)
	{
		cin >> arr_b[i];
	}
	for ( long long int i=0; i<=(m-1); i++)
	{
		cin >> arr_g[i];
	}

	long long int ans = 0;

	for ( long long int i=0; i<=(n-1); i++)
	{
		ans = ans + arr_b[i];
	}

	ans = ans * m;
	
	sort(arr_b, arr_b + n );
	sort(arr_g, arr_g + m );

	if ( arr_g[0] < arr_b[n-1] )
	{
		cout << "-1"<< endl;
		return 0;
	}

	for ( long long int i=(m-1) ; i>0; i-- )
	{
		ans = ans + ( arr_g[i] - arr_b[n-1] );
	}

	if ( arr_g[0] != arr_b[n-1] )
	{
		ans = ans + ( arr_g[0] - arr_b[n-2] );
	}
	cout << ans << endl;
	return 0;
}
