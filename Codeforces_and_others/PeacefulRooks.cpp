#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

vector<ll> connected;
void dfs(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited)
{
    isVisited[vertex] = true;
    connected.push_back(vertex);
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            dfs(x, graph, isVisited);
        }
    }
}

bool cycleFlag;
void isCycle(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited, ll parrent)
{
    isVisited[vertex] = true;
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            isCycle(x, graph, isVisited, vertex);
        }
        else if (x != parrent)
        {
            cycleFlag = true;
        }
    }
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> m;
    vector<vector<ll>> graph(m + 1), cols(n + 1), rows(n + 1);
    vector<bool> isVIsited(m + 1, false);
    vector<pair<ll, ll>> rooksCord(m + 1);
    for (i = 1; i <= m; i++)
    {
        cin >> a >> b;
        if (a == b)
        {
            isVIsited[i] = true;
            continue;
        }
        rooksCord[i] = {a, b};
        rows[a].push_back(i);
        cols[b].push_back(i);
    }
    for (i = 1; i <= n; i++)
    {
        if (cols[i].size() == 1 && rows[i].size() == 1)
        {
            graph[cols[i][0]].push_back(rows[i][0]);
            graph[rows[i][0]].push_back(cols[i][0]);
        }
    }
    ll ans = 0;
    for (i = 1; i <= m; i++)
    {
        if (!isVIsited[i])
        {
            connected.clear();
            cycleFlag = false;
            dfs(i, graph, isVIsited);
            for (auto x : connected)
            {
                isVIsited[x] = false;
            }
            isCycle(i, graph, isVIsited, i);
            ll nodes = connected.size();
            if (nodes == 1)
            {
                ans++;
            }
            else if (nodes == 2)
            {
                a = connected[0], b = connected[1];
                if (rooksCord[a].first == rooksCord[b].second && rooksCord[a].second == rooksCord[b].first)
                {
                    ans += 3;
                }
                else
                {
                    ans += 2;
                }
            }
            else
            {
                if (cycleFlag)
                {
                    ans += 1 + nodes;
                }
                else
                {
                    ans += nodes;
                }
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