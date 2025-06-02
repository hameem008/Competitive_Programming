#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

int v[1001][1001];
int minimum[1001][1001];
int maximum[1001][1001];

ll dpmin(ll n, ll m)
{
    if (minimum[n][m] != INT32_MAX)
        return minimum[n][m];
    ll a = INT32_MAX;
    if (m - 1 > 0)
        a = dpmin(n, m - 1);
    ll b = INT32_MAX;
    if (n - 1 > 0)
        b = dpmin(n - 1, m);
    minimum[n][m] = v[n][m] + min(a, b);
    return minimum[n][m];
}

ll dpmax(ll n, ll m)
{
    if (maximum[n][m] != INT32_MIN)
        return maximum[n][m];
    ll a = INT32_MIN;
    if (m - 1 > 0)
        a = dpmax(n, m - 1);
    ll b = INT32_MIN;
    if (n - 1 > 0)
        b = dpmax(n - 1, m);
    maximum[n][m] = v[n][m] + max(a, b);
    return maximum[n][m];
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    // solve starts
    cin >> n >> m;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            cin >> v[i][j];
        }
    }
    if ((n + m) % 2 == 0)
    {
        cout << "NO" << endl;
        return;
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            minimum[i][j] = INT32_MAX;
        }
    }
    minimum[1][1] = v[1][1];
    a = dpmin(n, m);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            maximum[i][j] = INT32_MIN;
        }
    }
    maximum[1][1] = v[1][1];
    b = dpmax(n, m);
    if (0 <= b && 0 >= a)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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