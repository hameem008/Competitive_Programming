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
    vector<T> t;
    vector<T> lazy;
    vector<T> lazy2;
    ll root = 1;
    ll tla = 0, tra = 0;
    T combine(T a, T b)
    {
        return min(a, b);
    }
    void push(ll v, ll tl, ll tm, ll tr)
    {
        if (lazy[v] > 0)
        {
            t[v * 2] += lazy[v];
            lazy[v * 2] += lazy[v];
            t[v * 2 + 1] += lazy[v];
            lazy[v * 2 + 1] += lazy[v];
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
            t[v] = combine(t[v * 2], t[v * 2 + 1]);
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
        return combine(a, b);
    }
    void update(ll v, ll tl, ll tr, ll l, ll r, T val)
    {
        if (l > r)
            return;
        if (l == tl && r == tr)
        {
            t[v] += val;
            lazy[v] += val;
        }
        else
        {
            ll tm = (tl + tr) / 2;
            push(v, tl, tm, tr);
            update(v * 2, tl, tm, l, min(r, tm), val);
            update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
            t[v] = combine(t[v * 2], t[v * 2 + 1]);
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
        clear();
        N = a.size() + 1;
        tla = 0, tra = a.size() - 1;
        t.assign(4 * N, 0);
        lazy.assign(4 * N, 0);
        lazy2.assign(4 * N, 0);
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
        t.clear();
        lazy.clear();
        lazy2.clear();
        N = 0, tra = 0, tla = 0;
    }
    ~lazy_segment_tree()
    {
        clear();
    }
};

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> m;
    vector<ll> v(n, 0);
    lazy_segment_tree<ll> lsg(v);
    for (i = 0; i < m; i++)
    {
        int l, r, v;
        cin >> k >> l >> r;
        if (k == 1)
        {
            cin >> v;
            lsg.update(l, r - 1, v);
        }
        else
        {
            cout << lsg.query(l, r - 1) << endl;
        }
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