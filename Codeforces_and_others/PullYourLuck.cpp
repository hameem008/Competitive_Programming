#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

bool pf(ll n, ll x, ll i, ll a)
{
    return a * a + a - 2 * (n * i - x) >= 0;
}

void solve(int I, int T)
{
    ll i, j, k, a, x, b, c, d, m, n, p, q;
    bool flag = false;
    // solve starts
    cin >> n >> x >> p;
    ll lim = p / n > 100 ? p / n : 100;
    for (i = 1; i <= lim; i++)
    {
        ll hi = p, lo = 1, mid;
        while (hi - lo > 1)
        {
            mid = (hi + lo) / 2;
            if (pf(n, x, i, mid))
                hi = mid;
            else
                lo = mid + 1;
        }
        a = lo * lo + lo - 2 * (n * i - x);
        b = hi * hi + hi - 2 * (n * i - x);
        if (a == 0 || b == 0)
            flag = true;
        if (flag)
            break;
    }
    flag ? cout << "YES" << endl : cout << "NO" << endl;
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