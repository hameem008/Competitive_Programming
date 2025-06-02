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
    ll zeros = 0;
    for (i = 0; i < n; i++)
    {
        cin >> v[i];
        if (v[i] == 0)
            zeros++;
    }
    if ((n - zeros) % 2 != 0)
    {
        cout << -1 << endl;
        return;
    }
    vector<pair<ll, ll>> pv;
    for (i = 0; i < n; i++)
    {
        if (v[i] != 0)
        {
            pv.push_back({v[i], i + 1});
        }
    }
    vector<pair<ll, ll>> ans;
    set<ll> ind;
    if (pv.size() == 0)
        goto level;
    for (i = 0; i < pv.size() - 1; i += 2)
    {
        if (pv[i].first == pv[i + 1].first)
        {
            if (pv[i].second + 1 == pv[i + 1].second)
            {
                ans.push_back({pv[i].second, pv[i + 1].second});
            }
            else
            {
                ans.push_back({pv[i].second, pv[i].second});
                ans.push_back({pv[i + 1].second - 1, pv[i + 1].second});
            }
        }
        else
        {
            ans.push_back({pv[i].second, pv[i].second});
            ans.push_back({pv[i + 1].second, pv[i + 1].second});
        }
    }
    for (i = 0; i < ans.size(); i++)
    {
        ind.insert(ans[i].first);
        ind.insert(ans[i].second);
    }
level:
    for (i = 0; i < v.size(); i++)
    {
        ll size = ind.size();
        ind.insert(i + 1);
        if (size != ind.size())
        {
            ans.push_back({i + 1, i + 1});
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (i = 0; i < ans.size(); i++)
    {
        cout << ans[i].first << gap << ans[i].second << endl;
    }
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