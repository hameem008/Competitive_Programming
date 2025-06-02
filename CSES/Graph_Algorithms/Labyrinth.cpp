#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

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

vector<vector<ll>> grid_to_arr;
vector<pair<ll, ll>> arr_to_grid;
vector<vector<ll>> grid_mapping(ll n, ll m)
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

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> m;
    k = 1;
    ll src, dst;
    char grid[n + 1][m + 1];
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            cin >> grid[i][j];
        }
    }
    vector<vector<ll>> graph = grid_mapping(n, m);
    vector<bool> isVisited(graph.size() + 1, false);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            if (grid[i][j] == '#')
            {
                isVisited[grid_to_arr[i][j]] = true;
            }
            if (grid[i][j] == 'A')
            {
                src = grid_to_arr[i][j];
            }
            if (grid[i][j] == 'B')
            {
                dst = grid_to_arr[i][j];
            }
        }
    }
    bfs(src, graph, isVisited);
    if (!isVisited[dst])
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    vector<pair<ll, ll>> path;
    for (auto x : shortest_path(dst))
    {
        path.push_back(arr_to_grid[x]);
    }
    string ans;
    for (i = 0; i < path.size() - 1; i++)
    {
        if (path[i].first == path[i + 1].first)
        {
            if (path[i].second > path[i + 1].second)
            {
                ans.push_back('L');
            }
            else if (path[i].second < path[i + 1].second)
            {
                ans.push_back('R');
            }
        }
        else if (path[i].second == path[i + 1].second)
        {
            if (path[i].first > path[i + 1].first)
            {
                ans.push_back('U');
            }
            else if (path[i].first < path[i + 1].first)
            {
                ans.push_back('D');
            }
        }
    }
    cout << ans.size() << endl;
    cout << ans << endl;
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