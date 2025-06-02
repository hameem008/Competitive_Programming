#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

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

void dfs(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited)
{
    isVisited[vertex] = true;
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            dfs(x, graph, isVisited);
        }
    }
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> m;
    vector<vector<ll>> graph(n + 1);
    vector<bool> isVisited(n + 1, false);
    vector<pair<ll, pair<ll, ll>>> v;
    vector<bool> isDone(n + 1, false);
    for (i = 1; i <= m; i++)
    {
        cin >> a >> b >> k;
        graph[a].push_back(b);
        graph[b].push_back(a);
        v.push_back({k, {a, b}});
    }
    dfs(1, graph, isVisited);
    flag = true;
    for (i = 1; i <= n; i++)
    {
        if (!isVisited[i])
            flag = false;
    }
    if (!flag)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    sort(v.begin(), v.end());
    dsu ds(n);
    ll cost = 0;
    for (auto x : v)
    {
        if (ds.Find(x.second.first) != ds.Find(x.second.second))
        {
            ds.Union(x.second.first, x.second.second);
            cost += x.first;
        }
    }
    cout << cost << endl;
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