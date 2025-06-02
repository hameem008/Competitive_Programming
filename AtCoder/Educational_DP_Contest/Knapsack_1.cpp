#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

ll dp[108][100008];

ll knapsack(ll ind, ll remw, vector<ll> &value, vector<ll> &weight)
{
    if (ind < 0 || remw == 0)
        return 0;
    if (dp[ind][remw] == -1)
    {
        ll a = knapsack(ind - 1, remw, value, weight);
        ll b = INT32_MIN;
        if (remw >= weight[ind])
            b = knapsack(ind - 1, remw - weight[ind], value, weight) + value[ind];
        dp[ind][remw] = max(a, b);
    }
    return dp[ind][remw];
}

void solve(int I, int T)
{
    ll i, j, k, a, w, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> w;
    vector<ll> value(n), weight(n);
    for (i = 0; i < n; i++)
    {
        cin >> weight[i] >> value[i];
    }
    cout << knapsack(n - 1, w, value, weight) << endl;
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int i = 0; i < 108; i++)
    {
        for (int j = 0; j < 100008; j++)
        {
            dp[i][j] = -1;
        }
    }
    ll T = 1;
    // cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}