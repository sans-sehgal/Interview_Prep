#include <bits/stdc++.h>
using namespace std;

// We need a queue, an indegree datastructure and we DO NOT need a visited data structure. 
// this is also known as the kahns algorithm


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
    vector<int> indegree(V+1);
    vector <int> topo;
    queue <int> q;
    for(int i=1; i<=V; i++)
    {
        for(auto j : mp[i])
            indegree[j]++;
    }
    for(int i=1; i<=V; i++)
        if(indegree[i] == 0)
            q.push(i);
    // int cnt = 0;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        // cnt++;
        for(auto i :mp[node])
        {
            indegree[i]--;
            if(indegree[i] == 0)
                q.push(i);
        }
    }
    
    
    // this check is to ensure if the topo sort is correct of if there is a cycle in the graph. 
    // it can be a cycle detection test in a DAG.
    // instead of size, a cnt can be used (see comments), especially if topo elements are not needed. Cnt is much faster.
    
    if(topo.size() == V)
    {
        cout<<"True"<<endl;
        for(auto i : topo)
            cout<<i<<" ";
    }
    else
        cout<<"False"<<endl;
    
    return 0;
}