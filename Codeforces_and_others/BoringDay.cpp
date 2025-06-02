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
    cin >> n >> p >> q;
    vector<ll> v(n + 2, 0);
    for (i = 1; i <= n; i++)
        cin >> v[i];
    for (i = n; i >= 0; i--)
    {
        v[i] += v[i + 1];
    }
    vector<ll> dp(n + 1, 0);
    for (i = 1; i <= n; i++)
    {
        dp[i] = dp[i - 1];
        ll dum_p = p + v[i + 1];
        ll dum_q = q + v[i + 1];
        ll ind = v.rend() - lower_bound(v.rbegin(), v.rend(), dum_p) - 2;
        if (ind > -1)
        {
            ll val = *lower_bound(v.rbegin(), v.rend(), dum_p);
            if (val <= dum_q)
                dp[i] = max(dp[i], dp[ind] + 1);
        }
    }
    cout << dp[n] << endl;
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