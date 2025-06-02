#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

template <class T>
class segment_tree
{
private:
    ll N = 0;
    T *t;
    ll root = 1;
    ll tla = 0, tra = 0;
    T combine(T a, T b)
    {
        return a + b;
    }
    void build(vector<T> &a, ll v, ll tl, ll tr)
    {
        if (tl == tr)
            t[v] = a[tl];
        else
        {
            ll tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            t[v] = t[v * 2] + t[v * 2 + 1];
            t[v] = combine(t[v * 2], t[v * 2 + 1]);
        }
    }
    T query(ll v, ll tl, ll tr, ll l, ll r)
    {
        if (l > r)
            return 0;
        if (l == tl && r == tr)
            return t[v];
        ll tm = (tl + tr) / 2;
        T a = query(v * 2, tl, tm, l, min(r, tm));
        T b = query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
        return combine(a, b);
    }
    void update(ll v, ll tl, ll tr, ll pos, T new_val)
    {
        if (tl == tr)
            t[v] = new_val;
        else
        {
            ll tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v * 2, tl, tm, pos, new_val);
            else
                update(v * 2 + 1, tm + 1, tr, pos, new_val);
            t[v] = combine(t[v * 2], t[v * 2 + 1]);
        }
    }

public:
    segment_tree()
    {
    }
    segment_tree(vector<T> &a)
    {
        build(a);
    }
    void build(vector<T> &a)
    {
        if (N)
            clear();
        N = a.size() + 1;
        tla = 0, tra = a.size() - 1;
        t = new T[4 * N];
        build(a, 1, tla, tra);
    }
    T query(ll l, ll r)
    {
        return query(root, tla, tra, l, r);
    }
    void update(ll pos, T new_val)
    {
        update(root, tla, tra, pos, new_val);
    }
    void clear()
    {
        if (N)
            delete[] t;
        N = 0, tra = 0, tla = 0;
    }
    ~segment_tree()
    {
        if (N)
            clear();
    }
};

bool pf(segment_tree<ll> &sgis, ll mid, ll k)
{
    if (sgis.query(0, mid) >= k)
        return true;
    else
        return false;
}

ll func(ll n, ll k, segment_tree<ll> &sgis)
{
    if (sgis.query(0, n - 1) <= k)
    {
        return n - 1;
    }
    else
    {
        ll hi = n - 1, lo = 0, mid;
        while (hi - lo > 1)
        {
            mid = (hi + lo) / 2;
            if (pf(sgis, mid, k))
                hi = mid;
            else
                lo = mid + 1;
        }
        if (pf(sgis, lo, k))
            return lo;
        else
            return hi;
    }
}

void solve(int I, int T)
{
    ll i, j, k, t, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> k;
    vector<vector<ll>> tb(1e6 + 1);
    vector<ll> v, is(n, 1);
    set<ll> s;
    for (i = 1; i <= n; i++)
    {
        cin >> t >> b;
        tb[t].push_back(b);
        v.push_back(t);
        s.insert(b);
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    map<ll, vector<ll>> mp;
    for (i = 0; i < n; i++)
    {
        mp[tb[v[i]].back()].push_back(i);
        tb[v[i]].pop_back();
    }
    segment_tree<ll> sgv(v), sgis(is);
    ll prev = 0;
    ll ans = 0;
    for (auto x : s)
    {
        for (auto y : mp[prev])
        {
            sgis.update(y, 0);
            sgv.update(y, 0);
        }
        ll ind_k = func(n, k, sgis);
        ans = max(ans, x * sgv.query(0, ind_k));
        prev = x;
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
    // cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}