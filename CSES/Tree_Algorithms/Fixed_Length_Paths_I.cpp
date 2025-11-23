#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

ll n, k;

vector<pair<ll, ll>> max_and_total_count;
vector<ll> visited_nodes;

void dfs(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited)
{
    max_and_total_count[vertex] = {0, 1};
    isVisited[vertex] = true;
    visited_nodes.push_back(vertex);
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            dfs(x, graph, isVisited);
            max_and_total_count[vertex].second += max_and_total_count[x].second;
            max_and_total_count[vertex].first = max(max_and_total_count[vertex].first, max_and_total_count[x].second);
        }
    }
    isVisited[vertex] = false;
}

ll find_a_centroid(vector<vector<ll>> &graph, vector<bool> &isVisited, ll root)
{
    dfs(root, graph, isVisited);
    ll n = visited_nodes.size();
    for (auto x : visited_nodes)
    {
        ll val = max(max_and_total_count[x].first, n - max_and_total_count[x].second);
        if (val <= n / 2)
            root = x;
    }
    visited_nodes.clear();
    return root;
}

vector<ll> depths;
vector<ll> depth_freq;
void d_dfs(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited, ll depth)
{
    isVisited[vertex] = true;
    depths.push_back(depth);
    depth_freq[depth]++;
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            d_dfs(x, graph, isVisited, depth + 1);
        }
    }
    isVisited[vertex] = false;
}

ll decomposition(vector<vector<ll>> &graph, vector<bool> &isVisited, ll centroid)
{
    ll cnt = 0;
    vector<vector<ll>> v_depths;
    isVisited[centroid] = true;
    depth_freq[0]++;
    for (auto x : graph[centroid])
    {
        if (!isVisited[x])
        {
            d_dfs(x, graph, isVisited, 1);
            v_depths.push_back(depths);
            depths.clear();
        }
    }
    for (auto x : v_depths)
    {
        for (auto y : x)
            depth_freq[y]--;
        for (auto y : x)
            if (k - y >= 0)
                cnt += depth_freq[k - y];
    }
    v_depths.clear();
    depth_freq[0]--;
    for (auto x : graph[centroid])
    {
        if (!isVisited[x])
            cnt += decomposition(graph, isVisited, find_a_centroid(graph, isVisited, x));
    }
    return cnt;
}

void solve(int I, int T)
{
    ll i, j, a, b, c, d, m, p, q;
    bool flag;
    // solve starts
    cin >> n >> k;
    vector<vector<ll>> graph(n + 1);
    max_and_total_count.assign(n + 1, {0, 1});
    depth_freq.assign(n + 1, 0);
    for (i = 1; i < n; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<bool> isVisited(n + 1, false);
    cout << decomposition(graph, isVisited, find_a_centroid(graph, isVisited, 1)) << endl;
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