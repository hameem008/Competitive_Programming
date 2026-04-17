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
    vector<vector<int>> graph;
    vector<bool> isVisited;
    vector<int> stac;
    void dfs(int vertex, int cnt)
    {
        if (isVisited[vertex])
        {
            if (stac[vertex] != 0)
                ret = false;
            return;
        }
        isVisited[vertex] = true;
        stac[vertex] = cnt;
        for (auto x : graph[vertex])
            dfs(x, cnt);
        stac[vertex] = 0;
    }
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> v;
        graph.assign(numCourses, v);
        isVisited.assign(numCourses, false);
        stac.assign(numCourses, 0);
        for (vector<int> x : prerequisites)
        {
            graph[x[0]].push_back(x[1]);
        }
        for (int i = 0; i < numCourses; i++)
        {
            if (!isVisited[i])
            {
                dfs(i, 1);
            }
        }
        return ret;
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