#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

class Solution
{
public:
    vector<int> v;
    vector<vector<int>> graph;
    vector<bool> is_visited;
    void dfs(int vertex)
    {
        if (is_visited[vertex])
            return;
        is_visited[vertex] = true;
        for (auto x : graph[vertex])
            dfs(x);
    }
    int countComponents(int n, vector<vector<int>> &edges)
    {
        graph.assign(n, v);
        is_visited.assign(n, false);
        for (auto x : edges)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (!is_visited[i])
            {
                dfs(i);
                cnt++;
            }
        }
        return cnt;
    }
};

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts

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