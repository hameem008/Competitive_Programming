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
    ll x, y;
    cin >> x >> y;
    a = max(x, y) - 1;
    if (a * a % 2 != 0)
    {
        if (x == y)
            cout << a * a + x << endl;
        else if (x < y)
            cout << a * a + x << endl;
        else if (x > y)
            cout << (a + 1) * (a + 1) - y + 1 << endl;
    }
    else
    {
        if (x == y)
            cout << a * a + x << endl;
        else if (x < y)
            cout << (a + 1) * (a + 1) - x + 1 << endl;
        else if (x > y)
            cout << a * a + y << endl;
    }
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