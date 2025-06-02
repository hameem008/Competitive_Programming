class Solution
{
public:
    int dp[310][10010];

    int calc(int amount, vector<int> &coins, int ind)
    {
        if (amount == 0)
            return 1;
        if (amount < 0 || ind < 0)
            return 0;

        if (dp[ind][amount] == -1)
        {
            int ways = 0;
            for (int cur_amount = 0; cur_amount <= amount; cur_amount += coins[ind])
            {
                ways += calc(amount - cur_amount, coins, ind - 1);
            }
            dp[ind][amount] = ways;
        }

        return dp[ind][amount];
    }

    int change(int amount, vector<int> &coins)
    {
        for (int i = 0; i < 310; i++)
        {
            for (int j = 0; j < 10010; j++)
            {
                dp[i][j] = -1;
            }
        }
        sort(coins.begin(), coins.end());
        return calc(amount, coins, coins.size() - 1);
    }
};