#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

ll func(vector<ll> v)
{
    ll ret = infinite;
    vector<ll> pos, neg;
    vector<ll> dumv;
    dumv = v;
    v.clear();
    v.push_back(0);
    for (auto x : dumv)
    {
        v.push_back(x);
    }
    pos = neg = v;
    for (ll i = 0; i < v.size(); i += 2)
    {
        pos[i] = -pos[i];
    }
    for (ll i = 1; i < v.size(); i += 2)
    {
        neg[i] = -neg[i];
    }
    for (ll i = 1; i < v.size(); i++)
    {
        pos[i] += pos[i - 1];
        neg[i] += neg[i - 1];
    }
    for (ll i = 1; i < v.size(); i++)
    {
        ll dum = pos[i - 1] - pos[0] + neg[neg.size() - 1] - neg[i];
        dum = -dum;
        ret = min(ret, dum);
    }
    return ret;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> k;
    set<ll> s;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;

    map<ll, ll> mp;
    for (auto x : v)
    {
        mp[x]++;
        if (mp[x] == 2)
            mp[x] = 0;
    }

    v.clear();
    for (auto x : mp)
    {
        if (x.second == 1)
        {
            v.push_back(x.first);
        }
    }
    n = v.size();

    map<ll, vector<ll>> mpv;
    ll ans = 0;
    vector<pair<ll, ll>> dumv;
    for (auto x : v)
    {
        mpv[x % k].push_back((x - x % k) / k);
    }
    ll cnt = 0;
    for (auto x : mpv)
    {
        sort(x.second.begin(), x.second.end());
        if (x.second.size() % 2 == 0)
        {
            for (i = 0; i < x.second.size() - 1; i += 2)
            {
                ans += x.second[i + 1] - x.second[i];
            }
        }
        else if (x.second.size() == 1)
        {
            cnt++;
        }
        else
        {
            cnt++;
            ans += func(x.second);
        }
    }
    if (cnt < 2)
    {
        if (cnt == 1 && n % 2 == 0)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
    else
        cout << -1 << endl;
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