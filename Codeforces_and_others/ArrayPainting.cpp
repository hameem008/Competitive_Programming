#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

ll ans = 0;
void dfs(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited)
{
    isVisited[vertex] = true;
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
    vector<ll> v(n + 1, 0);
    for (i = 1; i <= n; i++)
        cin >> v[i];
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    vector<vector<ll>> graph(n + 1);
    vector<bool> isConnected(n + 1, false), isVisited(n + 1, false);
    if (v[1] == 2)
    {
        v[1]--;
    }
    if (v[n] == 2)
    {
        v[n]--;
    }

    for (i = 1; i <= n; i++)
    {
        if (v[i] == 2)
        {
            graph[i].push_back(i + 1);
            graph[i].push_back(i - 1);
            graph[i + 1].push_back(i);
            graph[i - 1].push_back(i);
            isConnected[i] = isConnected[i + 1] = isConnected[i - 1] = true;
        }
    }

    if (v[1] == 1)
    {
        graph[1].push_back(2);
        isConnected[1] = true;
        if (n != 3)
        {
            graph[2].push_back(1);
            isConnected[2] = true;
        }
    }
    if (v[n] == 1)
    {
        graph[n].push_back(n - 1);
        isConnected[n] = true;
        if (n != 3)
        {
            graph[n - 1].push_back(n);
            isConnected[n - 1] = true;
        }
    }

    for (i = 2; i <= n - 1; i++)
    {
        if (isConnected[i] && v[i] == 1)
        {
            if (find(graph[i].begin(), graph[i].end(), i - 1) != graph[i].end())
            {
                graph[i].push_back(i + 1);
                graph[i + 1].push_back(i);
                isConnected[i] = isConnected[i + 1] = true;
            }
            else if (find(graph[i].begin(), graph[i].end(), i + 1) != graph[i].end())
            {
                graph[i].push_back(i - 1);
                graph[i - 1].push_back(i);
                isConnected[i] = isConnected[i - 1] = true;
            }
        }
    }

    for (i = 2; i <= n - 1; i++)
    {
        if (!isConnected[i] && v[i] == 1)
        {
            if (v[i - 1] == 0 && !isConnected[i - 1])
            {
                graph[i].push_back(i - 1);
                graph[i - 1].push_back(i);
            }
            else if (v[i + 1] == 0 && !isConnected[i + 1])
            {
                graph[i].push_back(i + 1);
                graph[i + 1].push_back(i);
            }
        }
    }

    if (!isVisited[1])
    {
        ans++;
        dfs(1, graph, isVisited);
    }
    if (!isVisited[n])
    {
        ans++;
        dfs(n, graph, isVisited);
    }

    for (i = 2; i <= n - 1; i++)
    {
        if (!isVisited[i])
        {
            ans++;
            dfs(i, graph, isVisited);
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
    // cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}