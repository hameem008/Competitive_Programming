#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;
const ll mod = 1e9 + 7;

ll lcm(ll a, ll b)
{
    return a * b / __gcd(a, b);
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    ll mul = 1, ans = 0;
    for (i = 2; i <= 50; i++)
    {
        ans += (((n / mul - n / lcm(mul, i)) % mod) * i) % mod;
        ans %= mod;
        mul = lcm(mul, i);
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