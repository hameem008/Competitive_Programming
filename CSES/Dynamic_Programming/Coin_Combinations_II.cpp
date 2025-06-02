#include <bits/stdc++.h>
using namespace std;

int dp[101][1000001];

int main()
{
    int i, j, a, b, k, n;
    int sum;
    int mod = 1e9 + 7;
    cin >> n >> k;
    int v[n + 1];
    for (i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    dp[0][0] = 1;
    for (i = 1; i <= k; i++)
    {
        for (j = 1; j <= n; j++)
        {
            dp[j][i] = dp[j - 1][i];
            if (i - v[j] == 0)
            {
                dp[j][i] += 1;
                dp[j][i] %= mod;
            }
            else if (i - v[j] > 0)
            {
                dp[j][i] += dp[j][i - v[j]];
                dp[j][i] %= mod;
            }
        }
    }
    cout << dp[n][k];
}