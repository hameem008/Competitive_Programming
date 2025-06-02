#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag = true;
    // solve starts
    cin >> n;
    vector<ll> v(n);
    for (i = 0; i < n; i++)
    {
        cin >> v[i];
        if (v[i] != 1 && i != 0 && i != n - 1)
            flag = false;
    }
    if (n == 3 && v[1] % 2 != 0)
    {
        cout << -1 << endl;
        return;
    }
    else if (flag)
    {
        cout << -1 << endl;
        return;
    }
    ll ans = 0;
    for (i = 1; i < n - 1; i++)
    {
        v[i] % 2 == 0 ? ans += v[i] / 2 : ans += v[i] / 2 + 1;
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