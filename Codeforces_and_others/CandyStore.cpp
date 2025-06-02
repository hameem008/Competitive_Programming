#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

ll LCM(ll a, ll b)
{
    return a * b / __gcd(a, b);
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<ll> amount(n), price(n);
    for (i = 0; i < n; i++)
    {
        cin >> amount[i] >> price[i];
    }
    ll ans = 1;
    ll lcmOfPrice = price[0], gcdOfAmount = amount[0] * price[0];
    for (i = 0; i < n; i++)
    {
        lcmOfPrice = LCM(lcmOfPrice, price[i]);
        gcdOfAmount = __gcd(gcdOfAmount, amount[i] * price[i]);
        if (gcdOfAmount % lcmOfPrice != 0)
        {
            ans++;
            lcmOfPrice = price[i], gcdOfAmount = amount[i] * price[i];
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