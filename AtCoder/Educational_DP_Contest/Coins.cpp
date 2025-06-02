#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<lld> v(n + 1);
    for (i = 1; i <= n; i++)
        cin >> v[i];
    vector<vector<lld>> dp(n + 1, vector<lld>(n + 1, 0));
    dp[0][0] = 1;
    for (i = 1; i <= n; i++)
    {
        dp[0][i] = 0;
    }
    for (i = 1; i <= n; i++)
    {
        dp[i][0] = dp[i - 1][0] * (1 - v[i]);
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            dp[i][j] = dp[i - 1][j - 1] * v[i] + dp[i - 1][j] * (1 - v[i]);
        }
    }
    lld ans = 0;
    for (i = n / 2 + 1; i <= n; i++)
    {
        ans += dp[n][i];
    }
    cout << setprecision(10) << ans << endl;
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