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
    cin >> n;
    vector<vector<ll>> graph(n + 1);
    for (i = 1; i <= n - 1; i++)
    {
        cin >> p >> q;
        graph[p].push_back(q);
        graph[q].push_back(p);
    }
    vector<bool> isVisited(n + 1, false);
    bfs(1, graph, isVisited);
    ll root1, root2;
    ll max_dis = 0;
    for (i = 1; i <= n; i++)
    {
        if (max_dis < Distance[i])
        {
            max_dis = Distance[i];
            root1 = i;
        }
    }
    isVisited.clear();
    isVisited.assign(n + 1, false);
    bfs(root1, graph, isVisited);
    vector<vector<ll>> dis_root1(n + 1);
    for (i = 1; i <= n; i++)
    {
        dis_root1[Distance[i]].push_back(i);
    }
    max_dis = 0;
    for (i = 1; i <= n; i++)
    {
        if (max_dis < Distance[i])
        {
            max_dis = Distance[i];
            root2 = i;
        }
    }
    isVisited.clear();
    isVisited.assign(n + 1, false);
    bfs(root2, graph, isVisited);
    vector<vector<ll>> dis_root2(n + 1);
    for (i = 1; i <= n; i++)
    {
        dis_root2[Distance[i]].push_back(i);
    }
    vector<bool> counted(n + 1, false);
    vector<ll> ans(n + 2, n);
    for (i = n; i >= 1; i--)
    {
        ll cnt = 0;
        for (auto x : dis_root1[i])
        {
            if (!counted[x])
            {
                cnt++;
                counted[x] = true;
            }
        }
        for (auto x : dis_root2[i])
        {
            if (!counted[x])
            {
                cnt++;
                counted[x] = true;
            }
        }
        ans[i] = ans[i + 1] - cnt;
    }
    for (i = 1; i <= n; i++)
    {
        if (ans[i] < n)
            ans[i]++;
        cout << ans[i] << gap;
    }
    cout << endl;
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