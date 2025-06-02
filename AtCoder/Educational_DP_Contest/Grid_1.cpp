#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;
const ll mod = 1e9 + 7;

ll n, m;
char grid[1008][1008];
ll dp[1008][1008];

ll rec(ll i, ll j)
{
    if (grid[i][j] == '#' || i < 1 || j < 1)
    {
        return 0;
    }
    if (dp[i][j] == -1)
    {
        dp[i][j] = (rec(i - 1, j) + rec(i, j - 1)) % mod;
    }
    return dp[i][j];
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, p, q;
    bool flag;
    // solve starts
    cin >> n >> m;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            cin >> grid[i][j];
            dp[i][j] = -1;
        }
    }
    dp[1][1] = 1;
    cout << rec(n, m) << endl;
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