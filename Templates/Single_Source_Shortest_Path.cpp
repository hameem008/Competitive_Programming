vector<int> parrents_dijkstra;
vector<int> distance_dijkstra;
void dijkstra(vector<vector<pair<int, int>>> &graph, int source)
{
    int n = graph.size();
    parrents_dijkstra.clear();
    distance_dijkstra.clear();
    parrents_dijkstra.assign(n, -1);
    distance_dijkstra.assign(n, 99999999);
    distance_dijkstra[source] = 0;
    parrents_dijkstra[source] = source;
    vector<bool> isDone(n, false);
    int cost;
    set<pair<int, int>> pq;
    pq.insert({distance_dijkstra[source], source});
    while (pq.size())
    {
        pair<int, int> p = *pq.begin();
        pq.erase(pq.begin());
        cost = p.first;
        if (isDone[p.second])
            continue;
        isDone[p.second] = true;
        for (auto x : graph[p.second])
        {
            if (cost + x.second < distance_dijkstra[x.first])
            {
                distance_dijkstra[x.first] = cost + x.second;
                parrents_dijkstra[x.first] = p.second;
                pq.insert({distance_dijkstra[x.first], x.first});
            }
        }
    }
}
vector<int> shortest_path_dijkstra(int source, int destination)
{
    vector<int> path;
    int node = destination;
    while (node != source)
    {
        path.push_back(node);
        node = parrents_dijkstra[node];
    }
    path.push_back(source);
    reverse(path.begin(), path.end());
    return path;
}

bool isCyclePresent = false;
vector<int> parrents_bellman_ford;
vector<int> distance_bellman_ford;
void bellman_ford(vector<pair<pair<int, int>, int>> &edge_list, int source, int n)
{
    parrents_bellman_ford.clear();
    distance_bellman_ford.clear();
    parrents_bellman_ford.assign(n + 1, -1);
    distance_bellman_ford.assign(n + 1, 99999999);
    parrents_bellman_ford[source] = source;
    distance_bellman_ford[source] = 0;
    int limit = n - 1;
    while (limit--)
    {
        for (auto x : edge_list)
        {
            if (distance_bellman_ford[x.first.first] + x.second < distance_bellman_ford[x.first.second])
            {
                distance_bellman_ford[x.first.second] = distance_bellman_ford[x.first.first] + x.second;
                parrents_bellman_ford[x.first.second] = x.first.first;
            }
        }
    }
    vector<int> check = distance_bellman_ford;
    for (auto x : edge_list)
    {
        if (distance_bellman_ford[x.first.first] + x.second < distance_bellman_ford[x.first.second])
        {
            distance_bellman_ford[x.first.second] = distance_bellman_ford[x.first.first] + x.second;
            parrents_bellman_ford[x.first.second] = x.first.first;
        }
    }
    if (check != distance_bellman_ford)
        isCyclePresent = true;
}
vector<int> shortest_path_bellman_ford(int source, int destination)
{
    vector<int> path;
    int node = destination;
    while (node != source)
    {
        path.push_back(node);
        node = parrents_bellman_ford[node];
    }
    path.push_back(source);
    reverse(path.begin(), path.end());
    return path;
}