#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    ll l1, l2, r1, r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;
    ll ans = 0;
    if (k == 1)
    {
        if (l1 >= l2 && r1 <= r2)
        {
            ans += r1 - l1 + 1;
        }
        else if (l2 >= l1 && r2 <= r1)
        {
            ans += r2 - l2 + 1;
        }
        else if (r1 >= l2 && r1 <= r2)
        {
            ans += r1 - l2 + 1;
        }
        else if (l1 >= l2 && l1 <= r2)
        {
            ans += r2 - l1 + 1;
        }
    }
    else
    {
        ll limit = 30;
        while (limit--)
        {
            if (l1 >= l2 && r1 <= r2)
            {
                ans += r1 - l1 + 1;
            }
            else if (l2 >= l1 && r2 <= r1)
            {
                ans += r2 - l2 + 1;
            }
            else if (r1 >= l2 && r1 <= r2)
            {
                ans += r1 - l2 + 1;
            }
            else if (l1 >= l2 && l1 <= r2)
            {
                ans += r2 - l1 + 1;
            }
            l2 = ceil(l2 * 1.0 / k);
            r2 /= k;
        }
    }
    cout << ans << endl;
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