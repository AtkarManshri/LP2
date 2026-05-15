#include<bits/stdc++.h>
using namespace std;

void prims(vector<int> &vis,
           vector<int> &parent,
           vector<vector<pair<int,int>>> &adj,
           int src)
{
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    // {weight,node}
    pq.push({0,src});

    int sum = 0;

    while(!pq.empty())
    {
        int wt = pq.top().first;
        int node = pq.top().second;

        pq.pop();

        // skip if already visited
        if(vis[node] == 1)
            continue;

        vis[node] = 1;

        sum += wt;

        for(auto it : adj[node])
        {
            int dist = it.first;
            int cnode = it.second;

            if(!vis[cnode])
            {
                pq.push({dist,cnode});
                parent[cnode] = node;
            }
        }
    }

    cout << "\nMinimum Spanning Tree Edges:\n";

    for(int i=0;i<parent.size();i++)
    {
        if(i != src)
        {
            cout << parent[i] << " -> " << i << endl;
        }
    }

    cout << "\nMinimum Cost = " << sum << endl;
}

int main()
{
    int n,m;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> m;

    // adjacency list
    vector<vector<pair<int,int>>> grid(n);

    vector<int> vis(n,0);

    for(int i=0;i<m;i++)
    {
        int u,v,w;

        cout << "\nEnter u: ";
        cin >> u;

        cout << "Enter v: ";
        cin >> v;

        cout << "Enter weight: ";
        cin >> w;

        // {weight,node}
        grid[u].push_back({w,v});
        grid[v].push_back({w,u});
    }

    vector<int> parent(n);

    for(int i=0;i<=n;i++)
    {
        parent[i] = -1;
    }

    int src;

    cout << "\nEnter source node: ";
    cin >> src;

    parent[src] = src;

    prims(vis,parent,grid,src);

    return 0;
}