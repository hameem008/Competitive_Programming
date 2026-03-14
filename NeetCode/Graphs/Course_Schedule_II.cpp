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
    bool ret = true;
    vector<int> v;
    vector<vector<int>> graph;
    vector<bool> is_visited;
    vector<bool> is_in_stack;
    vector<int> end_time;
    void top_sort(int vertex, int &time)
    {
        if (is_visited[vertex])
            return;
        time++;
        is_visited[vertex] = true;
        for (auto x : graph[vertex])
            top_sort(x, time);
        time++;
        end_time[vertex] = time;
    }
    void cycle(int vertex)
    {
        if (is_visited[vertex])
        {
            if (is_in_stack[vertex])
                ret = false;
            return;
        }
        is_visited[vertex] = true;
        is_in_stack[vertex] = true;
        for (auto x : graph[vertex])
            cycle(x);
        is_in_stack[vertex] = false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        graph.assign(numCourses, v);
        is_visited.assign(numCourses, false);
        is_in_stack.assign(numCourses, 0);
        for (vector<int> x : prerequisites)
            graph[x[0]].push_back(x[1]);
        for (int i = 0; i < numCourses; i++)
            if (!is_visited[i])
                cycle(i);
        if (!ret)
            return v;
        else
        {
            is_visited.clear();
            is_visited.assign(numCourses, false);
            end_time.assign(numCourses, 0);
            int time = 0;
            for (int i = 0; i < numCourses; i++)
                if (!is_visited[i])
                    top_sort(i, time);
            vector<pair<int, int>> vp;
            for (int i = 0; i < numCourses; i++)
                vp.push_back({end_time[i], i});
            sort(vp.begin(), vp.end());
            for (auto x : vp)
                v.push_back(x.second);
        }
        return v;
    }
};

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1, 0},
                                         {2, 0},
                                         {3, 1},
                                         {3, 2}};
    Solution sl;
    sl.findOrder(numCourses, prerequisites);
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