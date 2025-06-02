#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;
 
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
 
vector<ll> Parents;
vector<ll> Distance;
ll Source;
void bfs(ll source, vector<vector<ll>> &graph, vector<bool> &isVisited, vector<char> vchar)
{
    Parents.clear();
    Distance.clear();
    Parents.assign(isVisited.size(), 0);
    Distance.assign(isVisited.size(), infinite);
    Source = source;
    queue<ll> q;
    isVisited[source] = true;
    q.push(source);
    Distance[source] = 0;
    while (q.size())
    {
        ll vertex = q.front();
        q.pop();
        for (auto x : graph[vertex])
        {
            if (!isVisited[x])
            {
                if (vchar[x] == '#')
                {
                    Distance[x] = infinite;
                    isVisited[x] = true;
                }
                else
                {
                    q.push(x);
                    isVisited[x] = true;
                    Parents[x] = vertex;
                    Distance[x] = Distance[vertex] + 1;
                }
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
 
vector<ll> multi_Distance;
void multi_bfs(vector<ll> source, vector<vector<ll>> &graph, vector<bool> &isVisited, vector<char> vchar)
{
    multi_Distance.assign(isVisited.size(), infinite);
    queue<ll> q;
    for (auto x : source)
    {
        isVisited[x] = true;
        q.push(x);
        multi_Distance[x] = 0;
    }
    while (q.size())
    {
        ll vertex = q.front();
        q.pop();
        for (auto x : graph[vertex])
        {
            if (!isVisited[x])
            {
                if (vchar[x] == '#')
                {
                    multi_Distance[x] = infinite;
                    isVisited[x] = true;
                }
                else
                {
                    q.push(x);
                    isVisited[x] = true;
                    multi_Distance[x] = 1 + multi_Distance[vertex];
                }
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
    vector<vector<ll>> graph = grid_mapped_arr(n, m);
    vector<char> vchar(graph.size());
    char grid[n + 1][m + 1];
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            cin >> grid[i][j];
            vchar[grid_to_arr[i][j]] = grid[i][j];
        }
    }
    vector<ll> sources;
    ll src;
    for (i = 1; i < graph.size(); i++)
    {
        if (vchar[i] == 'M')
            sources.push_back(i);
        if (vchar[i] == 'A')
            src = i;
    }
    vector<bool> isVisited(graph.size(), false);
    multi_bfs(sources, graph, isVisited, vchar);
    isVisited.clear();
    isVisited.assign(graph.size(), false);
    bfs(src, graph, isVisited, vchar);
    ll ans_sq = 0;
    for (i = 1; i < graph.size(); i++)
    {
        if (graph[i].size() < 4 && Distance[i] < multi_Distance[i])
        {
            ans_sq = i;
            break;
        }
    }
    if (ans_sq == 0)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        vector<pair<ll, ll>> path;
        for (auto x : shortest_path(ans_sq))
        {
            path.push_back(arr_to_grid[x]);
        }
        cout << path.size() - 1 << endl;
        string ans;
        for (i = 0; i < path.size() - 1; i++)
        {
            if (path[i].first == path[i + 1].first)
            {
                if (path[i].second < path[i + 1].second)
                {
                    ans.push_back('R');
                }
                else if (path[i].second > path[i + 1].second)
                {
                    ans.push_back('L');
                }
            }
            else if (path[i].second == path[i + 1].second)
            {
                if (path[i].first < path[i + 1].first)
                {
                    ans.push_back('D');
                }
                else if (path[i].first > path[i + 1].first)
                {
                    ans.push_back('U');
                }
            }
        }
        cout << ans << endl;
    }
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