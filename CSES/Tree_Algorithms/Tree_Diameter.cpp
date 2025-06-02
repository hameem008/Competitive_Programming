#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

vector<ll> dp;
ll ans = 0;

void dfs(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited)
{
    isVisited[vertex] = true;
    vector<ll> v;
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            dfs(x, graph, isVisited);
            dp[vertex] = max(dp[vertex], dp[x] + 1);
            v.push_back(dp[x]);
        }
    }
    sort(v.begin(), v.end());
    if (v.size() == 1)
    {
        ans = max(ans, dp[vertex]);
    }
    else if (v.size() > 1)
    {
        ans = max(ans, 2 + v[v.size() - 1] + v[v.size() - 2]);
    }
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    dp.assign(n + 1, 0);
    vector<vector<ll>> graph(n + 1);
    for (i = 1; i <= n - 1; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<bool> isVisited(n + 1, false);
    dfs(1, graph, isVisited);
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