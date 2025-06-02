#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

ll dp[5001][5001];

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<ll> v(n + 1, 0);
    for (i = 1; i <= n; i++)
        cin >> v[i];
    if (n % 2 == 0)
    {
        flag = true;
    }
    else
    {
        flag = false;
        for (i = 1; i <= n; i++)
            dp[i][i] = v[i];
    }
    for (k = 1; k <= n; k++)
    {
        for (i = 1; i <= n; i++)
        {
            j = i + k;
            if (i >= n || j > n)
                continue;
            if (flag)
                dp[i][j] = max(dp[i][j - 1] + v[j], dp[i + 1][j] + v[i]);
            else
                dp[i][j] = min(dp[i][j - 1], dp[i + 1][j]);
        }
        flag ? flag = false : flag = true;
    }
    ll ans = -accumulate(v.begin(), v.end(), 0LL);
    ans += dp[1][n];
    ans += dp[1][n];
    cout << ans << endl;
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