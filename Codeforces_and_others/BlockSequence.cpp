#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

vector<ll> dp;
ll rec(ll n, ll k, vector<ll> &v)
{
    if (k == n + 1)
        return 0;
    else if (k > n + 1)
        return infinite;
    if (dp[k] == -1)
    {
        dp[k] = min(1 + rec(n, k + 1, v), rec(n, k + v[k] + 1, v));
    }
    return dp[k];
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<ll> v(n + 1);
    dp.clear();
    dp.assign(n + 1, -1);
    for (i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    cout << rec(n, 1, v) << endl;
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