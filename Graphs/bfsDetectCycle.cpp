// Cycle in undirected Graph using BFS

#include <bits/stdc++.h>
using namespace std;

bool detectCycleBFS(pair<int,int> p, map <int,vector<int>> mp,  vector<int> &vis)
{
    vector <int> bfs; 
    queue <pair<int,int>> q;
    q.push(p);
    vis[p.first] = 1;
    while(!q.empty())
    {
        int n = q.front().first;
        int p = q.front().second;
        q.pop();
        bfs.push_back(n);
        for(auto i : mp[n])
        {
            if(vis[i] == 1 && i!=p)
                return true;
            else if(vis[i] == 0)
            {
                q.push({i , n});
                vis[i] = 1;
            }
        }

    }
    return false;
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
    vector <int> vis(V+1 , 0);
    bool val;

    for(int i=1; i<=V; i++)
    {
        if(!vis[i])
        {
            vis[i] = 1;
            pair<int,int>p = {i , -1};
            if (detectCycleBFS(p, mp, vis)) 
            {
                cout<<"true";
                return 0;
            }
        }
    }
    cout<<"false";
    return 0;
}

