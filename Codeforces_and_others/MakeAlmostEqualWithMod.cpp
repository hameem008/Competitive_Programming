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
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    ll gc = 0;
    for (auto x : v)
    {
        gc = __gcd(gc, x);
    }
    while (1)
    {
        set<ll> s;
        for (auto x : v)
        {
            s.insert(x % gc);
        }
        if (s.size() == 2)
        {
            cout << gc << endl;
            break;
        }
        gc *= 2;
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