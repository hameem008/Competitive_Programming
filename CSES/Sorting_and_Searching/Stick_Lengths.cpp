#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

lld fun(lld mid, vector<ll> &v)
{
    lld ret = 0;
    for (auto x : v)
    {
        ret += abs(x - mid);
    }
    return ret;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    lld lo = 0, hi = 1e9;
    while (hi - lo > 1e-3)
    {
        lld mid1 = lo + (hi - lo) / 3, mid2 = hi - (hi - lo) / 3;
        lld ans1 = fun(mid1, v), ans2 = fun(mid2, v);
        if (ans1 < ans2)
            hi = mid2;
        else if (ans1 > ans2)
            lo = mid1;
        else
        {
            hi = mid2;
            lo = mid1;
        }
    }
    lld ans = min({fun(floor(hi), v), fun(ceil(hi), v), fun(floor(lo), v), fun(ceil(lo), v)});
    cout << (ll)ans << endl;
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