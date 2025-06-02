#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> m;
    char grid[n][m];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            cin >> grid[i][j];
    }
    set<ll> s;
    bool white, black;
    white = black = false;
    for (i = 0; i < n; i++)
    {
        if (grid[i][0] == 'W')
            white = true;
        else if (grid[i][0] == 'B')
            black = true;
    }
    if (white && black)
    {
        s.insert(0);
    }
    else if (white)
    {
        s.insert(1);
    }
    else if (black)
    {
        s.insert(2);
    }
    white = black = false;
    for (i = 0; i < n; i++)
    {
        if (grid[i][m - 1] == 'W')
            white = true;
        else if (grid[i][m - 1] == 'B')
            black = true;
    }
    if (white && black)
    {
        s.insert(0);
    }
    else if (white)
    {
        s.insert(1);
    }
    else if (black)
    {
        s.insert(2);
    }
    white = black = false;
    for (i = 0; i < m; i++)
    {
        if (grid[0][i] == 'W')
            white = true;
        else if (grid[0][i] == 'B')
            black = true;
    }
    if (white && black)
    {
        s.insert(0);
    }
    else if (white)
    {
        s.insert(1);
    }
    else if (black)
    {
        s.insert(2);
    }
    white = black = false;
    for (i = 0; i < m; i++)
    {
        if (grid[n - 1][i] == 'W')
            white = true;
        else if (grid[n - 1][i] == 'B')
            black = true;
    }
    if (white && black)
    {
        s.insert(0);
    }
    else if (white)
    {
        s.insert(1);
    }
    else if (black)
    {
        s.insert(2);
    }
    if (s.count(1) != 0 && s.count(2) != 0)
        flag = false;
    else
        flag = true;
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