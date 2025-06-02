#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

vector<ll> nodeValue;
vector<ll> visitedNodes;
ll cnt_plus_1, cnt_minus_1;
void dfs_plus_1(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited)
{
    isVisited[vertex] = true;
    visitedNodes.push_back(vertex);
    if (nodeValue[vertex] == 1)
        cnt_plus_1++;
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            dfs_plus_1(x, graph, isVisited);
        }
    }
}
void dfs_minus_1(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited)
{
    isVisited[vertex] = true;
    if (nodeValue[vertex] == -1)
        cnt_minus_1++;
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            dfs_minus_1(x, graph, isVisited);
        }
    }
}

set<pair<ll, ll>> same, opposite;
void bfs(ll source, vector<vector<ll>> &graph, vector<bool> &isVisited)
{
    queue<ll> q;
    isVisited[source] = true;
    q.push(source);
    nodeValue[source] = 1;
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
                if (same.find({vertex, x}) != same.end())
                {
                    nodeValue[x] = 0 + nodeValue[vertex];
                }
                else if (opposite.find({vertex, x}) != opposite.end())
                {
                    nodeValue[x] = 0 - nodeValue[vertex];
                }
            }
        }
    }
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    nodeValue.clear();
    same.clear();
    opposite.clear();
    cin >> n >> m;
    vector<pair<pair<ll, ll>, string>> input;
    vector<vector<ll>> graph(n + 1), crewmate(n + 1), imposter(n + 1);
    vector<bool> isVisited(n + 1, false);
    set<ll> impos, crews;
    for (i = 1; i <= m; i++)
    {
        string str;
        cin >> a >> b >> str;
        input.push_back({{a, b}, str});
        graph[a].push_back(b);
        graph[b].push_back(a);
        if (str == "crewmate")
        {
            crewmate[a].push_back(b);
            crewmate[b].push_back(a);
            crews.insert(a);
            crews.insert(b);
            same.insert({a, b});
            same.insert({b, a});
        }
        else if (str == "imposter")
        {
            imposter[a].push_back(b);
            imposter[b].push_back(a);
            impos.insert(a);
            impos.insert(b);
            opposite.insert({a, b});
            opposite.insert({b, a});
        }
    }
    nodeValue.assign(n + 1, 0);
    for (i = 1; i <= n; i++)
    {
        if (!isVisited[i])
            bfs(i, graph, isVisited);
    }
    for (auto x : crews)
    {
        for (auto y : crewmate[x])
        {
            if (nodeValue[x] != nodeValue[y])
            {
                cout << -1 << endl;
                return;
            }
        }
    }
    for (auto x : impos)
    {
        for (auto y : imposter[x])
        {
            if (nodeValue[x] == nodeValue[y])
            {
                cout << -1 << endl;
                return;
            }
        }
    }
    isVisited.clear();
    isVisited.assign(n + 1, false);
    ll ans = 0;
    for (i = 1; i <= n; i++)
    {
        if (!isVisited[i])
        {
            cnt_plus_1 = cnt_minus_1 = 0;
            visitedNodes.clear();
            dfs_plus_1(i, graph, isVisited);
            for (auto x : visitedNodes)
                isVisited[x] = false;
            dfs_minus_1(i, graph, isVisited);
            ans += max(cnt_minus_1, cnt_plus_1);
        }
    }
    cout << ans << endl;
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