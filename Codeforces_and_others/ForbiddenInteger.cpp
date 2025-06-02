#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q, x;
    bool flag;
    // solve starts
    cin >> n >> k >> x;
    if (x != 1)
    {
        cout << "YES" << endl;
        cout << n << endl;
        for (i = 1; i <= n; i++)
        {
            cout << 1 << gap;
        }
        cout << endl;
    }
    else if (k == 1)
    {
        cout << "NO" << endl;
    }
    else if (k == 2)
    {
        if (n % 2 == 0)
        {
            ll limit = n / 2;
            cout << "YES" << endl;
            cout << limit << endl;
            while (limit--)
                cout << 2 << gap;
            cout << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    else if (k >= 3)
    {
        cout << "YES" << endl;
        if (n % 2 == 0)
        {
            ll limit = n / 2;
            cout << limit << endl;
            while (limit--)
                cout << 2 << gap;
            cout << endl;
        }
        else
        {
            n -= 3;
            ll limit = n / 2;
            cout << limit + 1 << endl;
            cout << 3 << gap;
            while (limit--)
                cout << 2 << gap;
            cout << endl;
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
    cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}