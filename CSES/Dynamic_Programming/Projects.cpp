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
    vector<pair<pair<ll, ll>, ll>> v;
    v.push_back({{0, 0}, 0});
    for (i = 1; i <= n; i++)
    {
        cin >> a >> b >> c;
        v.push_back({{b, a}, c});
    }
    sort(v.begin(), v.end());
    vector<ll> dp(n + 1, 0);
    for (i = 1; i <= n; i++)
    {
        ll st = v[i].first.second;
        pair<pair<ll, ll>, ll> p = {{st - 1, st - 1}, infinite};
        ll ind = upper_bound(v.begin(), v.end(), p) - v.begin();
        ind--;
        dp[i] = max(dp[i - 1], dp[ind] + v[i].second);
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
    // cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}