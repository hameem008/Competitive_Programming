#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = 8e16;

vector<ll> parrents_dijkstra;
vector<ll> distance_dijkstra;
void dijkstra(vector<vector<pair<ll, ll>>> &graph, ll source)
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
    set<pair<ll, ll>> pq;
    pq.insert({distance_dijkstra[source], source});
    while (pq.size())
    {
        pair<ll, ll> p = *pq.begin();
        pq.erase(pq.begin());
        cost = p.first;
        if (isDone[p.second])
            continue;
        isDone[p.second] = true;
        for (auto x : graph[p.second])
        {
            if (cost + x.second < distance_dijkstra[x.first])
            {
                distance_dijkstra[x.first] = cost + x.second;
                parrents_dijkstra[x.first] = p.second;
                pq.insert({distance_dijkstra[x.first], x.first});
            }
        }
    }
}
vector<ll> shortest_path_dijkstra(ll source, ll destination)
{
    vector<ll> path;
    ll node = destination;
    while (node != source)
    {
        path.push_back(node);
        node = parrents_dijkstra[node];
    }
    path.push_back(source);
    reverse(path.begin(), path.end());
    return path;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> graph(n + 1);
    for (i = 1; i <= m; i++)
    {
        ll w;
        cin >> a >> b >> w;
        graph[a].push_back({b, w});
    }
    dijkstra(graph, 1);
    for (i = 1; i <= n; i++)
    {
        cout << distance_dijkstra[i] << gap;
    }
    cout << endl;
    // solve ends
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    ll T = 1;
    // cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}