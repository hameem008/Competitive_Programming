#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p;
    // solve starts
    cin >> n >> m >> d;
    vector<ll> v(n + 1);
    for (i = 1; i <= n; i++)
    {
        cin >> a;
        v[a] = i;
    }
    vector<ll> q(m);
    for (auto &x : q)
        cin >> x;
    set<ll> ans;
    for (i = 0; i < m - 1; i++)
    {
        if (v[q[i]] > v[q[i + 1]])
            ans.insert(0);
        else
        {
            ll dif = v[q[i + 1]] - v[q[i]];
            ans.insert(dif);
            if (d + 2 <= n)
                ans.insert(d + 1 - dif);
            if (dif >= d + 1)
                ans.insert(0);
        }
    }
    while (*ans.begin() < 0)
        ans.erase(ans.begin());
    cout << *ans.begin() << endl;
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