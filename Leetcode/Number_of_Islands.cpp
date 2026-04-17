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
    void dfs(vector<vector<char>> &grid, int n, int m)
    {
        if (n < 0 || n == rows || m < 0 || m == cols)
            return;
        if (grid[n][m] == '0')
            return;
        grid[n][m] = '0';
        dfs(grid, n + 1, m);
        dfs(grid, n - 1, m);
        dfs(grid, n, m + 1);
        dfs(grid, n, m - 1);
    }
    int numIslands(vector<vector<char>> &grid)
    {
        rows = grid.size();
        cols = grid[0].size();
        int ret = 0;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (grid[i][j] == '1')
                    ret++, dfs(grid, i, j);
        return ret;
    }
};

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts

    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll T = 1;
    cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}