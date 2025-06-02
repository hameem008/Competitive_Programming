#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

vector<ll> nodes;
void dfs(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited)
{
    isVisited[vertex] = true;
    nodes.push_back(vertex);
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            dfs(x, graph, isVisited);
        }
    }
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<ll> fear(n + 1);
    vector<set<ll>> vs(n + 1);
    vector<bool> sold(n + 1, false);
    vector<ll> ans;
    for (i = 1; i <= n; i++)
    {
        cin >> a;
        fear[i] = a;
        vs[a].insert(i);
    }
    queue<ll> qq;
    for (i = 1; i <= n; i++)
    {
        if (vs[i].size() == 0)
            qq.push(i);
    }
    vector<ll> cost(n + 1);
    for (i = 1; i <= n; i++)
    {
        cin >> cost[i];
    }
    vector<vector<ll>> graph(n + 1);
    for (i = 1; i <= n; i++)
    {
        if (sold[i] == false && sold[fear[i]] == false)
        {
            graph[i].push_back(fear[i]);
        }
    }
    while (qq.size())
    {
        ll rem = qq.front();
        qq.pop();
        ans.push_back(rem);
        sold[rem] = true;
        vs[fear[rem]].erase(rem);
        if (vs[fear[rem]].size() == 0)
            qq.push(fear[rem]);
    }
    vector<bool> isVisited(n + 1, false);
    for (i = 1; i <= n; i++)
    {
        if (!sold[i])
        {
            nodes.clear();
            dfs(i, graph, isVisited);
            ll min_cost = infinite;
            ll last_sold;
            for (auto x : nodes)
            {
                if (min_cost > cost[x])
                {
                    last_sold = x;
                    min_cost = cost[x];
                }
            }
            ll sold_it = fear[last_sold];
            while (!sold[sold_it])
            {
                ans.push_back(sold_it);
                sold[sold_it] = true;
                sold_it = fear[sold_it];
            }
        }
    }
    for (auto x : ans)
        cout << x << gap;
    cout << endl;
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