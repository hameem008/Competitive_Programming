#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

void solve(int I, int T)
{
    ll i, j, k, l, r, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> q;
    vector<ll> v(n + 1, 0);
    ll sum = 0;
    vector<ll> presum(n + 1, 0);
    for (i = 1; i <= n; i++)
        cin >> v[i];
    for (i = 1; i <= n; i++)
    {
        sum += v[i];
        presum[i] = sum;
    }
    for (i = 0; i < q; i++)
    {
        cin >> l >> r >> k;
        ll cng = (r - l + 1) * k;
        ll newsum;
        newsum = sum - (presum[r] - presum[l - 1]) + cng;
        if (newsum % 2 != 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
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