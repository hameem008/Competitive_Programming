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
    vector<string> v;
    for (i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        v.push_back(str);
    }
    vector<pair<ll, ll>> vp;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (v[i][j] == '1')
                vp.push_back({i, j});
        }
    }
    vector<set<ll>> vs(n);
    for (i = 0; i < n; i++)
    {
        vs[i].insert(i + 1);
    }
    for (i = 0; i < vp.size(); i++)
    {
        for (auto it = vs[vp[i].first].begin(); it != vs[vp[i].first].end(); it++)
        {
            vs[vp[i].second].insert(*it);
        }
    }
    for (i = 0; i < vs.size(); i++)
    {
        cout << vs[i].size() << gap;
        for (auto it = vs[i].begin(); it != vs[i].end(); it++)
        {
            cout << *it << gap;
        }
        cout << endl;
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