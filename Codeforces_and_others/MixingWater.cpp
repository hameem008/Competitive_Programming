#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

lld fun(lld h, lld c, ll n, lld t)
{
    return abs(((n + 1) * h + c * n) / (2 * n + 1) - t);
}

void solve(int I, int T)
{
    ll i, j, k, a, b, d, m, n, p, q;
    bool flag;
    lld h, c, t;
    // solve starts
    ll ans = 2;
    cin >> h >> c >> t;
    lld dif = abs(t - (c + h) / 2);
    n = (t - h) / (h + c - 2 * t);
    if (dif > fun(h, c, n, t))
    {
        dif = fun(h, c, n, t);
        ans = 2 * n + 1;
    }
    n++;
    if (dif > fun(h, c, n, t))
    {
        dif = fun(h, c, n, t);
        ans = 2 * n + 1;
    }
    if (ans < 0)
        ans = 2;
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