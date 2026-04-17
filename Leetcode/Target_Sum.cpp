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
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int sum = 0;
        for (auto x : nums)
            sum += x;
        if (abs(sum) < abs(target))
            return 0;
        vector<vector<int>> dp(nums.size(), vector<int>(2 * sum + 1, 0));
        dp[0][sum + nums[0]] += 1;
        dp[0][sum - nums[0]] += 1;
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j <= 2 * sum; j++)
            {
                if (j - nums[i] >= 0)
                    dp[i][j] += dp[i - 1][j - nums[i]];
                if (j + nums[i] <= 2 * sum)
                    dp[i][j] += dp[i - 1][j + nums[i]];
            }
        }
        return dp[nums.size() - 1][sum + target];
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