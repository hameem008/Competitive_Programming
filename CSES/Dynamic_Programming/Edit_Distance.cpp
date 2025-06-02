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
    string stra, strb;
    cin >> stra;
    cin >> strb;
    n = max(stra.size(), strb.size());
    for (i = 0; i <= n; i++)
    {
        dp[0][i] = i;
        dp[i][0] = i;
    }
    for (i = 0; i < stra.size(); i++)
    {
        for (j = 0; j < strb.size(); j++)
        {
            m = i + 1, n = j + 1;
            if (stra[i] == strb[j])
            {
                dp[m][n] = dp[m - 1][n - 1];
            }
            else
            {
                dp[m][n] = min(dp[m - 1][n] + 1, dp[m][n - 1] + 1);
                dp[m][n] = min(dp[m][n], dp[m - 1][n - 1] + 1);
            }
        }
    }
    cout << dp[stra.size()][strb.size()] << endl;
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