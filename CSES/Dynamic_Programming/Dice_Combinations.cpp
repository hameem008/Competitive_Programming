#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;
const ll N = 1e6 + 1;
const ll mod = 1e9 + 7;
 
ll dp[N];
 
void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    dp[0] = 1;
    dp[1] = dp[0];
    dp[2] = dp[1] + dp[0];
    dp[3] = dp[2] + dp[1] + dp[0];
    dp[4] = dp[3] + dp[2] + dp[1] + dp[0];
    dp[5] = dp[4] + dp[3] + dp[2] + dp[1] + dp[0];
    dp[6] = dp[5] + dp[4] + dp[3] + dp[2] + dp[1] + dp[0];
    cin >> n;
    for (i = 7; i <= n; i++)
    {
        ll put = 0;
        for (j = 1; j <= 6; j++)
        {
            put += dp[i - j];
            put %= mod;
        }
        dp[i] = put;
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
    // cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}
