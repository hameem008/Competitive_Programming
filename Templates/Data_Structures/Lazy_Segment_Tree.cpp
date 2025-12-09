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
        return a + b;
        // return min(a, b);
        // return max(a, b);
    }
    void push(ll v, ll tl, ll tm, ll tr)
    {
        // change here for min/max
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
            t[v] = combine(t[v * 2], t[v * 2 + 1]);
        }
    }
    T query(ll v, ll tl, ll tr, ll l, ll r)
    {
        if (l > r)
            return 0;
        // for min--> return INT64_MAX;
        // for max--> return INT64_MIN;
        if (l == tl && r == tr)
            return t[v];
        ll tm = (tl + tr) / 2;
        push(v, tl, tm, tr);
        T a = query(v * 2, tl, tm, l, min(r, tm));
        T b = query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
        return combine(a, b);
    }
    void update(ll v, ll tl, ll tr, ll l, ll r, T val, ll op)
    {
        if (l > r)
            return;
        if (l == tl && r == tr)
        {
            if (op == 1) // increament
            {
                t[v] += (r - l + 1) * val;
                lazy[v] += val;
            }
            else if (op == 2) // assignment
            {
                t[v] = (r - l + 1) * val;
                lazy[v] = 0;
                lazy2[v] = val;
            }
        }
        else
        {
            ll tm = (tl + tr) / 2;
            push(v, tl, tm, tr);
            update(v * 2, tl, tm, l, min(r, tm), val, op);
            update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val, op);
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
    void update(ll l, ll r, T add_val, ll op)
    {
        update(root, tla, tra, l, r, add_val, op);
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