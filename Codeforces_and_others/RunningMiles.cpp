#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;
const ll N = 1e5 + 8;

ll v[N];
ll dp[3][N];

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    dp[0][1] = v[1] + 1;
    for (i = 2; i <= n; i++)
    {
        dp[0][i] = max(v[i] + i, dp[0][i - 1]);
    }
    dp[1][2] = v[2] + dp[0][1];
    for (i = 3; i <= n; i++)
    {
        dp[1][i] = max(v[i] + dp[0][i - 1], dp[1][i - 1]);
    }
    dp[2][3] = v[3] - 3 + dp[1][2];
    for (i = 4; i <= n; i++)
    {
        dp[2][i] = max(v[i] - i + dp[1][i - 1], dp[2][i - 1]);
    }
    cout << dp[2][n] << endl;
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