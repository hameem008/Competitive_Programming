#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

vector<ll> cnt;
void dfs_1(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited)
{
    isVisited[vertex] = true;
    cnt[vertex] = 1;
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            dfs_1(x, graph, isVisited);
            cnt[vertex] += cnt[x];
        }
    }
}

vector<ll> dp;
void dfs_2(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited)
{
    isVisited[vertex] = true;
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            dfs_2(x, graph, isVisited);
            dp[vertex] += cnt[x] + dp[x];
        }
    }
}

vector<ll> ans;
ll total_node_cnt;
void dfs_3(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited, ll parrent)
{
    isVisited[vertex] = true;
    if (parrent != 0)
    {
        ans[vertex] = ans[parrent] - cnt[vertex] + (total_node_cnt - cnt[vertex]);
    }
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            dfs_3(x, graph, isVisited, vertex);
        }
    }
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    cnt.assign(n + 1, 0);
    dp.assign(n + 1, 0);
    total_node_cnt = n;
    ans.assign(n + 1, 0);
    vector<vector<ll>> graph(n + 1);
    for (i = 1; i <= n - 1; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<bool> isVisited(n + 1, false);
    dfs_1(1, graph, isVisited);
    isVisited.assign(n + 1, false);
    dfs_2(1, graph, isVisited);
    isVisited.assign(n + 1, false);
    ans[1] = dp[1];
    dfs_3(1, graph, isVisited, 0);
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
    //  cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}