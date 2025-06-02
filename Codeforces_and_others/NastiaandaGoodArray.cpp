#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;
const ll prime = 1e9 + 7;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<ll> v(n + 1);
    vector<vector<ll>> ans;
    for (i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    for (i = 1; i < n; i++)
    {
        ll x, y;
        x = min(v[i], v[i + 1]);
    }
    cout << ans.size() << endl;
    for (auto x : ans)
    {
        for (auto y : x)
            cout << y << gap;
        cout << endl;
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