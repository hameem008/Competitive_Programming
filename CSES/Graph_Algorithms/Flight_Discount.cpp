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

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> m;
    vector<pair<pair<ll, ll>, ll>> edge_list;
    vector<vector<pair<ll, ll>>> grap1(n + 1), grap1n(n + 1);
    for (i = 0; i < m; i++)
    {
        cin >> a >> b >> d;
        edge_list.push_back({{a, b}, d});
        grap1[a].push_back({b, d});
        grap1n[b].push_back({a, d});
    }
    dijkstra(grap1, 1);
    vector<ll> dist_from_1 = distance_dijkstra;
    dijkstra(grap1n, n);
    vector<ll> dist_from_n = distance_dijkstra;
    ll ans = infinite;
    for (auto x : edge_list)
    {
        ans = min(ans, dist_from_1[x.first.first] + x.second / 2 + dist_from_n[x.first.second]);
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