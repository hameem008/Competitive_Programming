#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

vector<ll> parent;
vector<ll> shortest_path(ll source, vector<vector<ll>> &graph, vector<bool> &isVisited, ll destination)
{
    if (parent.size() == 0)
        parent.assign(isVisited.size(), -1);
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
                parent[x] = vertex;
            }
        }
    }
    vector<ll> path;
    if (parent[destination] != -1)
    {
        ll node = destination;
        while (node != source)
        {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(source);
        reverse(path.begin(), path.end());
    }
    // path.size() = 0 --> No path exist
    // distance = path.size() - 1
    return path;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    parent.clear();
    cin >> n >> m;
    vector<ll> dum;
    vector<vector<ll>> graph(n + 1, dum);
    vector<bool> isVisited(n + 1, false);
    for (i = 0; i < m; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (i = 1; i <= n; i++)
    {
        if (graph[i].size() == 1)
            break;
    }
    shortest_path(i, graph, isVisited, i);
    ll source = i;
    vector<ll> path;
    for (i = 1; i <= n; i++)
    {
        path = shortest_path(source, graph, isVisited, i);
        if (path.size() == 5)
            break;
    }
    ll x = graph[path[2]].size();
    ll y = graph[graph[path[2]].front()].size() - 1;
    cout << x << gap << y << endl;
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