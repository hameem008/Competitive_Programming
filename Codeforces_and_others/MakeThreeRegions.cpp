#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<vector<char>> grid(2, vector<char>(n + 2));
    grid[0][0] = grid[1][0] = grid[0][n + 1] = grid[1][n + 1] = '.';
    char ch;
    for (i = 1; i <= n; i++)
    {
        cin >> ch;
        grid[0][i] = ch;
    }
    for (i = 1; i <= n; i++)
    {
        cin >> ch;
        grid[1][i] = ch;
    }
    ll diya = 0;
    for (i = 1; i <= n; i++)
    {
        if (grid[0][i - 1] == 'x' && grid[0][i] == '.' && grid[0][i + 1] == 'x')
        {
            if (grid[1][i - 1] == '.' && grid[1][i] == '.' && grid[1][i + 1] == '.')
                diya++;
        }
        if (grid[1][i - 1] == 'x' && grid[1][i] == '.' && grid[1][i + 1] == 'x')
        {
            if (grid[0][i - 1] == '.' && grid[0][i] == '.' && grid[0][i + 1] == '.')
                diya++;
        }
    }
    cout << diya << endl;
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