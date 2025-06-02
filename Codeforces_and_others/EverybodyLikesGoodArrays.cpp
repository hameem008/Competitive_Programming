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
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    if (n == 1)
        cout << 0 << endl;
    else
    {
        ll odd = 0, even = 0;
        ll ans = 0;
        for (i = 0; i < n - 1; i++)
        {
            if (v[i] % 2 == 0 && v[i + 1] % 2 == 0)
            {
                even++;
            }
            else if (v[i] % 2 == 1 && v[i + 1] % 2 == 1)
            {
                odd++;
            }
            else
            {
                if (odd)
                {
                    ans = ans + odd;
                    odd = 0;
                }
                if (even)
                {
                    ans = ans + even;
                    even = 0;
                }
            }
        }
        if (odd)
        {
            ans = ans + odd;
            odd = 0;
        }
        if (even)
        {
            ans = ans + even;
            even = 0;
        }
        cout << ans << endl;
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