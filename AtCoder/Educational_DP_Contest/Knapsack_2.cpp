#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

ll dp[108][100008];
ll knapsack(ll ind, ll val, vector<ll> &value, vector<ll> &weight)
{
    if (val == 0)
        return 0;
    if (ind < 0)
        return 1e15;
    if (dp[ind][val] == -1)
    {
        ll a = knapsack(ind - 1, val, value, weight);
        ll b = 1e15;
        if (val >= value[ind])
            b = knapsack(ind - 1, val - value[ind], value, weight) + weight[ind];
        dp[ind][val] = min(a, b);
    }
    return dp[ind][val];
}

void solve(int I, int T)
{
    ll i, j, k, a, w, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> w;
    vector<ll> value(n), weight(n);
    ll sum = 0;
    for (auto x : value)
        sum += x;
    for (i = 0; i < n; i++)
        cin >> weight[i] >> value[i];
    for (i = 1e5; i >= 0; i--)
    {
        a = knapsack(n - 1, i, value, weight);
        if (a <= w)
        {
            cout << i << endl;
            break;
        }
    }
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