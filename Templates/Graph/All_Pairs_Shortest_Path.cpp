vector<vector<int>> shortest_distance;
vector<vector<int>> graph;
void floydwarshall(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int u = 1; u <= n; u++)
        {
            for (int v = 1; v <= n; v++)
            {
                shortest_distance[u][v] = min(shortest_distance[u][v], shortest_distance[u][i] + shortest_distance[i][v]);
            }
        }
    }
}