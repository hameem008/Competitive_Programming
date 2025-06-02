#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

bool flag;
vector<ll> coord;
void dfs(ll vertex, vector<vector<pair<ll, ll>>> &graph, vector<bool> &isVisited, ll curr_coord)
{
    isVisited[vertex] = true;
    for (auto x : graph[vertex])
    {
        if (!isVisited[x.first])
        {
            coord[x.first] = curr_coord + x.second;
            dfs(x.first, graph, isVisited, curr_coord + x.second);
        }
        else
        {
            if (coord[x.first] != curr_coord + x.second)
                flag = false;
        }
    }
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    // solve starts
    flag = true;
    cin >> n >> m;
    coord.assign(n + 1, infinite);
    vector<vector<pair<ll, ll>>> graph(n + 1);
    for (i = 1; i <= m; i++)
    {
        cin >> a >> b >> k;
        graph[a].push_back({b, k});
        graph[b].push_back({a, -k});
    }
    vector<bool> isVisited(n + 1, false);
    for (i = 1; i <= n; i++)
    {
        if (!isVisited[i])
        {
            coord[i] = 0;
            dfs(i, graph, isVisited, 0);
        }
    }
    flag ? cout << "YES" << endl : cout << "NO" << endl;
    // for (i = 1; i <= n; i++)
    //     cout << coord[i] << gap;
    // cout << endl;
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