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
ll query(pair<ll, ll> p1, pair<ll, ll> p2)
{
    return presum[p2.first][p2.second] + presum[p1.first - 1][p1.second - 1] - presum[p2.first][p1.second - 1] - presum[p1.first - 1][p2.second];
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> m >> k;
    ll grid[n + 1][m + 1];
    ll sum_w = 0, sum_wo = 0;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            cin >> grid[i][j];
        }
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            char ch;
            cin >> ch;
            presum[i][j] = int(ch - 48);
            if (presum[i][j] == 0)
                sum_wo += grid[i][j];
            else if (presum[i][j] == 1)
                sum_w += grid[i][j];
        }
    }
    ll dif = abs(sum_wo - sum_w);
    if (!dif)
    {
        cout << "YES" << endl;
        return;
    }
    grid_presum(n, m);
    vector<ll> v;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            p = i + k - 1;
            q = j + k - 1;
            if (p <= n && q <= m)
            {
                ll cnt = query({i, j}, {p, q});
                v.push_back(abs(2 * cnt - k * k));
            }
        }
    }
    ll gc = 0;
    for (auto x : v)
        gc = __gcd(gc, x);
    if (gc == 0 || dif % gc != 0)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
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