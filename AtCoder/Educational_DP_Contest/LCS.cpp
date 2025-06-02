#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    string str1, str2;
    cin >> str1 >> str2;
    string hor_str = " " + str1, ver_str = " " + str2;
    n = str1.size(), m = str2.size();
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            if (hor_str[i] == ver_str[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    string ans;
    i = n, j = m;
    while (1)
    {
        if (hor_str[i] == ver_str[j])
        {
            ans.push_back(hor_str[i]);
            i--, j--;
        }
        else
        {
            if (dp[i - 1][j] >= dp[i][j - 1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
        if (i == 0 || j == 0)
            break;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    // solve ends
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    ll T = 1;
    // cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}