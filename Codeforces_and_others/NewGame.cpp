#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = 1e8;

ll val;
bool pf(ll mid, vector<ll> &sg, ll ind, ll sg_size)
{
    val = sg[min(ind + mid, sg_size)] - sg[ind - 1];
    if (val > 0)
        return true;
    else
        return false;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> k;
    vector<ll> v(n, 0);
    set<ll> s;
    for (auto &x : v)
    {
        cin >> x;
        s.insert(x);
    }
    multiset<ll> ms(v.begin(), v.end());
    i = 1;
    ll prev_num = *s.begin() - 1;
    map<ll, ll> mp;
    for (auto x : s)
    {
        if (prev_num + 1 == x)
        {
            mp[x] = i;
            i++;
            prev_num = x;
        }
        else
        {
            i++;
            mp[x] = i;
            i++;
            prev_num = x;
        }
    }
    vector<ll> sgv(i + 8, 0);
    ll sg_size = i + 4;
    for (auto x : v)
    {
        sgv[mp[x]]++;
    }
    for (auto &x : sgv)
    {
        if (x == 0)
            x = -infinite;
    }
    for (i = 1; i < sgv.size(); i++)
    {
        sgv[i] += sgv[i - 1];
    }
    ll ans = 0;
    for (auto x : s)
    {
        ll hi = k - 1, lo = 0, mid;
        ll ind = mp[x];
        while (hi - lo > 1)
        {
            mid = (hi + lo) / 2;
            if (pf(mid, sgv, ind, sg_size))
                lo = mid;
            else
                hi = mid - 1;
        }
        if (pf(hi, sgv, ind, sg_size))
            ans = max(ans, val);
        else if (pf(lo, sgv, ind, sg_size))
            ans = max(ans, val);
    }
    cout << ans << endl;
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