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
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, 1e6);
        dp[0] = 0;
        for (int i = 0; i <= amount; i++)
        {
            for (auto x : coins)
                if (i + x <= amount && i + x > 0)
                    dp[i + x] = min(dp[i + x], dp[i] + 1);
        }
        if (dp[amount] == 1e6)
            dp[amount] = -1;
        return dp[amount];
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