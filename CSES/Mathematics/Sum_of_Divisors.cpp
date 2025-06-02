#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;
const ll MOD = 1e9 + 7;

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

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    ll limit = sqrt(n);
    ll tottal_sum = 0;
    ll modMulInvOf_2 = modMulInv(2, MOD);
    for (i = 1; i <= limit; i++)
    {
        k = n / i;
        a = ((k % MOD) * ((k % MOD + 1)) - (i * (i - 1)) % MOD + MOD) % MOD;
        a *= modMulInvOf_2;
        a %= MOD;
        ll sum = 0;
        sum = (sum + a) % MOD;
        sum = (sum + (((k - i + 1) % MOD) * i) % MOD) % MOD;
        sum = (sum - i + MOD) % MOD;
        tottal_sum = (tottal_sum + sum) % MOD;
    }
    cout << tottal_sum << endl;
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