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
    cin >> n >> k;
    vector<ll> v(n);
    map<ll, ll> mp;
    for (auto &x : v)
    {
        cin >> x;
        mp[x]++;
    }
    flag = true;
    ll l, r, need;
    pair<ll, ll> ans = {0, -1};
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        if (flag)
        {
            need = it->first;
        }
        if (it->second >= k && need == it->first)
        {
            if (flag)
            {
                l = it->first;
                flag = false;
            }
            r = it->first;
            need++;
            if (ans.second - ans.first < r - l)
                ans = {l, r};
        }
        else
        {
            flag = true;
            if (it->second >= k)
            {
                l = it->first;
                flag = false;
                need = l + 1;
            }
        }
    }
    ans.second - ans.first >= 0 ? cout << ans.first << gap << ans.second << endl : cout << -1 << endl;
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