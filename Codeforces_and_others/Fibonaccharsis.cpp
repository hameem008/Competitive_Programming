#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

ll dp[(ll)1e6 + 10];
void fibo()
{
    dp[0] = 0, dp[1] = 1;
    for (int i = 2; i < 1e6 + 10; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> k;
    ll ans = 0;
    if (k >= 1e6)
    {
        cout << ans << endl;
        return;
    }
    for (i = 0; i <= n; i++)
    {
        if ((n - dp[k - 2] * i) % dp[k - 1] == 0 && i <= (n - dp[k - 2] * i) / dp[k - 1])
        {
            ans++;
        }
    }
    cout << ans << endl;
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fibo();
    ll T = 1;
    cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}