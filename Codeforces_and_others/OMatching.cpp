#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;
const ll mod = 1e9 + 7;
vector<vector<ll>> dp;

ll rec(ll men, ll women, vector<vector<ll>> &mat, ll rem, ll n)
{
    if (rem == 0)
        return 1;
    else if (dp[men][women] == -1)
    {
        ll ans = 0;
        for (ll j = 0; j < n; j++)
        {
            ll check = women & (1 << j);
            if (mat[men][j] == 1 && check != 0)
            {
                ans += rec(men + 1, women ^ (1 << j), mat, rem - 1, n);
                ans %= mod;
            }
        }
        dp[men][women] = ans;
    }
    return dp[men][women];
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<vector<ll>> mat(n, vector<ll>(n));
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            cin >> mat[i][j];
    dp.assign(n, vector<ll>(1 << n, -1));
    cout << rec(0, (1 << n) - 1, mat, n, n) << endl;
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