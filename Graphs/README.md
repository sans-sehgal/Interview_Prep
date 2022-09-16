## Graphs – Important notes and Questions

1) Most important algo, BFS. 
Fringe List: Queue. Works on a FIFO basis. 
```
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
```

2) DFS is as important. Write recusrsive code. 
Fringe List: Can use stack as fringle list if required. Works on a LIFO basis. 
```
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
 
    vector <int> vis (V+1 , 0);
    vector <int> dfs;
    for(int i=1; i<=V; i++)
    {
        if(!vis[i])
            dfs_graph(i, vis, V, mp, dfs);
    }
    return 0;
}

```

3)  Bipartite Graph defintition (not official): A graph that can be coloured using two colours such that no two adjacent nodes are of the same color. <br>  
```
// Checking bipartite using BFS

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

int main() 
{
    map <int , vector <int>> mp;
    int V, E;
    cin>>V>>E;
    vector <color> (V , -1);
    for(int i=1; i<=V; i++)
    {
        if(color[i] == -1)
            if(!bipartite(i, mp, V, color))
            {
                cout<<"false";
                return 0;
            }
    }
    cout<<"true";
}
```
```
// Checking Bipartite using DFS

bool bipartite(int node, int curr_color, map<int,vector<int>> mp, vector<int> &color)
{
    color[node] = curr_color;
    for(auto i : mp[node])
    {
        if(color[i] == -1)
            return if(!bipartite(i, !curr_color, mp, color)) return false; //this is an important an necessary condition you cant just 
                                                                            // return the function  
        else if(color[i] == curr_color)
            return false;
    }
    return true;
}

int main() {
    map <int , vector <int>> mp;
    int V, E;
    
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
    cout<<"true";
    return 0;
}
```

4) Code for cycle detection in present in the files uploaded, have a look for both BFS and DFS. 