#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

vector<ll> vertices;

void dfs(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVIsited)
{
    isVIsited[vertex] = true;
    vertices.push_back(vertex);
    for (auto x : graph[vertex])
    {
        if (!isVIsited[x])
        {
            dfs(x, graph, isVIsited);
            vertices.push_back(vertex);
        }
    }
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> m >> k;
    vector<ll> dum;
    vector<vector<ll>> graph(n + 1, dum);
    vector<bool> isVisited(n + 1, false);
    for (i = 0; i < m; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vertices.clear();
    dfs(1, graph, isVisited);
    vector<vector<ll>> ans(k, dum);
    if (vertices.size() % k == 0)
    {
        ll lim = vertices.size() / k;
        j = 0;
        for (i = 0; i < vertices.size(); i++)
        {
            ans[j].push_back(vertices[i]);
            if ((i + 1) % lim == 0)
            {
                j++;
            }
        }
    }
    else
    {
        ll lim = vertices.size() / k;
        b = vertices.size() - lim * k;
        a = k - b;
        j = 0;
        for (i = 0; i < vertices.size(); i++)
        {
            ans[j].push_back(vertices[i]);
            if ((i + 1) % lim == 0)
            {
                j++;
                a--;
            }
            if (a == 0)
                break;
        }
        i++;
        a = lim + 1;
        for (; i < vertices.size(); i++)
        {
            ans[j].push_back(vertices[i]);
            a--;
            if (a == 0)
            {
                a = lim + 1;
                j++;
            }
        }
    }
    for (auto x : ans)
    {
        cout << x.size() << gap;
        for (auto y : x)
            cout << y << gap;
        cout << endl;
    }
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