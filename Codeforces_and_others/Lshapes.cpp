#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

char grid[51][51];
bool isVisited[51][51];
vector<pair<ll, ll>> vp;

void grid_dfs(ll i, ll j, ll row, ll column)
{
    if (i < 1 || i > row || j < 1 || j > column || isVisited[i][j] == true || grid[i][j] == '.')
        return;
    isVisited[i][j] = true;
    vp.push_back({i, j});
    // adjacent cell
    grid_dfs(i + 1, j, row, column);
    grid_dfs(i - 1, j, row, column);
    grid_dfs(i, j + 1, row, column);
    grid_dfs(i, j - 1, row, column);
    // diagonal cell
    grid_dfs(i + 1, j + 1, row, column);
    grid_dfs(i - 1, j + 1, row, column);
    grid_dfs(i - 1, j - 1, row, column);
    grid_dfs(i + 1, j - 1, row, column);
}

bool check(pair<ll, ll> mid, pair<ll, ll> ud, pair<ll, ll> lr)
{
    if (mid.first == lr.first && mid.second == ud.second)
        return true;
    return false;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag = true;
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
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            if (!isVisited[i][j] && grid[i][j] == '*')
            {
                vp.clear();
                grid_dfs(i, j, n, m);
                if (vp.size() != 3)
                    flag = false;
                else
                {
                    bool temp_flag = false;
                    temp_flag |= check(vp[0], vp[1], vp[2]);
                    temp_flag |= check(vp[0], vp[2], vp[1]);
                    temp_flag |= check(vp[1], vp[0], vp[2]);
                    temp_flag |= check(vp[1], vp[2], vp[0]);
                    temp_flag |= check(vp[2], vp[0], vp[1]);
                    temp_flag |= check(vp[2], vp[1], vp[0]);
                    if (!temp_flag)
                        flag = false;
                }
            }
        }
    }
    flag ? cout << "YES" << endl : cout << "NO" << endl;
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