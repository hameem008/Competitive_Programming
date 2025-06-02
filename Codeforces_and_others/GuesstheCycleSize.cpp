#include <bits/stdc++.h>
using namespace std;
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    ll ans;
    for (i = 2; i <= 25; i++)
    {
        cout << "?" << gap << 1 << gap << i << endl;
        cin >> a;
        if (a == -1)
        {
            ans = i - 1;
            break;
        }
        cout << "?" << gap << i << gap << 1 << endl;
        cin >> b;
        if (b == -1)
        {
            ans = i - 1;
            break;
        }
        if (a != b)
        {
            ans = a + b;
            break;
        }
    }
    cout << "!" << gap << ans << endl;
    // solve ends
}

int main()
{
    ll T = 1;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}