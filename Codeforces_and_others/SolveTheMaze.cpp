#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

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
            // if (i > 1 && j > 1)
            // {
            //     graph[grid_to_arr[i][j]].push_back(grid_to_arr[i - 1][j - 1]);
            // }
            // if (i < n && j > 1)
            // {
            //     graph[grid_to_arr[i][j]].push_back(grid_to_arr[i + 1][j - 1]);
            // }
            // if (i < n && j < n)
            // {
            //     graph[grid_to_arr[i][j]].push_back(grid_to_arr[i + 1][j + 1]);
            // }
            // if (i > 1 && j < n)
            // {
            //     graph[grid_to_arr[i][j]].push_back(grid_to_arr[i - 1][j + 1]);
            // }
        }
    }
    return graph;
}

void dfs(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited, vector<char> &maze)
{
    isVisited[vertex] = true;
    if (maze[vertex] == '.')
    {
        maze[vertex] = '#';
        return;
    }
    else if (maze[vertex] == 'G' || maze[vertex] == '#')
        return;
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            dfs(x, graph, isVisited, maze);
        }
    }
}

void bfs(ll source, vector<vector<ll>> &graph, vector<bool> &isVisited, vector<char> &maze)
{
    queue<ll> q;
    if (maze[source] == '#')
        return;
    isVisited[source] = true;
    q.push(source);
    while (q.size())
    {
        ll vertex = q.front();
        q.pop();
        for (auto x : graph[vertex])
        {
            if (!isVisited[x] && maze[x] != '#')
            {
                q.push(x);
                isVisited[x] = true;
            }
        }
    }
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> m;
    char grid[n + 1][m + 1];
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            cin >> grid[i][j];
        }
    }
    vector<vector<ll>> graph = grid_mapped_arr(n, m);
    vector<bool> isVisited(graph.size(), false);
    vector<char> maze(graph.size());
    for (i = 1; i < graph.size(); i++)
    {
        maze[i] = grid[arr_to_grid[i].first][arr_to_grid[i].second];
    }
    for (i = 1; i < graph.size(); i++)
    {
        if (maze[i] == 'B')
        {
            dfs(i, graph, isVisited, maze);
        }
    }
    flag = true;
    isVisited.clear();
    isVisited.assign(graph.size(), false);
    bfs(grid_to_arr[n][m], graph, isVisited, maze);
    for (i = 1; i < graph.size(); i++)
    {
        if ((maze[i] == 'B' && isVisited[i]) || (maze[i] == 'G' && !isVisited[i]))
            flag = false;
    }
    flag ? cout << "Yes" << endl : cout << "No" << endl;
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