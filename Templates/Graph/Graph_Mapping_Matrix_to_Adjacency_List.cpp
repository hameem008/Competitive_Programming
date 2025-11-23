vector<vector<ll>> grid_to_arr;
vector<pair<ll, ll>> arr_to_grid;
vector<vector<ll>> grid_mapped_arr(ll n, ll m)
{
    grid_to_arr.assign(n + 1, vector<ll>(m + 1, 0));
    arr_to_grid.assign((n + 1) * (m + 1), {0, 0});
    ll k = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            grid_to_arr[i][j] = k;
            arr_to_grid[k] = {i, j};
            k++;
        }
    }
    vector<vector<ll>> graph(k);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // adjacent
            if (i > 1)
            {
                graph[grid_to_arr[i][j]].push_back(grid_to_arr[i - 1][j]);
            }
            if (j > 1)
            {
                graph[grid_to_arr[i][j]].push_back(grid_to_arr[i][j - 1]);
            }
            if (i < n)
            {
                graph[grid_to_arr[i][j]].push_back(grid_to_arr[i + 1][j]);
            }
            if (j < m)
            {
                graph[grid_to_arr[i][j]].push_back(grid_to_arr[i][j + 1]);
            }
            
            // diagonal
            if (i > 1 && j > 1)
            {
                graph[grid_to_arr[i][j]].push_back(grid_to_arr[i - 1][j - 1]);
            }
            if (i < n && j > 1)
            {
                graph[grid_to_arr[i][j]].push_back(grid_to_arr[i + 1][j - 1]);
            }
            if (i < n && j < n)
            {
                graph[grid_to_arr[i][j]].push_back(grid_to_arr[i + 1][j + 1]);
            }
            if (i > 1 && j < n)
            {
                graph[grid_to_arr[i][j]].push_back(grid_to_arr[i - 1][j + 1]);
            }
        }
    }
    return graph;
}