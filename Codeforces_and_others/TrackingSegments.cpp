#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

bool pf(ll ans, ll n, vector<ll> &query, vector<pair<ll, ll>> &vp)
{
    vector<ll> v(n + 1, 0);
    for (ll i = 1; i <= ans; i++)
    {
        v[query[i]] = 1;
    }
    for (ll i = 1; i <= n; i++)
    {
        v[i] += v[i - 1];
    }
    bool flag = false;
    for (auto x : vp)
    {
        if (v[x.second] - v[x.first - 1] > (x.second - x.first + 1) / 2)
            flag = true;
    }
    return flag;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> m;
    vector<pair<ll, ll>> vp(m);
    for (i = 0; i < m; i++)
    {
        cin >> vp[i].first >> vp[i].second;
    }
    cin >> q;
    vector<ll> query(q + 1);
    for (i = 1; i <= q; i++)
    {
        cin >> query[i];
    }
    ll hi = q, lo = 1, mid;
    while (hi - lo > 1)
    {
        mid = (hi + lo) / 2;
        if (pf(mid, n, query, vp))
            hi = mid;
        else
            lo = mid + 1;
    }
    ll ans = -1;
    if (pf(lo, n, query, vp))
        ans = lo;
    else if (pf(hi, n, query, vp))
        ans = hi;
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