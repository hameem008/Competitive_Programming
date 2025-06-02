#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

ll cnt = 0;

bool isRing(vector<vector<ll>> &graph, vector<bool> &isVisited, ll vertex)
{
    cnt++;
    isVisited[vertex] = true;
    if (graph[vertex].size() == 2)
    {
        if (isVisited[graph[vertex][0]] && isVisited[graph[vertex][1]])
            return true;
        else if (isVisited[graph[vertex][0]])
            return isRing(graph, isVisited, graph[vertex][1]);
        else
            return isRing(graph, isVisited, graph[vertex][0]);
    }
    else
        return false;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    // solve starts
    cin >> n;
    vector<vector<ll>> graph(n + 1);
    vector<bool> isVisited(n + 1, false);
    for (i = 0; i < n; i++)
    {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    bool flag = true;
    for (i = 1; i <= n; i++)
    {
        if (!isVisited[i])
        {
            cnt = 0;
            flag &= isRing(graph, isVisited, i) & (cnt % 2 == 0);
        }
        if (!flag)
            break;
    }
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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