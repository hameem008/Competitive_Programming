#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

ll dp[100000 + 10];
vector<ll> v(1e5 + 10);

ll jump(ll n)
{
    if (n == 1)
        return 0;
    else if (n == 2)
        return abs(v[1] - v[2]);
    if (dp[n] == -1)
        dp[n] = min(jump(n - 1) + abs(v[n] - v[n - 1]), jump(n - 2) + abs(v[n] - v[n - 2]));
    return dp[n];
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    fill(dp, dp + 100000 + 10, -1);
    for (i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    cout << jump(n) << endl;
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