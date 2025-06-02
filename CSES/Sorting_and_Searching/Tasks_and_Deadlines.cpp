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
    vector<pair<ll, ll>> vp;
    for (i = 1; i <= n; i++)
    {
        cin >> a >> b;
        vp.push_back({a, b});
    }
    sort(vp.begin(), vp.end());
    ll time_ = 0;
    ll ans = 0;
    for (auto x : vp)
    {
        time_ += x.first;
        ans += x.second - time_;
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
    // cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}