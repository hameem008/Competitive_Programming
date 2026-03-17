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
    vector<vector<bool>> visited;
    bool pre(int n, vector<vector<int>> &grid)
    {
        visited.clear();
        visited.assign(grid.size(), vector<bool>(grid.size(), false));
        queue<pair<int, int>> q;
        if (grid[0][0] > n)
            return false;
        visited[0][0] = true;
        q.push({0, 0});
        while (q.size())
        {
            pair<int, int> p = q.front();
            q.pop();

            if (p.first + 1 < grid.size())
                if (!visited[p.first + 1][p.second] && grid[p.first + 1][p.second] <= n)
                {
                    visited[p.first + 1][p.second] = true;
                    q.push({p.first + 1, p.second});
                }

            if (p.first - 1 >= 0)
                if (!visited[p.first - 1][p.second] && grid[p.first - 1][p.second] <= n)
                {
                    visited[p.first - 1][p.second] = true;
                    q.push({p.first - 1, p.second});
                }

            if (p.second + 1 < grid.size())
                if (!visited[p.first][p.second + 1] && grid[p.first][p.second + 1] <= n)
                {
                    visited[p.first][p.second + 1] = true;
                    q.push({p.first, p.second + 1});
                }

            if (p.second - 1 >= 0)
                if (!visited[p.first][p.second - 1] && grid[p.first][p.second - 1] <= n)
                {
                    visited[p.first][p.second - 1] = true;
                    q.push({p.first, p.second - 1});
                }
        }
        return visited[grid.size() - 1][grid.size() - 1];
    }
    int swimInWater(vector<vector<int>> &grid)
    {
        int hi = grid.size() * grid.size(), lo = 0, mid;
        while (hi - lo > 1)
        {
            mid = (hi + lo) / 2;
            if (pre(mid, grid))
                hi = mid;
            else
                lo = mid + 1;
        }
        if (pre(lo, grid))
            return lo;
        else
            return hi;
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