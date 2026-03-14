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
    vector<vector<int>> ret;
    vector<int> container;
    void rec(vector<int> &nums, int index)
    {
        if (index == nums.size())
        {
            ret.push_back(container);
            return;
        }

        rec(nums, index + 1);
        container.push_back(nums[index]);
        rec(nums, index + 1);
        container.pop_back();
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        rec(nums, 0);
        return ret;
    }
};

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    Solution sl;
    vector<int> v = {1, 2, 3};
    for (auto x : sl.subsets(v))
    {
        for (auto y : x)
            cout << y << gap;
        cout << endl;
    }
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