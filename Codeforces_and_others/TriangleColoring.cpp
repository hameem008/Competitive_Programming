#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
ll MOD = 998244353;

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
    ll nfact = 1, rfact = 1, n_rfact = 1;
    for (int i = 1; i <= n; i++)
    {
        nfact *= i;
        nfact %= mod;
    }
    for (int i = 1; i <= r; i++)
    {
        rfact *= i;
        rfact %= mod;
    }
    for (int i = 1; i <= n - r; i++)
    {
        n_rfact *= i;
        n_rfact %= mod;
    }
    ll ans = abybmod(nfact, rfact, mod);
    ans = abybmod(ans, n_rfact, mod);
    return ans;
}

ll check_triangle(ll a, ll b, ll c)
{
    set<ll> s = {a, b, c};
    multiset<ll> ms = {a, b, c};
    if (s.size() == 1)
        return 3;
    else if (s.size() == 2)
    {
        if (ms.count(*s.begin()) == 2)
            return 2;
        else
            return 1;
    }
    else
        return 1;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<ll> v;
    for (i = 0; i < n; i++)
    {
        cin >> a;
        v.push_back(a);
    }
    ll ans = 1;
    for (i = 0; i < n; i += 3)
    {
        ans *= check_triangle(v[i], v[i + 1], v[i + 2]);
        ans %= MOD;
    }
    cout << (nCr(n / 3, n / 6, MOD) * ans) % MOD << endl;
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