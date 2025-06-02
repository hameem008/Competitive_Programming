#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
ll mod = 1e9 + 7;

void dfs(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisted)
{
    if (isVisted[vertex])
        return;
    isVisted[vertex] = true;
    for (auto x : graph[vertex])
    {
        dfs(x, graph, isVisted);
    }
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<ll> va(n + 1), vb(n + 1), vc(n + 1);
    for (i = 1; i <= n; i++)
        cin >> va[i];
    for (i = 1; i <= n; i++)
        cin >> vb[i];
    for (i = 1; i <= n; i++)
        cin >> vc[i];
    vector<vector<ll>> graph(2 * n + 1);
    for (i = 1; i <= n; i++)
    {
        graph[va[i]].push_back(vb[i] + n);
    }
    for (i = 1; i <= n; i++)
    {
        graph[vb[i] + n].push_back(vb[i]);
    }
    vector<bool> isVisited(2 * n + 1, false);
    ll ans = 1;
    for (i = 1; i <= n; i++)
    {
        if (vc[i] != 0)
        {
            dfs(vc[i], graph, isVisited);
        }
    }
    for (i = 1; i <= 2 * n; i++)
    {
        if (!isVisited[i])
        {

            dfs(i, graph, isVisited);
            if (abs(i - graph[i][0]) == n)
            {
                ans *= 1;
            }
            else
            {
                ans *= 2;
                ans %= mod;
            }
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