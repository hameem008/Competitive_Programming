#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

ll special_node;
set<pair<ll, ll>> edges;
set<ll> vertices;
bool flag;

void dfs(ll vertex, vector<set<ll>> &graph, vector<bool> &isVisited, ll parrent)
{
    isVisited[vertex] = true;
    if (graph[vertex].find(special_node) != graph[vertex].end() && parrent != special_node)
    {
        flag = true;
        edges.insert({special_node, vertex});
        vertices.insert(special_node);
        vertices.insert(vertex);
    }
    for (auto x : graph[vertex])
    {
        if (!isVisited[x] && !flag)
        {
            dfs(x, graph, isVisited, vertex);
        }
    }
    if (flag)
    {
        edges.insert({vertex, parrent});
        vertices.insert(vertex);
        vertices.insert(parrent);
    }
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    // solve starts
    cin >> n >> m;
    vector<set<ll>> graph(n + 1);
    for (i = 1; i <= m; i++)
    {
        cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
    }
    for (i = 1; i <= n; i++)
    {
        if (graph[i].size() >= 4)
        {
            special_node = i;
            flag = false;
            edges.clear();
            vertices.clear();
            vector<bool> isVisited(n + 1, false);
            dfs(special_node, graph, isVisited, 0);
            if (!flag)
                continue;
            pair<ll, ll> pp = {special_node, 0};
            vertices.erase(0);
            edges.erase(pp);
            ll cnt = 0;
            for (auto x : graph[special_node])
            {
                if (vertices.find(x) == vertices.end())
                {
                    vertices.insert(x);
                    edges.insert({x, special_node});
                    cnt++;
                }
                if (cnt == 2)
                    break;
            }
            cout << "YES" << endl;
            cout << edges.size() << endl;
            for (auto x : edges)
                cout << x.first << gap << x.second << endl;
            return;
        }
    }
    cout << "NO" << endl;
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