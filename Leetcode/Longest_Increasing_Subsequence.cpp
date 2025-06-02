class Solution
{
public:
    int dp[100000 + 10];
    int fun(int n, vector<int> &nums)
    {
        if (n == 0)
            return dp[0] = 1;
        if (dp[n] == -1)
        {
            int max = 0;
            for (int i = 1; i <= n; i++)
            {
                if (nums[n] > nums[n - i] && max < fun(n - i, nums))
                    max = fun(n - i, nums);
            }
            dp[n] = max + 1;
        }
        return dp[n];
    }
    int lengthOfLIS(vector<int> &nums)
    {
        fill(dp, dp + 100000 + 10, -1);
        int i, j, k, a, b, c, d, m, p, q;
        bool flag;
        // solve starts
        for (i = 0; i < nums.size(); i++)
        {
            fun(i, nums);
        }
        // cout << *max_element(dp, dp+100000+10) << endl;
        return *max_element(dp, dp + 100000 + 10);
    }
};