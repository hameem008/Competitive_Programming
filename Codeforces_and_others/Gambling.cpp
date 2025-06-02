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
    vector<ll> v(n + 1, 0);
    for (i = 1; i <= n; i++)
        cin >> v[i];
    v.push_back(infinite);
    map<ll, vector<pair<ll, ll>>> mp;
    ll curr_num = v[1];
    ll start = 1, end = 1;
    for (i = 2; i < v.size(); i++)
    {
        if (v[i] == curr_num)
        {
            end++;
        }
        else
        {
            mp[curr_num].push_back({start, end});
            curr_num = v[i];
            start = end = i;
        }
    }
    vector<ll> ans(4, 0);
    ans[0] = -1;
    for (auto x : mp)
    {
        vector<ll> dum;
        vector<pair<ll, ll>> mapping;
        dum.push_back(0);
        mapping.push_back({0, x.second[0].first - 1});
        for (i = 0; i < x.second.size() - 1; i++)
        {
            dum.push_back(x.second[i].second - x.second[i].first + 1);
            mapping.push_back({x.second[0].first, x.second[i].second});
            dum.push_back(-(x.second[i + 1].first - x.second[i].second - 1));
            mapping.push_back({x.second[0].first, x.second[i + 1].first - 1});
        }
        dum.push_back(x.second[i].second - x.second[i].first + 1);
        mapping.push_back({x.second[0].first, x.second[i].second});
        for (i = 1; i < dum.size(); i++)
        {
            dum[i] = dum[i - 1] + dum[i];
        }
        set<pair<ll, ll>> s;
        for (i = 0; i < dum.size(); i++)
        {
            s.insert({dum[i], i});
        }
        i = dum.size() - 1;
        while (s.size() > 1)
        {
            s.erase({dum[i], i});
            ll num = s.begin()->first;
            j = s.begin()->second;
            if (ans[0] < dum[i] - num)
            {
                ans[0] = dum[i] - num;
                ans[1] = x.first;
                ans[2] = mapping[j].second + 1;
                ans[3] = mapping[i].second;
            }
            i--;
        }
    }
    cout << ans[1] << gap << ans[2] << gap << ans[3] << endl;
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