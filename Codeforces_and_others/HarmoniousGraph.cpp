#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

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

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> m;
    dsu ds(n);
    for (i = 1; i <= m; i++)
    {
        cin >> a >> b;
        ds.Union(ds.Find(a), ds.Find(b));
    }
    for (i = 1; i <= n; i++)
        ds.Find(i);
    vector<pair<ll, ll>> vp(n + 1, {-1, -1});
    for (i = 1; i <= n; i++)
    {
        if (vp[ds.Find(i)].first == -1)
        {
            vp[ds.Find(i)].first = i;
        }
    }
    for (i = n; i >= 1; i--)
    {
        if (vp[ds.Find(i)].second == -1)
        {
            vp[ds.Find(i)].second = i;
        }
    }
    set<pair<ll, ll>> s;
    for (i = 1; i <= n; i++)
    {
        if (vp[i] != (pair<ll, ll>){-1, -1})
        {
            s.insert({vp[i]});
        }
    }
    ll ans = 0;
    while (s.size() > 1)
    {
        auto it = s.begin();
        pair<ll, ll> seg1 = *it;
        it++;
        pair<ll, ll> seg2 = *it;
        if (seg1.second > seg2.first)
        {
            s.erase(s.begin());
            s.erase(s.begin());
            s.insert({seg1.first, max(seg1.second, seg2.second)});
            ans++;
        }
        else
        {
            s.erase(s.begin());
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
    // cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}