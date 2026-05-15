#include <bits/stdc++.h>
using namespace std;

/* -------- DFS (Recursive) -------- */
void dfs(int node, vector<int> adj[], vector<int>& vis) {
    vis[node] = 1;
    cout << node << " ";

    for (int neigh : adj[node]) {
        if (!vis[neigh]) {
            dfs(neigh, adj, vis);
        }
    }
}

/* -------- BFS -------- */
void bfs(int start, vector<int> adj[], int V) {
    vector<int> vis(V, 0);
    queue<int> q;

    vis[start] = 1;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neigh : adj[node]) {
            if (!vis[neigh]) {
                vis[neigh] = 1;
                q.push(neigh);
            }
        }
    }
}


int main() {
    int V = 5;
    vector<int> adj[V];

    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 4};
    adj[3] = {1};
    adj[4] = {2};

    vector<int> vis(V, 0);

    cout << "DFS Traversal: ";
    dfs(0, adj, vis);

    cout << "\nBFS Traversal: ";
    bfs(0, adj, V);

    return 0;
}
