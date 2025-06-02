#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<ll> v(n + 1, 0);
    for (i = 1; i <= n; i++)
        cin >> v[i];
    ll dp[n + 1][n + 1];
    ll qry[n + 1][n + 1];
    for (i = 0; i <= n; i++)
    {
        qry[0][i] = 0;
        qry[1][i] = v[1];
    }
    for (i = 2; i <= n; i++)
    {
        qry[i][0] = INT64_MIN;
        for (j = 1; j <= n; j++)
        {
            if (i > j)
            {
                ll val = qry[i - j][j];
                if (val == INT64_MIN)
                    dp[i][j] = INT64_MIN;
                else
                    dp[i][j] = v[i] + val;
            }
            else
            {
                dp[i][j] = INT64_MIN;
            }
            qry[i][j] = dp[i][j];
        }
        for (j = n - 1; j >= 0; j--)
        {
            qry[i][j] = max(qry[i][j], qry[i][j + 1]);
        }
    }
    ll ans = INT64_MIN;
    for (i = 1; i <= n; i++)
    {
        ans = max(ans, dp[n][i]);
    }
    cout << ans << endl;
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