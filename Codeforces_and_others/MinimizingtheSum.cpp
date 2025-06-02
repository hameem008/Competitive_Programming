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
    cin >> n >> k;
    vector<ll> v(n + 1, 0);
    for (i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, infinite));
    dp[0][0] = 0;
    for (i = 0; i <= k; i++)
    {
        dp[0][i] = 0;
    }

    for (i = 1; i <= n; i++)
    {
        dp[i][0] = dp[i - 1][0] + v[i];
    }
    for (i = 0; i <= n - 1; i++)
    {
        for (j = 0; j <= k; j++)
        {
            ll curr_min = infinite;
            for (ll l = 0; l <= k - j; l++)
            {
                if (i + l + 1 > n)
                    break;
                curr_min = min(curr_min, v[i + l + 1]);
                dp[i + l + 1][j + l] = min(dp[i + l + 1][j + l], dp[i][j] + (l + 1) * curr_min);
            }
        }
    }
    cout << dp[n][k] << endl;
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