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
    vector<int> parrent;
    vector<int> distance;
    vector<bool> visited;
    void dijkstra(vector<vector<pair<int, int>>> &graph, int source)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        parrent[source] = source, distance[source] = 0;
        pq.push({distance[source], source});
        while (pq.size())
        {
            pair<int, int> tp = pq.top();
            pq.pop();
            if (visited[tp.second])
                continue;
            visited[tp.second] = true;
            for (auto x : graph[tp.second])
            {
                if (distance[tp.second] + x.first < distance[x.second])
                {
                    distance[x.second] = distance[tp.second] + x.first;
                    parrent[x.second] = tp.second;
                    pq.push({distance[x.second], x.second});
                }
            }
        }
    }
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<pair<int, int>>> graph(n + 1);
        for (auto x : times)
            graph[x[0]].push_back({x[2], x[1]});
        parrent.assign(n + 1, -1), distance.assign(n + 1, INT32_MAX), visited.assign(n + 1, false);
        dijkstra(graph, k);
        int ret = 0;
        for (int i = 1; i <= n; i++)
            ret = max(ret, distance[i]);
        if (ret == INT32_MAX)
            ret = -1;
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