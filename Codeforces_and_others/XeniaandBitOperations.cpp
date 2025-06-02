#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

template <class T>
class segment_tree
{
private:
    ll N = 0;
    T *t;
    ll root = 1;
    ll tla = 0, tra = 0;
    void build(vector<T> &a, ll v, ll tl, ll tr)
    {
        if (tl == tr)
            t[v] = a[tl];
        else
        {
            ll tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            ll val = (ll)log2(tr - tl + 1);
            if (val % 2 == 0)
                t[v] = (t[v * 2] ^ t[v * 2 + 1]);
            else
                t[v] = (t[v * 2] | t[v * 2 + 1]);
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
        ll val = (ll)log2(tr - tl + 1);
        if (val % 2 == 0)
            return (a ^ b);
        else
            return (a | b);
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
            ll val = (ll)log2(tr - tl + 1);
            if (val % 2 == 0)
                t[v] = (t[v * 2] ^ t[v * 2 + 1]);
            else
                t[v] = (t[v * 2] | t[v * 2 + 1]);
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

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    // solve starts
    cin >> n >> m;
    vector<ll> v;
    for (i = 0; i < pow(2, n); i++)
    {
        cin >> a;
        v.push_back(a);
    }
    segment_tree<ll> sg(v);
    for (i = 0; i < m; i++)
    {
        cin >> a >> b;
        a--;
        sg.update(a, b);
        cout << sg.query(0, pow(2, n) - 1) << endl;
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