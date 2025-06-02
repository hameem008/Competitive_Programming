#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = 5e12;

vector<vector<ll>> shortest_distance;
vector<vector<ll>> graph;
void floydwarshall(ll n)
{
    for (ll i = 1; i <= n; i++)
    {
        for (ll u = 1; u <= n; u++)
        {
            for (ll v = 1; v <= n; v++)
            {
                shortest_distance[u][v] = min(shortest_distance[u][v], shortest_distance[u][i] + shortest_distance[i][v]);
            }
        }
    }
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> m >> q;
    graph.assign(n + 1, vector<ll>(n + 1, infinite));
    for (i = 0; i < m; i++)
    {
        cin >> a >> b >> d;
        graph[a][b] = graph[b][a] = min(d, graph[a][b]);
    }
    for (i = 1; i <= n; i++)
    {
        graph[i][i] = 0;
    }
    shortest_distance = graph;
    floydwarshall(n);
    for (i = 0; i < q; i++)
    {
        cin >> a >> b;
        shortest_distance[a][b] >= infinite ? cout << -1 << endl : cout << shortest_distance[a][b] << endl;
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