#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;
const ll N = 2e5 + 8;

bool isPossible;
vector<ll> cuts;
ll dp[N];
void dfs(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited, map<pair<ll, ll>, ll> &egdeIndex)
{
    isVisited[vertex] = true;
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            dfs(x, graph, isVisited, egdeIndex);
            if (dp[x] == 3)
            {
                pair<ll, ll> p = {vertex, x};
                cuts.push_back(egdeIndex[p]);
            }
            else if (dp[vertex] + dp[x] > 3)
                isPossible = false;
            else
                dp[vertex] += dp[x];
        }
    }
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    isPossible = true;
    cuts.clear();
    cin >> n;
    vector<vector<ll>> graph(n + 1);
    vector<bool> isVisited(n + 1, false);
    map<pair<ll, ll>, ll> edgeIndex;
    for (i = 1; i <= n - 1; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        edgeIndex.insert({{a, b}, i});
        edgeIndex.insert({{b, a}, i});
    }
    for (i = 1; i <= n; i++)
        dp[i] = 1;
    dfs(1, graph, isVisited, edgeIndex);
    if (dp[1] != 3)
        isPossible = false;
    if (isPossible)
    {
        cout << cuts.size() << endl;
        for (auto x : cuts)
            cout << x << gap;
        cout << endl;
    }
    else
        cout << -1 << endl;
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