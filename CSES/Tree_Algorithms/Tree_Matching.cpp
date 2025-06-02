#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

vector<vector<ll>> dp;
void dfs(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited, ll parrent)
{
    isVisited[vertex] = true;
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            dfs(x, graph, isVisited, vertex);
            dp[0][vertex] += max(dp[0][x], dp[1][x]);
        }
    }
    for (auto x : graph[vertex])
    {
        if (x != parrent)
            dp[1][vertex] = max(dp[1][vertex], 1 + dp[0][vertex] - max(dp[0][x], dp[1][x]) + dp[0][x]);
    }
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<ll> v(n + 1, 0);
    dp.push_back(v);
    dp.push_back(v);
    vector<vector<ll>> graph(n + 1);
    for (i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<bool> isVIsited(n + 1, false);
    dfs(1, graph, isVIsited, 0);
    cout << max(dp[0][1], dp[1][1]) << endl;
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