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
    int cycle_head;
    vector<int> v, cont;
    vector<vector<int>> graph;
    vector<bool> is_visited;
    vector<bool> is_in_stack;
    void capture_cycle(int vertex, int parrent)
    {
        if (is_visited[vertex])
        {
            cont[parrent] = vertex;
            v = cont;
            return;
        }
        is_visited[vertex] = true;
        cont[parrent] = vertex;
        for (auto x : graph[vertex])
            if (x != parrent)
                capture_cycle(x, vertex);
        cont[parrent] = 0;
        is_visited[vertex] = false;
    }
    void cycle(int vertex, int parrent)
    {
        if (is_visited[vertex])
        {
            if (is_in_stack[vertex])
            {
                ret = true;
                cycle_head = vertex;
            }
            return;
        }
        is_visited[vertex] = true;
        is_in_stack[vertex] = true;
        for (auto x : graph[vertex])
            if (x != parrent)
                cycle(x, vertex);
        is_in_stack[vertex] = false;
    }
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size() + 1;
        graph.assign(n, v);
        cont.assign(n, 0);
        is_visited.assign(n, false);
        is_in_stack.assign(n, false);
        for (auto x : edges)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        for (int i = 1; i < n; i++)
            if (!is_visited[i])
                cycle(i, i);
        is_visited.clear();
        is_visited.assign(n, false);
        capture_cycle(cycle_head, cycle_head);
        vector<int> ret_v;
        for (auto x : edges)
        {
            if (v[x[0]] == x[1] || v[x[1]] == x[0])
            {
                ret_v = {x[0], x[1]};
            }
        }
        return ret_v;
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