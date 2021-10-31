#include<iostream>
#include<queue>
#include<vector>
#include<stack>

using namespace std;

vector <int> adj[100000];
bool vis_bfs [100000];
bool vis_dfs [100000];
stack <int> stack1;

void addEdges ( int from, int to )
{
	adj[from].push_back (to);
}
void bfs ( int s )
{
	queue < int > q;
	vis_bfs[s] = true;
	q.push(s);

	while ( !q.empty() )
	{
		int p = q.front();
		cout << p << " ";
		q.pop();

		for ( auto i : adj[p] )
		{
			if ( vis_bfs[i] == false )
			{
				vis_bfs[i] = true;
				q.push (i);
			}
		}
	}
}
void dfs ( int s )
{
	vis_dfs[s] = true;
	cout << s << " ";
	for ( auto i : adj[s] )
	{
		if ( vis_dfs[i] == false )
		{
			dfs ( i );
		}
	}
	stack1.push (s);
}

void sort ()
{
		for ( auto i : vis_dfs )
		{
			if ( !vis_dfs[i] )
			{
				vis_dfs[i] = true;
				dfs (i);
			}
		}

		while ( ! stack.size ( stack1 ) )
		{
			cout << stack1.top () << " ";
			stack1.pop ();
		}
}
int main()
{
	int edges;
	cin >> edges;
	
	int vertices;
	cin >> vertices;

	for ( int i=0; i<=(edges-1); i++)
	{
		int from, to;
		cin >> from >> to;
		addEdges (from, to);
	}

	
	int s_bfs;
	cin >> s_bfs;
	bfs (s_bfs);
	cout << endl;

	int s_dfs;
	cin >> s_dfs;
	dfs ( s_dfs );
	cout << endl;

	sort();
	cout << endl;
}
