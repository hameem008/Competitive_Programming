#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

int dp[108][1000003];

int calc(int amount, vector<int> &coins, int ind)
{
    if (amount == 0)
        return 1;
    if (amount < 0 || ind < 0)
        return 0;

    if (dp[ind][amount] == -1)
    {
        int ways = 0;
        for (int cur_amount = 0; cur_amount <= amount; cur_amount += coins[ind])
        {
            ways += calc(amount - cur_amount, coins, ind - 1);
        }
        dp[ind][amount] = ways;
    }

    return dp[ind][amount];
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> m;
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;
    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
            dp[j][i] = -1;
    }
    cout << calc(m, v, n - 1) << endl;
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