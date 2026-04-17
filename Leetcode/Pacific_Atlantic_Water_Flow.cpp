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
    vector<vector<int>> mark;
    int rows, cols;
    void rec(int n, int m, int val, int parrent_height, vector<vector<int>> &heights)
    {
        if (n == -1 || n == rows || m == -1 || m == cols)
            return;
        if (mark[n][m] % val != 0 || heights[n][m] < parrent_height)
            return;
        mark[n][m] /= val;
        rec(n + 1, m, val, heights[n][m], heights);
        rec(n - 1, m, val, heights[n][m], heights);
        rec(n, m + 1, val, heights[n][m], heights);
        rec(n, m - 1, val, heights[n][m], heights);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        rows = heights.size(), cols = heights[0].size();
        vector<int> v(cols, 6);
        mark.assign(rows, v);
        for (int j = 0; j < cols; j++)
            rec(0, j, 2, 0, heights);
        for (int i = 0; i < rows; i++)
            rec(i, 0, 2, 0, heights);
        for (int j = 0; j < cols; j++)
            rec(rows - 1, j, 3, 0, heights);
        for (int i = 0; i < rows; i++)
            rec(i, cols - 1, 3, 0, heights);
        vector<vector<int>> ret;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (mark[i][j] == 1)
                {
                    vector<int> v = {i, j};
                    ret.push_back(v);
                }
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
    vector<vector<int>> heights = {{4, 2, 7, 3, 4}, {7, 4, 6, 4, 7}, {6, 3, 5, 3, 6}};
    Solution sl;
    for (vector<int> x : sl.pacificAtlantic(heights))
        cout << x[0] << gap << x[1] << endl;
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