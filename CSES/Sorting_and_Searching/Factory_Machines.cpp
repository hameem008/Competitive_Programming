#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

bool pf(ll mid, vector<ll> &v, ll t)
{
    for (auto x : v)
    {
        t -= mid / x;
        if (t <= 0)
            return true;
    }
    return false;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q, t;
    bool flag;
    // solve starts
    cin >> n >> t;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    ll hi = 1e18, lo = 1, mid;
    while (hi - lo > 1)
    {
        mid = (hi + lo) / 2;
        if (pf(mid, v, t))
            hi = mid;
        else
            lo = mid + 1;
    }
    if (pf(lo, v, t))
        cout << lo << endl;
    else
        cout << hi << endl;
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