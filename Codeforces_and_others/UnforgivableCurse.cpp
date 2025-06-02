#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

vector<ll> nodes;
void dfs(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited)
{
    if (isVisited[vertex])
        return;
    isVisited[vertex] = true;
    nodes.push_back(vertex);
    for (auto x : graph[vertex])
        dfs(x, graph, isVisited);
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag = true;
    // solve starts
    nodes.clear();
    cin >> n >> k;
    string s, t;
    cin >> s >> t;
    vector<vector<ll>> graph(n);
    vector<bool> isVisited(n, false);
    for (i = 0; i < n; i++)
    {
        if (i + k < n)
        {
            graph[i].push_back(i + k);
            graph[i + k].push_back(i);
        }
        if (i + k + 1 < n)
        {
            graph[i].push_back(i + k + 1);
            graph[i + k + 1].push_back(i);
        }
    }
    for (i = 0; i < n; i++)
    {
        if (!isVisited[i])
        {
            nodes.clear();
            dfs(i, graph, isVisited);
            string strs, strt;
            for (auto x : nodes)
            {
                strs.push_back(s[x]);
                strt.push_back(t[x]);
            }
            sort(strs.begin(), strs.end());
            sort(strt.begin(), strt.end());
            if (strs != strt)
                flag = false;
        }
        if (!flag)
            break;
    }
    flag ? cout << "YES" << endl : cout << "NO" << endl;
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