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
    bool pf(int mid, vector<vector<int>> &matrix, int target)
    {
        int row_num = matrix.size();
        int col_num = matrix[0].size();
        if (matrix[mid][0] >= target && matrix[mid][col_num - 1] >= target)
            return true;
        else if (matrix[mid][0] <= target && matrix[mid][col_num - 1] >= target)
            return true;
        else
            return false;
    }
    int bin_search(vector<vector<int>> &matrix, int target)
    {
        int row_num = matrix.size();
        int col_num = matrix[0].size();
        int row;
        int hi = row_num - 1, lo = 0, mid;
        while (hi - lo > 1) // FFFFTTT find first true
        {
            mid = (hi + lo) / 2;
            if (pf(mid, matrix, target))
                hi = mid;
            else
                lo = mid + 1;
        }
        if (pf(lo, matrix, target))
            row = lo;
        else
            row = hi;
        if (matrix[row][0] <= target && matrix[row][col_num - 1] >= target)
        {
        }
        else
            row = -1;
        return row;
    }
    bool pf2(int mid, vector<vector<int>> &matrix, int row, int target)
    {
        return matrix[row][mid] >= target;
    }
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int row_num = matrix.size();
        int col_num = matrix[0].size();
        int row = bin_search(matrix, target);
        if (row == -1)
            return false;
        int ans;
        int hi = col_num - 1, lo = 0, mid;
        while (hi - lo > 1) // FFFFTTT find first true
        {
            mid = (hi + lo) / 2;
            if (pf2(mid, matrix, row, target))
                hi = mid;
            else
                lo = mid + 1;
        }
        if (pf2(lo, matrix, row, target))
            ans = lo;
        else
            ans = hi;
        if (matrix[row][ans] == target)
            return true;
        else
            return false;
    }
};

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    vector<vector<int>> matrix = {{1, 2, 4, 8}, {10, 11, 12, 13}, {14, 20, 30, 40}};
    int target = 10;
    Solution sl;
    cout << sl.searchMatrix(matrix, target) << endl;
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