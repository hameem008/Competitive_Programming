#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

ll dp[100008];
vector<ll> vcnt(100008, 0);
ll are_mama_kop(ll n, vector<ll> &v)
{
    if (dp[n] == -1)
    {
        ll inc = v[n] > max(v[n + 1], v[n - 1]) ? 0 : 1 + max(v[n + 1], v[n - 1]) - v[n];
        if (vcnt[n - 2] > vcnt[n - 3])
        {
            dp[n] = inc + are_mama_kop(n - 2, v);
            vcnt[n] = 1 + vcnt[n - 2];
        }
        else if (vcnt[n - 2] < vcnt[n - 3])
        {
            dp[n] = inc + are_mama_kop(n - 3, v);
            vcnt[n] = 1 + vcnt[n - 3];
        }
        else
        {
            dp[n] = inc + min(are_mama_kop(n - 2, v), are_mama_kop(n - 3, v));
            vcnt[n] = 1 + vcnt[n - 2];
        }
    }
    return dp[n];
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    fill(dp, dp + 100008, -1);
    cin >> n;
    vector<ll> v(n + 1);
    v[0] = -1;
    for (i = 1; i <= n; i++)
        cin >> v[i];
    dp[0] = INT32_MAX;
    dp[1] = INT32_MAX;
    dp[2] = v[2] > max(v[1], v[3]) ? 0 : 1 + max(v[1], v[3]) - v[2];
    vcnt[2] = 1;
    if (n > 3)
    {
        dp[3] = v[3] > max(v[2], v[4]) ? 0 : 1 + max(v[2], v[4]) - v[3];
        vcnt[3] = 1;
    }
    for (i = 4; i <= n - 1; i++)
    {
        are_mama_kop(i, v);
    }
    if (vcnt[n - 1] > vcnt[n - 2])
        cout << dp[n - 1] << endl;
    else if (vcnt[n - 1] < vcnt[n - 2])
        cout << dp[n - 2] << endl;
    else
        cout << min(dp[n - 1], dp[n - 2]) << endl;
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