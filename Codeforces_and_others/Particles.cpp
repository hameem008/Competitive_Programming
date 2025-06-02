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
    vector<ll> v(n + 1), dp(n + 1, -infinite);
    for (i = 1; i <= n; i++)
    {
        cin >> v[i];
        dp[i] = v[i];
    }
    for (i = 3; i <= n; i++)
    {
        dp[i] = max({dp[i], dp[i - 2], dp[i] + dp[i - 2]});
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
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