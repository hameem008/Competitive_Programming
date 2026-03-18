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
    vector<int> countBits(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        int div = 4;
        for (int i = 2; i <= n; i++)
        {
            if (div == i)
                div *= 2;
            dp[i] = 1 + dp[i % (div / 2)];
        }
        return dp;
    }
};

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    Solution sl;
    for (auto x : sl.countBits(16))
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
    cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}