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
    cin >> n >> k;
    vector<ll> v;
    v.push_back(0);
    for (i = 0; i < n; i++)
    {
        cin >> a;
        v.push_back(a);
    }
    for (i = 0; i <= 40; i++)
    {
        v.push_back(0);
    }
    vector<ll> presum(v.size(), 0);
    for (i = 1; i < presum.size(); i++)
    {
        presum[i] = presum[i - 1] + v[i];
    }
    ll ans = 0;
    for (i = 0; i <= n; i++)
    {
        a = presum[i] - i * k;
        b = 0;
        for (j = 1; j < 32; j++)
        {
            b += v[i + j] / powl(2, j );
        }
        ans = max(ans, a + b);
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