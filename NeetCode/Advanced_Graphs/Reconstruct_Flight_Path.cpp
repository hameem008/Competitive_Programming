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
    // Hierholzer's algorithm
    vector<string> ret;
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
    void dfs(string vertex)
    {
        auto it = graph.find(vertex);
        while (it->second.size())
        {
            string child = it->second.top();
            it->second.pop();
            dfs(child);
        }
        ret.push_back(vertex);
    }
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        for (auto x : tickets)
        {
            graph[x[0]].push(x[1]);
            graph[x[1]];
        }
        dfs("JFK");
        reverse(ret.begin(), ret.end());
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