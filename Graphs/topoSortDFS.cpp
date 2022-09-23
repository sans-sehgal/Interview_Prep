#include <bits/stdc++.h>
using namespace std;


void topoSort(int node, vector<int> &vis, stack<int> &st, map<int,vector<int> >mp)
{
	vis[node] = 1;

	for(auto i:mp[node])
	{
		if(!vis[i])
			topoSort(i,vis,st,mp);
	}

	st.push(node);
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
    stack <int> st;
    for(int i=1; i<=V; i++)
    {
        if(!vis[i])
        	topoSort(i, vis, st, mp);
    }
    while(!st.empty())
    {
    	cout<<st.top()<<" ";
    	st.pop();
    }
    return 0;
}