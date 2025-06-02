#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

vector<ll> parrents;
bool isCycle;
ll start, stop;
void dfs(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited)
{
    if (isCycle)
        return;
    isVisited[vertex] = true;
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            parrents[x] = vertex;
            dfs(x, graph, isVisited);
        }
        else if (x != parrents[vertex] && !isCycle)
        {
            isCycle = true;
            stop = x;
            start = vertex;
            return;
        }
    }
}

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

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    isCycle = false;
    // solve starts
    cin >> n >> a >> b;
    parrents.clear();
    parrents.assign(n + 1, 0);
    vector<vector<ll>> graph(n + 1);
    vector<bool> isVisited(n + 1, false);
    for (i = 0; i < n; i++)
    {
        cin >> c >> d;
        graph[c].push_back(d);
        graph[d].push_back(c);
    }
    dfs(1, graph, isVisited);
    vector<bool> node_in_cycle(n + 1, false);
    node_in_cycle[start] = node_in_cycle[stop] = true;
    ll node = start;
    while (node != stop)
    {
        node_in_cycle[node] = true;
        node = parrents[node];
    }
    isVisited.clear();
    isVisited.assign(n + 1, false);
    bfs(a, graph, isVisited);
    vector<ll> distance_from_marcel = Distance;
    isVisited.clear();
    isVisited.assign(n + 1, false);
    bfs(b, graph, isVisited);
    vector<ll> distance_from_valeriu = Distance;
    flag = false;
    for (i = 1; i <= n; i++)
    {
        if (node_in_cycle[i])
        {
            if (distance_from_valeriu[i] < distance_from_marcel[i])
                flag = true;
        }
    }
    flag ? cout << "YES" << endl : cout << "NO" << endl;
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