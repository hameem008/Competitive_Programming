#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = 1e17;

vector<multiset<ll>> distance_dijkstra;
void dijkstra(vector<vector<pair<ll, ll>>> &graph, ll source, ll k)
{
    ll n = graph.size();
    distance_dijkstra.clear();
    while (distance_dijkstra.size() != n)
    {
        multiset<ll> ms;
        for (ll j = 1; j <= k; j++)
        {
            ms.insert(infinite);
        }
        distance_dijkstra.push_back(ms);
    }
    distance_dijkstra[1].erase(--distance_dijkstra[1].end());
    distance_dijkstra[1].insert(0);
    ll cost;
    multiset<pair<ll, ll>> pq;
    pq.insert({0, source});
    while (pq.size())
    {
        pair<ll, ll> p = *pq.begin();
        pq.erase(pq.begin());
        cost = p.first;
        if (*(--distance_dijkstra[p.second].end()) < cost)
            continue;
        for (auto x : graph[p.second])
        {
            auto it = --distance_dijkstra[x.first].end();
            if (cost + x.second < *it)
            {
                distance_dijkstra[x.first].erase(it);
                distance_dijkstra[x.first].insert(cost + x.second);
                pq.insert({cost + x.second, x.first});
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
    vector<vector<pair<ll, ll>>> graph(n + 1);
    for (i = 1; i <= m; i++)
    {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    dijkstra(graph, 1, k);
    for (auto x : distance_dijkstra[n])
        cout << x << gap;
    cout << endl;
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