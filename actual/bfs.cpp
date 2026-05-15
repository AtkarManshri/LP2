#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n; //nodes
    int m; //edges
  
    vector<int> bfslist;
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
    queue<int> q;
    q.push(0);
   
    while(!q.empty())
    {
        int node=q.front();
        vis[node]=1;
        q.pop();
        bfslist.push_back(node);
        for(auto it:grid[node])
        {

          if(vis[it]==0)
          {
            vis[it] = 1;
            q.push(it);
          }
        }
    }

    for(auto it : bfslist)
    {
        cout<<it;
        }
    

}