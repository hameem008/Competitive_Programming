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
    cin >> n;
    ll hi = n, lo = 1, mid, ans;
    while (1)
    {
        mid = (hi + lo) / 2;
        cout << "?" << gap << lo << gap << mid << endl;
        ll cnt = 0;
        ans = -1;
        for (i = lo; i <= mid; i++)
        {
            cin >> a;
            if (a >= lo && a <= mid)
            {
                cnt++;
                ans = a;
            }
        }
        if (cnt == 1)
        {
            break;
        }
        else if (cnt % 2 == 0)
        {
            lo = mid + 1;
        }
        else if (cnt % 2 == 1)
        {
            hi = mid;
        }
    }
    cout << "!" << gap << ans << endl;
    // solve ends
}

int main()
{
    ll T = 1;
    cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}