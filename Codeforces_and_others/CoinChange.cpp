#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

int dp[100000 + 10];
int ans = 0;

int calc(int n, vector<int> &coins)
{
    if (n == 0)
    {
        ans++;
        return 0;
    }
    if (n < 0)
        return INT32_MAX;
    if (dp[n] == -2)
    {
        int min = INT32_MAX;
        for (auto x : coins)
        {
            if (min > calc(n - x, coins) && calc(n - x, coins) != -1)
            {
                min = calc(n - x, coins);
            }
        }
        if (min != INT32_MAX)
            dp[n] = min + 1;
        else
            dp[n] = -1;
    }
    return dp[n];
}

int submit(vector<int> &coins, int amount)
{
    fill(dp, dp + 100000 + 10, -2);
    sort(coins.begin(), coins.end());
    return calc(amount, coins);
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
    cout << submit(v, m) << endl;
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