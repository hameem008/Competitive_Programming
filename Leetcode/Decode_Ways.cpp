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
    int numDecodings(string s)
    {
        if (s.front() == '0')
            return 0;
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        for (int i = 1; i < n; i++)
        {
            if (s[i] == '0')
            {
                int val = (s[i - 1] - '0') * 10;
                if (val <= 26 && val > 0)
                    dp[i + 1] += dp[i - 1];
                else
                    return 0;
            }
            else
            {
                dp[i + 1] += dp[i];
                if (s[i - 1] != '0')
                {
                    int val = (s[i - 1] - '0') * 10 + (s[i] - '0');
                    if (val <= 26)
                        dp[i + 1] += dp[i - 1];
                }
            }
        }
        return dp[n];
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