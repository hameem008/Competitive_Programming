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
    cin >> n >> m;
    ll limit1 = sqrt(n);
    ll limit2 = sqrt(m);
    ll ans = 0;
    for (i = 1; i <= limit1; i++)
    {
        for (j = 1; j <= limit2; j++)
        {
            if (__gcd(i, j) == 1)
                ans += min(n / i, m / j) / (i + j);
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