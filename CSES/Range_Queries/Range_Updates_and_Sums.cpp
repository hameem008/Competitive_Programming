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
    T *lazy2;
    ll root = 1;
    ll tla = 0, tra = 0;
    void push(ll v, ll tl, ll tm, ll tr)
    {
        if (lazy[v] > 0 && lazy2[v] > 0)
        {
            t[v * 2] = (tm - tl + 1) * lazy2[v];
            t[v * 2] += (tm - tl + 1) * lazy[v];
            lazy2[v * 2] = lazy2[v];
            lazy[v * 2] = lazy[v];
            t[v * 2 + 1] = (tr - tm) * lazy2[v];
            t[v * 2 + 1] += (tr - tm) * lazy[v];
            lazy2[v * 2 + 1] = lazy2[v];
            lazy[v * 2 + 1] = lazy[v];
            lazy2[v] = 0;
            lazy[v] = 0;
        }
        else if (lazy[v] > 0)
        {
            t[v * 2] += (tm - tl + 1) * lazy[v];
            lazy[v * 2] += lazy[v];
            t[v * 2 + 1] += (tr - tm) * lazy[v];
            lazy[v * 2 + 1] += lazy[v];
            lazy[v] = 0;
        }
        else if (lazy2[v] > 0)
        {
            t[v * 2] = (tm - tl + 1) * lazy2[v];
            lazy2[v * 2] = lazy2[v];
            t[v * 2 + 1] = (tr - tm) * lazy2[v];
            lazy2[v * 2 + 1] = lazy2[v];
            lazy2[v] = 0;
            lazy[v * 2] = lazy[v * 2 + 1] = 0;
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
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }
    T query(ll v, ll tl, ll tr, ll l, ll r)
    {
        if (l > r)
            return 0;
        if (l == tl && r == tr)
            return t[v];
        ll tm = (tl + tr) / 2;
        push(v, tl, tm, tr);
        T a = query(v * 2, tl, tm, l, min(r, tm));
        T b = query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
        return a + b;
    }
    void update(ll v, ll tl, ll tr, ll l, ll r, T add_val, ll op)
    {
        if (l > r)
            return;
        if (l == tl && r == tr)
        {
            if (op == 1)
            {
                t[v] += (r - l + 1) * add_val;
                lazy[v] += add_val;
            }
            else if (op == 2)
            {
                t[v] = (r - l + 1) * add_val;
                lazy[v] = 0;
                lazy2[v] = add_val;
            }
        }
        else
        {
            ll tm = (tl + tr) / 2;
            push(v, tl, tm, tr);
            update(v * 2, tl, tm, l, min(r, tm), add_val, op);
            update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, add_val, op);
            t[v] = t[v * 2] + t[v * 2 + 1];
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
        lazy2 = new T[4 * N];
        for (int i = 0; i < 4 * N; i++)
            lazy[i] = lazy2[i] = 0;
        build(a, 1, tla, tra);
    }
    T query(ll l, ll r)
    {
        return query(root, tla, tra, l, r);
    }
    void update(ll l, ll r, T add_val, ll op)
    {
        update(root, tla, tra, l, r, add_val, op);
    }
    void clear()
    {
        if (N)
        {
            delete[] t;
            delete[] lazy;
            delete[] lazy2;
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
    cin >> n >> q;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    lazy_segment_tree<ll> lsz(v);
    for (int i = 1; i <= q; i++)
    {
        cin >> c;
        if (c == 1)
        {
            ll x;
            cin >> a >> b >> x;
            lsz.update(a - 1, b - 1, x, 1);
        }
        else if (c == 2)
        {
            ll x;
            cin >> a >> b >> x;
            lsz.update(a - 1, b - 1, x, 2);
        }
        else if (c == 3)
        {
            cin >> a >> b;
            cout << lsz.query(a - 1, b - 1) << endl;
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