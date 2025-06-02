#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
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
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    sort(v.begin(), v.end());
    ll odd = 0, even = 0;
    for (auto x : v)
    {
        if (x % 2 == 0)
            even++;
        else
            odd++;
    }
    if (odd == 0 || even == 0)
    {
        cout << 0 << endl;
        return;
    }
    ll big_odd;
    for (auto x : v)
    {
        if (x % 2 == 1)
            big_odd = x;
    }
    for (auto x : v)
    {
        if (x % 2 == 0 && x < big_odd)
            big_odd += x;
    }
    if (v.back() % 2 == 0)
    {
        if (big_odd > v.back())
            cout << even << endl;
        else
            cout << even + 1 << endl;
    }
    else
        cout << even << endl;
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