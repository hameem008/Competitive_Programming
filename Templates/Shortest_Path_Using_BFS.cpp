vector<ll> Parents;
vector<ll> Distance;
ll Source;
void bfs(ll source, vector<vector<ll>> &graph, vector<bool> &isVisited)
{
    Parents.clear();
    Distance.clear();
    Parents.assign(isVisited.size(), 0);
    Distance.assign(isVisited.size(), 0);
    Source = source;
    queue<ll> q;
    isVisited[source] = true;
    q.push(source);
    while (q.size())
    {
        ll vertex = q.front();
        q.pop();
        for (auto x : graph[vertex])
        {
            if (!isVisited[x])
            {
                q.push(x);
                isVisited[x] = true;
                Parents[x] = vertex;
                Distance[x] = Distance[vertex] + 1;
            }
        }
    }
}

vector<ll> shortest_path(ll destination)
{
    ll source = Source;
    vector<ll> path;
    ll node = destination;
    while (node != source)
    {
        path.push_back(node);
        node = Parents[node];
    }
    path.push_back(source);
    reverse(path.begin(), path.end());
    return path;
}