#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    // solve starts
    cin >> n;
    if (n % 2 == 0)
    {
        cout << "YES" << endl;
        for (i = 1; i <= n; i++)
        {
            if (i % 2 != 0)
                cout << 1 << gap;
            else
                cout << -1 << gap;
        }
        cout << endl;
    }
    else if (n != 3)
    {
        cout << "YES" << endl;
        for (i = 1; i <= n; i++)
        {
            if (i % 2 != 0)
                cout << n / 2 - 1 << gap;
            else
                cout << -n / 2 << gap;
        }
        cout << endl;
    }
    else
        cout << "NO" << endl;
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