#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

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
    // solve starts
    cin >> n >> m;
    vector<vector<ll>> graph(n + 1);
    for (i = 1; i <= m; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<bool> isVisited(n + 1, false);
    bfs(a, graph, isVisited);
    vector<ll> ans1, ans2;
    for (i = 1; i <= n; i++)
    {
        if (Distance[i] % 2 == 0)
            ans2.push_back(i);
        else
            ans1.push_back(i);
    }
    if (ans1.size() > ans2.size())
    {
        cout << ans2.size() << endl;
        for (auto x : ans2)
            cout << x << gap;
        cout << endl;
    }
    else
    {
        cout << ans1.size() << endl;
        for (auto x : ans1)
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
    cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}