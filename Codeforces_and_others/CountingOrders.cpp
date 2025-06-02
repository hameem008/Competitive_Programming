#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;
ll MOD = 1e9 + 7;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<ll> va(n), vb(n);
    for (auto &x : va)
        cin >> x;
    for (auto &x : vb)
        cin >> x;
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());
    reverse(vb.begin(), vb.end());
    ll ans = 1;
    for (i = 0; i < n; i++)
    {
        ll greater = upper_bound(va.begin(), va.end(), vb[i]) - va.begin();
        ans *= (va.size() - greater);
        ans %= MOD;
        va.pop_back();
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