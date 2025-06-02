#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;
const ll N = 1e5 + 6;

ll v[3][N];
ll dp[3][N];

ll rec(ll task, ll n)
{
    if (n == 0)
    {
        return 0;
    }
    if (dp[task][n] == -1)
    {
        if (task == 0)
        {
            dp[task][n] = v[task][n] + max(rec(1, n - 1), rec(2, n - 1));
        }
        else if (task == 1)
        {
            dp[task][n] = v[task][n] + max(rec(0, n - 1), rec(2, n - 1));
        }
        else if (task == 2)
        {
            dp[task][n] = v[task][n] + max(rec(0, n - 1), rec(1, n - 1));
        }
    }
    return dp[task][n];
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        dp[0][i] = dp[1][i] = dp[2][i] = -1;
        cin >> v[0][i] >> v[1][i] >> v[2][i];
    }
    cout << max(max(rec(0, n), rec(1, n)), rec(2, n)) << endl;
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