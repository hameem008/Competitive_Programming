#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

vector<ll> op(2001, infinite);
void calc()
{
    op[0] = op[1] = 0;
    for (ll i = 1; i <= 1000; i++)
    {
        for (ll j = 1; j <= i; j++)
        {
            op[i + i / j] = min(op[i + i / j], op[i] + 1);
        }
    }
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> k;
    vector<ll> vc(n + 1), vb(n + 1);
    for (i = 1; i <= n; i++)
    {
        cin >> vb[i];
    }
    for (i = 1; i <= n; i++)
    {
        cin >> vc[i];
    }
    k = min(k, (ll)15 * 1001);
    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, 0));
    for (i = 1; i <= n; i++)
    {
        if (vb[i] == 1)
            dp[i][0] = vc[i];
        dp[i][0] += dp[i - 1][0];
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= k; j++)
        {
            if (j - op[vb[i]] >= 0)
                dp[i][j] = max(dp[i - 1][j - op[vb[i]]] + vc[i], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][k] << endl;
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    calc();
    ll T = 1;
    cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}