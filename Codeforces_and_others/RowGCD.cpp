#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

void solve(int I, int T)
{
    ll i, j, k, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    ll pre_gcd = 0;
    sort(a.begin(), a.end());
    ll num = a.front();
    for (auto x : a)
        pre_gcd = __gcd(pre_gcd, x - num);
    for (auto x : b)
    {
        cout << __gcd(pre_gcd, x + num) << gap;
    }
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