#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

bool isPossible(vector<ll> v, ll h, ll n, ll m)
{
    ll sum = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (v[i] >= h)
            sum = sum + h;
        else if (v[i] < h)
            sum = sum + v[i] + (h - v[i]) / 2;
    }

    return sum >= m;
}

void solve(int I)
{
    ll i, j, k, a, b, m, n, p;
    // solve stars
    cin >> n >> m;
    vector<ll> v(n + 1);
    for (i = 0; i < n + 1; i++)
    {
        v[i] = 0;
    }
    for (i = 0; i < m; i++)
    {
        cin >> p;
        v[p]++;
    }
    ll lo = 1, hi = 2 * m, mid;
    while (hi - lo > 1)
    {
        mid = (hi + lo) / 2;
        if (isPossible(v, mid, n, m))
        {
            hi = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }
    if (isPossible(v, lo, n, m))
        cout << lo << endl;
    else
        cout << hi << endl;
    //  solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
    cin >> t;
    for (int I = 1; I <= t; I++)
        solve(I);
    return 0;
}