#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

void dfs(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVIsited)
{
    isVIsited[vertex] = true;
    for (auto x : graph[vertex])
    {
        if (!isVIsited[x])
        {
            dfs(x, graph, isVIsited);
        }
    }
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, x, y, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> x >> y;
    m = n - 1;
    ll ans = 0;
    vector<ll> dum;
    vector<vector<ll>> graph(n + 1, dum);
    vector<bool> isVisited(n + 1, false);
    for (i = 0; i < m; i++)
    {
        cin >> p >> q;
        graph[p].push_back(q);
        graph[q].push_back(p);
    }
    isVisited[y] = true;
    dfs(x, graph, isVisited);
    ll cnty = 1, cntx = 1;
    for (i = 1; i <= n; i++)
    {
        if (!isVisited[i])
            cnty++;
    }
    isVisited.clear();
    isVisited.assign(n + 1, false);
    isVisited[x] = true;
    dfs(y, graph, isVisited);
    for (i = 1; i <= n; i++)
    {
        if (!isVisited[i])
            cntx++;
    }
    cout << n * (n - 1) - cntx * cnty << endl;
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