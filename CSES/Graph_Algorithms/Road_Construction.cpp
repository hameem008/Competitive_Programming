#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;
 
vector<ll> ele_cnt;
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
            ele_cnt[a] += ele_cnt[b];
            ele_cnt[b] = 0;
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
    ele_cnt.assign(n + 1, 1);
    ll max_ans = 1;
    ll comp = n;
    dsu ds(n);
    for (i = 1; i <= m; i++)
    {
        cin >> a >> b;
        a = ds.Find(a);
        b = ds.Find(b);
        if (a != b)
        {
            ds.Union(a, b);
            comp--;
            max_ans = max({max_ans, ele_cnt[a], ele_cnt[b]});
        }
        cout << comp << gap << max_ans << endl;
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