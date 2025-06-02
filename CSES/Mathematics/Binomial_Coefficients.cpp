#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;
const ll MOD = 1e9 + 7;

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
        return (a * b) % MOD;
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
            return 1;
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

segment_tree<ll> sg;

ll binExp(ll a, ll b, ll mod)
{
    if (b == 0)
        return 1;
    ll rec = binExp(a, b / 2, mod);
    if (b % 2 != 0)
        return ((a % mod) * (rec % mod) % mod) * (rec % mod) % mod;
    else
        return (rec % mod) * (rec % mod) % mod;
}

ll modMulInv(ll n, ll mod)
{
    return binExp(n, mod - 2, mod) % mod;
}

ll abybmod(ll a, ll b, ll mod)
{
    ll ans = a;
    ans %= mod;
    ans *= modMulInv(b, mod);
    ans %= mod;
    return ans;
}

ll nCr(ll n, ll r, ll mod)
{
    ll nfact = sg.query(0, n - 1), rfact = sg.query(0, r - 1), n_rfact = sg.query(0, n - r - 1);
    ll ans = abybmod(nfact, rfact, mod);
    ans = abybmod(ans, n_rfact, mod);
    return ans;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> a >> b;
    cout << nCr(a, b, MOD) << endl;
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<ll> sgv;
    for (ll i = 1; i <= 1e6; i++)
        sgv.push_back(i);
    sg.build(sgv);
    ll T = 1;
    cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}