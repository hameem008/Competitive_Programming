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
    vector<set<ll>> vs(n);
    for (i = 0; i < n; i++)
    {
        vs[i].insert(i);
    }
    for (i = 0; i < m; i++)
    {
        cin >> a >> b;
        for (auto it = vs[a].begin(); it != vs[a].end(); it++)
        {
            vs[b].insert(*it);
        }
    }
    
    for (i = 0; i < n; i++)
    {
        for (auto x : vs[i])
            cout << x << gap;
        cout << endl;
    }
    
    set<ll> big;
    for (i = 0; i < m; i++)
    {
        big.insert(vs[i].size());
    }
    ll max = *(--big.end());
    ll cnt_ans = 0;
    vector<ll> ans;
    for (i = 0; i < n; i++)
    {
        if (vs[i].size() == max)
        {
            ans.push_back(i);
            cnt_ans++;
        }
    }
    ll cnt = 0;
    for (i = 0; i < n; i++)
    {
        cnt = 0;
        for (j = 0; j < n; j++)
        {
            if (vs[j].size() == max && vs[j].find(i) != vs[j].end())
            {
                cnt++;
            }
        }
        if (cnt_ans == cnt)
            break;
    }
    cout << i << endl;
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

    ll t = 1;
    // cin >> t;
    for (int I = 1; I <= t; I++)
        solve(I);
    return 0;
}