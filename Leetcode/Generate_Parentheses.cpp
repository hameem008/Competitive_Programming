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
    vector<vector<string>> dp;
    vector<string> generateParenthesis(int n)
    {
        vector<string> vs = {"()"};
        dp.push_back(vs);
        vs = {"()()", "(())"};
        dp.push_back(vs);
        for (int len = 3; len <= n; len++)
        {
            vector<string> vs_len;
            for (int i = 0; i < len; i++)
            {
                int j = len - 1 - i;
                if (i)
                {
                    for (auto strx : dp[i - 1])
                    {
                        string str;
                        str.push_back('(');
                        for (auto x : strx)
                            str.push_back(x);
                        str.push_back(')');
                        if (j)
                        {
                            for (auto stry : dp[j - 1])
                            {
                                string strrr = str;
                                for (auto y : stry)
                                    strrr.push_back(y);
                                vs_len.push_back(strrr);
                            }
                        }
                        else
                            vs_len.push_back(str);
                    }
                }
                else
                {
                    for (auto strx : dp[j - 1])
                    {
                        string str;
                        str.push_back('(');
                        str.push_back(')');
                        for (auto x : strx)
                            str.push_back(x);
                        vs_len.push_back(str);
                    }
                }
            }
            dp.push_back(vs_len);
        }
        return dp[n - 1];
    }
};

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    Solution sl;
    for (auto x : sl.generateParenthesis(n))
        cout << x << gap;
    cout << endl;
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