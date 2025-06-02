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
    cin >> n >> m;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    map<ll, ll> freq;
    for (auto x : v)
        freq[x]++;
    vector<pair<ll, ll>> vpfreq;
    for (auto x : freq)
        vpfreq.push_back(x);
    ll ans = 0;
    ll buf = 1;
    n = vpfreq.size();
    if (m > n)
    {
        cout << ans << endl;
        return;
    }
    for (i = 0; i <= m - 1; i++)
    {
        buf *= vpfreq[i].second;
        buf %= MOD;
    }
    i = 0, j = m - 1;
    if (vpfreq[j].first - vpfreq[i].first == m - 1)
    {
        ans += buf;
        ans %= MOD;
    }
    i++, j++;
    for (; j < vpfreq.size(); i++, j++)
    {
        buf = abybmod(buf, vpfreq[i - 1].second, MOD);
        buf *= vpfreq[j].second;
        buf %= MOD;
        if (vpfreq[j].first - vpfreq[i].first == m - 1)
        {
            ans += buf;
            ans %= MOD;
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