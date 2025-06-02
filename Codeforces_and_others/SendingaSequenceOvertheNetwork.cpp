#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<ll> v(n + 1);
    for (i = 1; i <= n; i++)
        cin >> v[i];
    vector<ll> dp(n + 1, false);
    dp[0] = true;
    for (i = 1; i <= n; i++)
    {
        if (i - (v[i] + 1) >= 0 && dp[i - (v[i] + 1)])
            dp[i] = true;
        if (i + v[i] <= n && dp[i - 1])
            dp[i + v[i]] = true;
    }
    dp[n] ? cout << "YES" << endl : cout << "NO" << endl;
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