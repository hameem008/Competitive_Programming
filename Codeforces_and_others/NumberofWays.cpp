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
    cin >> n;
    vector<ll> v(n + 1);
    vector<ll> prefix_sum(n + 1, 0);
    for (i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    for (i = 1; i <= n; i++)
    {
        prefix_sum[i] = prefix_sum[i - 1] + v[i];
    }
    if (prefix_sum[n] % 3 != 0)
    {
        cout << 0 << endl;
        return;
    }
    vector<ll> from_first, from_last;
    for (i = 2; i <= n - 1; i++)
    {
        if (prefix_sum[i - 1] * 2 == prefix_sum[n] - prefix_sum[i - 1])
            from_first.push_back(i);
        if (prefix_sum[i] == (prefix_sum[n] - prefix_sum[i]) * 2)
            from_last.push_back(i);
    }
    ll ans = 0;
    for (auto x : from_first)
    {
        ans += from_last.end() - lower_bound(from_last.begin(), from_last.end(), x);
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
    // cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}