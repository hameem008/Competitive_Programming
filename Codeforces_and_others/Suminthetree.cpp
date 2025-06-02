#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

vector<ll> ansv, sumv;
bool flag;
void dfs(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited, ll prefix)
{
    if (!flag)
        return;
    isVisited[vertex] = true;
    if (sumv[vertex] == -1)
    {
        ll val = infinite;
        for (auto x : graph[vertex])
        {
            if (!isVisited[x])
                val = min(val, sumv[x] - prefix);
        }
        if (val < 0)
            flag = false;
        else if (val == infinite)
            val = 0;
        ansv[vertex] = val;
        for (auto x : graph[vertex])
        {
            if (!isVisited[x])
                ansv[x] = sumv[x] - prefix - val;
        }
        for (auto x : graph[vertex])
        {
            if (!isVisited[x])
            {
                dfs(x, graph, isVisited, sumv[x]);
            }
        }
    }
    else
    {
        for (auto x : graph[vertex])
        {
            if (!isVisited[x])
            {
                dfs(x, graph, isVisited, prefix);
            }
        }
    }
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    // solve starts
    flag = true;
    cin >> n;
    vector<vector<ll>> graph(n + 1);
    ansv.assign(n + 1, 0);
    sumv.assign(n + 1, 0);
    for (i = 2; i <= n; i++)
    {
        cin >> a;
        graph[a].push_back(i);
        graph[i].push_back(a);
    }
    for (i = 1; i <= n; i++)
        cin >> sumv[i];
    ansv[1] = sumv[1];
    vector<bool> isVisited(n + 1, false);
    dfs(1, graph, isVisited, sumv[1]);
    ll ans = 0;
    for (i = 1; i <= n; i++)
    {
        ans += ansv[i];
    }
    flag ? cout << ans << endl : cout << -1 << endl;
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