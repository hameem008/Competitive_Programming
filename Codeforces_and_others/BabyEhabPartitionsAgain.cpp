#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

ll dp[101][100001];

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<ll> v(n + 1, 0);
    for (i = 1; i <= n; i++)
        cin >> v[i];
    ll sum = 0, ind = 0;
    for (i = 1; i <= n; i++)
    {
        sum += v[i];
        if (v[i] % 2 != 0)
            ind = i;
    }
    if (sum % 2 != 0)
    {
        cout << 0 << endl;
    }
    else
    {
        for (i = 0; i <= sum / 2; i++)
        {
            dp[0][i] = 0;
        }
        for (i = 0; i <= n; i++)
        {
            dp[i][0] = 1;
        }
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= sum / 2; j++)
            {
                dp[i][j] = 0;
                if (j >= v[i] && i > 0)
                {
                    dp[i][j] |= dp[i - 1][j - v[i]];
                }
                if (i > 0)
                {
                    dp[i][j] |= dp[i - 1][j];
                }
            }
        }
        if (!dp[n][sum / 2])
        {
            cout << 0 << endl;
        }
        else if (ind)
        {
            cout << 1 << endl;
            cout << ind << endl;
        }
        else
        {
            while (!ind)
            {
                for (i = 1; i <= n; i++)
                {
                    v[i] /= 2;
                    if (v[i] % 2 != 0)
                    {
                        ind = i;
                        break;
                    }
                }
            }
            cout << 1 << endl;
            cout << ind << endl;
        }
    }
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