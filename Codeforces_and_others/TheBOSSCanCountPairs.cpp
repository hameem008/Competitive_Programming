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
    vector<pair<ll, ll>> vp(n);
    for (i = 0; i < n; i++)
        cin >> vp[i].first;
    for (i = 0; i < n; i++)
        cin >> vp[i].second;
    sort(vp.begin(), vp.end());
    ll ans = 0;
    for (i = 1; i < 633; i++)
    {
        vector<ll> cnt(n + 1, 0);
        for (auto x : vp)
        {
            a = x.first * i - x.second;
            if (a > 0 && a <= n)
            {
                ans += cnt[a];
            }
            if (x.first == i)
                cnt[x.second]++;
        }
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