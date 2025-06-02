#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I)
{
    ll i, j, a, b, m, n, p;
    // solve stars
    cin >> n;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    long double sum = 0;
    for (auto x : v)
        sum += x;
    long double k = sum / n;
    multiset<long double> ms;
    for (auto x : v)
        ms.insert(x);
    ll ans = 0;
    sort(v.begin(), v.end());
    for (auto x : v)
    {
        ll cnt = ms.count(2 * k - x);
        ll cnt2 = ms.count(x);
        if (cnt > 0)
        {
            if (x == k)
                ans += cnt * (cnt - 1) / 2;
            else
                ans += cnt * cnt2;
        }
        ms.erase(x);
        ms.erase(2 * k - x);
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