#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

vector<vector<ll>> dp;
ll rec(vector<ll> &v, ll pos, ll n)
{
    if (n == 0)
        return 0;
    if (dp[n][pos] == -1)
    {
        ll val = infinite;
        for (int i = n - 1; i < pos; i++)
        {
            val = min(val, rec(v, i, n - 1) + abs(pos - v[n]));
        }
        dp[n][pos] = val;
    }
    return dp[n][pos];
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    dp.clear();
    // solve starts
    cin >> n;
    vector<ll> v(n + 1, 0);
    for (i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    dp.assign(n + 10, vector<ll>(410, -1));
    ll ans = infinite;
    for (i = n; i <= 401; i++)
    {
        ans = min(ans, rec(v, i, n));
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
    cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}