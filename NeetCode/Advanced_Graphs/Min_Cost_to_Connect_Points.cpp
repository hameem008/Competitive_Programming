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
    vector<int> rank;
    int Find(int v)
    {
        if (v == parrent[v])
            return v;
        return parrent[v] = Find(parrent[v]);
    }
    void Union(int a, int b)
    {
        a = Find(a);
        b = Find(b);
        if (a != b)
        {
            if (rank[a] < rank[b])
                swap(a, b);
            parrent[b] = a;
            if (rank[a] == rank[b])
                rank[a]++;
        }
    }
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        set<vector<int>> ms;
        for (int i = 0; i < points.size(); i++)
            for (int j = i + 1; j < points.size(); j++)
            {
                vector<int> v = {abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]), i, j};
                ms.insert(v);
            }
        for (int i = 0; i < points.size(); i++)
        {
            parrent.push_back(i);
            rank.push_back(0);
        }
        int ret = 0;
        for (auto x : ms)
        {
            if (Find(x[1]) != Find(x[2]))
            {
                ret += x[0];
                Union(x[1], x[2]);
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