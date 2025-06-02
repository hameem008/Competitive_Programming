#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I)
{
    ll i, j, k, a, b, c, d, m, n, p;
    // solve stars
    cin >> a >> b;
    cin >> c >> d;
    if (((a < b) && (b < d)) && ((a < c) && (c < d)))
        cout << "YES" << endl;
    else if (((c < a) && (a < b)) && ((c < d) && (d < b)))
        cout << "YES" << endl;
    else if (((d < c) && (c < a)) && ((d < b) && (b < a)))
        cout << "YES" << endl;
    else if (((b < d) && (d < c)) && ((b < a) && (a < c)))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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