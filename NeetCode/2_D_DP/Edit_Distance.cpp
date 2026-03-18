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
    int minDistance(string word1, string word2)
    {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for (int i = 1; i <= word1.size(); i++)
            dp[i][0] = i;
        for (int j = 1; j <= word2.size(); j++)
            dp[0][j] = j;
        for (int i = 1; i <= word1.size(); i++)
        {
            for (int j = 1; j <= word2.size(); j++)
            {
                int val = INT32_MAX;
                if (word1[i - 1] == word2[j - 1])
                    val = min(val, dp[i - 1][j - 1]);
                val = min({val, dp[i - 1][j - 1] + 1, dp[i][j - 1] + 1, dp[i - 1][j] + 1});
                dp[i][j] = val;
            }
        }
        return dp[word1.size()][word2.size()];
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