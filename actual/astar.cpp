#include<bits/stdc++.h>
using namespace std;
int Astar(int V,
              vector<vector<pair<int,int>>> &adj,
              int src,
              int goal,
              vector<int>& heuristic) {

        vector<int> dist(V, 1e9);      // g-cost
        vector<int> parent(V, -1);     // for path reconstruction

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        dist[src] = 0;
        //pq {f,node}

        pq.push({heuristic[src], src});

        cout << "Step-by-step A* execution:\n";
        cout << "N\tg\t h\t f\n";

        while(!pq.empty()) {

            int f = pq.top().first; //fn val
            int node = pq.top().second; //node
            pq.pop();

            cout << node << "\t"
                 << dist[node] << "\t "
                 << heuristic[node] << "\t "
                 << f << endl;

            if(node == goal)
            {int finalans=dist[node];
                break;
            }

            for(auto it : adj[node]) {
                int next = it.first;
                int wt   = it.second;

                int newd = dist[node] + wt; 
                //diatnce it parent +dist of parent to child
                //only distance 

                if(newd < dist[next]) {
                    dist[next] = newd;
                    parent[next] = node;

                    int newF = newd + heuristic[next]; //newd +heuist of child =fn 
                    //push fn,next
                    pq.push({newF, next});
                }
            }
        }

        if(dist[goal] == 1e9)
            return -1;

        // Reconstruct path
        vector<int> path;
        for(int v = goal; v != -1; v = parent[v])
            path.push_back(v);

        reverse(path.begin(), path.end());

        cout << "\nFinal Path for cost:"<<dist[goal]<<"\n";

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
    vector<int> parent(n);
    vector<int> vis(n,0);
    vector<int> heuristic(n);
    vector<int> dist(n,1e9);

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
     heuristic[0]=0;
    for(int i=1;i<n;i++)
    {
      cout<<"enter heuristic "<<i;
      int val;
      cin>>val;
    }
    int src;
    cout<<"enter src";
    cin>> src;
    int goal;
    cout<<"enter goal";
    cin>> goal;

   Astar(n,grid,src,goal,heuristic);


  

    
}
