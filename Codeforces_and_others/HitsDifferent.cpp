#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

vector<pair<ll, ll>> vp(2024);
vector<ll> dp(2023 * 1012 + 1, 0);

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    cout << dp[n] << endl;
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vp[1].first = vp[1].second = 1;
    vp[2].first = 2;
    vp[2].second = 3;
    for (ll row = 3; row <= 2023; row++)
    {
        vp[row].first = vp[row - 1].first + row - 1;
        vp[row].second = vp[row].first + row - 1;
    }
    ll cur_row = 2;
    dp[1] = 1;
    for (ll i = 2; i <= 2023 * 1012; i++)
    {
        if (i == vp[cur_row].first)
        {
            dp[i] = dp[i - cur_row + 1] + i * i;
        }
        else if (i == vp[cur_row].second)
        {
            dp[i] = dp[i - cur_row] + i * i;
            cur_row++;
        }
        else
        {
            dp[i] = dp[i - cur_row] + dp[i - cur_row + 1] - dp[i - 2 * (cur_row - 1)] + i * i;
        }
    }

    ll T = 1;
    cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}