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
    bool canPartition(vector<int> &nums)
    {
        if (nums.size() == 0)
            return true;
        int sum = 0;
        for (auto x : nums)
            sum += x;
        if (sum % 2 != 0)
            return false;
        sum /= 2;
        vector<vector<bool>> dp(nums.size(), vector<bool>(sum + 1, false));
        for (int i = 0; i < nums.size(); i++)
            dp[i][0] = true;
        if (nums[0] <= sum)
            dp[0][nums[0]] = true;
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                if (j - nums[i] >= 0 && j - nums[i] <= sum)
                    dp[i][j] = dp[i][j] | dp[i - 1][j - nums[i]];
                dp[i][j] = dp[i][j] | dp[i - 1][j];
            }
        }
        return dp[nums.size() - 1][sum];
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