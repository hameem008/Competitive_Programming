#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

bool flag;
vector<ll> color;
vector<ll> Parents;
vector<ll> Distance;
ll Source;
void bfs(ll source, vector<vector<ll>> &graph, vector<bool> &isVisited)
{
    color[source] = 0;
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
                color[x] = 1 - color[vertex];
            }
            else if (color[x] == color[vertex])
            {
                flag = false;
                break;
            }
        }
    }
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    flag = true;
    // solve starts
    cin >> n >> m;
    color.assign(n + 1, 0);
    vector<vector<ll>> graph(n + 1);
    for (i = 1; i <= m; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<bool> isVisited(n + 1, false);
    Parents.clear();
    Distance.clear();
    Parents.assign(isVisited.size(), 0);
    Distance.assign(isVisited.size(), 0);
    for (i = 1; i <= n; i++)
    {
        if (!isVisited[i])
            bfs(i, graph, isVisited);
    }
    if (!flag)
        cout << "IMPOSSIBLE" << endl;
    else
    {
        for (i = 1; i <= n; i++)
        {
            if (color[i] == 1)
                cout << 1 << gap;
            else
                cout << 2 << gap;
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
    // cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}