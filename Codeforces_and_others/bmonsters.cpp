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
    cin >> n >> k;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    set<ll> s;
    set<pair<ll, ll>> ps;
    multimap<ll, ll> mp;
    for (i = 0; i < n; i++)
    {
        if (v[i] % k == 0)
            v[i] = k;
        else
            v[i] = v[i] % k;
        s.insert(v[i]);
        ps.insert({v[i], i + 1});
    }
    for (auto x : ps)
    {
        mp.insert(x);
    }
    vector<ll> ans;
    for (auto it = s.rbegin(); it != s.rend(); it++)
    {
        vector<ll> dum;
        auto it2 = mp.lower_bound(*it);
        for (; it2 != mp.end(); it2++)
        {
            if (it2->first != *it)
                break;
            dum.push_back(it2->second);
        }
        for (auto x : dum)
            ans.push_back(x);
    }
    for (auto x : ans)
        cout << x << gap;
    cout << endl;
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