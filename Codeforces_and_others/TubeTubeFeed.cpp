#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, t, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> t;
    vector<ll> va(n), vb(n);
    for (auto &x : va)
        cin >> x;
    for (auto &x : vb)
        cin >> x;
    for (i = 0; i < n; i++)
        va[i] += i;
    ll ans = 0;
    ll ind = -2;
    for (i = 0; i < n; i++)
    {
        if (va[i] <= t)
        {
            if (vb[i] > ans)
            {
                ans = vb[i];
                ind = i;
            }
        }
    }
    cout << ind + 1 << endl;
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