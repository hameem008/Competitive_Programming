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
    cin >> n;
    ll sum = 0;
    for (i = 1; i <= n; i++)
    {
        sum += i * (2 * i - 1);
    }
    cout << sum << gap << 2 * n << endl;
    for (i = n; i >= 1; i--)
    {
        cout << 2 << gap << i << gap;
        for (k = 1; k <= n; k++)
            cout << k << gap;
        cout << endl;
        cout << 1 << gap << i << gap;
        for (k = 1; k <= n; k++)
            cout << k << gap;
        cout << endl;
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