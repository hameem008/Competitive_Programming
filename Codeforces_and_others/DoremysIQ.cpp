#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> q;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    ll iq = 0;
    vector<ll> ans(n, 0);
    for (i = n - 1; i >= 0; i--)
    {
        if (iq < v[i] && iq < q)
        {
            iq++;
            ans[i] = 1;
        }
        else if (iq >= v[i])
        {
            ans[i] = 1;
        }
    }
    for (auto x : ans)
        cout << x;
    cout << endl;
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