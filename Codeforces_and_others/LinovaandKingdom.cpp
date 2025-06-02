#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

vector<ll> depth;
void dfs_depth(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited, ll deep)
{
    isVisited[vertex] = true;
    depth[vertex] = deep;
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            dfs_depth(x, graph, isVisited, deep + 1);
        }
    }
}

vector<ll> childs;
void dfs_childs(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited)
{
    isVisited[vertex] = true;
    ll cnt = 0;
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            dfs_childs(x, graph, isVisited);
            cnt += 1 + childs[x];
        }
    }
    childs[vertex] = cnt;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> k;
    vector<vector<ll>> graph(n + 1);
    depth.assign(n + 1, 0);
    childs.assign(n + 1, 0);
    for (i = 1; i <= n - 1; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<bool> isVisited(n + 1, false);
    dfs_depth(1, graph, isVisited, 0);
    isVisited.clear();
    isVisited.assign(n + 1, false);
    dfs_childs(1, graph, isVisited);
    vector<ll> ansv;
    for (i = 1; i <= n; i++)
    {
        ansv.push_back(depth[i] - childs[i]);
    }
    sort(ansv.begin(), ansv.end());
    reverse(ansv.begin(), ansv.end());
    ll ans = 0;
    for (i = 0; i < k; i++)
        ans += ansv[i];
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