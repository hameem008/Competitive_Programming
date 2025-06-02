#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

vector<ll> dp;
void dfs(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited)
{
    isVisited[vertex] = true;
    ll max_ver = -infinite;
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            dfs(x, graph, isVisited);
        }
        max_ver = max(max_ver, dp[x]);
    }
    dp[vertex] = max_ver + 1;
}

void check(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited)
{
    isVisited[vertex] = true;
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            check(x, graph, isVisited);
        }
    }
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> m;
    dp.assign(n + 1, 0);
    dp[1] = 1;
    vector<vector<ll>> graph(n + 1);
    vector<bool> isVisited(n + 1, false);
    for (i = 1; i <= m; i++)
    {
        cin >> a >> b;
        graph[b].push_back(a);
    }
    check(n, graph, isVisited);
    if (!isVisited[1])
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    isVisited.assign(n + 1, false);
    isVisited[1] = true;
    dfs(n, graph, isVisited);
    vector<ll> path;
    ll vertex = n;
    while (1)
    {
        path.push_back(vertex);
        if (vertex == 1)
            break;
        for (auto x : graph[vertex])
        {
            if (dp[vertex] - 1 == dp[x])
            {
                vertex = x;
                break;
            }
        }
    }
    reverse(path.begin(), path.end());
    cout << path.size() << endl;
    for (auto x : path)
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