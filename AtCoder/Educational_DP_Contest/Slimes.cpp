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
    vector<ll> presum(n + 1, 0);
    for (i = 1; i <= n; i++)
        presum[i] = v[i] + presum[i - 1];
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));
    for (k = 1; k <= n - 1; k++)
    {
        for (i = 1; i + k <= n; i++)
        {
            ll min_cost = infinite;
            for (c = i; c <= i + k - 1; c++)
            {
                min_cost = min(min_cost, dp[i][c] + dp[c + 1][i + k]);
            }
            dp[i][i + k] = min_cost + presum[i + k] - presum[i - 1];
        }
    }
    cout << dp[1][n] << endl;
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