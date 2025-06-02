#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    ll x1, x2, y1, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    n++;
    ll lv1, lv2;
    if (y1 >= x1 && y1 <= n - x1)
    {
        lv1 = min(x1, n - x1);
    }
    else
    {
        lv1 = min(y1, n - y1);
    }
    if (y2 >= x2 && y2 <= n - x2)
    {
        lv2 = min(x2, n - x2);
    }
    else
    {
        lv2 = min(y2, n - y2);
    }
    cout << abs(lv1 - lv2) << endl;
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