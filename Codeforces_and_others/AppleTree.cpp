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
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            dfs(x, graph, isVisited, cnt);
            cnt[vertex] += cnt[x];
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
    vector<ll> cnt(n + 1, 0);
    for (i = 1; i <= n - 1; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (i = 2; i <= n; i++)
    {
        if (graph[i].size() == 1)
        {
            cnt[i] = 1;
        }
    }
    vector<bool> isVisited(n + 1, false);
    dfs(1, graph, isVisited, cnt);
    cin >> q;
    for (i = 1; i <= q; i++)
    {
        cin >> a >> b;
        cout << cnt[a] * cnt[b] << endl;
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