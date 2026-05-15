#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {

        int count = 0;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int,int>> q;

        // First & last row
        for(int j = 0; j < m; j++) {
            if(grid[0][j] == 1) {
                q.push({0, j});
                vis[0][j] = 1;
            }
            if(grid[n-1][j] == 1) {
                q.push({n-1, j});
                vis[n-1][j] = 1;
            }
        }

        // First & last column
        for(int i = 0; i < n; i++) {
            if(grid[i][0] == 1) {
                q.push({i, 0});
                vis[i][0] = 1;
            }
            if(grid[i][m-1] == 1) {
                q.push({i, m-1});
                vis[i][m-1] = 1;
            }
        }

        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        // BFS
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m &&
                   grid[nr][nc] == 1 && vis[nr][nc] == 0) {

                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }

        // Count enclaves
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && vis[i][j] == 0)
                    count++;
            }
        }

        return count;
    }
};

int main() {
    vector<vector<int>> grid = {
        {0,0,0,0},
        {1,0,1,0},
        {0,1,1,0},
        {0,0,0,0}
    };

    Solution obj;
    cout << "Number of enclaves: " << obj.numEnclaves(grid);

    return 0;
}
