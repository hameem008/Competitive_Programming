#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

lld fun(double n, vector<ll> &v, vector<ll> &t)
{
    lld max = fabs(v[0] - n) + t[0];
    for (int i = 1; i < v.size(); i++)
    {
        if (max < fabs(v[i] - n) + t[i])
            max = fabs(v[i] - n) + t[i];
    }
    return max;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    // solve starts
    cin >> n;
    vector<ll> v(n), t(n);
    for (auto &x : v)
        cin >> x;
    for (auto &x : t)
        cin >> x;
    lld hi = *max_element(v.begin(), v.end()), lo = *min_element(v.begin(), v.end());
    while (hi - lo > 1e-7)
    {
        lld mid1 = lo + (hi - lo) / 3, mid2 = hi - (hi - lo) / 3;
        lld ans1 = fun(mid1, v, t), ans2 = fun(mid2, v, t);
        if (ans1 < ans2)
            hi = mid2;
        else if (ans1 > ans2)
            lo = mid1;
        else
        {
            hi = mid2;
            lo = mid1;
        }
    }
    cout.precision(7);
    cout << hi << endl;
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