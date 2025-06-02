#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

ll dp[(ll)1e6 + 8];

vector<ll> extract_digits(ll n)
{
    vector<ll> v;
    while (n)
    {
        v.push_back(n % 10);
        n /= 10;
    }
    return v;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    for (i = 1; i <= 9; i++)
    {
        dp[i] = 1;
    }
    for (i = 10; i <= n; i++)
    {
        dp[i] = infinite;
        for (auto x : extract_digits(i))
        {
            dp[i] = min(dp[i], dp[i - x] + 1);
        }
    }
    cout << dp[n] << endl;
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