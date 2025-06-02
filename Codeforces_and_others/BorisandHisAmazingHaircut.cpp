#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

void solve(int I, int T)
{
    ll i, j, k, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<ll> a(n), b(n);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    cin >> m;
    multiset<ll> rz;
    for (i = 0; i < m; i++)
    {
        cin >> c;
        rz.insert(c);
    }
    for (i = 0; i < n; i++)
    {
        if (b[i] > a[i])
        {
            cout << "NO" << endl;
            return;
        }
    }
    map<ll, vector<ll>> mp;
    for (i = 0; i < n; i++)
    {
        mp[b[i]].push_back(i);
    }
    flag = true;
    set<ll> done;
    for (auto &x : mp)
        x.second.push_back(n);
    for (auto it = mp.rbegin(); it != mp.rend(); it++)
    {
        ll need = 0;
        bool prev = false;
        for (i = 0; i < it->second.size() - 1; i++)
        {
            ll lo = it->second[i], hi = it->second[i + 1];
            auto it1 = done.upper_bound(lo);
            auto it2 = done.upper_bound(hi);
            if (!prev && a[lo] != b[lo])
            {
                need++;
                prev = true;
            }
            if (it1 != it2)
            {
                prev = false;
            }
            done.insert(lo);
        }
        if (need > rz.count(it->first))
        {
            flag = false;
            break;
        }
    }
    flag ? cout << "YES" << endl : cout << "NO" << endl;
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