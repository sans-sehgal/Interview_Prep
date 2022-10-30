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

bool bfs(int node, vector<vector<int>> graph, vector<int> &color, int curr_color)
{
    queue<int> q;
    q.push(node);
    color[node] = curr_color;
    while(!q.empty())
    {
        int n = q.front();
        q.pop();
        curr_color = color[n];
        for(auto i : graph[n])
        {
            if(color[i] == -1)
            {
                color[i] = 1 - curr_color;
                q.push(i);
            }
            else if(color[i] == color[n])
                return false;
        }
    }
    return true;
}


bool isBipartite(vector<vector<int>>& graph) 
{
    vector<int> color(graph.size(), -1);
    int curr_color = 0;
    for(int i=0; i<graph.size(); i++)
    {
        if(color[i] == -1 && !bfs(i, graph, color, curr_color))
            return false;
    }
    return true;
}

```
```
// Checking Bipartite using DFS

bool checkBipartiteDFS(int node, vector<vector<int>> graph, vector<int> &color, int prev_color)
{
    prev_color = 1 - prev_color;
    color[node] = prev_color;
    for(auto i : graph[node])
    {
        if(color[i] == -1)
            if(checkBipartiteDFS(i, graph, color, prev_color) == false) return false;
        if(color[i] == color[node])
        {
            return false;
        }
    }
    return true;
}


bool isBipartite(vector<vector<int>>& graph) 
{
    vector<int> color(graph.size(), -1);
    int prev_color = 1;
    bool ans = true;
    for(int i=0; i<graph.size(); i++)
    {
        if(color[i] == -1 && checkBipartiteDFS(i, graph, color, prev_color) == false)
            return false;
    }
    for(auto i:color)
        cout<<i<<" ";
    cout<<endl;
    return true;
}
```

4) Code for cycle detection is present in the files uploaded, have a look for both BFS and DFS. For both directed and undirected graphs. <br>

5) Topoogical Sorting: Linear ordering of vertices such that if there is an edge between u->v, 'u' appears before 'v' in that ordering. Ofcourse, this can only be done for directed graphs <br>
```
// Code for topological sort DFS

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
}
```
```
//code for topological sort using BFS. This is also called kahns algo. 

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
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto i :mp[node])
        {
            indegree[i]--;
            if(indegree[i] == 0)
                q.push(i);
        }
    }
}

```
