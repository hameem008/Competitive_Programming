#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

bool dp[2][(ll)1e5 + 1];

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> k;
    vector<ll> v(n + 1);
    for (i = 1; i <= n; i++)
        cin >> v[i];
    for (j = 0; j <= k; j++)
    {
        bool var = false;
        for (i = 1; i <= n; i++)
        {
            if (j - v[i] >= 0 && dp[1][j - v[i]] == false)
                var = true;
        }
        dp[0][j] = var;

        var = false;
        for (i = 1; i <= n; i++)
        {
            if (j - v[i] >= 0 && dp[0][j - v[i]] == false)
                var = true;
        }
        dp[1][j] = var;
    }
    if (dp[0][k])
        cout << "First" << endl;
    else
        cout << "Second" << endl;
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