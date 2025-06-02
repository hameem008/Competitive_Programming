#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;
const ll N = 1e5 + 8;

ll dp[2][N];
void dfs(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited, vector<pair<ll, ll>> &vp)
{
    isVisited[vertex] = true;
    dp[0][vertex] = dp[1][vertex] = 0;
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            dfs(x, graph, isVisited, vp);
            dp[0][vertex] += max(dp[0][x] + abs(vp[vertex].first - vp[x].first), dp[1][x] + abs(vp[vertex].first - vp[x].second));
            dp[1][vertex] += max(dp[0][x] + abs(vp[vertex].second - vp[x].first), dp[1][x] + abs(vp[vertex].second - vp[x].second));
        }
    }
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<pair<ll, ll>> vp(n + 1);
    for (i = 1; i <= n; i++)
    {
        cin >> vp[i].first >> vp[i].second;
        dp[0][i] = dp[1][i] = -1;
    }
    vector<vector<ll>> graph(n + 1);
    for (i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<bool> isVisited(n + 1, false);
    dfs(1, graph, isVisited, vp);
    cout << max(dp[0][1], dp[1][1]) << endl;
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