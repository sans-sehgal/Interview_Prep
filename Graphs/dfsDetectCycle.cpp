// Cycle in undirected Graph using DFS


#include <bits/stdc++.h>
using namespace std;


bool dfsCycle(int node, int parent, map<int,vector<int>> mp, vector<int> &vis)
{
	vis[node] = 1;
	for(auto i : mp[node])
	{
		if(vis[i] == 1 && i!=parent)
			return true;
		else if(vis[i] == 0)
		{	
			return dfsCycle(i, node, mp, vis);
		}
	}
	return false;
}


int main()
{
	int V,E;
	cin>>V>>E;
	map<int,vector<int>> mp;
	for(int i=0; i<E; i++)
	{
		int v1,v2;
		cin>>v1>>v2;
		mp[v1].push_back(v2);
		mp[v2].push_back(v1);
	}
	for(auto i : mp)
	{
		cout<<i.first<<"->";
		for(auto j : i.second)
			cout<<j<<", ";
		cout<<endl;
	}
	vector <int> vis(V+1 , 0);

	for(int i=1; i<=V; i++)
	{
		if(!vis[i])
		{
			if(dfsCycle(i, -1, mp, vis))
			{
				cout<<"true";
				return 0;
			}
		}
	}
	cout<<"false";
	return 0;
}