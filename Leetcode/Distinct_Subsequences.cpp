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
    int numDistinct(string s, string t)
    {
        vector<vector<int>> dp(t.size() + 1, vector<int>(s.size() + 1, 0));
        for (int i = 0; i <= s.size(); i++)
            dp[0][i] = 1;
        for (int i = 1; i <= t.size(); i++)
        {
            for (int j = 1; j <= s.size(); j++)
            {
                if (t[i - 1] == s[j - 1])
                    dp[i][j] += dp[i - 1][j - 1];
                long long int val = dp[i][j];
                val += dp[i][j - 1];
                if (val <= INT32_MAX)
                    dp[i][j] = val;
                else
                    dp[i][j] = INT32_MAX;
            }
        }
        return dp[t.size()][s.size()];
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