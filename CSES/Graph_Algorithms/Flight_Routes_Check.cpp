#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

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

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> m;
    vector<vector<ll>> graph(n + 1), rev_graph(n + 1);
    for (i = 1; i <= m; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        rev_graph[b].push_back(a);
    }
    vector<bool> isVisited(n + 1, false);
    dfs(1, graph, isVisited);
    for (i = 1; i <= n; i++)
    {
        if (!isVisited[i])
        {
            cout << "NO" << endl;
            cout << 1 << gap << i << endl;
            return;
        }
    }
    isVisited.assign(n + 1, false);
    dfs(1, rev_graph, isVisited);
    for (i = 1; i <= n; i++)
    {
        if (!isVisited[i])
        {
            cout << "NO" << endl;
            cout << i << gap << 1 << endl;
            return;
        }
    }
    cout << "YES" << endl;
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