#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll mod = 1e9 + 7;

ll dp[101][100001];

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> m;
    vector<ll> v(n + 1);
    for (i = 1; i <= n; i++)
        cin >> v[i];

    if (v[1] == 0)
    {
        for (i = 1; i <= m; i++)
            dp[i][1] = 1;
    }
    else
    {
        dp[v[1]][1] = 1;
    }

    for (i = 2; i <= n; i++)
    {
        if (v[i] == 0)
        {
            for (j = 1; j <= m; j++)
            {
                ll lim = 3;
                k = -1;
                while (lim--)
                {
                    if (j + k >= 1 && j + k <= m)
                    {
                        dp[j][i] = (dp[j][i] + dp[j + k][i - 1]) % mod;
                    }
                    k++;
                }
            }
        }
        else
        {
            j = v[i];
            ll lim = 3;
            k = -1;
            while (lim--)
            {
                if (j + k >= 1 && j + k <= m)
                {
                    dp[j][i] = (dp[j][i] + dp[j + k][i - 1]) % mod;
                }
                k++;
            }
        }
    }
    ll ans = 0;
    for (i = 1; i <= m; i++)
    {
        ans = (ans + dp[i][n]) % mod;
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