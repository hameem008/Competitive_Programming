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
    vector<ll> v(n + 1, 0);
    for (i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    ll sum = 0;
    vector<ll> presum(n + 1, 0);
    for (i = 0; i <= n; i++)
    {
        sum += v[i];
        presum[i] = sum;
    }
    ll ans = 0;
    for (i = 0; i <= k; i++)
    {
        ans = max(ans, presum[n - (k - i)] - presum[2 * i]);
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