#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

bool pf(ll n, ll l, ll r)
{
    if (n * (n + 1) / 2 <= r - l)
        return true;
    return false;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    ll l, r;
    cin >> l >> r;
    ll hi = 1e9, lo = 0, mid;
    while (hi - lo > 1)
    {
        mid = (hi + lo) / 2;
        if (pf(mid, l, r))
            lo = mid;
        else
            hi = mid - 1;
    }
    if (pf(hi, l, r))
        cout << hi + 1 << endl;
    else
        cout << lo + 1 << endl;
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