int edmondsKarp(vector<vector<int>> &graph, int source, int sink, vector<vector<int>> &edge_capacity)
{
    int n = graph.size();
    int max_flow = 0;
    while (1)
    {
        vector<bool> isVisited(n, false);
        vector<int> parrents(n, 0);
        queue<int> q;
        isVisited[source] = true;
        parrents[source] = source;
        q.push(source);
        while (q.size())
        {
            int vertex = q.front();
            q.pop();
            for (auto x : graph[vertex])
            {
                if (edge_capacity[vertex][x] > 0 && !isVisited[x])
                {
                    q.push(x);
                    isVisited[x] = true;
                    parrents[x] = vertex;
                }
            }
        }
        if (parrents[sink] == 0)
            break;
        vector<int> path;
        int node = sink;
        while (node != source)
        {
            path.push_back(node);
            node = parrents[node];
        }
        path.push_back(source);
        reverse(path.begin(), path.end());
        int bottle_neck = INT32_MAX;
        for (int i = 0; i < path.size() - 1; i++)
        {
            bottle_neck = min(bottle_neck, edge_capacity[path[i]][path[i + 1]]);
        }
        for (int i = 0; i < path.size() - 1; i++)
        {
            edge_capacity[path[i]][path[i + 1]] -= bottle_neck;
            edge_capacity[path[i + 1]][path[i]] += bottle_neck;
        }
        max_flow += bottle_neck;
    }
    return max_flow;
}