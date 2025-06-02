#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    // solve starts
    cin >> n >> m;
    multiset<ll> ms;
    for (i = 0; i < n; i++)
    {
        cin >> a;
        ms.insert(a);
    }
    vector<ll> v(m);
    for (auto &x : v)
        cin >> x;
    for (auto x : v)
    {
        ms.erase(ms.begin());
        ms.insert(x);
    }
    ll sum = 0;
    for (auto x : ms)
    {
        sum += x;
    }
    cout << sum << endl;
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