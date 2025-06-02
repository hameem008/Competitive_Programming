#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

void solve(int I, int T)
{
    ll i, j, k = 0, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> m;
    p = m + 1;
    for (i = 31; i >= 0; i--)
    {
        ll ni = n & (1 << i), pi = p & (1 << i);
        if (ni == 0 && pi != 0)
        {
            k = k ^ (1 << i);
        }
        else if (ni != 0 && pi == 0)
        {
            break;
        }
    }
    cout << k << endl;
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