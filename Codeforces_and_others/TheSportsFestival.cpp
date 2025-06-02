#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

vector<vector<ll>> dp;
ll rec(ll start, ll end, vector<ll> &v)
{
    if (start == end)
        return 0;
    if (dp[start][end] == -1)
    {
        dp[start][end] = min(rec(start, end - 1, v), rec(start + 1, end, v)) + v[end] - v[start];
    }
    return dp[start][end];
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    dp.assign(n + 1, vector<ll>(n + 1, -1));
    for (i = 1; i <= n; i++)
        dp[i][i] = 0;
    vector<ll> v(n + 1, 0);
    for (i = 1; i <= n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    cout << rec(1, n, v) << endl;
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