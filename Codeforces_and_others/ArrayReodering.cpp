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
    vector<ll> odds, evens;
    for (auto x : v)
    {
        if (x % 2 == 0)
            evens.push_back(x);
        else
            odds.push_back(x);
    }
    sort(evens.begin(), evens.end());
    sort(odds.begin(), odds.end());
    vector<ll> dum;
    for (auto x : evens)
    {
        dum.push_back(x);
    }
    for (auto x : odds)
    {
        dum.push_back(x);
    }
    ll ans = 0;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (__gcd(dum[i], 2 * dum[j]) > 1)
                ans++;
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