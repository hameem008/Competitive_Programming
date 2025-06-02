#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

bool pf(ll mid, vector<ll> &v, ll n)
{
    bool flag = false;
    vector<ll> hash(2e6, 0);
    multiset<ll> ms;
    for (ll i = 0; i < mid; i++)
    {
        hash[v[i]]++;
    }
    for (ll i = 0; i < mid; i++)
    {
        ms.insert(hash[v[i]]);
    }
    if (*ms.rbegin() > n / 2)
        flag = true;
    ll k = mid;
    while (k < n)
    {
        if (*ms.rbegin() > n / 2)
        {
            flag = true;
            break;
        }
        ms.erase(ms.find(hash[v[k - mid]]));
        hash[v[k - mid]]--;
        ms.insert(hash[v[k - mid]]);
        if (hash[v[k]])
        {
            ms.erase(ms.find(hash[v[k]]));
        }
        hash[v[k]]++;
        ms.insert(hash[v[k]]);
        k++;
    }
    return flag;
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
    map<ll, ll> mp;
    set<ll> s(v.begin(), v.end());
    k = 0;
    for (auto x : s)
    {
        mp[x] = k;
        k++;
    }
    for (i = 0; i < n; i++)
        v[i] = mp[v[i]];
    ll hi = n, lo = n / 2 + 1, mid;
    while (hi - lo > 1)
    {
        mid = (hi + lo) / 2;
        if (pf(mid, v, n))
            hi = mid;
        else
            lo = mid + 1;
    }
    if (pf(lo, v, n))
        cout << lo << endl;
    else if (pf(hi, v, n))
        cout << hi << endl;
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
    // cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}