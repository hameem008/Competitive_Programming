#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;
const ll N = 2e5 + 1;

ll dp[N];

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<ll> v(n + 1);
    for (i = 1; i <= n; i++)
    {
        cin >> v[i];
        dp[i] = 0;
    }
    vector<pair<ll, ll>> vp(n + 1, {n + 1, n + 1});
    vector<bool> vmark(n + 1, true);
    for (i = 1; i <= n; i++)
    {
        vp[v[i]].first = vp[v[i]].second;
        vp[v[i]].second = i;
        if (vp[v[i]].second > vp[v[i]].first)
        {
            dp[i] = (vp[v[i]].second - vp[v[i]].first + 1) + dp[vp[v[i]].first] - 1;
            if (vmark[v[i]])
            {
                dp[i]++;
                vmark[v[i]] = false;
            }
            dp[i] = max(dp[i], (vp[v[i]].second - vp[v[i]].first + 1) + dp[vp[v[i]].first - 1]);
        }
        dp[i] = max(dp[i], dp[i - 1]);
    }
    cout << dp[n] << endl;
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