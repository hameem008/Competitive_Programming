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
    cin >> n >> p;
    vector<ll> v(n + 1, 0);
    for (i = 1; i <= n; i++)
        cin >> v[i];
    vector<ll> presum(n + 1, 0);
    for (i = 1; i <= n; i++)
    {
        presum[i] += presum[i - 1] + v[i];
    }
    vector<ll> max_seg_sum(n + 1, 0);
    for (ll length = 1; length <= n; length++)
    {
        ll temp_max = -infinite;
        for (i = 0; i + length <= n; i++)
        {
            temp_max = max(temp_max, presum[i + length] - presum[i]);
        }
        max_seg_sum[length] = temp_max;
    }
    vector<ll> ans_v;
    for (k = 0; k <= n; k++)
    {
        ll ans = 0;
        for (i = 0; i <= n; i++)
        {
            ans = max(ans, max_seg_sum[i] + (ll)min(k, i) * p);
        }
        ans_v.push_back(ans);
    }
    for (auto x : ans_v)
        cout << x << gap;
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