#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;
const ll N = 1e5 + 8;
ll dp[N];

ll rec(ll vertex, vector<vector<ll>> &graph)
{
    if (graph[vertex].size() == 0)
    {
        return dp[vertex] = 0;
    }
    if (dp[vertex] == -1)
    {
        ll max_path = 0;
        for (auto x : graph[vertex])
        {
            max_path = max(max_path, rec(x, graph));
        }
        dp[vertex] = max_path + 1;
    }
    return dp[vertex];
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> m;
    vector<vector<ll>> graph(n + 1);
    for (i = 1; i <= m; i++)
    {
        cin >> a >> b;
        graph[b].push_back(a);
    }
    for (i = 1; i <= n; i++)
    {
        dp[i] = -1;
    }
    ll ans = 0;
    for (i = 1; i <= n; i++)
    {
        rec(i, graph);
    }
    for (i = 1; i <= n; i++)
        ans = max(ans, dp[i]);
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