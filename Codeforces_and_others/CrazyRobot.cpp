#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

vector<vector<char>> v;
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
            if (v[i][j] == '#')
                continue;

            if (i > 1 && v[i - 1][j] != '#')
            {
                graph[grid_to_arr[i][j]].push_back(grid_to_arr[i - 1][j]);
            }
            if (j > 1 && v[i][j - 1] != '#')
            {
                graph[grid_to_arr[i][j]].push_back(grid_to_arr[i][j - 1]);
            }
            if (i < n && v[i + 1][j] != '#')
            {
                graph[grid_to_arr[i][j]].push_back(grid_to_arr[i + 1][j]);
            }
            if (j < m && v[i][j + 1] != '#')
            {
                graph[grid_to_arr[i][j]].push_back(grid_to_arr[i][j + 1]);
            }
        }
    }
    return graph;
}

void dfs(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited)
{
    isVisited[vertex] = true;
    pair<ll, ll> pr = arr_to_grid[vertex];
    if (v[pr.first][pr.second] != '+')
        return;
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            ll plus_cnt = 0;
            for (auto y : graph[x])
            {
                pair<ll, ll> pp = arr_to_grid[y];
                if (v[pp.first][pp.second] == '+')
                    plus_cnt++;
            }
            if (plus_cnt + 1 == graph[x].size() || plus_cnt == graph[x].size())
            {
                pair<ll, ll> pp = arr_to_grid[x];
                v[pp.first][pp.second] = '+';
                dfs(x, graph, isVisited);
            }
        }
    }
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    v.clear();
    grid_to_arr.clear();
    arr_to_grid.clear();
    cin >> n >> m;
    v.assign(n + 1, vector<char>(m + 1));
    pair<ll, ll> lab;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            cin >> v[i][j];
            if (v[i][j] == 'L')
                lab = {i, j};
        }
    }
    vector<vector<ll>> graph = grid_mapped_arr(n, m);
    vector<bool> isVisited(graph.size(), false);
    v[lab.first][lab.second] = '+';
    dfs(grid_to_arr[lab.first][lab.second], graph, isVisited);
    v[lab.first][lab.second] = 'L';
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            cout << v[i][j];
        }
        cout << endl;
    }
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