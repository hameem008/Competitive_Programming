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
    void dfs(vector<vector<int>> &grid, int val, int n, int m)
    {
        if (n < 0 || n >= grid.size() || m < 0 || m >= grid[0].size())
            return;
        if (val == 0 || val < grid[n][m])
        {
            grid[n][m] = val;
            dfs(grid, val + 1, n + 1, m);
            dfs(grid, val + 1, n - 1, m);
            dfs(grid, val + 1, n, m + 1);
            dfs(grid, val + 1, n, m - 1);
        }
    }
    void islandsAndTreasure(vector<vector<int>> &grid)
    {
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                if (grid[i][j] == 0)
                    dfs(grid, 0, i, j);
        return;
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