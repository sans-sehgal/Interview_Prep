#include <bits/stdc++.h>
using namespace std;


bool bipartite(int node, map<int,vector<int>> mp, int V, vector<int> &color)
{
	queue<int> q;
	color[node] = 0;
	q.push(node);
	while(!q.empty())
	{
		int front = q.front();
		q.pop();

		for(auto i:mp[front])
		{
			int prev_color = color[front];
			if(color[i] == -1)
			{
				color[i] = !(prev_color);
				q.push(i);
			}
			else if(color[i] == prev_color)
				return false;
		}
	}
	return true;
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
    vector<int> color(V+1, -1);
    for(int i=1; i<=V; i++)
    {
    	if(color[i] == -1)
    		if(!bipartite(i, mp, V, color))
    		{
    			cout<<"false";
    			return 0;
    		}
    }
    for(auto i : color)
    	cout<<i<<" ";
 	cout<<"true";
 	return 0;
}