#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

ll used = 0;
vector<ll> parrents_dijkstra;
vector<ll> distance_dijkstra;
void dijkstra(vector<vector<vector<ll>>> &graph, ll source)
{
    ll n = graph.size();
    parrents_dijkstra.clear();
    distance_dijkstra.clear();
    parrents_dijkstra.assign(n, -1);
    distance_dijkstra.assign(n, infinite);
    distance_dijkstra[source] = 0;
    parrents_dijkstra[source] = source;
    vector<bool> isDone(n, false);
    ll cost;
    multiset<vector<ll>> pq;
    pq.insert({distance_dijkstra[source], 0, source});
    while (pq.size())
    {
        vector<ll> p = *pq.begin();
        pq.erase(pq.begin());
        cost = p[0];
        if (isDone[p[2]])
            continue;
        isDone[p[2]] = true;
        if (p[1] == 1)
            used++;
        for (auto x : graph[p[2]])
        {
            if (cost + x[0] < distance_dijkstra[x[2]])
            {
                distance_dijkstra[x[2]] = cost + x[0];
                parrents_dijkstra[x[2]] = p[2];
                pq.insert({distance_dijkstra[x[2]], x[1], x[2]});
            }
        }
    }
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> m >> k;
    vector<vector<vector<ll>>> graph(n + 1);
    for (i = 1; i <= m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({w, 0, v});
        graph[v].push_back({w, 0, u});
    }
    for (i = 1; i < k; i++)
    {
        ll u = 1, v, w;
        cin >> v >> w;
        graph[u].push_back({w, 1, v});
        graph[v].push_back({w, 1, u});
    }
    for (i = 1; i <= n; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }
    dijkstra(graph, 1);
    cout << k - used << endl;
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