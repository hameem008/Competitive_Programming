#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

bool cycle_flag = false;
vector<ll> parrents;
vector<bool> st;
ll start_vertex = 0, end_vertex = 0;
void dfs(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited, ll parrent)
{
    if (cycle_flag)
        return;
    isVisited[vertex] = true;
    st[vertex] = true;
    parrents[vertex] = parrent;
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            dfs(x, graph, isVisited, vertex);
        }
        else if (st[x] && !cycle_flag)
        {
            cycle_flag = true;
            start_vertex = vertex;
            end_vertex = x;
        }
    }
    st[vertex] = false;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> m;
    vector<vector<ll>> graph(n + 1);
    vector<bool> isVisited(n + 1, false);
    st.assign(n + 1, false);
    parrents.assign(n + 1, 0);
    for (i = 1; i <= m; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
    }
    for (i = 1; i <= n; i++)
    {
        if (!isVisited[i])
        {
            dfs(i, graph, isVisited, 0);
        }
    }
    if (cycle_flag)
    {
        vector<ll> path;
        ll vertex = start_vertex;
        while (1)
        {
            path.push_back(vertex);
            if (vertex == end_vertex)
            {
                path.push_back(start_vertex);
                break;
            }
            vertex = parrents[vertex];
        }
        reverse(path.begin(), path.end());
        cout << path.size() << endl;
        for (auto x : path)
        {
            cout << x << gap;
        }
        cout << endl;
    }
    else
        cout << "IMPOSSIBLE" << endl;
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