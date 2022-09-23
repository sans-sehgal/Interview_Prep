#include <bits/stdc++.h>
using namespace std;


bool detectCycle(int node, vector<int> &vis, vector<int> &dfs_vis, map<int, vector<int> > mp)
{
	vis[node] = 1;
	dfs_vis[node] = 1;
	for(auto i: mp[node])
	{
		if(!vis[i])
		{
			// dfs_vis[i] = 1;
			if(detectCycle(i, vis, dfs_vis, mp)) return true;
		}
		else if(dfs_vis[i] == 1)
			return true;
	}
	dfs_vis[node] = 0;
	return false;
}

int main() 
{
    map <int , vector <int> > mp;
    int V, E;
    cin>>V>>E;
    for(int i=0; i<E; i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        mp[v1].push_back(v2);
    }
	for(auto i : mp)
    {
        cout<<i.first<<"->";
        for(auto j : i.second)
            cout<<j<<", ";
        cout<<endl;
    }
    vector <int> vis (V+1 , 0);
    vector <int> dfsVis(V+1, 0);
    for(int i=1; i<=V; i++)
    {
        if(!vis[i])
            if(detectCycle(i, vis, dfsVis, mp))
            {
            	cout<<"true!";
            	return 0;
            }
    }
    cout<<"false";
    return 0;
}