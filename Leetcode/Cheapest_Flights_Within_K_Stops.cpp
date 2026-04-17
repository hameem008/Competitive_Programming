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
    vector<int> distance, temp_distance;
    void bellman_ford(vector<vector<int>> &flights, int k)
    {
        while (k--)
        {
            temp_distance = distance;
            for (auto x : flights)
                if (distance[x[0]] + x[2] < temp_distance[x[1]])
                    temp_distance[x[1]] = distance[x[0]] + x[2];
            distance = temp_distance;
        }
    }
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        distance.assign(n, 1e6);
        distance[src] = 0;
        bellman_ford(flights, k + 1);
        if (distance[dst] < 1e6)
            return distance[dst];
        return -1;
    }
};

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    n = 4;
    vector<vector<int>> flights = {{0, 1, 200}, {1, 2, 100}, {1, 3, 300}, {2, 3, 100}};
    int src = 0;
    int dst = 3;
    k = 1;
    Solution sl;
    sl.findCheapestPrice(n, flights, src, dst, k);
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