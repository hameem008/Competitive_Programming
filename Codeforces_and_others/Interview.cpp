#include <bits/stdc++.h>
using namespace std;
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<ll> v(n + 1, 0);
    for (i = 1; i <= n; i++)
        cin >> v[i];
    vector<ll> presum(n + 1, 0);
    for (i = 1; i <= n; i++)
        presum[i] += presum[i - 1] + v[i];
    ll hi = n, lo = 1, mid, weight;
    while (hi - lo > 1)
    {
        mid = (hi + lo) / 2;
        cout << "?" << gap << mid - lo + 1 << gap;
        for (i = lo; i <= mid; i++)
        {
            cout << i << gap;
        }
        cout << endl;
        cin >> weight;
        if (presum[mid] - presum[lo - 1] == weight - 1)
            hi = mid;
        else
            lo = mid + 1;
    }
    cout << "?" << gap << 1 << gap << lo << endl;
    cin >> weight;
    if (weight == v[lo])
        cout << "!" << gap << hi << endl;
    else
        cout << "!" << gap << lo << endl;
    // solve ends
}

int main()
{
    ll T = 1;
    cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}