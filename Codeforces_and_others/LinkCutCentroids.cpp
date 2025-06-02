#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

void dfs(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited, vector<ll> &cnt)
{
    isVisited[vertex] = true;
    ll ct = 1;
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            dfs(x, graph, isVisited, cnt);
            ct += cnt[x];
        }
    }
    cnt[vertex] = ct;
}

void dfs1(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited)
{
    isVisited[vertex] = true;
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            dfs1(x, graph, isVisited);
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
    vector<bool> isVisited(n + 1, false);
    for (i = 1; i <= n - 1; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    ll root;
    for (i = 1; i <= n; i++)
    {
        if (graph[i].size() == 1)
        {
            root = i;
            break;
        }
    }
    vector<ll> cnt(n + 1, 0);
    dfs(root, graph, isVisited, cnt);
    vector<ll> centroids;
    ll mx_size = infinite;
    for (i = 1; i <= n; i++)
    {
        ll val = 0;
        for (auto x : graph[i])
        {
            if (cnt[x] > cnt[i])
            {
                val = max(val, n - cnt[i]);
            }
            else
            {
                val = max(val, cnt[x]);
            }
        }
        if (val == mx_size)
        {
            centroids.push_back(i);
        }
        else if (val < mx_size)
        {
            centroids.clear();
            centroids.push_back(i);
            mx_size = val;
        }
    }
    if (centroids.size() == 1)
    {
        cout << centroids[0] << gap << graph[centroids[0]][0] << endl;
        cout << centroids[0] << gap << graph[centroids[0]][0] << endl;
    }
    else
    {
        isVisited.clear();
        isVisited.assign(n + 1, false);
        isVisited[centroids[0]] = true;
        dfs1(centroids[1], graph, isVisited);
        ll con;
        for (i = 1; i <= n; i++)
        {
            if (graph[i].size() == 1 && isVisited[i])
            {
                con = i;
                break;
            }
        }
        cout << con << gap << graph[con][0] << endl;
        cout << con << gap << centroids[0] << endl;
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