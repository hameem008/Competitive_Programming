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
    cin >> n >> m;
    if (n < 0)
        n *= -1;
    if (m < 0)
        m *= -1;
    ll ans = 0;
    if (n > m)
    {
        ans = m * 2 + 1;
        ans += (n - m - 1) * 2;
    }
    else if (n < m)
    {
        ans = n * 2 + 1;
        ans += (m - n - 1) * 2;
    }
    else
        ans = m * 2;
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