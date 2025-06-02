#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

ll m;
vector<ll> cats;
map<ll, ll> reachable;

void dfs(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVIsited, ll catsCount)
{
    if (cats[vertex] == 0 && catsCount <= m)
    {
        catsCount = 0;
    }
    else
    {
        catsCount += cats[vertex];
    }
    isVIsited[vertex] = true;
    if (graph[vertex].size() == 1 && vertex != 1)
    {
        reachable[vertex] = catsCount;
    }
    else
    {
        for (auto x : graph[vertex])
        {
            if (!isVIsited[x])
            {
                dfs(x, graph, isVIsited, catsCount);
            }
        }
    }
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, n, p, q;
    bool flag;
    // solve starts
    reachable.clear();
    cin >> n >> m;
    cats.clear();
    cats.assign(n + 1, 0);
    for (i = 1; i <= n; i++)
    {
        cin >> cats[i];
    }
    vector<ll> dum;
    vector<vector<ll>> graph(n + 1, dum);
    vector<bool> isVisited(n + 1, false);
    for (i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1, graph, isVisited, 0);
    ll ans = 0;
    for (auto x : reachable)
    {
        if (x.second <= m)
            ans++;
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