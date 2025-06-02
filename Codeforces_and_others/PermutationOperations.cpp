#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I)
{
    ll i, j, k, a, b, m, n, p;
    // solve stars
    cin >> n;
    vector<ll> v(n);
    for (auto &x : v)
    {
        cin >> x;
    }
    vector<ll> ans(n + 1, 1);
    set<ll> s;
    for (i = 1; i <= n; i++)
    {
        s.insert(i);
    }
    for (i = n - 1; i > 0; i--)
    {
        if (v[i] <= v[i - 1])
        {
            auto it = s.lower_bound(v[i - 1] - v[i] + 1);
            ans[*it] = i + 1;
            s.erase(it);
        }
    }
    for (i = 1; i <= n; i++)
    {
        cout << ans[i] << gap;
    }
    cout << endl;
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