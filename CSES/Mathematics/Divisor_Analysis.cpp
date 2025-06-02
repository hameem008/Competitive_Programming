#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;
const ll md = 1e9 + 7;

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
    vector<ll> vx(n + 1, 0), vk(n + 1, 0);
    for (i = 1; i <= n; i++)
    {
        cin >> vx[i] >> vk[i];
    }
    vector<ll> dpn(n + 1, 0), dpn2(n + 1, 0), dps(n + 1, 0), dpm(n + 1, 0);
    dpn[0] = dpn2[0] = dps[0] = dpm[0] = 1;
    for (i = 1; i <= n; i++)
    {
        a = vk[i] + 1;
        dpn[i] = a * dpn[i - 1];
        dpn[i] %= md;
        a = vk[i] + 1;
        dpn2[i] = a * dpn2[i - 1];
        dpn2[i] %= (md - 1);
        a = binExp(vx[i], vk[i] + 1, md) - 1 + md;
        a %= md;
        a = abybmod(a, vx[i] - 1, md);
        dps[i] = a * dps[i - 1];
        dps[i] %= md;
        a = vk[i] * (vk[i] + 1);
        a /= 2;
        a %= (md - 1);
        a *= dpn2[i - 1];
        a %= (md - 1);
        a = binExp(vx[i], a, md);
        dpm[i] = a * binExp(dpm[i - 1], vk[i] + 1, md);
        dpm[i] %= md;
    }
    cout << dpn[n] << gap << dps[n] << gap << dpm[n] << endl;
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