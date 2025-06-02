#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

vector<ll> ans;
vector<ll> Parents;
vector<ll> Distance;
ll Source;
void bfs(ll source, vector<vector<pair<ll, ll>>> &graph, vector<bool> &isVisited)
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
        ans.push_back(vertex);
        q.pop();
        for (auto x : graph[vertex])
        {
            if (!isVisited[x.second])
            {
                q.push(x.second);
                isVisited[x.second] = true;
                Parents[x.second] = vertex;
                Distance[x.second] = Distance[vertex] + 1;
            }
        }
    }
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    ans.clear();
    cin >> n;
    vector<pair<ll, ll>> edges;
    for (i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        edges.push_back({a, b});
    }
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    map<ll, ll> mp;
    for (i = 0; i < n; i++)
    {
        mp.insert({v[i], i});
    }
    vector<vector<pair<ll, ll>>> graph(n + 1);
    for (auto x : edges)
    {
        graph[x.first].push_back({mp[x.second], x.second});
        graph[x.second].push_back({mp[x.first], x.first});
    }
    for (i = 1; i <= n; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }
    vector<bool> isVisited(n + 1, false);
    bfs(1, graph, isVisited);
    if (ans == v)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
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