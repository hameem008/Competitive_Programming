class dsu
{
private:
    ll N = 0;
    ll *parrents;
    ll *ranks;

public:
    dsu(ll n)
    {
        build(n);
    }
    void build(ll n)
    {
        if (N)
            clear();
        N = n;
        parrents = new ll[n + 1];
        ranks = new ll[n + 1];
        for (ll i = 1; i <= n; i++)
        {
            parrents[i] = i;
            ranks[i] = 0;
        }
    }
    ll Find(ll v)
    {
        if (v == parrents[v])
            return v;
        return parrents[v] = Find(parrents[v]);
    }
    void Union(ll a, ll b)
    {
        a = Find(a);
        b = Find(b);
        if (a != b)
        {
            if (ranks[a] < ranks[b])
                swap(a, b);
            parrents[b] = a;
            if (ranks[a] == ranks[b])
                ranks[a]++;
        }
    }
    void clear()
    {
        if (N)
        {
            delete[] parrents;
            delete[] ranks;
        }
        N = 0;
    }
    ~dsu()
    {
        if (N)
            clear();
    }
};