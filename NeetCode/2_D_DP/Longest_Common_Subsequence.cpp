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
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size(), m = text2.size();
        if (n == 0 || m == 0)
            return 0;
        bool flag = false;
        vector<vector<int>> dp(n, vector(m, 0));
        for (int i = 0; i < m; i++)
        {
            if (text2[i] == text1[0])
                flag = true;
            if (flag)
                dp[0][i] = 1;
        }
        flag = false;
        for (int i = 0; i < n; i++)
        {
            if (text1[i] == text2[0])
                flag = true;
            if (flag)
                dp[i][0] = 1;
        }
        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++)
            {
                if (text1[i] == text2[j])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                dp[i][j] = max({dp[i][j], dp[i - 1][j], dp[i][j - 1]});
            }
        return dp[n - 1][m - 1];
    }
};

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    Solution sl;
    sl.longestCommonSubsequence("zabt", "crabt");
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