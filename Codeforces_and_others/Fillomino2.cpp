#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

ll grid[508][508] = {1000};
ll cnt;

void grid_dfs(ll i, ll j, ll row, ll column, vector<bool> &isDone)
{
    if (cnt == grid[i][j])
        return;

    if (!isDone[grid[i][j - 1]])
    {
        cnt++;
        grid[i][j - 1] = grid[i][j];
        grid_dfs(i, j - 1, row, column, isDone);
    }
    else if (!isDone[grid[i + 1][j]])
    {
        cnt++;
        grid[i + 1][j] = grid[i][j];
        grid_dfs(i + 1, j, row, column, isDone);
    }
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    vector<bool> isDone(1001, false);
    isDone[0] = true;
    cin >> n;
    vector<ll> v(n + 1);
    for (i = 1; i <= n; i++)
        cin >> v[i];
    for (i = 1; i <= n; i++)
    {
        cnt = 1;
        grid[i][i] = v[i];
        grid_dfs(i, i, n, n, isDone);
        isDone[v[i]] = true;
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= i; j++)
        {
            cout << grid[i][j] << gap;
        }
        cout << endl;
    }
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (ll i = 0; i < 508; i++)
    {
        grid[i][0] = 0;
    }
    for (ll i = 1; i < 508; i++)
    {
        for (ll j = 1; j < 508; j++)
        {
            grid[i][j] = 1001;
        }
    }
    ll T = 1;
    // cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}