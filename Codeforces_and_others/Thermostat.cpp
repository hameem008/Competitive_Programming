#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I)
{
    ll i, j, k, a, b, m, n, p, l, x, r;
    // solve stars
    cin >> l >> r >> x;
    cin >> a >> b;
    if (a == b)
        cout << 0 << endl;
    else if (abs(a - b) >= x)
        cout << 1 << endl;
    else if (a < b)
    {
        if (a - l >= x)
            cout << 2 << endl;
        else if (r - a >= x && r - b >= x)
            cout << 2 << endl;
        else if (r - a >= x && b - l >= x)
            cout << 3 << endl;
        else
            cout << -1 << endl;
    }
    else if (a > b)
    {
        if (r - a >= x)
            cout << 2 << endl;
        else if (a - l >= x && b - l >= x)
            cout << 2 << endl;
        else if (a - l >= x && r - b >= x)
            cout << 3 << endl;
        else
            cout << -1 << endl;
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