#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

void bridgedfs(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited, vector<ll> &start, vector<ll> &low, vector<ll> &parrents, ll &timer, vector<pair<ll, ll>> &ret)
{
    isVisited[vertex] = true;
    start[vertex] = timer++;
    low[vertex] = start[vertex];
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            parrents[x] = vertex;
            bridgedfs(x, graph, isVisited, start, low, parrents, timer, ret);
        }
        if (parrents[vertex] != x)
            low[vertex] = min(low[vertex], low[x]);
    }
    if (low[vertex] > start[parrents[vertex]] && vertex > 1)
    {
        ret.push_back({min(vertex, parrents[vertex]), max(vertex, parrents[vertex])});
    }
}
vector<pair<ll, ll>> bridges(vector<vector<ll>> &graph)
{
    ll n = graph.size() - 1, timer = 1;
    vector<ll> start(n + 1, 0), low(n + 1);
    vector<ll> parrents(n + 1, 0);
    vector<bool> isVisited(n + 1, false);
    vector<pair<ll, ll>> ret;
    bridgedfs(1, graph, isVisited, start, low, parrents, timer, ret);
    return ret;
}

vector<ll> nodes;
void dfs(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited)
{
    isVisited[vertex] = true;
    nodes.push_back(vertex);
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            dfs(x, graph, isVisited);
        }
    }
}

ll ans, N;
void dfs2(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited, vector<ll> &cnt, vector<ll> &amtNodes)
{
    isVisited[vertex] = true;
    cnt[vertex] = amtNodes[vertex];
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            dfs2(x, graph, isVisited, cnt, amtNodes);
            cnt[vertex] += cnt[x];
        }
    }
    ll a = cnt[vertex], b = N - cnt[vertex];
    ans = min(ans, (a * a - a) / 2 + (b * b - b) / 2);
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    ans = infinite;
    // solve starts
    cin >> n >> m;
    N = n;
    vector<vector<ll>> graph(n + 1);
    set<pair<ll, ll>> edges;
    for (i = 1; i <= m; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        edges.insert({min(a, b), max(a, b)});
    }
    vector<pair<ll, ll>> brdg = bridges(graph);
    for (auto x : brdg)
    {
        edges.erase(x);
    }
    if (edges.size() == m)
    {
        cout << (n * n - n) / 2 << endl;
        return;
    }
    vector<vector<ll>> graph2(n + 1);
    for (auto x : edges)
    {
        graph2[x.first].push_back(x.second);
        graph2[x.second].push_back(x.first);
    }
    vector<ll> cycleNum(n + 1, 0);
    ll cycleCnt = 0;
    vector<bool> isVisited(n + 1, false);
    for (i = 1; i <= n; i++)
    {
        if (!isVisited[i])
        {
            nodes.clear();
            dfs(i, graph2, isVisited);
            cycleCnt++;
            for (auto x : nodes)
            {
                cycleNum[x] = cycleCnt;
            }
        }
    }
    vector<ll> amtNodes(cycleCnt + 1, 0);
    for (i = 1; i <= n; i++)
    {
        amtNodes[cycleNum[i]]++;
    }
    vector<vector<ll>> graph3(cycleCnt + 1);
    for (auto x : brdg)
    {
        a = cycleNum[x.first];
        b = cycleNum[x.second];
        graph3[a].push_back(b);
        graph3[b].push_back(a);
    }
    vector<ll> cnt(cycleCnt + 1);
    isVisited.clear();
    isVisited.assign(cycleCnt + 1, false);
    dfs2(1, graph3, isVisited, cnt, amtNodes);
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