#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isSafe(vector<string> &board, int row, int col, int n)
    {
        for(int j = 0; j < n; j++)
        {
            if(board[row][j] == 'Q')
            {
                return false;
            }
        }

        for(int i = 0; i < n; i++)
        {
            if(board[i][col] == 'Q')
            {
                return false;
            }
        }

        // left diagonal
        int i = row, j = col;

        while(i >= 0 && j >= 0)
        {
            if(board[i][j] == 'Q')
            {
                return false;
            }

            i--;
            j--;
        }

        // right diagonal
        i = row;
        j = col;

        while(i >= 0 && j < n)
        {
            if(board[i][j] == 'Q')
            {
                return false;
            }

            i--;
            j++;
        }

        return true;
    }

    void nqueen(vector<string> &board,
                int n,
                int row,
                vector<vector<string>> &ans)
    {
        if(row == n)
        {
            ans.push_back(board);
            return;
        }

        for(int j = 0; j < n; j++)
        {
            if(isSafe(board, row, j, n))
            {
                board[row][j] = 'Q';

                nqueen(board, n, row + 1, ans);

                board[row][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;

        vector<string> board(n, string(n, '.'));

        nqueen(board, n, 0, ans);

        return ans;
    }
};

int main()
{
    int n;

    cout << "Enter n: ";
    cin >> n;

    Solution obj;

    vector<vector<string>> ans = obj.solveNQueens(n);

    cout << "All Possible Solutions:\n\n";

    for(int i = 0; i < ans.size(); i++)
    {
        cout << "Solution " << i + 1 << ":\n";

        for(auto row : ans[i])
        {
            cout << row << endl;
        }

        cout << endl;
    }

    return 0;
}