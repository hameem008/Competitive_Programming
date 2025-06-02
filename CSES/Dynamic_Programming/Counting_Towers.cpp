#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;
const ll mod = 1e9 + 7;

vector<vector<ll>> dp;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    cout << (dp[1][n] + dp[2][n]) % mod << endl;
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n = 1e6 + 8;
    dp.assign(3, vector<ll>(n + 1, 0));
    dp[1][1] = dp[2][1] = 1;
    for (ll i = 2; i <= n; i++)
    {
        dp[1][i] = dp[2][i - 1] + 4 * dp[1][i - 1];
        dp[1][i] %= mod;
        dp[2][i] = dp[1][i - 1] + 2 * dp[2][i - 1];
        dp[2][i] %= mod;
    }
    
    ll T = 1;
    cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}