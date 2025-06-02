#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

ll root;
void dfs(ll vertex, vector<set<ll>> &graph, vector<bool> &isVisited, ll parrent)
{
    isVisited[vertex] = true;
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            dfs(x, graph, isVisited, vertex);
        }
        else if (isVisited[x] && x != parrent)
        {
            root = vertex;
        }
    }
}

bool flag;
vector<ll> path;
void dfs2(ll vertex, vector<set<ll>> &graph, vector<bool> &isVisited, ll parrent)
{
    isVisited[vertex] = true;
    if (graph[vertex].find(root) != graph[vertex].end() && parrent != root)
    {
        flag = true;
        path.push_back(root);
        path.push_back(vertex);
    }
    for (auto x : graph[vertex])
    {
        if (!isVisited[x] && !flag)
        {
            dfs2(x, graph, isVisited, vertex);
        }
    }
    if (flag)
    {
        path.push_back(parrent);
    }
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    flag = false;
    // solve starts
    root = -1;
    cin >> n >> m;
    vector<set<ll>> graph(n + 1);
    for (i = 1; i <= m; i++)
    {
        cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
    }
    vector<bool> isVisited(n + 1, false);
    for (i = 1; i <= n; i++)
    {
        if (root != -1)
            break;
        if (!isVisited[i])
            dfs(i, graph, isVisited, 0);
    }
    if (root == -1)
        cout << "IMPOSSIBLE" << endl;
    else
    {
        isVisited.clear();
        isVisited.assign(n + 1, false);
        dfs2(root, graph, isVisited, root);
        path.pop_back();
        cout << path.size() << endl;
        for (auto x : path)
            cout << x << gap;
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
    // cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}