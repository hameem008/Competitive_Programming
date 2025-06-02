#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    // solve starts
    cin >> n >> m;
    vector<ll> vn(n + 1, 0), vm(m + 1, 0);
    multiset<ll> guests, tables;
    for (i = 0; i < n; i++)
    {
        cin >> a;
        vn[a]++;
    }

    for (i = 0; i < m; i++)
    {
        cin >> a;
        tables.insert(a);
    }
    for (auto x : vn)
    {
        if (x != 0)
            guests.insert(x);
    }
    ll ans = 0;
    while (guests.size() && tables.size())
    {
        ll g = *(--guests.end()), t = *(--tables.end());
        if (g > t)
        {
            ans += t;
            guests.erase((--guests.end()));
            guests.insert(g - t);
            tables.erase((--tables.end()));
        }
        else
        {
            ans += g;
            guests.erase((--guests.end()));
            tables.erase((--tables.end()));
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

    ll T = 1;
    cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}