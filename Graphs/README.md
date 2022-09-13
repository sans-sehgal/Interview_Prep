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
