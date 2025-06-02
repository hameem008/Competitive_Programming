#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

vector<ll> bfs(ll source, vector<vector<ll>> &graph)
{
    vector<ll> dist(graph.size(), 0);
    vector<bool> isVisited(graph.size(), false);
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
                dist[x] = dist[vertex] + 1;
            }
        }
    }
    return dist;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<vector<ll>> graph(n + 1);
    for (i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    set<ll> parrentsOfLeaf;
    for (i = 1; i <= n; i++)
    {
        if (graph[i].size() == 1)
        {
            parrentsOfLeaf.insert(graph[i][0]);
        }
    }
    ll root1 = -1, root2 = -1;
    for (i = 1; i <= n; i++)
    {
        if (graph[i].size() == 1)
        {
            root1 = i;
            break;
        }
    }
    vector<ll> root1_dist = bfs(root1, graph);
    for (i = 1; i <= n; i++)
    {
        if (root1_dist[i] % 2 != 0)
        {
            root2 = i;
            break;
        }
    }
    vector<ll> ans;
    ll ans_cnt;
for_root1:
    vector<ll> ans1(n + 1, 0);
    ll ans1_cnt = 0;
    for (i = 1; i <= n; i++)
    {
        if (root1_dist[i] % 2 == 0)
        {
            ans1[i] = graph[i].size();
            ans1_cnt++;
        }
        else
        {
            ans1[i] = 1;
        }
    }
for_root2:
    if (root2 != -1)
    {
        vector<ll> ans2(n + 1, 0);
        ll ans2_cnt = 0;
        vector<ll> root2_dist = bfs(root2, graph);
        for (i = 1; i <= n; i++)
        {
            if (root2_dist[i] % 2 == 0)
            {
                ans2[i] = graph[i].size();
                ans2_cnt++;
            }
            else
            {
                ans2[i] = 1;
            }
        }
    compare:
        if (ans1_cnt > ans2_cnt)
        {
            ans = ans1;
            ans_cnt = ans1_cnt;
        }
        else if (ans1_cnt < ans2_cnt)
        {
            ans = ans2;
            ans_cnt = ans2_cnt;
        }
        else
        {
            if (accumulate(ans1.begin(), ans1.end(), 0LL) > accumulate(ans2.begin(), ans2.end(), 0LL))
            {
                ans = ans2;
                ans_cnt = ans2_cnt;
            }
            else
            {
                ans = ans1;
                ans_cnt = ans1_cnt;
            }
        }
    }
    for (auto x : parrentsOfLeaf)
        ans[x] = 1;
    ans_cnt = 0;
    for (i = 1; i <= n; i++)
    {
        if (graph[i].size() == ans[i])
            ans_cnt++;
    }
    cout << ans_cnt << gap << accumulate(ans.begin(), ans.end(), 0LL) << endl;
    for (i = 1; i <= n; i++)
    {
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