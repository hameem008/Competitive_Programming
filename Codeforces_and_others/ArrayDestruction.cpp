#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

vector<pair<ll, ll>> fun(ll max_ele, ll num, vector<ll> &v)
{
    multiset<ll> ms(v.begin(), v.end());
    ll x = max_ele;
    vector<pair<ll, ll>> ret;
    ret.push_back({num, max_ele});
    ms.erase(ms.find(max_ele));
    ms.erase(ms.find(num));
    while (ms.size())
    {
        max_ele = *(--ms.end());
        ms.erase(--ms.end());
        auto it = ms.find(x - max_ele);
        if (it != ms.end())
        {
            ret.push_back({x - max_ele, max_ele});
            x = max_ele;
            ms.erase(it);
        }
        else
        {
            ret.clear();
            return ret;
        }
    }
    return ret;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    n *= 2;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    sort(v.begin(), v.end());
    for (i = 0; i < n - 1; i++)
    {
        vector<pair<ll, ll>> vp = fun(v[n - 1], v[i], v);
        if (vp.size())
        {
            cout << "YES" << endl;
            cout << v[n - 1] + v[i] << endl;
            for (auto x : vp)
                cout << x.first << gap << x.second << endl;
            return;
        }
    }
    cout << "NO" << endl;
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