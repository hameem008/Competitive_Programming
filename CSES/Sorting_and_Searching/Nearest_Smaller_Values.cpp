#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

template <class T>
class lazy_segment_tree
{
private:
    ll N = 0;
    T *t;
    T *lazy;
    ll root = 1;
    ll tla = 0, tra = 0;
    void push(ll v, ll tl, ll tm, ll tr)
    {
        if (lazy[v])
        {
            t[v * 2] = lazy[v];
            lazy[v * 2] = lazy[v];
            t[v * 2 + 1] = lazy[v];
            lazy[v * 2 + 1] = lazy[v];
            lazy[v] = 0;
        }
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
            t[v] = min(t[v * 2], t[v * 2 + 1]);
        }
    }
    T query(ll v, ll tl, ll tr, ll l, ll r)
    {
        if (l > r)
            return INT32_MAX;
        if (l == tl && r == tr)
            return t[v];
        ll tm = (tl + tr) / 2;
        push(v, tl, tm, tr);
        T a = query(v * 2, tl, tm, l, min(r, tm));
        T b = query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
        return min(a, b);
    }
    void update(ll v, ll tl, ll tr, ll l, ll r, T add_val)
    {
        if (l > r)
            return;
        if (l == tl && r == tr)
        {
            t[v] = add_val;
            lazy[v] = add_val;
        }
        else
        {
            ll tm = (tl + tr) / 2;
            push(v, tl, tm, tr);
            update(v * 2, tl, tm, l, min(r, tm), add_val);
            update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, add_val);
            t[v] = min(t[v * 2], t[v * 2 + 1]);
        }
    }

public:
    lazy_segment_tree()
    {
    }
    lazy_segment_tree(vector<T> &a)
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
        lazy = new T[4 * N];
        for (int i = 0; i < 4 * N; i++)
            lazy[i] = 0;
        build(a, 1, tla, tra);
    }
    T query(ll l, ll r)
    {
        return query(root, tla, tra, l, r);
    }
    void update(ll l, ll r, T add_val)
    {
        update(root, tla, tra, l, r, add_val);
    }
    void clear()
    {
        if (N)
        {
            delete[] t;
            delete[] lazy;
        }
        N = 0, tra = 0, tla = 0;
    }
    ~lazy_segment_tree()
    {
        if (N)
            clear();
    }
};

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<ll> v(n);
    for (i = 1; i <= n; i++)
    {
        cin >> v[i - 1];
    }
    set<ll> s(v.begin(), v.end());
    i = 0;
    map<ll, ll> mp;
    for (auto x : s)
    {
        mp[x] = i;
        i++;
    }
    vector<ll> lsgv(i + 8, 0);
    ll lsgv_size = i + 7;
    lazy_segment_tree<ll> lsg(lsgv);
    for (i = 0; i < n; i++)
    {
        cout << lsg.query(mp[v[i]], lsgv_size) << gap;
        lsg.update(mp[v[i]] + 1, lsgv_size, i + 1);
    }
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