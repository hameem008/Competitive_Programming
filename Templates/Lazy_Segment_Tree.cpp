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
        t[v * 2] += (tm - tl + 1) * lazy[v];
        lazy[v * 2] += lazy[v];
        t[v * 2 + 1] += (tr - tm) * lazy[v];
        lazy[v * 2 + 1] += lazy[v];
        lazy[v] = 0;
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
        // for min--> return INT32_MAX;
        // for max--> return INT32_MIN;
        if (l == tl && r == tr)
            return t[v];
        ll tm = (tl + tr) / 2;
        push(v, tl, tm, tr);
        T a = query(v * 2, tl, tm, l, min(r, tm));
        T b = query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
        return a + b;
    }
    void update(ll v, ll tl, ll tr, ll l, ll r, T add_val)
    {
        if (l > r)
            return;
        if (l == tl && r == tr)
        {
            t[v] += (r - l + 1) * add_val;
            lazy[v] += add_val;
        }
        else
        {
            ll tm = (tl + tr) / 2;
            push(v, tl, tm, tr);
            update(v * 2, tl, tm, l, min(r, tm), add_val);
            update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, add_val);
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