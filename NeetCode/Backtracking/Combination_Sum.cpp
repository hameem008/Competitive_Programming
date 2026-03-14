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
    void rec(vector<int> &nums, int sum, int target, int index)
    {
        if (sum == target)
            ret.push_back(container);
        if (index == nums.size() || sum >= target)
            return;
        rec(nums, sum, target, index + 1);
        sum += nums[index];
        container.push_back(nums[index]);
        rec(nums, sum, target, index);
        container.pop_back();
        sum -= nums[index];
    }
    vector<vector<int>> combinationSum(vector<int> &nums, int target)
    {
        rec(nums, 0, target, 0);
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
    // cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}