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