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
    bool ret = false;
    vector<int> v;
    vector<vector<int>> graph;
    vector<bool> is_visited;
    vector<bool> is_in_stack;
    void cycle(int vertex, int parrent)
    {
        if (is_visited[vertex])
        {
            if (is_in_stack[vertex])
                ret = true;
            return;
        }
        is_visited[vertex] = true;
        is_in_stack[vertex] = true;
        for (auto x : graph[vertex])
            if (x != parrent)
                cycle(x, vertex);
        is_in_stack[vertex] = false;
    }
    bool validTree(int n, vector<vector<int>> &edges)
    {
        graph.assign(n, v);
        is_visited.assign(n, false);
        is_in_stack.assign(n, false);
        for (auto x : edges)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
            if (x[0] == x[1])
                ret = true;
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
            if (!is_visited[i])
            {
                cycle(i, i);
                cnt++;
            }
        if (ret || cnt > 1)
            return false;
        else
            return true;
    }
};

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    n = 5;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}, {1, 4}};
    Solution sl;
    sl.validTree(n, edges);
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