#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
ll mod = 998244353;

bool pf(ll n, ll max_ans, ll r, bool is3 = false)
{
    ll temp = 0;
    if (is3)
    {
        n *= 3;
        temp++;
    }
    temp += log10(r / n) / log10(2);
    temp++;
    if (temp == max_ans)
        return true;
    else
        return false;
}

void solve(int I, int T)
{
    ll i, j, k, a, l, r, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> l >> r;
    ll ans = 0;
    ll max_ans = 0;
    j = l;
    while (j <= r)
    {
        max_ans++;
        j *= 2;
    }
    ll hi = r, lo = l, mid;
    while (hi - lo > 1) // TTTTFFF find last true
    {
        mid = (hi + lo) / 2;
        if (pf(mid, max_ans, r))
            lo = mid;
        else
            hi = mid - 1;
    }
    if (pf(hi, max_ans, r))
        ans = (hi - l + 1) % mod;
    else if (pf(lo, max_ans, r))
        ans = (lo - l + 1) % mod;
    hi = r, lo = l;
    while (hi - lo > 1) // TTTTFFF find last true
    {
        mid = (hi + lo) / 2;
        if (pf(mid, max_ans, r, true))
            lo = mid;
        else
            hi = mid - 1;
    }
    if (pf(hi, max_ans, r, true))
        ans = (ans + (max_ans - 1) * (hi - l + 1)) % mod;
    else if (pf(lo, max_ans, r, true))
        ans = (ans + (max_ans - 1) * (lo - l + 1)) % mod;
    cout << max_ans << gap << ans << endl;
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