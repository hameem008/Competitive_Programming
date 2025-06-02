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
    cin >> n >> m;
    vector<vector<ll>> dp(11, vector<ll>(1001, 0));
    dp[1][2] = dp[2][1] = 1;
    for (i = 3; i <= 1000; i++)
    {
        dp[1][i] = dp[1][i - 2];
    }
    for (i = 3; i <= 10; i++)
    {
        dp[i][1] = dp[i - 2][1];
    }
    dp[2][2] = 2;
    for (i = 3; i <= 1000; i++)
    {
        dp[2][i] += dp[2][i - 1];
        dp[2][i] %= mod;
        dp[2][i] += dp[2][i - 2];
        dp[2][i] %= mod;
    }
    for (i = 3; i <= 10; i++)
    {
        dp[i][2] += dp[i - 1][2];
        dp[i][2] %= mod;
        dp[i][2] += dp[i - 2][2];
        dp[i][2] %= mod;
    }
    for (i = 3; i <= 10; i++)
    {
        for (j = 3; j <= 1000; j++)
        {
            dp[i][j] += (dp[2][j] * dp[i - 2][j]) % mod;
            dp[i][j] %= mod;
            dp[i][j] += (dp[i][2] * dp[i][j - 2]) % mod;
            dp[i][j] %= mod;
        }
    }
    cout << dp[n][m] << endl;
    for (i = 1; i <= 7; i++)
    {
        for (j = 1; j <= 7; j++)
        {
            cout << dp[i][j] << gap;
        }
        cout << endl;
    }
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