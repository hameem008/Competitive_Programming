#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

vector<ll> fun(ll n, ll num)
{
    vector<ll> ret;
    while (num)
    {
        if (num <= n && num >= 1)
        {
            ret.push_back(num);
        }
        num /= 2;
    }
    return ret;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    vector<multiset<ll>> vms(n + 1);
    for (auto x : v)
    {
        for (auto y : fun(n, x))
        {
            vms[y].insert(x);
        }
    }
    set<pair<ll, ll>> s;
    for (i = 1; i <= n; i++)
    {
        s.insert({vms[i].size(), i});
    }
    flag = true;
    vector<bool> done(n + 1, false);
    while (s.size())
    {
        ll cnt = s.begin()->first;
        if (cnt == 0)
        {
            flag = false;
            break;
        }
        else
        {
            ll in = s.begin()->second;
            done[in] = true;
            ll num = *vms[s.begin()->second].begin();
            for (auto x : fun(n, num))
            {
                s.erase({vms[x].size(), x});
                vms[x].erase(vms[x].find(num));
                if (!done[x])
                    s.insert({vms[x].size(), x});
            }
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