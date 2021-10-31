#include<iostream>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

vector <int> adj[100000];
bool vis_dfs [100000];
bool vis_bfs[100000];
stack <int> stack1;

void addEdge ( int from, int to )
{
	adj [from].push_back (to);
}

void bfs ( int s )
{
	queue <int> q;
	q.push (s);
	vis_bfs[s] = true;

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
				q.push(i);
			}
		}
	}
}

void dfs ( int v )
{
	vis_dfs[v] = true;
	
	cout << v << " "; 

	for ( auto i : adj[v] )
	{
		if ( !vis_dfs[i] )
		{
			dfs ( i );
		}
	}
	stack.push ( stack1, v ); // used for defining indegree in topological sort
}
int main()
{
	int choice;

	while ( choice != 5 )
	{
		cout << "********* MAIN MENU *********" << endl 
		<< "1. Enter edge " << endl 
		<< "2. DFS" << endl
		<< "3. BFS" << endl
		<< "4. Topological Sort" << endl;
		<< "5. Exit " << endl;

		cout << "Enter your choice : ";
		cin >> choice;

		if ( choice == 1 )
		{
			int u,v;
			cout << "Enter the node from and to : ";
			cin >> u >> v;
			addEdge ( u,v );
		}

		else if ( choice == 2 )
		{
			int node;
			cout << "Enter the node on which dfs is to started: ";
			cin >> node;
			dfs ( node );
			cout << endl;
		}
		else if ( choice == 3 )
		{
			int node;
			cout << "Enter the node on which bfs is to started: ";
			cin >> node;
			bfs ( node );
			cout << endl;
		}
	}
}
// Topological sort
//crohan bfs
// SSC
