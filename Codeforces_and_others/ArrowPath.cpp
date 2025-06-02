#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

vector<vector<ll>> grid_to_arr;
vector<pair<ll, ll>> arr_to_grid;
vector<vector<ll>> grid_mapped_arr(ll n, ll m, vector<vector<char>> ch)
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
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            if ((i + j) % 2 == 0)
            {
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
            }
            else
            {
                if (ch[i][j] == '>')
                {
                    if (j < m)
                    {
                        graph[grid_to_arr[i][j]].push_back(grid_to_arr[i][j + 1]);
                    }
                }
                else if (ch[i][j] == '<')
                {
                    if (j > 1)
                    {
                        graph[grid_to_arr[i][j]].push_back(grid_to_arr[i][j - 1]);
                    }
                }
            }
        }
    }
    return graph;
}

void dfs(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited)
{
    isVisited[vertex] = true;
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            dfs(x, graph, isVisited);
        }
    }
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<vector<char>> ch(3, vector<char>(n + 1));
    for (i = 1; i <= n; i++)
        cin >> ch[1][i];
    for (i = 1; i <= n; i++)
        cin >> ch[2][i];
    vector<vector<ll>> graph = grid_mapped_arr(2, n, ch);
    vector<bool> isVisited(graph.size() + 1, false);
    dfs(1, graph, isVisited);
    isVisited[grid_to_arr[2][n]] ? cout << "YES" << endl : cout << "NO" << endl;
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