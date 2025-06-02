#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef int ll;
typedef long double lld;

ll dp[1001][(ll)1e5 + 1];

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> q;
    vector<pair<ll, ll>> books(n + 1);
    for (i = 1; i <= n; i++)
    {
        cin >> books[i].first;
    }
    for (i = 1; i <= n; i++)
    {
        cin >> books[i].second;
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= q; j++)
        {
            if (j - books[i].first >= 0)
                dp[i][j] = dp[i - 1][j - books[i].first] + books[i].second;
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }
    cout << dp[n][q] << endl;
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll T = 1;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}