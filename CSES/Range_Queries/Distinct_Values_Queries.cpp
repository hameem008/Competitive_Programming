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
        // return min(a, b);
        // return max(a, b);
        // return __gcd(a, b);
        // return a ^ b;
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
        // for min--> return INT32_MAX;
        // for max--> return INT32_MIN;
        // for gcd--> retyrn 0;
        // for xor--> return 0;
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

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> q;
    vector<ll> v(n + 1, 0);
    for (i = 1; i <= n; i++)
        cin >> v[i];
    vector<pair<ll, ll>> queries, dum_queries;
    for (i = 1; i <= q; i++)
    {
        cin >> a >> b;
        queries.push_back({a, b});
    }
    dum_queries = queries;
    sort(dum_queries.begin(), dum_queries.end());
    map<ll, set<ll>> mp;
    map<pair<ll, ll>, ll> ans;
    for (i = 1; i <= n; i++)
    {
        mp[v[i]].insert(i);
    }
    vector<ll> dum_v(n + 1, 0);
    for (auto x : mp)
    {
        dum_v[*x.second.begin()] = 1;
    }
    segment_tree<ll> sg(dum_v);
    ll low = 0, up = 0;
    for (auto x : dum_queries)
    {
        up = x.first - 1;
        for (i = low; i <= up; i++)
        {
            if (dum_v[i] == 1)
            {
                auto it = mp[v[i]].lower_bound(up + 1);
                if (it != mp[v[i]].end())
                {
                    dum_v[*it] = 1;
                    sg.update(*it, 1);
                }
                dum_v[i] = 0;
                sg.update(i, 0);
            }
        }
        low = x.first;
        ans[x] = sg.query(x.first, x.second);
    }
    for (auto x : queries)
        cout << ans[x] << endl;
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