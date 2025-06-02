#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

ll dp[501][501];

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> m;
    dp[1][1] = 0;
    for (i = 2; i <= m; i++)
    {
        dp[1][i] = i - 1;
    }
    for (i = 2; i <= n; i++)
    {
        dp[i][1] = i - 1;
    }
    for (i = 2; i <= n; i++)
    {
        for (j = 2; j <= m; j++)
        {
            if (i != j)
            {
                ll ans = infinite;
                for (k = 1; k <= i - 1; k++)
                {
                    ans = min(ans, dp[i - k][j] + 1 + dp[k][j]);
                }
                for (k = 1; k <= j - 1; k++)
                {
                    ans = min(ans, dp[i][j - k] + 1 + dp[i][k]);
                }
                dp[i][j] = ans;
            }
        }
    }
    cout << dp[n][m] << endl;
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