#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

map<pair<ll, ll>, ll> mp;
ll assign_it;

void dfs(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVIsited)
{
    isVIsited[vertex] = true;
    for (auto x : graph[vertex])
    {
        if (!isVIsited[x])
        {
            if (vertex > x)
            {
                mp[{x, vertex}] = assign_it;
                if (assign_it == 2)
                    assign_it = 3;
                else
                    assign_it = 2;
            }
            else
            {
                mp[{vertex, x}] = assign_it;
                if (assign_it == 2)
                    assign_it = 3;
                else
                    assign_it = 2;
            }
            dfs(x, graph, isVIsited);
        }
    }
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    assign_it = 2;
    // solve starts
    cin >> n;
    vector<pair<ll, ll>> edges;
    vector<vector<ll>> graph(n + 1);
    vector<bool> isVisited(n + 1, false);
    for (i = 0; i < n - 1; i++)
    {
        cin >> p >> q;
        graph[p].push_back(q);
        graph[q].push_back(p);
        if (p > q)
        {
            mp.insert({{q, p}, 0});
            edges.push_back({q, p});
        }
        else
        {
            mp.insert({{p, q}, 0});
            edges.push_back({p, q});
        }
    }
    ll root;
    for (i = 1; i <= n; i++)
    {
        if (graph[i].size() == 1)
            root = i;
        if (graph[i].size() > 2)
        {
            cout << -1 << endl;
            return;
        }
    }
    dfs(root, graph, isVisited);
    for (auto x : edges)
        cout << mp[x] << gap;
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