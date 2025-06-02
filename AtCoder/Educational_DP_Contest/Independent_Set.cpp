#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;
const ll mod = 1e9 + 7;
vector<vector<ll>> dp;

ll dfs(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited, ll color)
{
    isVisited[vertex] = true;
    if (dp[color][vertex] == -1)
    {
        ll ans = 1;
        if (color == 0)
        {
            for (auto x : graph[vertex])
            {
                if (!isVisited[x])
                {
                    ll sum = (dfs(x, graph, isVisited, 0) + dfs(x, graph, isVisited, 1)) % mod;
                    ans *= sum;
                    ans %= mod;
                }
            }
        }
        else if (color == 1)
        {
            for (auto x : graph[vertex])
            {
                if (!isVisited[x])
                {
                    ll sum = dfs(x, graph, isVisited, 0);
                    ans *= sum;
                    ans %= mod;
                }
            }
        }
        isVisited[vertex] = false;
        dp[color][vertex] = ans;
    }
    return dp[color][vertex];
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<vector<ll>> graph(n + 1);
    for (i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dp.assign(2, vector<ll>(n + 1, -1));
    vector<bool> isVisited(n + 1, false);
    cout << (dfs(1, graph, isVisited, 0) + dfs(1, graph, isVisited, 1)) % mod << endl;
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