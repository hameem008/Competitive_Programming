#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

ll fun()
{
}

bool pf_1(ll mid, ll n, ll m, ll sum_n, ll sum_m)
{
    ll r = mid / m;
    ll c = mid % m;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> m >> q;
    vector<ll> v_m, v_n;
    ll sum_m = 0, sum_n = 0;
    for (i = 0; i < n; i++)
    {
        cin >> a;
        sum_n += a;
        v_n.push_back(a);
    }
    for (i = 0; i < m; i++)
    {
        cin >> a;
        sum_m += a;
        v_m.push_back(a);
    }
    for (i = 0; i < q; i++)
    {
        cin >> k;
        ll hi = m * n, lo = 1, mid;
        while (hi - lo > 1) // FFFFTTT find first true
        {
            mid = (hi + lo) / 2;
            if (pf_1(mid, n, m))
                hi = mid;
            else
                lo = mid + 1;
        }
        if (pf_1(lo, n, m))
            cout << lo << endl;
        else
            cout << hi << endl;
    }
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