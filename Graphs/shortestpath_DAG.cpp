#include <bits/stdc++.h>
using namespace std;

void topoSort(stack<int> &st, int node, map<int,vector<pair<int,int> > >mp, vector<int> &vis)
{
    vis[node] = 1;
    for(auto i : mp[node])
        if(!vis[i.first])
            topoSort(st, i.first, mp, vis);
    st.push(node);
}

void shortestPathDAG(stack<int> st, int src, int V , map <int,vector<pair<int,int> > > mp)
{
    vector<int> dis(V, INT_MAX);
    dis[src] = 0;
    
    while(!st.empty())
    {
        int node = st.top();
        st.pop();
        // this is a required condition since if you cannot reach certain nodes from your source they will continue to be INT_MAX
        if(dis[node]!=INT_MAX)
        {
            for(auto i:mp[node])
            {
                if(dis[i.first] > i.second + dis[node])
                    dis[i.first] = dis[node] + i.second;
            }
        }
    }
    for(auto d : dis)
        cout<<d<<" ";
}

int main() 
{
    map <int , vector <pair<int,int> > > mp;
    int V, E;
    cin>>V>>E;
    for(int i=0; i<E; i++)
    {
        int v1,v2,w;
        cin>>v1>>v2>>w;
        pair<int,int> p = make_pair(v2,w);
        mp[v1].push_back(p);
    }
	for(auto i : mp)
    {
        cout<<i.first<<"->";
        for(auto j : i.second)
            cout<<j.first<<" "<<j.second<<", ";
        cout<<endl;
    }
    stack <int> st;
    vector<int> vis(V, 0);
    topoSort(st, 0, mp, vis);
    shortestPathDAG(st, 0, V, mp);

    return 0;
}