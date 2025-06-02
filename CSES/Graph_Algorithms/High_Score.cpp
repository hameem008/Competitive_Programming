#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = 8e16;

vector<bool> can_be_reached;
vector<bool> can_be_reached_from_1;
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

bool isCyclePresent = false;
vector<ll> parrents_bellman_ford;
vector<ll> distance_bellman_ford;
void bellman_ford(vector<pair<pair<ll, ll>, ll>> &edge_list, ll source, ll n)
{
    parrents_bellman_ford.clear();
    distance_bellman_ford.clear();
    parrents_bellman_ford.assign(n, -1);
    distance_bellman_ford.assign(n, infinite);
    parrents_bellman_ford[source] = source;
    distance_bellman_ford[source] = 0;
    ll limit = n - 1;
    while (limit--)
    {
        for (auto x : edge_list)
        {
            if (distance_bellman_ford[x.first.first] + x.second < distance_bellman_ford[x.first.second])
            {
                distance_bellman_ford[x.first.second] = distance_bellman_ford[x.first.first] + x.second;
                parrents_bellman_ford[x.first.second] = x.first.first;
            }
        }
    }
    vector<ll> check = distance_bellman_ford;
    limit = 3;
    while (limit--)
    {
        for (auto x : edge_list)
        {
            if (distance_bellman_ford[x.first.first] + x.second < distance_bellman_ford[x.first.second])
            {
                distance_bellman_ford[x.first.second] = distance_bellman_ford[x.first.first] + x.second;
                parrents_bellman_ford[x.first.second] = x.first.first;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (can_be_reached[i] && can_be_reached_from_1[i])
        {
            if (check[i] != distance_bellman_ford[i])
                isCyclePresent = true;
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
    vector<vector<ll>> graph(n + 1);
    can_be_reached.assign(n + 1, false);
    can_be_reached_from_1 = can_be_reached;
    for (i = 0; i < m; i++)
    {
        cin >> a >> b >> d;
        graph[a].push_back(b);
        edge_list.push_back({{a, b}, -d});
    }
    for (i = 1; i <= n; i++)
    {
        vector<bool> isVisited(n + 1, false);
        dfs(i, graph, isVisited);
        can_be_reached[i] = isVisited[n];
    }
    vector<bool> isVisited(n + 1, false);
    dfs(1, graph, isVisited);
    for (i = 1; i <= n; i++)
    {
        can_be_reached_from_1[i] = isVisited[i];
    }
    bellman_ford(edge_list, 1, n + 1);
    if (isCyclePresent)
        cout << -1 << endl;
    else
        cout << -distance_bellman_ford[n] << endl;
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