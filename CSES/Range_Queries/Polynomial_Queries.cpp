#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;
ll L, R;

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
        lld d = lazy2[v];
        lld a = lazy[v];
        lld n = tm - tl + 1;
        lld sum = (2 * a + (n - 1) * d) * (n / 2);
        t[v * 2] += (ll)sum;
        lazy[v * 2] += a;
        lazy2[v * 2] += lazy2[v];
        a = a + n * d;
        n = tr - tm;
        sum = (2 * a + (n - 1) * d) * (n / 2);
        t[v * 2 + 1] += (ll)sum;
        lazy[v * 2 + 1] += a;
        lazy2[v * 2 + 1] += lazy2[v];
        lazy[v] = 0;
        lazy2[v] = 0;
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
    void update(ll v, ll tl, ll tr, ll l, ll r)
    {
        if (l > r)
            return;
        if (l == tl && r == tr)
        {
            lld d = 1;
            lld a = l - L + 1;
            lld n = r - l + 1;
            lld sum = (2 * a + (n - 1) * d) * (n / 2);
            t[v] += (ll)sum;
            lazy[v] += a;
            lazy2[v]++;
        }
        else
        {
            ll tm = (tl + tr) / 2;
            push(v, tl, tm, tr);
            update(v * 2, tl, tm, l, min(r, tm));
            update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
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
    void update(ll l, ll r)
    {
        update(root, tla, tra, l, r);
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
    lazy_segment_tree<ll> lsg(v);
    for (i = 0; i < q; i++)
    {
        cin >> c >> a >> b;
        a--, b--;
        if (c == 1)
        {
            L = a, R = b;
            lsg.update(a, b);
        }
        else if (c == 2)
        {
            cout << lsg.query(a, b) << endl;
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