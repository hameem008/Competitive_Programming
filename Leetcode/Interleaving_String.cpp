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
    bool isInterleave(string s1, string s2, string s3)
    {
        if (s1.size() + s2.size() != s3.size())
            return false;
        vector<vector<bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1, false));
        for (int i = 1; i <= s1.size(); i++)
        {
            if (s1[i - 1] == s3[i - 1])
                dp[i][0] = true;
            else
                break;
        }
        for (int i = 1; i <= s2.size(); i++)
        {
            if (s2[i - 1] == s3[i - 1])
                dp[0][i] = true;
            else
                break;
        }
        dp[0][0] = true;
        for (int i = 1; i <= s1.size(); i++)
        {
            for (int j = 1; j <= s2.size(); j++)
            {
                if (s3[i + j - 1] == s1[i - 1])
                    dp[i][j] = dp[i][j] | dp[i - 1][j];
                if (s3[i + j - 1] == s2[j - 1])
                    dp[i][j] = dp[i][j] | dp[i][j - 1];
            }
        }
        return dp[s1.size()][s2.size()];
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