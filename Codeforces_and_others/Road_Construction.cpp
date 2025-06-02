#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I)
{
    ll i, j, k, a, b, m, n, p;
    // solve stars
    cin >> n >> m;
    set<ll> s;
    for (i = 1; i <= n; i++)
        s.insert(i);
    for (i = 0; i < m; i++)
    {
        cin >> a >> b;
        s.erase(a);
        s.erase(b);
    }
    ll key = *s.begin();
    cout << n - 1 << endl;
    for (i = 1; i <= n; i++)
    {
        if (i != key)
            cout << key << gap << i << endl;
    }
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
    // cin >> t;
    for (int I = 1; I <= t; I++)
        solve(I);
    return 0;
}