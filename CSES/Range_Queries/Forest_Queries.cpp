#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

ll presum[1008][1008];
void grid_presum(ll row, ll column)
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

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> q;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            char ch;
            cin >> ch;
            if (ch == '*')
                presum[i][j] = 1;
            else
                presum[i][j] = 0;
        }
    }
    grid_presum(n, n);
    for (i = 0; i < q; i++)
    {
        ll hs, ws, hb, wb;
        cin >> hs >> ws >> hb >> wb;
        hs--, ws--;
        cout << presum[hb][wb] - presum[hb][ws] - presum[hs][wb] + presum[hs][ws] << endl;
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