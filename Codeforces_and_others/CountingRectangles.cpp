#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

ll dp[1001][1001];

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> q;
    multiset<pair<ll, ll>> ms;
    for (i = 0; i < n; i++)
    {
        cin >> a >> b;
        ms.insert({a, b});
    }
    dp[1][1] = ms.count({1, 1}) * 1 * 1;
    for (i = 2; i <= 1000; i++)
    {
        dp[1][i] = ms.count({1, i}) * 1 * i + dp[1][i - 1];
        dp[i][1] = ms.count({i, 1}) * 1 * i + dp[i - 1][1];
    }
    for (i = 2; i <= 1000; i++)
    {
        for (j = 2; j <= 1000; j++)
        {
            dp[i][j] = ms.count({i, j}) * i * j + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
        }
    }
    for (i = 0; i < q; i++)
    {
        ll hs, ws, hb, wb;
        cin >> hs >> ws >> hb >> wb;
        hb--, wb--;
        cout << dp[hb][wb] - dp[hb][ws] - dp[hs][wb] + dp[hs][ws] << endl;
    }
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