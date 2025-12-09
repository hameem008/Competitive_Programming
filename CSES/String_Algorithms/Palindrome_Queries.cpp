#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;
int mod = 1e9 + 9;

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

vector<ll> forward_hash, backward_hash;
vector<ll> vexp;
ll compute_hash(string &s, vector<ll> &v_hash)
{
    int p = 31; // 53 for both case
    int m = 1e9 + 9;
    ll hash_value = 0;
    ll p_pow = 1;
    vexp.push_back(p_pow);
    int i = 0;
    for (char c : s)
    {
        ll add_hash_value = (c - 'a' + 1) * p_pow % m;
        hash_value = (hash_value + add_hash_value) % m;
        p_pow = (p_pow * p) % m;
        vexp.push_back(p_pow);
        v_hash.push_back(add_hash_value);
    }
    return hash_value;
}

template <class T>
class fenwick_tree
{
private:
    int N;
    vector<T> bit;
    T sum(int r)
    {
        T ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret = (ret + bit[r]) % mod;
        return ret;
    }

public:
    fenwick_tree() {}
    fenwick_tree(vector<T> &a) { build(a); }
    void build(vector<T> &a)
    {
        N = a.size();
        bit.assign(N, 0);
        for (int i = 0; i < a.size(); i++)
            add(i, a[i]);
    }
    T sum(int l, int r)
    {
        return (sum(r) - sum(l - 1) + mod) % mod;
    }
    void add(int pos, int add_val)
    {
        for (; pos < N; pos = pos | (pos + 1))
            bit[pos] = (bit[pos] + add_val) % mod;
    }
};

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    char ch;
    bool flag;
    // solve starts
    cin >> n >> m;
    string str;
    cin >> str;
    compute_hash(str, forward_hash);
    reverse(str.begin(), str.end());
    compute_hash(str, backward_hash);
    reverse(str.begin(), str.end());
    fenwick_tree<ll> fen_f(forward_hash), fen_b(backward_hash);
    for (i = 0; i < m; i++)
    {
        cin >> k;
        if (k == 1)
        {
            cin >> k >> ch;
            fen_f.add(k - 1, mod - fen_f.sum(k - 1, k - 1));
            fen_f.add(k - 1, (ch - 'a' + 1) * vexp[k - 1] % mod);
            fen_b.add(n - k, mod - fen_b.sum(n - k, n - k));
            fen_b.add(n - k, (ch - 'a' + 1) * vexp[n - k] % mod);
        }
        else
        {
            cin >> p >> q;
            ll val_f = abybmod(fen_f.sum(p - 1, q - 1), vexp[p - 1], mod);
            ll val_b = abybmod(fen_b.sum(n - q, n - p), vexp[n - q], mod);
            if (val_f == val_b)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
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