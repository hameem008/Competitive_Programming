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
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() <= 1)
            return 0;
        vector<vector<int>> dp(2, vector<int>(prices.size(), 0));
        dp[0][0] = 0;
        dp[1][0] = -prices[0];
        dp[0][1] = max(0, dp[1][0] + prices[1]);
        dp[1][1] = max(dp[1][0], -prices[1]);
        for (int i = 2; i < prices.size(); i++)
        {
            dp[0][i] = max(dp[1][i - 1] + prices[i], dp[0][i - 1]);
            dp[1][i] = max(dp[1][i - 1], dp[0][i - 2] - prices[i]);
        }
        return max(dp[0][prices.size() - 1], dp[1][prices.size() - 1]);
    }
};

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    vector<int> prices = {1, 3, 4, 0, 4};
    Solution sl;
    cout << sl.maxProfit(prices) << endl;
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