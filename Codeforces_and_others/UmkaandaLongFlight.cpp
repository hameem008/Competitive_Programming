#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;
vector<ll> fibonacci(46, 0);

bool rec(ll row, ll column, ll i, ll j)
{
    if (row > column)
    {
        if (i + column <= row)
            return rec(row - column, column, i, j);
        else if (i - column >= 1)
            return rec(row - column, column, i - column, j);
        else
            return false;
    }
    else if (row < column)
    {
        if (j + row <= column)
            return rec(row, column - row, i, j);
        else if (j - row >= 1)
            return rec(row, column - row, i, j - row);
        else
            return false;
    }
    else
        return true;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> i >> j;
    ll row = fibonacci[n], column = fibonacci[n + 1];
    rec(row, column, i, j) ? cout << "YES" << endl : cout << "NO" << endl;
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fibonacci[0] = fibonacci[1] = 1;
    for (ll i = 2; i <= 45; i++)
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];

    ll T = 1;
    cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}