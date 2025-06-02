#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;
const ll N = 1e6 + 8;
const ll mod = 1e9 + 7;

ll dp[N];

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> k;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    dp[0] = 1;
    for (i = 1; i <= k; i++)
    {
        ll ans = 0;
        for (auto x : v)
        {
            if (i - x >= 0)
            {
                ans += dp[i - x];
                ans %= mod;
            }
        }
        dp[i] = ans;
    }
    cout << dp[k] << endl;
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