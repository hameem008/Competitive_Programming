#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

vector<ll> visited_nodes;
void dfs(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited)
{
    isVisited[vertex] = true;
    visited_nodes.push_back(vertex);
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
    vector<vector<ll>> graph(n + 1);
    vector<bool> isVisited(n + 1, false);
    for (i = 0; i < m; i++)
    {
        cin >> a;
        vector<ll> dum;
        for (j = 0; j < a; j++)
        {
            cin >> b;
            dum.push_back(b);
        }
        for (j = 0; j < a - 1; j++)
        {
            graph[dum[j]].push_back(dum[j + 1]);
            graph[dum[j + 1]].push_back(dum[j]);
        }
    }
    vector<ll> ans(n + 1, 0);
    for (i = 1; i <= n; i++)
    {
        if (!isVisited[i])
        {
            dfs(i, graph, isVisited);
            for (auto x : visited_nodes)
            {
                ans[x] = visited_nodes.size();
            }
            visited_nodes.clear();
        }
    }
    for (i = 1; i <= n; i++)
        cout << ans[i] << gap;
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