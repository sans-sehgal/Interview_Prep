#include <bits/stdc++.h>
using namespace std;
void dfs_graph(int node, vector <int> &vis, int V, map<int,vector<int>> mp, vector<int> &dfs)
{
    if(!vis[node])
    {
        vis[node] = 1;
        dfs.push_back(node);
        for(auto i : mp[node])
            if(!vis[i])
                dfs_graph(i ,vis, V, mp, dfs);
    }
}

int main() 
{
    map <int , vector <int>> mp;
    int V, E;
    cin>>V>>E;
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
    vector <int> vis (V+1 , 0);
    vector <int> dfs;
    for(int i=1; i<=V; i++)
    {
        if(!vis[i])
            dfs_graph(i, vis, V, mp, dfs);
    }
    for(auto i : dfs)
        cout<<i<<" ";
    return 0;
}

