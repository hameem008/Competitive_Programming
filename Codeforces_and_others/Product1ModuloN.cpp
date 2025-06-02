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
    cin >> n;
    ll mul = 1;
    set<ll> s;
    for (i = 1; i <= n - 1; i++)
    {
        if (__gcd(n, i) == 1)
        {
            mul *= i;
            mul %= n;
            s.insert(i);
        }
    }
    if (mul != 1)
    {
        s.erase(mul);
    }
    cout << s.size() << endl;
    for (auto x : s)
        cout << x << gap;
    cout << endl;
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll T = 1;
    // cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}