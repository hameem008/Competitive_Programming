#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef int ll;
typedef long double lld;

bool dp[101][100001];
ll v[101];

int main()
{
    ll i, j, n;
    cin >> n;
    ll limit = 0;
    for (i = 1; i <= n; i++)
    {
        cin >> v[i];
        limit += v[i];
    }
    dp[0][0] = true;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= limit; j++)
        {
            if (j - v[i] == 0)
                dp[i][j] = true;
            else if (j - v[i] > 0)
                dp[i][j] |= dp[i - 1][j - v[i]];
            dp[i][j] |= dp[i - 1][j];
        }
    }
    vector<ll> ans;
    for (i = 1; i <= limit; i++)
        if (dp[n][i])
            ans.push_back(i);
    cout << ans.size() << endl;
    for (auto x : ans)
        cout << x << gap;
    cout << endl;
}