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
        T a = query(v * 2, tl, tm, l, min(r, tm));
        T b = query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
        return min(a, b);
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
            t[v] = min(t[v * 2], t[v * 2 + 1]);
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
    bool flag;
    // solve starts
    cin >> n;
    vector<ll> map1(n), map2(n);
    for (auto &x : map1)
        cin >> x;
    for (auto &x : map2)
        cin >> x;
    map<ll, ll> mp1, mp2;
    for (i = 0; i < n; i++)
    {
        mp1.insert({map1[i], i});
        mp2.insert({map2[i], i});
    }
    i = 0;
    for (auto x : mp1)
    {
        map1[x.second] = i;
        i++;
    }
    i = 0;
    for (auto x : mp2)
    {
        map2[x.second] = i;
        i++;
    }
    mp1.clear();
    mp2.clear();
    for (i = 0; i < n; i++)
    {
        mp1.insert({map1[i], i});
        mp2.insert({map2[i], i});
    }
    vector<ll> map1keymap2value(n), map2keymap1value(n);
    for (auto x : mp1)
    {
        map1keymap2value[x.first] = map2[x.second];
    }
    for (auto x : mp2)
    {
        map2keymap1value[x.first] = map1[x.second];
    }
    segment_tree<ll> sgmap1keymap2value(map1keymap2value), sgmap2keymap1value(map2keymap1value);
    ll lowmap1 = n - 1, lowmap2 = n - 1;
    for (i = 0; i < n; i++)
    {
        lowmap1 = sgmap2keymap1value.query(lowmap2, n - 1);
        lowmap2 = sgmap1keymap2value.query(lowmap1, n - 1);
    }
    for (i = 0; i < n; i++)
    {
        if (map1[i] >= lowmap1 || map2[i] >= lowmap2)
            cout << 1;
        else
            cout << 0;
    }
    cout << endl;
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll T = 1;
    cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}