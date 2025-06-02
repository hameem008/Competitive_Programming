#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

vector<int> parrents_dijkstra;
vector<int> distance_dijkstra;
void dijkstra(vector<vector<pair<int, int>>> &graph, int source)
{
    int n = graph.size();
    parrents_dijkstra.clear();
    distance_dijkstra.clear();
    parrents_dijkstra.assign(n, -1);
    distance_dijkstra.assign(n, 99999999);
    distance_dijkstra[source] = 0;
    parrents_dijkstra[source] = source;
    vector<bool> isDone(n, false);
    int cost;
    set<pair<int, int>> pq;
    pq.insert({distance_dijkstra[source], source});
    while (pq.size())
    {
        pair<int, int> p = *pq.begin();
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
vector<int> shortest_path_dijkstra(int source, int destination)
{
    vector<int> path;
    int node = destination;
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

    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll T = 1;
    cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}