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
    vector<pair<ll, ll>> vp(n + m + 1, {-1, -1});
    vector<ll> freq(n + m + 1, 0);
    vector<ll> v(n + 1);
    for (i = 1; i <= n; i++)
    {
        cin >> v[i];
        vp[v[i]].first = 0;
        vp[v[i]].second = m;
    }
    for (i = 1; i <= m; i++)
    {
        ll ind, num;
        cin >> ind >> num;

        vp[v[ind]].second = i - 1;
        freq[v[ind]] += vp[v[ind]].second - vp[v[ind]].first + 1;
        vp[v[ind]].first = -1;
        vp[v[ind]].second = -1;

        vp[num].first = i;
        vp[num].second = m;

        v[ind] = num;
    }
    for (i = 1; i <= n + m; i++)
    {
        pair<ll, ll> pp = {-1, -1};
        if (vp[i] != pp)
        {
            freq[i] += vp[i].second - vp[i].first + 1;
        }
    }
    ll ans = 0;
    for (i = 1; i <= n + m; i++)
    {
        ans += freq[i] * m - freq[i] * (freq[i] - 1) / 2;
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