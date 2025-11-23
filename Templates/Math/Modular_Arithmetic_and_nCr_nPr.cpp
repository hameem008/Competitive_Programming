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

ll nPr(ll n, ll r, ll mod)
{
    ll nfact = 1, n_rfact = 1;
    for (int i = 1; i <= n; i++)
    {
        nfact *= i;
        nfact %= mod;
    }
    for (int i = 1; i <= n - r; i++)
    {
        n_rfact *= i;
        n_rfact %= mod;
    }
    ll ans = abybmod(nfact, n_rfact, mod);
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