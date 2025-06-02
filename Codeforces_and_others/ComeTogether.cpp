#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

ll fun(pair<ll, ll> a, pair<ll, ll> b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    pair<ll, ll> alice, bob, carol;
    cin >> alice.first >> alice.second;
    cin >> bob.first >> bob.second;
    cin >> carol.first >> carol.second;
    if (fun(alice, bob) + fun(alice, carol) == fun(bob, carol))
    {
        cout << 1 << endl;
    }
    else
    {
        ll ans = 0;
        ans = fun(alice, bob) + fun(alice, carol) - fun(bob, carol);
        cout << (ans / 2) + 1 << endl;
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