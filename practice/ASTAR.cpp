#include <bits/stdc++.h>
using namespace std;
void astar(  vector<vector<pair<int,int>>> &adj, vector<int> &heuristic,int goal,int src,int n)
{   vector<int> parent(n,-1);
    vector<int> path;
    vector<int> dist(n,1e9);
    dist[src]=0;
  
    //f,n
    priority_queue<pair<int,int> ,vector<pair<int,int>> , greater<pair<int,int>>> pq;
      pq.push({heuristic[src],src});//rmebr
      
    while(!pq.empty())
    {
        
        int node=pq.top().second;
        int d=dist[node];//rmebr
        
        pq.pop();
        for(auto it:adj[node])
        {
            int cnode=it.first;
            int w=it.second;
            
            if(d+w<dist[cnode]) //rembr
            {
                dist[cnode]=d+w;
                parent[cnode]=node;
                int newf=dist[cnode]+heuristic[cnode];//rmenr
                
                pq.push({newf,cnode});
            }
        }
    }
    
    int node=goal;
    while(node!=src)
    { 
        path.push_back(node);
        node=parent[node];
        
    }
    path.push_back(src);
    reverse(path.begin(),path.end());
    cout<<"path with cost"<<dist[goal];
    cout<<endl;
    for(auto it: path)
    {
        cout<<it;
        
    }
    
    
    
}

int main()
{
    int n,e;
    cout<<"entr nodes";
    cin>>n;
    cout<<"enter edges";
    cin>>e;
    vector<vector<pair<int,int>>> adj(n); //rmebr
    for(int i=0;i<e;i++)
    {
        int u,v,w;
        cout<<"enter u";
        cin>>u;
        cout<<"neter v";
        cin>>v;
        cout<<"netr w";
        cin>>w;
        
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    cout<<"enter src";
    int src;
    cin>>src;
    
    cout<<"enter goal";
    int goal;
    cin>>goal;
    vector<int> heuristic(n);
    for(int i=0;i<n;i++)
    {
        cout<<"enter heuristic valeue for"<<i;
        cin>>heuristic[i];
    }
    
    astar(adj,heuristic,goal,src,n);
    
}