#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

class Solution
{
public:
    int rows, cols;
    void dfs(vector<vector<char>> &board, int n, int m)
    {
        if (n == -1 || n == rows || m == -1 || m == cols)
            return;
        if (board[n][m] != 'O')
            return;
        board[n][m] = '#';
        dfs(board, n + 1, m);
        dfs(board, n - 1, m);
        dfs(board, n, m + 1);
        dfs(board, n, m - 1);
    }
    void solve(vector<vector<char>> &board)
    {
        rows = board.size(), cols = board[0].size();
        for (int i = 0; i < rows; i++)
        {
            if (board[i][0] == 'O')
                dfs(board, i, 0);
            if (board[i][cols - 1] == 'O')
                dfs(board, i, cols - 1);
        }
        for (int j = 0; j < cols; j++)
        {
            if (board[0][j] == 'O')
                dfs(board, 0, j);
            if (board[rows - 1][j] == 'O')
                dfs(board, rows - 1, j);
        }
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
    }
};

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    vector<vector<char>> board = {{'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'X', 'O'}};
    Solution sl;
    sl.solve(board);
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll T = 1;
    // cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}