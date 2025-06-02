#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

vector<ll> dp;
void dfs(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited)
{
    isVisited[vertex] = true;
    dp[vertex] = 1;
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            dfs(x, graph, isVisited);
            dp[vertex] += dp[x];
        }
    }
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    dp.clear();
    cin >> n;
    dp.assign(n + 1, 0);
    vector<vector<ll>> graph(n + 1);
    for (i = 2; i <= n; i++)
    {
        cin >> a;
        graph[i].push_back(a);
        graph[a].push_back(i);
    }
    vector<bool> isVIsited(n + 1, false);
    dfs(1, graph, isVIsited);
    for (i = 1; i <= n; i++)
    {
        cout << dp[i] - 1 << gap;
    }
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