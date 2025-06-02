#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long double ll;
const ll infinite = INT64_MAX;

ll fun(ll a, ll b, vector<ll> &v)
{
    ll n = v.size() - 1;
    vector<ll> dum(n + 1);
    for (ll i = 1; i <= n; i++)
    {
        dum[i] = v[i];
    }
    ll d = (v[b] - v[a]) / (b - a);
    ll rep = v[a];
    for (ll i = a - 1; i >= 1; i--)
    {
        rep -= d;
        dum[i] = rep;
    }
    rep = v[a];
    for (ll i = a + 1; i <= n; i++)
    {
        rep += d;
        dum[i] = rep;
    }
    ll cnt = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (abs(dum[i] - v[i]) > 0.00001)
            cnt++;
    }
    return cnt;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<ll> v(n + 1);
    for (i = 1; i <= n; i++)
        cin >> v[i];
    ll ans;
    n == 1 ? ans = 0 : ans = infinite;
    for (i = 1; i <= n - 1; i++)
    {
        for (j = i + 1; j <= n; j++)
        {
            ans = min(ans, fun(i, j, v));
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