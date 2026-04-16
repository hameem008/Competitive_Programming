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
    bool in_range(int val, vector<int> inv)
    {
        if (val >= inv[0] && val <= inv[1])
            return true;
        return false;
    }
    vector<int> select_it(vector<int> inv1, vector<int> inv2)
    {
        if (in_range(inv1[0], inv2) && in_range(inv1[1], inv2))
            return inv1;
        else if (in_range(inv2[0], inv1) && in_range(inv2[1], inv1))
            return inv2;
        else if (inv1[1] < inv2[1])
            return inv1;
        else if (inv1[1] > inv2[1])
            return inv2;
        else
        {
            if (inv1[0] < inv2[0])
                return inv2;
            else if (inv1[0] > inv2[0])
                return inv1;
            else
                return inv1;
        }
    }
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ret;
        for (auto x : intervals)
        {
            if (ret.size() == 0)
                ret.push_back(x);
            else if (ret.back()[1] <= x[0])
                ret.push_back(x);
            else
            {
                vector<int> v = ret.back();
                ret.pop_back();
                v = select_it(v, x);
                ret.push_back(v);
            }
        }
        return intervals.size() - ret.size();
    }
};

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    vector<vector<int>> intervals = {{1, 2}, {2, 4}, {1, 4}};
    Solution sl;
    sl.eraseOverlapIntervals(intervals);
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