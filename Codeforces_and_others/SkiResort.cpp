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
    cin >> n >> k >> q;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    v.push_back(infinite);
    ll cnt = 0;
    ll ans = 0;
    for (i = 0; i < v.size(); i++)
    {
        if (v[i] <= q)
            cnt++;
        else
        {
            if (cnt >= k)
            {
                ll num = cnt + 1 - k;
                ans += num * (num + 1) / 2;
            }
            cnt = 0;
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