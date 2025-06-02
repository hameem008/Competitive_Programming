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
    map<ll, ll> mp;
    for (auto x : v)
        mp[x]++;
    while (mp.size() > 1)
    {
        map<ll, ll> dump;
        auto it1 = mp.begin();
        auto it2 = ++mp.begin();
        for (; it2 != mp.end(); it1++, it2++)
        {
            if (it1->second > 1)
                dump[0] += it1->second - 1;
            dump[it2->first - it1->first]++;
        }
        if (it1->second > 1)
            dump[0] += it1->second - 1;
        mp = dump;
    }
    if (mp.begin()->second > 1)
        cout << 0 << endl;
    else
        cout << mp.begin()->first << endl;
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