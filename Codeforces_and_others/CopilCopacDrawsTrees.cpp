#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;
const ll N = 2e5 + 8;

ll dp[N];
void dfs(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited, map<pair<ll, ll>, ll> &mp, ll parInd)
{
    isVisited[vertex] = true;
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            pair<ll, ll> p = {x, vertex};
            if (mp[p] > parInd)
            {
                dp[x] = dp[vertex];
                dfs(x, graph, isVisited, mp, mp[p]);
            }
            else
            {
                dp[x] = dp[vertex] + 1;
                dfs(x, graph, isVisited, mp, mp[p]);
            }
        }
    }
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    map<pair<ll, ll>, ll> mp;
    vector<vector<ll>> graph(n + 1);
    for (i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        mp.insert({{a, b}, i});
        mp.insert({{b, a}, i});
    }
    dp[1] = 1;
    vector<bool> isVisited(n + 1, false);
    dfs(1, graph, isVisited, mp, -1);
    ll ans = 0;
    for (i = 1; i <= n; i++)
    {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
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