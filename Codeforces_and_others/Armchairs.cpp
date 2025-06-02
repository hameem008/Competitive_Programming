#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

vector<vector<ll>> dp;
ll rec(ll i, ll j, vector<ll> &empty, vector<ll> &full)
{
    if (i == full.size())
        return 0;
    else if (j == empty.size())
        return infinite;
    if (dp[i][j] == -1)
    {
        dp[i][j] = min(rec(i + 1, j + 1, empty, full) + abs(full[i] - empty[j]), rec(i, j + 1, empty, full));
    }
    return dp[i][j];
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    dp.assign(n + 1, vector<ll>(n + 1, -1));
    vector<ll> v(n + 1);
    for (i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    vector<ll> full, empty;
    for (i = 1; i <= n; i++)
    {
        if (v[i])
            full.push_back(i);
        else
            empty.push_back(i);
    }
    cout << rec(0, 0, empty, full) << endl;
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