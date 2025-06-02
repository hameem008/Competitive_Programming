#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

void dfs(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited, vector<ll> &cost)
{
    isVisited[vertex] = true;
    if (graph[vertex].size() == 0)
        return;
    ll sum = 0;
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            dfs(x, graph, isVisited, cost);
        }
        sum += cost[x];
    }
    cost[vertex] = min(cost[vertex], sum);
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> k;
    vector<ll> cost(n + 1, 0);
    vector<vector<ll>> graph(n + 1);
    vector<bool> isVisited(n + 1, false);
    for (i = 1; i <= n; i++)
    {
        cin >> cost[i];
    }
    for (i = 1; i <= k; i++)
    {
        cin >> a;
        cost[a] = 0;
    }
    for (i = 1; i <= n; i++)
    {
        cin >> m;
        for (j = 1; j <= m; j++)
        {
            cin >> a;
            graph[i].push_back(a);
        }
    }
    for (i = 1; i <= n; i++)
    {
        if (!isVisited[i])
        {
            dfs(i, graph, isVisited, cost);
        }
    }
    for (i = 1; i <= n; i++)
        cout << cost[i] << gap;
    cout << endl;
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