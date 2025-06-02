#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

ll lcm(ll a, ll b)
{
    return a * b / __gcd(a, b);
}

vector<ll> lcc;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    ll ans = 1;
    for (i = 1; i < lcc.size(); i++)
    {
        if (n % lcc[i] == 0)
            ans = i;
        else
            break;
    }
    cout << ans << endl;
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lcc.push_back(0);
    ll mul = 1;
    for (int i = 1; i <= 1e6; i++)
    {
        mul = lcm(mul, i);
        if (mul < 0)
            break;
        lcc.push_back(mul);
    }
    ll T = 1;
    cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}