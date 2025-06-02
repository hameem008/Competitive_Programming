#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

bool pf(ll mid, ll k, vector<ll> &v)
{
    ll length = 0;
    bool flag = false;
    for (int i = 0; i < v.size(); i++)
    {
        if (length % 2 == 0)
        {
            if (mid >= v[i])
                length++;
        }
        else
        {
            length++;
        }
    }
    if (length >= k)
        flag = true;
    length = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (length % 2 != 0)
        {
            if (mid >= v[i])
                length++;
        }
        else
        {
            length++;
        }
    }
    if (length >= k)
        flag = true;
    return flag;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> k;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    ll hi = 1e9, lo = 1, mid;
    while (hi - lo > 1)
    {
        mid = (hi + lo) / 2;
        if (pf(mid, k, v))
            hi = mid;
        else
            lo = mid + 1;
    }
    if (pf(lo, k, v))
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