#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> c >> q;
    vector<char> v(n + 1);
    for (i = 1; i <= n; i++)
        cin >> v[i];
    ll size = n;
    map<pair<ll, ll>, pair<ll, ll>> mp;
    for (i = 0; i < c; i++)
    {
        ll l, r;
        cin >> l >> r;
        size++;
        mp[{size, size + r - l}] = {l, r};
        size += r - l;
    }
    for (i = 0; i < q; i++)
    {
        cin >> k;
        auto it = mp.begin();
        while (k > n)
        {
            if (it->first.first <= k && k <= it->first.second)
                k = it->second.first + k - it->first.first;
            it++;
            if (it == mp.end())
                it = mp.begin();
        }
        cout << v[k] << endl;
    }
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