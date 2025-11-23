#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

int n, k, k_1, k_2;

template <class T>
class fenwick_tree
{
private:
    int N;
    vector<T> bit;
    T sum(int r)
    {
        T ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

public:
    fenwick_tree() {}
    fenwick_tree(vector<T> &a) { build(a); }
    void build(vector<T> &a)
    {
        N = a.size();
        bit.assign(N, 0);
        for (int i = 0; i < a.size(); i++)
            add(i, a[i]);
    }
    T sum(int l, int r)
    {
        return sum(r) - sum(l - 1);
    }
    void add(int pos, int add_val)
    {
        for (; pos < N; pos = pos | (pos + 1))
            bit[pos] += add_val;
    }
};

int node_cnt, centroid;
vector<pair<int, int>> max_and_total_count;

void dfs(int vertex, vector<vector<int>> &graph, vector<char> &isVisited)
{
    max_and_total_count[vertex] = {0, 1};
    isVisited[vertex] = 1;
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            dfs(x, graph, isVisited);
            max_and_total_count[vertex].second += max_and_total_count[x].second;
            max_and_total_count[vertex].first = max(max_and_total_count[vertex].first, max_and_total_count[x].second);
        }
    }
    isVisited[vertex] = 0;
    ll val = max(max_and_total_count[vertex].first, node_cnt - max_and_total_count[vertex].second);
    if (val <= node_cnt / 2)
        centroid = vertex;
}

int find_a_centroid(vector<vector<int>> &graph, vector<char> &isVisited, int root)
{
    centroid = root;
    dfs(root, graph, isVisited);
    return centroid;
}

vector<int> depths;
vector<ll> depth_freq;
fenwick_tree<ll> seg_depth_freq;
void d_dfs(int vertex, vector<vector<int>> &graph, vector<char> &isVisited, int depth)
{
    isVisited[vertex] = 1;
    depths.push_back(depth);
    seg_depth_freq.add(depth, 1);
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            d_dfs(x, graph, isVisited, depth + 1);
        }
    }
    isVisited[vertex] = 0;
}

ll decomposition(vector<vector<int>> &graph, vector<char> &isVisited, int centroid)
{
    ll cnt = 0;
    vector<vector<int>> v_depths;
    isVisited[centroid] = true;
    seg_depth_freq.add(0, 1);
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
            seg_depth_freq.add(y, -1);
        for (auto y : x)
            if (k_2 - y >= 0)
                cnt += seg_depth_freq.sum(max(0, k_1 - y), k_2 - y);
    }
    v_depths.clear();
    seg_depth_freq.add(0, -1);
    for (auto x : graph[centroid])
    {
        if (!isVisited[x])
        {
            node_cnt = max_and_total_count[x].second;
            cnt += decomposition(graph, isVisited, find_a_centroid(graph, isVisited, x));
        }
    }
    return cnt;
}

void solve(int I, int T)
{
    ll i, j, a, b, c, d, m, p, q;
    bool flag;
    // solve starts
    cin >> n >> k_1 >> k_2;
    vector<vector<int>> graph(n + 1);
    max_and_total_count.assign(n + 1, {0, 1});
    depth_freq.assign(n + 1, 0);
    seg_depth_freq.build(depth_freq);
    for (i = 1; i < n; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<char> isVisited(n + 1, 0);
    node_cnt = n;
    cout << decomposition(graph, isVisited, find_a_centroid(graph, isVisited, 1)) << endl;
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cout.tie(NULL);

    int T = 1;
    // cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}