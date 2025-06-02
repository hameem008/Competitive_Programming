#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

ll calc_can_be_saved(ll vertex, vector<vector<ll>> &graph, vector<ll> &can_be_saved, vector<bool> &isVisited)
{
    isVisited[vertex] = true;
    ll saved = 1;
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
            saved += calc_can_be_saved(x, graph, can_be_saved, isVisited);
    }
    can_be_saved[vertex] = saved;
    return saved;
}

vector<ll> parrent;
void bfs(ll source, vector<vector<ll>> &graph, vector<bool> &isVisited)
{
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
                parrent[x] = vertex;
            }
        }
    }
}

ll save(ll vertex, vector<vector<ll>> &graph, vector<ll> &can_be_saved)
{
    ll ans1 = 0, ans2 = 0;
    if (graph[vertex].size() == 2)
    {
        ans1 = can_be_saved[graph[vertex][0]] + save(graph[vertex][1], graph, can_be_saved) - 1;
        ans2 = can_be_saved[graph[vertex][1]] + save(graph[vertex][0], graph, can_be_saved) - 1;
        return max(ans1, ans2);
    }
    else if (graph[vertex].size() == 1)
        return can_be_saved[graph[vertex][0]] - 1;
    else
        return 0;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<vector<ll>> graph(n + 1);
    vector<pair<ll, ll>> vp;
    for (i = 0; i < n - 1; i++)
    {
        cin >> p >> q;
        vp.push_back({p, q});
        graph[p].push_back(q);
        graph[q].push_back(p);
    }
    vector<bool> isVisited(n + 1, false);
    vector<ll> can_be_saved(n + 1, 0);
    calc_can_be_saved(1, graph, can_be_saved, isVisited);
    isVisited.clear();
    isVisited.assign(n + 1, false);
    parrent.assign(n + 1, 0);
    bfs(1, graph, isVisited);
    for (i = 2; i <= n; i++)
    {
        auto it = find(graph[i].begin(), graph[i].end(), parrent[i]);
        graph[i].erase(it);
    }
    cout << save(1, graph, can_be_saved) << endl;
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