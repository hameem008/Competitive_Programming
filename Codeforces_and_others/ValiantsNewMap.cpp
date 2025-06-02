#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

void grid_presum(ll row, ll column, vector<vector<ll>> &presum)
{
    for (ll i = 2; i <= row; i++)
    {
        presum[i][1] = presum[i][1] + presum[i - 1][1];
    }
    for (ll i = 2; i <= column; i++)
    {
        presum[1][i] = presum[1][i] + presum[1][i - 1];
    }
    for (ll i = 2; i <= row; i++)
    {
        for (ll j = 2; j <= column; j++)
        {
            presum[i][j] = presum[i][j] + presum[i - 1][j] + presum[i][j - 1] - presum[i - 1][j - 1];
        }
    }
}

bool pf(ll mid, vector<vector<ll>> &matrix, ll n, ll m)
{
    mid--;
    vector<vector<ll>> dum_matrix(n + 1, vector<ll>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (matrix[i][j] >= mid + 1)
                dum_matrix[i][j] = 1;
        }
    }
    grid_presum(n, m, dum_matrix);
    for (int i = 1; i + mid <= n; i++)
    {
        for (int j = 1; j + mid <= m; j++)
        {
            if (dum_matrix[i + mid][j + mid] + dum_matrix[i - 1][j - 1] - dum_matrix[i + mid][j - 1] - dum_matrix[i - 1][j + mid] == (mid + 1) * (mid + 1))
                return true;
        }
    }
    return false;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> m;
    vector<vector<ll>> matrix(n + 1, vector<ll>(m + 1));
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            cin >> matrix[i][j];
        }
    }
    ll hi = n, lo = 1, mid;
    while (hi - lo > 1)
    {
        mid = (hi + lo) / 2;
        if (pf(mid, matrix, n, m))
            lo = mid;
        else
            hi = mid - 1;
    }
    if (pf(hi, matrix, n, m))
        cout << hi << endl;
    else
        cout << lo << endl;
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