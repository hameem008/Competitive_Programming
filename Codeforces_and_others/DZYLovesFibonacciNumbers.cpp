#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef int ll;
typedef long double lld;
const ll mod = 1e9 + 9;
ll L, R;

vector<ll> fib;
void calculate_fib()
{
    ll N = 3e5 + 10;
    fib.assign(N, 0);
    fib[1] = 1;
    for (int i = 2; i < N; i++)
    {
        fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
    }
    for (int i = 1; i < N; i++)
    {
        fib[i] = (fib[i] + fib[i - 1]) % mod;
    }
}

ll get_fib_range_sum(ll l, ll r)
{
    ll sum = (fib[r] - fib[l - 1] + mod) % mod;
    return sum;
}

template <class T>
class lazy_segment_tree
{
private:
    ll N = 0;
    T *t;
    ll root = 1;
    ll tla = 0, tra = 0;
    vector<vector<ll>> fib_range;
    void push(ll v, ll tl, ll tm, ll tr)
    {
        for (auto x : fib_range[v])
        {
            ll lo = x, mid, hi = x + tr - tl;
            mid = lo + tm - tl;
            t[v * 2] += get_fib_range_sum(lo, mid);
            t[v * 2] %= mod;
            // if (fib_range[v * 2].size())
            // {
            //     push(v * 2, tl, (tl + tm) / 2, tm);
            // }
            if (lo != mid)
            {
                fib_range[v * 2].push_back(lo);
            }
            t[v * 2 + 1] += get_fib_range_sum(mid + 1, hi);
            t[v * 2 + 1] %= mod;
            // if (fib_range[v * 2 + 1].size())
            // {
            //     push(v * 2 + 1, tm + 1, (tm + 1 + tr) / 2, tr);
            // }
            if (mid + 1 != hi)
            {
                fib_range[v * 2 + 1].push_back(mid + 1);
            }
        }
        fib_range[v].clear();
        fib_range[v].shrink_to_fit();
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
            t[v] = (t[v * 2] + t[v * 2 + 1]) % mod;
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
        return (a + b) % mod;
    }
    void update(ll v, ll tl, ll tr, ll l, ll r)
    {
        if (l > r)
            return;
        if (l == tl && r == tr)
        {
            t[v] += get_fib_range_sum(1 + (l - L), (R - L + 1) - (R - r));
            t[v] %= mod;
            if ((R - L + 1) - (R - r) != 1 + (l - L))
            {
                fib_range[v].push_back(1 + (l - L));
            }
        }
        else
        {
            ll tm = (tl + tr) / 2;
            push(v, tl, tm, tr);
            update(v * 2, tl, tm, l, min(r, tm));
            update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
            t[v] = (t[v * 2] + t[v * 2 + 1]) % mod;
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
        vector<vector<ll>> vp(4 * N);
        fib_range = vp;
        for (int i = 0; i < 4 * N; i++)
        {
            fib_range[i].shrink_to_fit();
        }
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
            fib_range.clear();
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
    lazy_segment_tree<ll> lst(v);
    for (i = 1; i <= q; i++)
    {
        ll l, r;
        cin >> k >> l >> r;
        if (k == 1)
        {
            L = l - 1;
            R = r - 1;
            lst.update(l - 1, r - 1);
        }
        else if (k == 2)
        {
            cout << lst.query(l - 1, r - 1) << endl;
        }
    }
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    calculate_fib();
    for (int i = 1; i <= 10; i++)
        cout << fib[i] << gap;
    cout << endl;
    ll T = 1;
    // cin >> T;
    for (int I = 1; I <= T; I++)
    {
        // solve(I, T);
    }
    return 0;
}