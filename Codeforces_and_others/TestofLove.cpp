#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

ll n, m, k;
string str;
vector<bool> dp;
vector<bool> done;

bool rec(ll N, ll K)
{
    if (N == 0)
    {
        if (K >= 0)
            dp[N] = true;
        else
            dp[N] = false;
        return dp[N];
    }
    if (!dp[N])
    {
        if (str[N] == 'C')
            return dp[N];
        for (int i = 1; i <= m; i++)
        {
            if (N - i < 0)
                break;
            if (str[N - i] == 'L')
            {
                dp[N] = dp[N] | rec(N - i, K);
                return dp[N];
            }
        }
        if (str[N - 1] == 'W')
            dp[N] = dp[N] | rec(N - 1, K - 1);
    }
    return dp[N];
}

void solve(int I, int T)
{
    ll i, j, a, b, c, d, p, q;
    bool flag;
    // solve starts
    cin >> n >> m >> k;
    cin >> str;
    str.push_back('W');
    n++;
    reverse(str.begin(), str.end());
    str.push_back('L');
    reverse(str.begin(), str.end());
    dp.clear();
    dp.assign(n + 1, false);
    flag = rec(n, k);
    flag ? cout << "YES" << endl : cout << "NO" << endl;
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