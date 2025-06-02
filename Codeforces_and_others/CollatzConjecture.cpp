#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q, x, y;
    bool flag;
    // solve starts
    cin >> n >> k >> q;
    if (k == 1)
    {
        cout << 1 << endl;
        return;
    }

    n++, q--;
    while (n % k == 0)
    {
        n /= k;
    }

    while (q)
    {
        if ((k - n % k) <= q)
        {
            q -= k - n % k;
            n += k - n % k;
        }
        else
        {
            n += q;
            q = 0;
        }
        while (n % k == 0)
        {
            n /= k;
        }
        if (n == 1)
            break;
    }
    if (q)
    {
        n += q % (k - 1);
    }
    cout << n << endl;
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