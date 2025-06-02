#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

ll grid[1008][1008] = {15};
bool isVisited[1008][1008];
ll cnt;
void grid_dfs(ll i, ll j, ll row, ll column)
{
    if (i < 1 || i > row || j < 1 || j > column || isVisited[i][j])
        return;
    isVisited[i][j] = true;
    cnt++;
    if (!((grid[i][j] & 2) && (grid[i + 1][j] & 8))) // south
        grid_dfs(i + 1, j, row, column);

    if (!((grid[i][j] & 8) && (grid[i - 1][j] & 2))) // north
        grid_dfs(i - 1, j, row, column);

    if (!((grid[i][j] & 4) && (grid[i][j + 1] & 1))) // east
        grid_dfs(i, j + 1, row, column);

    if (!((grid[i][j] & 1) && (grid[i][j - 1] & 4))) // west
        grid_dfs(i, j - 1, row, column);
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> m;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            cin >> grid[i][j];
            isVisited[i][j] = false;
        }
    }
    vector<ll> ans;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            if (!isVisited[i][j])
            {
                cnt = 0;
                grid_dfs(i, j, n, m);
                ans.push_back(cnt);
            }
        }
    }
    sort(ans.rbegin(), ans.rend());
    for (auto x : ans)
        cout << x << gap;
    cout << endl;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            grid[i][j] = 15;
            isVisited[i][j] = false;
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