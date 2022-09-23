#include <bits/stdc++.h>
using namespace std;


bool bipartite(int node, int curr_color, map<int,vector<int> > mp, vector<int> &color)
{
	color[node] = curr_color;
	for(auto i : mp[node])
	{
		if(color[i] == -1)
            if(!bipartite(i, !curr_color, mp, color)) return false; 
		else if(color[i] == curr_color)
			return false;
	}
	return true;
}

int main() {
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
    vector<int> color(V+1, -1);
    for(int i=1; i<=V; i++)
    {
    	if(color[i] == -1)
    		if(!bipartite(i, 0, mp, color))
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