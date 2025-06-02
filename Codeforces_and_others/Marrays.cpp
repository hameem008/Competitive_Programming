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
    cin >> n >> m;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    vector<ll> fq(m + 1, 0);
    for (auto x : v)
        fq[x % m]++;
    ll ans = 0;
    if (fq[0])
        ans++;
    for (i = 1; i < m; i++)
    {
        a = fq[i];
        b = fq[m - i];
        if (a == 0 && b == 0)
            continue;
        if (i == m - i || a == b)
            ans++;
        else if (a > b)
        {
            a = a - (b + 1);
            ans++;
            ans += a;
        }
        else if (a < b)
        {
            b = b - (a + 1);
            ans++;
            ans += b;
        }
        fq[i] = fq[m - i] = 0;
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