#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    map<ll, ll> mp;
    for (auto x : v)
        mp[x]++;
    ll t = 0, s = 0;
    for (auto x : mp)
    {
        if (x.second == 1)
            s++;
        else
            t++;
    }
    cout << t + (s % 2 == 0 ? s / 2 : s / 2 + 1) << endl;
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