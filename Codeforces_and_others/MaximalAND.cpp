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
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    vector<ll> bitHash(31, 0);
    for (i = 0; i < n; i++)
    {
        for (ll mask = 0; mask <= 30; mask++)
        {
            if (v[i] & (1 << mask))
                bitHash[mask]++;
        }
    }
    vector<ll> ans_v;
    for (i = 30; i >= 0; i--)
    {
        if (n - bitHash[i] <= k)
        {
            ans_v.push_back(i);
            k -= (n - bitHash[i]);
        }
    }
    ll ans = 0;
    if (ans_v.size() == 0)
        ans = 0;
    else
    {
        for (auto x : ans_v)
        {
            ans += pow(2, x);
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