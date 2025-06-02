#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I)
{
    ll i, j, k, b, m, n, p;
    // solve stars
    cin >> n;
    if (n % 2 == 0)
    {
        ll x = (n - 2) / 2;
        ll a = x + 2;
        for (i = x + 1; i <= x + n + 1; i++)
        {
            if (i != x + a)
                cout << i << gap;
        }
        cout << endl;
    }
    else
    {
        ll a = (n + 3) / 2;
        for (i = a; i <= a + n + 1; i++)
        {
            if (i != n + 1 && i != n + 2)
                cout << i << gap;
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

    ll t = 1;
    cin >> t;
    for (int I = 1; I <= t; I++)
        solve(I);
    return 0;
}