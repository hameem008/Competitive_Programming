#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

template <class T>
class segment_tree
{
private:
    ll N = 0;
    T *t;
    T *t2;
    ll root = 1;
    ll tla = 0, tra = 0;
    void build(vector<T> &a, ll v, ll tl, ll tr)
    {
        if (tl == tr)
        {
            t[v] = a[tl] + tl;
            t2[v] = a[tl] - tl;
        }
        else
        {
            ll tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            t[v] = min(t[v * 2], t[v * 2 + 1]);
            t2[v] = min(t2[v * 2], t2[v * 2 + 1]);
        }
    }
    T query(ll v, ll tl, ll tr, ll l, ll r, ll der)
    {
        if (l > r)
            return INT32_MAX;
        if (l == tl && r == tr)
        {
            if (der == 0)
            {
                return t[v];
            }
            else
            {
                return t2[v];
            }
        }
        ll tm = (tl + tr) / 2;
        T a = query(v * 2, tl, tm, l, min(r, tm), der);
        T b = query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, der);
        return min(a, b);
    }
    void update(ll v, ll tl, ll tr, ll pos, T new_val)
    {
        if (tl == tr)
        {
            t[v] = new_val + tl;
            t2[v] = new_val - tl;
        }
        else
        {
            ll tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v * 2, tl, tm, pos, new_val);
            else
                update(v * 2 + 1, tm + 1, tr, pos, new_val);
            t[v] = min(t[v * 2], t[v * 2 + 1]);
            t2[v] = min(t2[v * 2], t2[v * 2 + 1]);
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
        t2 = new T[4 * N];
        build(a, 1, tla, tra);
    }
    T query(ll l, ll r, ll der)
    {
        return query(root, tla, tra, l, r, der);
    }
    void update(ll pos, T new_val)
    {
        update(root, tla, tra, pos, new_val);
    }
    void clear()
    {
        if (N)
        {
            delete[] t;
            delete[] t2;
        }
        N = 0, tra = 0, tla = 0;
    }
    ~segment_tree()
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
    segment_tree<ll> sg(v);
    for (i = 1; i <= q; i++)
    {
        cin >> c;
        if (c == 1)
        {
            cin >> a >> b;
            sg.update(a - 1, b);
            v[a - 1] = b;
        }
        else if (c == 2)
        {
            cin >> a;
            a--;
            if (a == 0)
            {
                cout << min(v[a], sg.query(1, n - 1, 0) - a) << endl;
            }
            else if (a == n - 1)
            {
                cout << min(v[a], sg.query(0, n - 2, 1) + a) << endl;
            }
            else
            {
                cout << min({v[a], sg.query(0, a - 1, 1) + a, sg.query(a + 1, n - 1, 0) - a}) << endl;
            }
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