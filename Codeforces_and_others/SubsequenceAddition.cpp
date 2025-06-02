#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

ll dp[2e5 + 1];

bool calc(ll n)
{
    if (dp[n] == 1)
        return true;
    else if (dp[n] == 0)
        return false;
    for (int i = 1; i <= n - 1; i++)
    {
        if (calc(i) && calc(n - i))
        {
            dp[n] = 1;
            break;
        }
    }
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    vector<ll> hash(2e5 + 1, 0);
    for (auto x : v)
        hash[x]++;
    for (i = 1; i <= 2e5; i++)
    {
        if (hash[i])
            dp[i] = -1;
    }
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