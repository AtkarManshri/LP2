#include <bits/stdc++.h>
using namespace std;

void dijk(vector<int> &dist, vector<int> &parent, vector<vector<pair<int,int>>> &adj ,int src,int goal)
{

    //dist , node
    priority_queue< pair<int,int> ,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,src});
    dist[src]=0;
    while(!pq.empty())
    {
        int pnode=pq.top().second;
        int pd=pq.top().first;
        pq.pop();

       
        for(auto it: adj[pnode])
        {
              int child=it.first;
              int cd=it.second;

              if(pd+cd < dist[child])
              {
                dist[child]=pd+cd;
                parent[child]=pnode;
                pq.push({dist[child],child});
              }
        

    }
             
        }
    vector<int> path;
    //contructing path
            int node=goal;
            while(node !=src)
            {
            path.push_back(node);
            node=parent[node];  //remebr

            }
    path.push_back(src);
    reverse(path.begin(),path.end());

    for(auto it:  path)
    {
        cout<<it <<" ";

    }
    cout<<dist[goal]<<"ist dist"; 
    


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

    vector<vector<pair<int,int>>> grid(n+1);

    vector<int> dist(n+1,1e9);
     for(int i = 1; i <= m; i++)
    {
        int u, v,w;
        cout<<"enter u";
        cin >> u;
        cout<<"enter v";
        cin>>v;
         cout<<"enter w";
        cin>>w;

        grid[u].push_back({v,w});
        grid[v].push_back({u,w});
    }


   vector<int> parent(n+1);
   for(int i=0;i<n;i++)
   {
    parent[i]=i;
   }

 int src, goal;

    cout << "Enter source: ";
    cin >> src;

    cout << "Enter destination: ";
    cin >> goal;

    dijk(dist, parent, grid, src, goal);
    

}
