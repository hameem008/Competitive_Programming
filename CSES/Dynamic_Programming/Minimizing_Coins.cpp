#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;
const ll N = 1e6 + 8;
 
ll dp[N];
 
void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    dp[0] = 0;
    cin >> n >> k;
    for (i = 1; i <= k; i++)
        dp[i] = -1;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    for (i = 1; i <= k + 1; i++)
    {
        ll num = infinite;
        for (auto x : v)
        {
            if (i - x >= 0 && dp[i - x] != -1)
            {
                num = min(num, dp[i - x] + 1);
            }
        }
        if (num != infinite)
            dp[i] = num;
    }
    cout << dp[k] << endl;
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