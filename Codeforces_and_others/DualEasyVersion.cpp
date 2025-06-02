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
    vector<ll> v(n + 1), v2(n + 1);
    set<pair<ll, ll>> s, s2;
    for (i = 1; i <= n; i++)
    {
        cin >> v[i];
        v2[i] = v[i];
        s.insert({v[i], i});
        s2.insert({v2[i], i});
    }
    vector<pair<ll, ll>> ans, ans2;
    if (s.rbegin()->first > 0)
    {
        for (i = 1; i < n; i++)
        {
            while (v[i] > v[i + 1])
            {
                ll largest = s.rbegin()->first;
                ans.push_back({i + 1, s.rbegin()->second});
                s.erase({v[i + 1], i + 1});
                v[i + 1] += largest;
                s.insert({v[i + 1], i + 1});
            }
        }
    }
    if (s2.begin()->first < 0)
    {
        for (i = n - 1; i >= 1; i--)
        {
            while (v2[i] > v2[i + 1])
            {
                ll smallest = s2.begin()->first;
                ans2.push_back({i, s2.begin()->second});
                s2.erase({v2[i], i});
                v2[i] += smallest;
                s2.insert({v2[i], i});
            }
        }
    }
    if (ans.size() == 0 && ans2.size() != 0)
    {
        cout << ans2.size() << endl;
        for (auto x : ans2)
            cout << x.first << gap << x.second << endl;
    }
    else if (ans.size() != 0 && ans2.size() == 0)
    {
        cout << ans.size() << endl;
        for (auto x : ans)
            cout << x.first << gap << x.second << endl;
    }
    else if (ans.size() == 0 && ans2.size() == 0)
    {
        cout << 0 << endl;
    }
    else
    {
        if (ans.size() <= ans2.size())
        {
            cout << ans.size() << endl;
            for (auto x : ans)
                cout << x.first << gap << x.second << endl;
        }
        else
        {
            cout << ans2.size() << endl;
            for (auto x : ans2)
                cout << x.first << gap << x.second << endl;
        }
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