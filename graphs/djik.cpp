#include<iostream>
#include<vector>
#include<set>
#include<queue>

using namespace std;

vector < pair < int, int > > ad [100000]; 
bool vis [100000];
int dis [100000];

void addEdge ( int from, int to, int weight )
{
	ad [from].push_back( make_pair (to,weight) );
	ad [to].push_back( make_pair (from,weight) );
}
	
void dijkstra (int s)
{
	memset ( vis, false, sizeof (vis));  //sets the 'vis' array to 'false' through 'size of vis'
	
	dis [s] = 0;                        // Distance from source to source is 0;

	multiset < pair < int, int > > s;   // Does the work of a min-priority queue
	s.insert ( 0, s );                  // Distance (weight) , to-vertex

	while ( !s.empty() )
	{
		pair < int, int > p = s.begin();
		s.erase ( s.begin() );
		
		int wei = p.first;
		int to_vertex = p.second;
		
		if ( !vis[to_vertex] )
		{
			vis[to_vertex] = true;

			for ( auto i : ad[ to_vertex ] ) // exploring all vertices of the 'to edge'
			{
				int current_to = ad[to_vertex][i].first; //to vertex
				int current_weight = ad[to_vertex][i].second; // weight 'to vertex'

				if ( dis[ to_vertex ] + current_weight < dis[ current_to] )
				{
					dis [current_to] = dis [to_vertex] + current_weight; 
					s.insert ( { dis [current_to] , current_weight } );
				}
			}
		}
	}
}

int main(void)
{
	int n,e;

	cout << "Enter no of. vertices and edges: "; 
	cin >> n >> e;

	for ( int i=0; i<=(e-1); i++)
	{

		int from, to, weight;

		cout << "From, to, weight : ";
		cin >> from >> to >> weight;

		addEdge (from, to, weight);
	}
	
	int s;
	cout << "Enter the source node :";
	cin >> s; 
	dijkstra (s);

	for ( int i=0; i<= ( n-1); i++)
	{
		cout << dis[i] << " ";
	}
	cout << endl;
}
