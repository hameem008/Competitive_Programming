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
    int maxProduct(vector<int> &nums)
    {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(2));
        dp[0][0] = dp[0][1] = 1;
        int ret = INT32_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            dp[i + 1][0] = max({dp[i][0] * nums[i], dp[i][1] * nums[i], nums[i]});
            dp[i + 1][1] = min({dp[i][0] * nums[i], dp[i][1] * nums[i], nums[i]});
            ret = max({ret, dp[i + 1][0], dp[i + 1][1]});
        }
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
    cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}