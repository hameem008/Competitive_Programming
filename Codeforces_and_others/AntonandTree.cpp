#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

void dfs(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVIsited, vector<ll> &color, ll curColor)
{
    isVIsited[vertex] = true;
    if (curColor == 1)
        color[vertex] = 0;
    else
        color[vertex] = 1;
    for (auto x : graph[vertex])
    {
        if (!isVIsited[x] && color[x] == curColor)
        {
            dfs(x, graph, isVIsited, color, curColor);
        }
    }
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<ll> color(n + 1, 0);
    for (i = 1; i <= n; i++)
        cin >> color[i];
    vector<ll> dum;
    vector<vector<ll>> graph(n + 1, dum);
    vector<bool> isVisited(n + 1, false);
    for (i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<ll> dumcolor1(color.begin(), color.end());
    vector<ll> dumcolor2(color.begin(), color.end());
    ll ans1 = 0;
    for (i = 1; i <= n; i++)
    {
        if (dumcolor1[i] == 0 && !isVisited[i])
        {
            ans1++;
            dfs(i, graph, isVisited, dumcolor1, 0);
        }
    }
    isVisited.clear();
    isVisited.assign(n + 1, false);
    ll ans2 = 0;
    for (i = 1; i <= n; i++)
    {
        if (dumcolor2[i] == 1 && !isVisited[i])
        {
            ans2++;
            dfs(i, graph, isVisited, dumcolor2, 1);
        }
    }
    cout << min(ans1, ans2) << endl;
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