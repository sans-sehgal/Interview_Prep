#include <bits/stdc++.h>
using namespace std;

void shortest_path(map<int,vector<int> > mp, vector<int> &dist, int src)
{
    dist[src] = 0;
    queue <int> q;
    q.push(src);
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto i : mp[node])
        {
            if(dist[node] + 1 < dist[i])
            {
                dist[i] = dist[node] + 1;
                q.push(i);
            }
        }
    }
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
        mp[v2].push_back(v1);
    }
	for(auto i : mp)
    {
        cout<<i.first<<"->";
        for(auto j : i.second)
            cout<<j<<", ";
        cout<<endl;
    }
    vector <int> dis(V+1 , INT_MAX);
    shortest_path(mp, dis, 0);
    for(auto i : dis)
        cout<<i<<" ";
    return 0;
}
