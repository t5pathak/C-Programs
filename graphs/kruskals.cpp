#include<bits/stdc++.h>
using namespace std;
vector<pair<long long int,pair<long long int,long long int>>> adj;
vector<long long int> height(2),parent(2);
vector<long long int> ans;
long long int n,m,k;
long long int total=0;
long long int weight=0;

long long int find(long long int); //union find; find subset

void merge(long long int u, long long int v) //union find merge subset
{
    u=find(u);
    v=find(v);
    if (parent[u]<parent[v])
        parent[u]=v;
    else if(parent[u]>parent[v])
        parent[v]=u;
    else
    {
        parent[v]=u;
        parent[u]++;
    }
}

long long int find(long long int node) //union find; find subset
{
    if (node!=parent[node])
        parent[node]=find(parent[node]);
    return parent[node];
}
long long int kruskal()
{
    sort(adj.begin(),adj.end()); //order in terms of edge weights
    weight=0;//final answer tree weight = 0
    long long int u,v;
    for (long long int i=0; i<adj.size(); i++)
    {
        u=find(adj[i].second.first);
        v=find(adj[i].second.second);
        //cout<<"u v: "<<u<<" "<<v<<endl;
        if (u!=v)
        {
            weight+=adj[i].first;
            ans.push_back(adj[i].first);
            merge(u,v);
        }
    }
}

int main()
{
    scanf("%lld %lld",&n,&m);
    height.resize(n+2); parent.resize(n+2);
    long long int u,v,w;
    for(long long int i=0;i<m;i++)
    {
        scanf("%lld %lld %lld",&u,&v,&w);
        adj.push_back({w,{u,v}});
    }

    for (long long int i=0;i<=n;i++) //initialize along long int disjonts
    {
        height[i]=0;//all heights '0'
        parent[i]=i;//All kids their own parent
    }

    kruskal();
    cout<<weight<<endl;
}
