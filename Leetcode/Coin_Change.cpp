class Solution
{
public:
    int dp[100000 + 10];
    int calc(int n, vector<int> &coins)
    {
        if (n == 0)
            return 0;
        if (n < 0)
            return INT32_MAX;
        if (dp[n] == -2)
        {
            int min = INT32_MAX;
            for (auto x : coins)
            {
                if (min > calc(n - x, coins) && calc(n - x, coins) != -1)
                    min = calc(n - x, coins);
            }
            if (min != INT32_MAX)
                dp[n] = min + 1;
            else
                dp[n] = -1;
        }
        return dp[n];
    }
    int coinChange(vector<int> &coins, int amount)
    {
        fill(dp, dp + 100000 + 10, -2);
        sort(coins.begin(), coins.end());
        return calc(amount, coins);
    }
};