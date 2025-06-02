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
    ll root = 1;
    ll tla = 0, tra = 0;
    T combine(T a, T b)
    {
        return a + b;
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
            t[v] = combine(t[v * 2], t[v * 2 + 1]);
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
        return combine(a, b);
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
            t[v] = combine(t[v * 2], t[v * 2 + 1]);
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

vector<ll> build(string str)
{
    ll upper = 0;
    vector<ll> v;
    for (ll i = str.size() - 1; i >= 0; i--)
    {
        ll num = powl(10, str[i] - 'A');
        if (num >= upper)
        {
            v.push_back(num);
        }
        else
        {
            v.push_back(-num);
        }
        upper = max(num, upper);
    }
    reverse(v.begin(), v.end());
    return v;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    string str;
    cin >> str;
    ll upper = 0;
    vector<ll> v = build(str);
    n = v.size();
    segment_tree<ll> sg(v);
    ll ans = -infinite;
    for (i = 0; i < n; i++)
    {
        sg.update(i, 10000);
        ans = max(ans, sg.query(0, n - 1));
        if (v[i] != 10000)
            sg.update(i, -abs(v[i]));
    }
    for (i = 0; i < n; i++)
    {
        v[i] = abs(v[i]);
    }
    vector<ll> pos;
    ll up = 0;
    for (i = n - 1; i >= 0; i--)
    {
        if (up < v[i])
        {
            up = v[i];
            pos.push_back(i);
        }
    }
    for (i = 0; i < pos.size(); i++)
    {
        for (char ch = 'A'; ch <= 'E'; ch++)
        {
            string dum_str = str;
            dum_str[pos[i]] = ch;
            v.clear();
            v = build(dum_str);
            ans = max(ans, accumulate(v.begin(), v.end(), 0LL));
        }
    }
    cout << ans << endl;
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