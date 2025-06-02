#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> m;
    vector<vector<ll>> arr(n + 1, vector<ll>(m + 1));
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
        }
    }
    k = __gcd(arr[1][1], arr[n][m]);
    ll limit = sqrt(k) + 1;
    vector<ll> divisors;
    for (i = 1; i <= limit; i++)
    {
        if (k % i == 0)
        {
            divisors.push_back(i);
            divisors.push_back(k / i);
        }
    }
    sort(divisors.begin(), divisors.end());
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));
    ll ans = 1;
    for (auto x : divisors)
    {
        dp[1][1] = 1;
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= m; j++)
            {
                if (i == 1 && j == 1)
                    continue;
                if (dp[i - 1][j] == 1 || dp[i][j - 1] == 1)
                {
                    if (arr[i][j] % x == 0)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = 0;
                }
                else
                    dp[i][j] = 0;
            }
        }
        if (dp[n][m])
            ans = x;
    }
    cout << ans << endl;
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