#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

ll op;

vector<ll> parrents;

vector<ll> depth;
ll dfs(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVIsited, ll max_height)
{
    isVIsited[vertex] = true;
    depth[vertex] = 1;
    for (auto x : graph[vertex])
    {
        if (!isVIsited[x])
        {
            depth[vertex] = max(depth[vertex], dfs(x, graph, isVIsited, max_height) + 1);
        }
    }
    if (depth[vertex] == max_height && parrents[vertex] != 1)
    {
        op++;
        return 0;
    }
    return depth[vertex];
}

bool pf(ll height, ll k, vector<vector<ll>> &graph)
{
    depth.assign(graph.size(), 1);
    vector<bool> isVisited(graph.size(), false);
    op = 0;
    dfs(1, graph, isVisited, height);
    return op <= k;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> k;
    vector<vector<ll>> graph(n + 1);
    parrents.clear();
    parrents.assign(n + 1, 1);
    vector<ll> in;
    for (i = 2; i <= n; i++)
    {
        cin >> a;
        parrents[i] = a;
        in.push_back(a);
        graph[i].push_back(a);
        graph[a].push_back(i);
    }
    ll ans;
    ll hi = n, lo = 1, mid;
    while (hi - lo > 1)
    {
        mid = (hi + lo) / 2;
        if (pf(mid, k, graph))
            hi = mid;
        else
            lo = mid + 1;
    }
    if (pf(lo, k, graph))
        ans = lo;
    else
        ans = hi;
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