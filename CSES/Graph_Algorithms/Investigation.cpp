#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;
const ll mod = 1e9 + 7;

vector<ll> paths, minf, maxf;

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
                paths[x.first] = paths[p.second];
                minf[x.first] = minf[p.second] + 1;
                maxf[x.first] = maxf[p.second] + 1;
                pq.insert({distance_dijkstra[x.first], x.first});
            }
            else if (cost + x.second == distance_dijkstra[x.first])
            {
                distance_dijkstra[x.first] = cost + x.second;
                parrents_dijkstra[x.first] = p.second;
                paths[x.first] += paths[p.second];
                paths[x.first] %= mod;
                minf[x.first] = min(minf[x.first], minf[p.second] + 1);
                maxf[x.first] = max(maxf[x.first], maxf[p.second] + 1);
                pq.insert({distance_dijkstra[x.first], x.first});
            }
        }
    }
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> m;
    paths.assign(n + 1, 0);
    paths[1] = 1;
    minf.assign(n + 1, 0);
    maxf.assign(n + 1, 0);
    vector<vector<pair<ll, ll>>> graph(n + 1);
    for (i = 1; i <= m; i++)
    {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    dijkstra(graph, 1);
    cout << distance_dijkstra[n] << gap << paths[n] << gap << minf[n] << gap << maxf[n] << endl;
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