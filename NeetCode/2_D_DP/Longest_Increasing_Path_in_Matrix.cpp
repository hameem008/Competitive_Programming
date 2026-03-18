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
    vector<vector<int>> dp;
    int n, m;
    int rec(int i, int j, vector<vector<int>> &matrix)
    {
        if (dp[i][j])
            return dp[i][j];
        if (i + 1 < n && matrix[i + 1][j] > matrix[i][j])
            dp[i][j] = max(dp[i][j], rec(i + 1, j, matrix));
        if (i - 1 >= 0 && matrix[i - 1][j] > matrix[i][j])
            dp[i][j] = max(dp[i][j], rec(i - 1, j, matrix));
        if (j + 1 < m && matrix[i][j + 1] > matrix[i][j])
            dp[i][j] = max(dp[i][j], rec(i, j + 1, matrix));
        if (j - 1 >= 0 && matrix[i][j - 1] > matrix[i][j])
            dp[i][j] = max(dp[i][j], rec(i, j - 1, matrix));
        dp[i][j]++;
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        n = matrix.size(), m = matrix[0].size();
        dp.assign(n, vector<int>(m, 0));
        int ret = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                ret = max(ret, rec(i, j, matrix));
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