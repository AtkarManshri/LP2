#include <bits/stdc++.h>
using namespace std;
void bfs(    vector<vector<int>>  &adj,int src,int n)
{
    vector<int> vis(n,0);
  
    queue<int> q;
      q.push(src);
      vis[src]=1;
    vector<int> bfsl;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
       
        bfsl.push_back(node);
        for(auto it:adj[node])
        {
            if(!vis[it])
            {   vis[it]=1;//remer
                q.push(it);
            }
        }
        
        
    }
    
    for(auto it:bfsl)
    {
        cout<<it<<"\n";
    }
    
}

void dfs(vector<int> &vis,int node,  vector<vector<int>>  &adj,vector<int> &dfsl)
{
    vis[node]=1;
    dfsl.push_back(node);
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            dfs(vis,it,adj,dfsl);
        }
    }
}

int main()
{
    int n,e;
    cout<<"entr nodes";
    cin>>n;
    cout<<"enter edges";
    cin>>e;
    vector<vector<int>> adj(n); //rmebr
    for(int i=0;i<e;i++)
    {
        int u,v,w;
        cout<<"enter u";
        cin>>u;
        cout<<"neter v";
        cin>>v;
        
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<"enter src";
    int src;
    cin>>src;
    cout<<"bfs";
    bfs(adj,src,n);
    vector<int> vis(n,0);
    vector<int> dfsl;
    
    cout<<"dfs";
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {   cout<<"component ";
            dfs(vis,i,adj,dfsl);
        }
    }
    
    for(auto it:dfsl)
    {
        cout<<it<<"\n";
    }
    
    
    
}