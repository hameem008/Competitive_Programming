#include <bits/stdc++.h>
using namespace std;
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;
const ll mod = 1e9;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    ll hi = 1e6, lo = 1, mid;
    while (hi - lo > 1) // FFFFTTT find first true
    {
        mid = (hi + lo) / 2;
        ll mul = 1;
        for (i = lo; i <= mid; i++)
        {
            mul *= i;
            mul %= mod;
        }
        if (pf(mid))
            hi = mid;
        else
            lo = mid + 1;
    }
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