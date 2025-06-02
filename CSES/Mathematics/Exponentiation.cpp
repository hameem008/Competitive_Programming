#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;
const ll MOD = 1e9 + 7;

ll binExp(ll a, ll b, ll mod)
{
    if (b == 0)
        return 1;
    ll rec = binExp(a, b / 2, mod);
    if (b % 2 != 0)
        return ((a % mod) * (rec % mod) % mod) * (rec % mod) % mod;
    else
        return (rec % mod) * (rec % mod) % mod;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> a >> b;
    cout << binExp(a, b, MOD) << endl;
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