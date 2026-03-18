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
    int change(int amount, vector<int> &coins)
    {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, 0));
        for (int i = 0; i < coins.size(); i++)
            dp[i][0] = 1;
        for (int i = 0; i <= amount; i++)
            if (i - coins[0] >= 0)
                dp[0][i] = dp[0][i - coins[0]];
        for (int i = 1; i < coins.size(); i++)
            for (int j = 1; j <= amount; j++)
            {
                if (j - coins[i] >= 0)
                    dp[i][j] += dp[i][j - coins[i]];
                dp[i][j] += dp[i - 1][j];
            }
        return dp[coins.size() - 1][amount];
    }
};

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    int amount = 4;
    vector<int> coins = {1, 2, 3};
    Solution sl;
    sl.change(amount, coins);
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