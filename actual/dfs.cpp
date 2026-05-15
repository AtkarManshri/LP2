#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int> &vis , int &node, vector<vector<int>> &adj,vector<int> &dfslist)
{
   vis[node]=1;
   dfslist.push_back(node);
   for(auto it:adj[node])
   {
    if(!vis[it])
    {
        dfs(vis,it,adj,dfslist);
    }
   }

}

int main()
{
    int n; //nodes
    int m; //edges
  
    vector<int> dfslist;
    //adjacency list
    cout<<"enter n nodes";
    cin>>n;
    cout<<"enter m edge";
    cin>>m;

    vector<vector<int>> grid(n+1);

    vector<int> vis(n+1,0);
     for(int i = 1; i <= m; i++)
    {
        int u, v;
        cout<<"enter u";
        cin >> u;
        cout<<"enter v";
        cin>>v;

        grid[u].push_back(v);
        grid[v].push_back(u);
    }


    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            dfs(vis,i, grid,dfslist);
        }
    }
    cout<<"dfs";
    for(auto it: dfslist)
    {
        cout<<it<<"\t";
    }

    

}