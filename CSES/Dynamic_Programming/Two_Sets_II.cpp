#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;
const ll mod = 1e9 + 7;

ll dp[501][62876];

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<ll> v(n + 1);
    for (i = 1; i <= n; i++)
        v[i] = i;
    if (n * (n + 1) % 4 != 0)
    {
        cout << 0 << endl;
        return;
    }
    k = n * (n + 1) / 4;
    dp[0][0] = 1;
    for (i = 1; i <= k; i++)
    {
        for (j = 1; j <= n; j++)
        {
            dp[j][i] = dp[j - 1][i];
            if (i - v[j] == 0)
            {
                dp[j][i] += 1;
                dp[j][i] %= mod;
            }
            else if (i - v[j] > 0)
            {
                dp[j][i] += dp[j - 1][i - v[j]];
                dp[j][i] %= mod;
            }
        }
    }
    dp[n][k] % 2 == 0 ? cout << dp[n][k] / 2 << endl : cout << ((dp[n][k] + mod) / 2) % mod << endl;
    //  solve ends
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