#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;
const ll mod = 998244353;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<ll> v(n + 1, 0);
    for (i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    ll sum = accumulate(v.begin(), v.end(), 0LL);
    vector<vector<ll>> dp(n + 1, vector<ll>(sum + 1, 0));
    for (i = 0; i <= sum; i++)
    {
        dp[0][i] = 0;
    }
    for (i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= sum; j++)
        {
            dp[i][j] += dp[i - 1][j];
            dp[i][j] %= mod;
            if (j - v[i] >= 0)
            {
                dp[i][j] += dp[i - 1][j - v[i]];
                dp[i][j] %= mod;
            }
        }
    }
    vector<ll> ansv(n + 1, 0);
    for (i = 1; i <= n; i++)
    {
        ll ans = 0;
        ans += ansv[i - 1];
        ans %= mod;
        for (j = 0; j <= sum; j++)
        {
            if (v[i] > j)
            {
                ans += ((dp[i - 1][j] % mod) * (v[i] % mod)) % mod;
                ans %= mod;
            }
            else
            {
                ans += ((dp[i - 1][j] % mod) * ((v[i] + j + 1) / 2) % mod) % mod;
                ans %= mod;
            }
        }
        ansv[i] = ans;
    }
    cout << ansv[n] << endl;
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