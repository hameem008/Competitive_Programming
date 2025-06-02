#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I)
{
    ll i, j, k, a, b, m, n, p;
    // solve stars
    cin >> n >> k;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    ll ans = 0;
    for (i = 0; i < n; i++)
    {
        ans += v[i] / k;
        v[i] = v[i] % k;
    }
    sort(v.begin(), v.end());
    multiset<ll> ms;
    for (auto x : v)
        ms.insert(x);
    for (auto x : v)
    {
        if (ms.size() != 0)
            ms.erase(ms.begin());
        auto it = ms.lower_bound(k - x);
        if (it != ms.end())
        {
            ans++;
            ms.erase(it);
        }
    }
    cout << ans << endl;
    // solve ends
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