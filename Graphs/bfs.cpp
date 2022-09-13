#include <bits/stdc++.h>
using namespace std;

vector<int> bfs_graph(map<int, vector<int>> mp, int V)
{
    vector <int> vis (V+1 , 0);
    vector <int> bfs;
    for(int i=1; i<=V; i++)
    {
        if(vis[i]==0)
        {
            vis[i] = 1;
            queue <int> q;
            q.push(i);
            while(!q.empty())
            {
                int node = q.front();
                q.pop();
                bfs.push_back(node);

                for(auto j : mp[node])
                    if(vis[j]==0)
                    {
                        q.push(j);
                        vis[j] = 1;
                    }
            }
        }
    }
    return bfs;
}

int main() {
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
    vector <int> bfs = bfs_graph(mp, V);
    for(auto i : bfs)
        cout<<i<<" ";
    return 0;
}

