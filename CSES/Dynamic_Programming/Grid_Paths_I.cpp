#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;
const ll mod = 1e9 + 7;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    char grid[n + 1][n + 1];
    ll dp[n + 1][n + 1];
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cin >> grid[i][j];
        }
    }
    if (grid[1][1] == '.')
        dp[1][1] = 1;
    else
        dp[1][1] = 0;
    for (i = 2; i <= n; i++)
    {
        if (grid[1][i] == '.')
            dp[1][i] = dp[1][i - 1];
        else
            dp[1][i] = 0;
    }
    for (i = 2; i <= n; i++)
    {
        if (grid[i][1] == '.')
            dp[i][1] = dp[i - 1][1];
        else
            dp[i][1] = 0;
    }
    for (i = 2; i <= n; i++)
    {
        for (j = 2; j <= n; j++)
        {
            if (grid[i][j] == '.')
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                dp[i][j] %= mod;
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    cout << dp[n][n] << endl;
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