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
    cin >> n;
    vector<ll> fq(1e5 + 1, 0), dp_first(1e5 + 1, 0), dp_last(1e5 + 1, 0), dp(1e5 + 1, 0);
    for (i = 0; i < n; i++)
    {
        cin >> a;
        fq[a]++;
    }
    dp_first[1] = fq[1] * 1;
    for (i = 2; i <= 1e5; i++)
    {
        dp_first[i] = max(dp_first[i - 1], dp_first[i - 2] + fq[i] * i);
    }
    dp_last[1e5] = fq[1e5] * (1e5);
    dp_last[1e5 - 1] = max(dp_last[1e5], fq[1e5 - 1] * (ll)(1e5 - 1));
    for (i = 1e5 - 2; i >= 0; i--)
    {
        dp_last[i] = max(dp_last[i + 1], dp_last[i + 2] + fq[i] * i);
    }
    for (i = 1; i <= 1e5; i++)
    {
        a = 0, b = 0;
        if (i - 2 > 0)
        {
            a += dp_first[i - 2];
        }
        if (i + 2 < 1e5 + 1)
        {
            a += dp_last[i + 2];
        }
        if (i - 1 > 0)
        {
            b += dp_first[i - 1];
        }
        if (i + 1 < 1e5 + 1)
        {
            b += dp_last[i + 1];
        }
        dp[i] = max(a + fq[i] * i, b);
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
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