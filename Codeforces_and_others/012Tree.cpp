#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> a >> b >> c;
    ll ans = 0;
    if (a == 0)
    {
        if (c == 1)
        {
            ans = b + 1;
        }
        else
        {
            ans = -1;
        }
    }
    else
    {
        ll bareHands = 0;
        for (i = 0; i < 32; i++)
        {
            if (a >= powl(2, i))
            {
                a -= powl(2, i);
                bareHands = powl(2, i + 1);
                ans++;
            }
            else
                break;
        }
        if (a + b > 0)
        {
            if (a + b >= bareHands)
            {
                ans++;
                b -= (bareHands - a);
                bareHands = bareHands + a;
                a = 0;
                ans += ceil(b * 1.0 / bareHands);
            }
            else
            {
                ans++;
                b = 0;
                bareHands = bareHands + a;
                a = 0;
            }
        }
        if (bareHands == c)
            ans++;
        else
            ans = -1;
    }
    if (ans != -1)
        ans--;
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