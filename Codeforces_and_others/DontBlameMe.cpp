#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;
const ll N = 2e5 + 10;
const ll mod = 1e9 + 7;

ll dp[N][128];
vector<ll> v;
ll k;

ll rec(ll index, ll AND)
{
    if (index == v.size())
    {
        if (AND == 127)
            return 0;
        if (bitset<6>(AND).count() == k)
            return 1;
        return 0;
    }

    if (dp[index][AND] == -1)
    {
        ll take = rec(index + 1, v[index] & AND);
        ll notTake = rec(index + 1, AND);
        dp[index][AND] = (take + notTake) % mod;
    }

    return dp[index][AND];
}

void solve(int I, int T)
{
    ll i, j, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> k;
    v.clear();
    for (i = 0; i < n; i++)
    {
        cin >> a;
        v.push_back(a);
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= 127; j++)
        {
            dp[i][j] = -1;
        }
    }
    cout << rec(0, 127) << endl;
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