ll time_ = 0;
vector<ll> start_t, end_t;
void scc_dfs(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited)
{
    isVisited[vertex] = true;
    time_++;
    start_t[vertex] = time_;
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            scc_dfs(x, graph, isVisited);
        }
    }
    time_++;
    end_t[vertex] = time_;
}
vector<ll> nodes;
void scc_dfs_2(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited)
{
    isVisited[vertex] = true;
    nodes.push_back(vertex);
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            scc_dfs_2(x, graph, isVisited);
        }
    }
}
vector<vector<ll>> all_scc;
vector<ll> map_scc_index;
void strongly_connnected_components(ll n, vector<pair<ll, ll>> &edge_list)
{
    ll i;
    start_t.assign(n + 1, 0);
    end_t.assign(n + 1, 0);
    map_scc_index.assign(n + 1, 0);
    vector<vector<ll>> graph(n + 1), graph_t(n + 1);
    for (auto x : edge_list)
    {
        graph[x.first].push_back(x.second);
        graph_t[x.second].push_back(x.first);
    }
    vector<bool> isVisited(n + 1, false);
    for (i = 1; i <= n; i++)
    {
        if (!isVisited[i])
        {
            scc_dfs(i, graph, isVisited);
        }
    }
    isVisited.assign(n + 1, false);
    vector<pair<ll, ll>> vp;
    for (i = 1; i <= n; i++)
    {
        vp.push_back({end_t[i], i});
    }
    sort(vp.begin(), vp.end());
    reverse(vp.begin(), vp.end());
    all_scc.push_back(vector<ll>(0));
    i = 1;
    for (auto x : vp)
    {
        if (!isVisited[x.second])
        {
            nodes.clear();
            scc_dfs_2(x.second, graph_t, isVisited);
            all_scc.push_back(nodes);
            for (auto y : nodes)
            {
                map_scc_index[y] = i;
            }
            i++;
        }
    }
}