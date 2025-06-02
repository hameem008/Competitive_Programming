#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

bool pf(ll mid, vector<ll> &v, ll c)
{
    for (auto x : v)
    {
        c -= (x + 2 * mid) * (x + 2 * mid);
        if (c < 0)
            return false;
    }
    return true;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> c;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    ll hi = 1e9, lo = 1, mid;
    while (hi - lo > 1)
    {
        mid = (hi + lo) / 2;
        if (pf(mid, v, c))
            lo = mid;
        else
            hi = mid - 1;
    }
    if (pf(hi, v, c))
        cout << hi << endl;
    else
        cout << lo << endl;
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